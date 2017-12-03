import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.awt.geom.*;
import java.util.*;

/**
 * This class draws a battle field. Requires a map provider. Provides custom scrolling
 * behaivour.
 * @author Ivan Porty
 * @version 1.1
 */
public class BattleField extends JComponent implements Scrollable {
	
	private MapProvider mp;
	
	private static Properties props;
	
	static {
		loadPreferences();
	}
	
	/**
	 * Requires a MapProvider to work. MapProvider is used to get map size and data.
	 * Different MapProvider's can get their data from various sources, thus allowing better flexibility (Strategy)
	 */
	public BattleField(MapProvider mp, InfoWindow info) {
		this.mp = mp;
		this.info = info;		
		setupColors();
		loadImages();
		createMapImage();
		createListeners();
	}
	
	private InfoWindow info;
	
	private int selectedCellX;
	private int selectedCellY;
	/**
	 * Registers required event listeners for this battle field.
	 * Currently only mouse listener gathering info about clicked cell
	 * is used.
	 */
	private void createListeners() {
		addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
					if ( ! SwingUtilities.isLeftMouseButton(e) ) return;
					int x = e.getX();
					int y = e.getY();
					// now we should convert to cells
					selectedCellX = x/cellSizeX;
					selectedCellY = mp.getMapSizeY() - y/cellSizeY - 1;
					// updating ship info window
					updateSelectedCellInfo();
					info.setShipInfo( selectedShipInfo );
				}
			});
	}
	
	public ShipInfo selectedShipInfo;
	// looks for ship at the specified cell
	public void updateSelectedCellInfo() {
		// traverse ship list looking for hit
		synchronized ( ships ) {
			Iterator i = ships.iterator();
			while ( i.hasNext() ) {
				ShipInfo si = (ShipInfo)i.next();
				if ( si.x == selectedCellX && si.y == selectedCellY ) {
					selectedShipInfo = si;
					return;
				}
			}
			// no ship detected at this cell
			selectedShipInfo = null;			
		}
	}
	
	/**
	 * Creates offscreen image used to speed up map drawings. Allows
	 * to query map provider only once (map is not changing during the game). Can be
	 * called during the game when cell sizes are changed and map requires redrawing
	 */
	public void createMapImage() {
		Dimension size = getPreferredSize();
		// give a hint to GC that this crap should be erased
		mapImage = null;
		System.gc();
		mapImage = new BufferedImage(size.width, size.height, BufferedImage.TYPE_INT_ARGB);
		Graphics2D g2 = (Graphics2D)mapImage.getGraphics();
		g2.setRenderingHint( RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		// drawing an offscreen map
		// from 1.1 we switch to 2D API, cause it's more flexible
		for ( int i=0; i<mp.getMapSizeX(); i++) {
			for ( int k=0; k<mp.getMapSizeY(); k++) {				
				// filling with appropriate color
				Rectangle rect = new Rectangle(getActualX(i) , getActualY(k) , cellSizeX, cellSizeY);
				switch ( mp.getFieldAt(i, k) ) {
				case MapConstants.FLEET: 
					g2.setPaint(fleet);
					break;
				case MapConstants.NORMAL:
					g2.setPaint(normal);					
					break;
				case MapConstants.LAND: 
					g2.setPaint(tpLand);					
					break;
				case MapConstants.DEEPLY: 
					g2.setPaint(tpDeeply);
					break;
				case MapConstants.VERY_DEEPLY: 
					g2.setPaint(tpVeryDeeply);
					break;
				default:
					g2.setPaint(land);					
					break;
				}
				g2.fill(rect);
				if ( mp.getFieldAt(i, k) == MapConstants.LAND )
					lookForEdge(g2, rect, i, k);
			}
		}
		// done it
		// lastly, create scroll pane decorations, if we in it
		if ( scroller != null ) createScrollPaneCorners();
	}
	
	private Image edgeEW = new ImageIcon("images/land_sea_EW.png").getImage();
	private Image edgeWE = new ImageIcon("images/land_sea_WE.png").getImage();
	private Image edgeNS = new ImageIcon("images/land_sea_NS.png").getImage();
	private Image edgeSN = new ImageIcon("images/land_sea_SN.png").getImage();
	private Image cornerEWS = new ImageIcon("images/cornerEW_S.png").getImage();
	private Image cornerEWN = new ImageIcon("images/cornerEW_N.png").getImage();
	private Image cornerWEN = new ImageIcon("images/cornerWE_N.png").getImage();
	private Image cornerWES = new ImageIcon("images/cornerWE_S.png").getImage();
	
	private void lookForEdge(Graphics2D g2, Rectangle rect, int cellX, int cellY) {
		if ( cellX == mp.getMapSizeX() || cellX == 0 || cellY == 0 ) return;
		// corners are currently used rarely
		if ( mp.getFieldAt(cellX-1, cellY) != MapConstants.LAND &&
				mp.getFieldAt(cellX, cellY-1) != MapConstants.LAND ) {
			g2.drawImage( cornerEWS, rect.x, rect.y, rect.width, rect.height, this);
			return;
		}
		if ( mp.getFieldAt(cellX-1, cellY) != MapConstants.LAND &&
				mp.getFieldAt(cellX, cellY+1) != MapConstants.LAND ) {
			g2.drawImage( cornerEWN, rect.x, rect.y, rect.width, rect.height, this);
			return;
		}
		if ( mp.getFieldAt(cellX+1, cellY) != MapConstants.LAND &&
				mp.getFieldAt(cellX, cellY+1) != MapConstants.LAND ) {
			g2.drawImage( cornerWEN, rect.x, rect.y, rect.width, rect.height, this);
			return;
		}
		if ( mp.getFieldAt(cellX+1, cellY) != MapConstants.LAND &&
				mp.getFieldAt(cellX, cellY-1) != MapConstants.LAND ) {
			g2.drawImage( cornerWES, rect.x, rect.y, rect.width, rect.height, this);
			return;
		}
		if ( mp.getFieldAt(cellX-1, cellY) != MapConstants.LAND ) {
			g2.drawImage( edgeEW, rect.x, rect.y, rect.width, rect.height, this);
		}
		else if ( mp.getFieldAt(cellX+1, cellY) != MapConstants.LAND ) {
			g2.drawImage( edgeWE, rect.x, rect.y, rect.width, rect.height, this);
		}
		else if ( mp.getFieldAt(cellX, cellY+1) != MapConstants.LAND ) {
			g2.drawImage( edgeSN, rect.x, rect.y, rect.width, rect.height, this);
		}
		else if ( mp.getFieldAt(cellX, cellY-1) != MapConstants.LAND ) {
			g2.drawImage( edgeNS, rect.x, rect.y, rect.width, rect.height, this);
		}
	}
	
	private JScrollPane scroller;
	public void setScrollPane(JScrollPane scroller) {
		this.scroller = scroller;
		createScrollPaneCorners();
	}
	
	// decorates scroll pane with some corners
	private void createScrollPaneCorners() {
		// should be the same size as a map
		Dimension size = getPreferredSize();
		// looking for scroll pane		
		scroller.setColumnHeaderView(new AxisLabel.AxisX(size.width, this));		
		scroller.setRowHeaderView(new AxisLabel.AxisY(size.height, this));
		scroller.invalidate();
		scroller.validate();
		scroller.repaint();
	}
	
	protected BufferedImage mapImage;
	
	/**
	 * Allows to easily convert cell coordinates to
	 * actual screen coordinates. Cell coordinates are counted from
	 * lower left corner (decart system)
	 */
	public int getActualX(int cellX) {
		return cellX*cellSizeX;
	}
	/**
	 * Allows to easily convert cell coordinates to
	 * actual screen coordinates. Cell coordinates are counted from
	 * lower left corner (decart system)
	 */
	public int getActualY(int cellY) {
		// get the max Y
		int maxY = cellSizeY*mp.getMapSizeY();
		return (maxY - cellY*cellSizeY - cellSizeY);
	}
	
	public MapProvider getMapProvider() {
		return mp;
	}
	
	protected Color fleet, normal, land, deeply, veryDeeply;
	protected Color shotTrace, shotEnding;
	/**
	 * Uploads color settings for the battle field
	 */
	public void setupColors() {
		fleet = Color.decode((String)props.get("ColorFleet"));
		normal = Color.decode((String)props.get("ColorNormal"));
		land = Color.decode((String)props.get("ColorLand"));
		deeply = Color.decode((String)props.get("ColorDeeply"));
		veryDeeply = Color.decode((String)props.get("ColorVeryDeeply"));
		shotTrace = Color.decode((String)props.get("ColorShotTrace"));
		shotEnding = Color.decode((String)props.get("ColorShotEnding"));
	}
	
	// controls grid painting
	protected boolean gridPaint = false;
	
	/**
	 * Paints the battle field.
	 */
	public void paintComponent(Graphics g) {
		// drawing prepared offscreen map image
		synchronized ( mapImage ) {
			g.drawImage(mapImage, 0, 0, this);
		}
		// check whether grid is needed
		if ( gridPaint ) {
			for ( int i=0; i<mp.getMapSizeX(); i++) {
				for ( int k=0; k<mp.getMapSizeY(); k++) {
					// drawing grid
					g.setColor(Color.white);				
					g.drawRect(i*cellSizeX, k*cellSizeY, cellSizeX, cellSizeY);
				}
			}
		}		
		// now ships			
		synchronized ( ships ) {
			Iterator it = ships.iterator();			
			while ( it.hasNext() ) {
				drawShip(g, (ShipInfo)it.next());
			}
		}
		// finally, shots
		drawShots(g);
	}
	
	int cellSizeX, cellSizeY;
	// where the ships is hold
	ArrayList ships = new ArrayList();
	// where the shots is hold
	ArrayList shots = new ArrayList();
	
	// holds ship images. Row is a startegy, column is a ship with direction
	protected Image[][] shipImages = new Image[8][8];
	
	// some textures
	private Image textureLand, textureVeryDeeply, textureDeeply;
	private TexturePaint tpLand, tpVeryDeeply, tpDeeply;
	
	protected void loadImages() {
		for ( int i=0; i<8; i++) {
			shipImages[0][i] = new ImageIcon("images/ship" + i + ".png").getImage();
			// duplicate images for all strategies
			for (int j=1; j<8; j++) 
				shipImages[j][i] = shipImages[0][i];
		}
		// now marking ships with different colors
		Color shipGray = new Color(192, 192, 192);
		for (int i=0; i<8; i++) {
			for (int j=0; j<8; j++) {
				int w = shipImages[i][j].getWidth(this);
				int h = shipImages[i][j].getHeight(this);
				BufferedImage bi = new BufferedImage(w, h, BufferedImage.TYPE_INT_ARGB);
				Graphics g = bi.getGraphics();
				g.drawImage( shipImages[i][j], 0, 0, this);
				// looking for RGB values and changing them
				for (int k=0; k<w; k++) {
					for (int n=0; n<h; n++) {
						int rgb = bi.getRGB(k, n);
						if ( shipGray.getRGB() == rgb ) {
							bi.setRGB(k, n, strategyColors[i].getRGB());
						}
					}
				}
				// changing original image
				shipImages[i][j] = bi;
			}
		}
		// loading textures
		textureLand = new ImageIcon((String)props.get("TextureLand")).getImage();
		textureDeeply = new ImageIcon((String)props.get("TextureDeeply")).getImage();
		textureVeryDeeply = new ImageIcon((String)props.get("TextureVeryDeeply")).getImage();
		tpLand = createTexturePainter(textureLand);
		tpVeryDeeply = createTexturePainter(textureVeryDeeply);
		tpDeeply = createTexturePainter(textureDeeply);
	}
	
	// helper method, used to create texture paints
	private TexturePaint createTexturePainter(Image i) {
		Rectangle2D rect = new Rectangle2D.Float(0f, 0f, (float)i.getWidth(this), (float)i.getHeight(this));
		BufferedImage buffer = new BufferedImage(i.getWidth(this), i.getHeight(this), BufferedImage.TYPE_INT_ARGB);
		buffer.getGraphics().drawImage(i, 0, 0, this);
		TexturePaint tp = new TexturePaint(buffer, rect);
		return tp;
	}
	
	// this is colors assigned to different strategies
	// there are 8 strategies maximum (see HLD), so this array
	// has length of 8
	private Color[] strategyColors = { Color.green, Color.white,
		Color.pink, Color.yellow, Color.red, Color.orange, new Color(128, 64, 0) /*Brown*/, new Color(128, 128, 64) /*Dark Green*/  };
	
	void drawShip(Graphics g, ShipInfo si) {		
		// defining an image to draw
		Image im = shipImages[si.strategy_id][si.heading];
		if ( im == null ) return;
		// marking cell as a cell with ship belonging to
		// some strategy. Different strategies use different colors
		//Graphics2D g2 = (Graphics2D)g;
		//g2.setComposite( AlphaComposite.getInstance( AlphaComposite.SRC_OVER, 0.3f ));
		//g2.setPaint(strategyColors[si.strategy_id]);
		//g2.fill(new Rectangle2D.Double( getActualX(si.x), getActualY(si.y), cellSizeX, cellSizeY));
		// switching back to full opacity
		//g2.setComposite( AlphaComposite.getInstance( AlphaComposite.SRC_OVER, 1.0f) );
		// drawing an image of the ship in the specified cell
		g.drawImage(im, getActualX(si.x)+1, getActualY(si.y)+1, cellSizeX-1, cellSizeY-1, this);
	}
	
	private float[] dash = { 0.0f, 3f, 0f, 3f };
	private BasicStroke shotStroke = new BasicStroke(2.5f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND, 1f, dash, 0f);
	// draws shots made by the ships
	private void drawShots(Graphics g) {
		synchronized ( shots ) {
			Iterator i = shots.iterator();
			while ( i.hasNext() ) {
				// drawing a dotted line from src to dest
				ShotInfo si = (ShotInfo)i.next();
				int x1 = getActualX(si.x) + cellSizeX/2;
				int y1 = getActualY(si.y) + cellSizeY/2;
				int x2 = getActualX(si.destX) + cellSizeX/2;
				int y2 = getActualY(si.destY) + cellSizeY/2;								
				Graphics2D g2 = (Graphics2D)g;
				g2.setPaint(shotTrace);
				g2.setStroke(shotStroke);
				g2.draw(new Line2D.Double(x1, y1, x2, y2));
				// drawing start and end of the shot
				g2.setPaint(shotEnding);
				g2.fill(new Ellipse2D.Double(x1-cellSizeX/4, y1-cellSizeY/4, cellSizeX/2, cellSizeX/2));
				g2.setStroke(new BasicStroke(2f));
				g2.draw(new Line2D.Double(x2-cellSizeX/4, y2-cellSizeY/4, x2+cellSizeX/4, y2+cellSizeY/4));
				g2.draw(new Line2D.Double(x2-cellSizeX/4, y2+cellSizeY/4, x2+cellSizeX/4, y2-cellSizeY/4));
			}
		}
	}
	
	public Dimension getPreferredSize() {		
		if ( cellSizeX == 0 ) {
			// if this is initial time, read from props
			cellSizeX = Integer.parseInt((String)props.get("CellSizeX"));
			cellSizeY = Integer.parseInt((String)props.get("CellSizeY"));
		}
		int x = mp.getMapSizeX()*cellSizeX;
		int y = mp.getMapSizeY()*cellSizeY;
		return new Dimension(x, y);
	}
	
	/**
	 * Used to load prefs for this battle field (colors and sizes, maybe something else)
	 */
	protected static void loadPreferences() {
		try {
			props = new Properties();
			props.load(BattleField.class.getResourceAsStream("battlefield.props"));
		}
		catch (Exception ex)
		{ ex.printStackTrace(); System.exit(1);	}
	}
	
	/**
	 * SCROLLABLE IMPLEMENTATION. PROVIDES CUSTOM CELL BASED SCROLLING
	 */

	public Dimension getPreferredScrollableViewportSize() {
		return getPreferredSize();
	}

	// TODO: actually should differentiate X and Y cells
	public int getScrollableUnitIncrement(Rectangle p1, int orient, int dir) {
		// when user press arrow		return cellSizeX;
	}

	public int getScrollableBlockIncrement(Rectangle p1, int orient, int dir) {	
		// when user press free space on scrollbar		return cellSizeX*5;
	}

	public boolean getScrollableTracksViewportWidth() {				return false;
	}

	public boolean getScrollableTracksViewportHeight() {				return false;
	}
}