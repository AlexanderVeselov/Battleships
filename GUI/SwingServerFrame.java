import javax.swing.*;
import java.net.*;
import java.io.*;
import java.awt.event.*;
import java.awt.*;

/**
 * Main frame of the application.
 */
public class SwingServerFrame extends JFrame implements TransferProtocol {
	
	public final int TEST_PORT = 5040;
	
	protected String addr;
	protected int port;
	
	/**
	 * Requires netrwork address and port number to run properly.
	 */
	public SwingServerFrame(String addr, int port) {
		super("Swing Server 1.1");
		this.addr = addr;
		this.port = port;
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setSize(600, 550);
		setLocation(25, 20);
		createGUI();
		initialize();		
		setVisible(true);
	}
	
	private JButton	zoomIn, zoomOut, grid;
	private JTextArea logWindow;
	private JScrollPane scroller;
	protected InfoWindow info;
	private void createGUI() {
		JPanel main = new JPanel( new java.awt.BorderLayout() );
		main.setBorder(BorderFactory.createEmptyBorder(12, 12, 12, 12));
		//
		JPanel buttons = new JPanel();
		buttons.setBorder(BorderFactory.createEmptyBorder(12, 12, 12, 12));
		buttons.setLayout(new BoxLayout(buttons, BoxLayout.Y_AXIS));
		buttons.add(Box.createGlue());
		buttons.add(zoomIn = new JButton(new ImageIcon("images/ZoomIn.gif")));
		buttons.add(Box.createVerticalStrut(5));
		buttons.add(zoomOut = new JButton(new ImageIcon("images/ZoomOut.gif")));
		buttons.add(Box.createVerticalStrut(5));		
		buttons.add(grid = new JButton(new ImageIcon("images/Grid.gif")));
		buttons.add(Box.createGlue());		
		//
		zoomIn.addActionListener(new ZoomAction());
		zoomOut.addActionListener(new ZoomAction());
		grid.addActionListener(new GridAction());
		//
		JPanel log = new JPanel(new BorderLayout() );
		log.setBorder(BorderFactory.createCompoundBorder( BorderFactory.createEmptyBorder(12, 0, 0, 0) ,BorderFactory.createTitledBorder("Log & Stats")));
		log.add(new JScrollPane(logWindow = new JTextArea(3, 80)));
		logWindow.setEditable(false);		
		//
		setContentPane(main);		
		getContentPane().add(buttons, "East");
		getContentPane().add(log, "South");
		// adding info window
		info = new InfoWindow(this, "Ship Information");
	}
	
	protected static int strategyCount = 0;
	
	private void initialize() {
		try {			
			
			// creating socket with passed parameters
			socket = new Socket(addr, port);
			
			// now we performing a kind of initialization
			sayHello(socket);
			
			// getting strategy types
			loadStrategy(socket);
			
			// loading battle field and getting map
			bf = new BattleField(new NetworkMapProvider(socket), info);
			getContentPane().add(scroller = new JScrollPane(bf, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS));
			bf.setScrollPane(scroller);
			//bf = new BattleField(new StreamMapProvider(new FileInputStream("map1.map")));
			
			// starting data cycle
			new ProtocolHandler();			
			
			
		} catch (Exception ex) {
			ex.printStackTrace();			
		}
	}
	
	
	public static final String HELLO_STRING = "Hello";
	
	/**
	 * This methods says Hello to server performing SDL sim
	 */
	private void sayHello(Socket s) throws Exception {
		// sending Hello messge
		DataInputStream dis = new DataInputStream(s.getInputStream());
		DataOutputStream dos = new DataOutputStream(s.getOutputStream());
		dos.writeBytes("Hello");
		// waiting for ACK signal from serve		
		byte ack = dis.readByte();
		// this message lenght is dummy, but we read it
		int msglen = dis.readInt();
		// check for answer
		if ( ack != ACK ) {
			System.out.println("Server sent unrecognized signal");
			System.exit(-1);
		}
		// auth is correct
		System.out.println("SDL Server connected");		
	}
	
	/**
	 * handles INIT message
	 */
	private void loadStrategy(Socket s) throws Exception {
		// getting strategu types
		DataInputStream dis = new DataInputStream(s.getInputStream());
		DataOutputStream dos = new DataOutputStream(s.getOutputStream());
		// reading
		byte cmd = dis.readByte();
		int cmdlen = dis.readInt();
		if ( cmd != INIT ) {
			System.out.println("Server sent unrecognized signal: " + cmd);
			System.exit(-1);
		}
		// reading number of strategies
		strategyCount = dis.readInt();
		// done it
		System.out.println("Starting out the game with " + strategyCount + " number of strategies");
	}

	
	class ProtocolHandler extends Thread {
		ProtocolHandler() {			
			try {
			dis = new DataInputStream(socket.getInputStream());
			} catch (Exception ex) {
				ex.printStackTrace();
			}
			start();
		}
		DataInputStream dis;
		public void run() {
			try {
				while ( true ) {
					/**
					 * Reading a command and its length, according
					 * to protocol.txt
					 */
					byte cmd = dis.readByte();
					int cmdlen = dis.readInt();
					//System.out.println("command received: " + cmd);
					switch ( cmd ) {
					case SHIPS:
						handleShips();
						//info.setShipInfo( bf.selectedShipInfo );
						break;
					case SHOTS:
						handleShots();
						break;
					}
					sleep(200);
				}
			}
			catch (Exception ex) {
				ex.printStackTrace();
			}
		}
		
		private void handleShips() throws IOException {
			int shipCount = dis.readInt();
			logWindow.append("SHIPS received: " + shipCount + " \n");
			synchronized ( bf.ships ) {
				bf.ships.clear();
				for ( int i = 0; i<shipCount; i++) {
					// this cycle is done according
					// to (protocol.txt)
					ShipInfo si = new ShipInfo();
					// init additional info
					si.visibility = new byte[strategyCount];
					// reading data
					si.id = dis.readInt();
					si.strategy_id = dis.readInt();
					si.type = dis.readInt();
					si.speed = dis.readInt();
					si.heading = dis.readInt();
					si.resource = dis.readInt();
					si.x = dis.readInt();
					si.y = dis.readInt();
					// weapons available
					si.missiles = dis.readInt();
					si.torpedoes = dis.readInt();
					si.shells = dis.readInt();
					si.repair = dis.readInt();
					// additional
					for ( int k=0; k<strategyCount; k++) {
						si.visibility[k] = dis.readByte();
					}
					// adding to list
					bf.ships.add(si);
				}
			}						
			bf.repaint();						
			logWindow.append("SHIPS handled \n");
			logWindow.setCaretPosition( logWindow.getDocument().getLength() );
		}
		
		private void handleShots() throws IOException {
			int shotsCount = dis.readInt();
			logWindow.append("SHOTS received: " + shotsCount + " \n");
			synchronized ( bf.shots ) {
				bf.shots.clear();
				// this cycle is done according
				// to (protocol.txt)
				for (int i=0; i<shotsCount; i++) {
					ShotInfo si = new ShotInfo();
					// reading data
					si.type = dis.readInt();
					si.x = dis.readInt();
					si.y = dis.readInt();
					si.destX = dis.readInt();
					si.destY = dis.readInt();
					// done it, adding to list
					bf.shots.add(si);
				}
			}
			bf.repaint();						
			logWindow.append("SHOTS handled \n");
			logWindow.setCaretPosition( logWindow.getDocument().getLength() );
		}
		
	}
	
	// our battle field
	private BattleField bf;
	// and socket to listen to
	private Socket socket;
	
	
	class ZoomAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			if ( e.getSource() == zoomIn ) {
				bf.cellSizeX += 5;
				bf.cellSizeY += 5;
				zoomOut.setEnabled(true);
			}
			else {
				if ( bf.cellSizeX == 5 ) {
					// smallest size possible reached
					// but we shouldn't get there
					return; 
				}
				bf.cellSizeX -= 5;
				bf.cellSizeY -= 5;
				if ( bf.cellSizeX == 5 ) zoomOut.setEnabled(false);
			}
			// recreate offscreen surface
			synchronized ( bf.mapImage ) {
				bf.createMapImage();
			}
			bf.invalidate();
			bf.repaint();
			scroller.revalidate();
			scroller.invalidate();
			scroller.repaint();
			validate();
			repaint();
		}
	}
	
	class GridAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			bf.gridPaint = ! bf.gridPaint;
			bf.repaint();
		}
	}
	
}
