import javax.swing.*;

/**
 * This window displays some ShipInfo in affordable manner
 */
public class InfoWindow  extends JDialog {
	
	public InfoWindow(JFrame parent, String title) {
		super(parent, title, false);
		setSize(160, 220);
		setLocation(500, 200);
		getContentPane().add( new JScrollPane( list = new JList() ) );
		list.setListData(new String[] { "No Ship Info Available" } );
		setVisible(true);
	}
	
	public void setShipInfo(ShipInfo si) {
		this.si = si;
		if ( si == null ) {
			list.setListData(new String[] { "No Ship Info Available" } );
			return;
		}
		// making up array of readable data
		String[] info = {
			"X: " + si.x,
			"Y: " + si.y,
			"Ship ID: " + si.id,
			"Strategy: " + si.strategy_id,
			"Type: " + ShipInfo.SHIP_NAME[si.type],
			"Heading: " + ShipInfo.HEADING_NAME[si.heading],
			"Speed: " + si.speed,
			"Resource: " + si.resource,
			"Shells: " + si.shells,
			"Missiles: " + si.missiles,
			"Torpedoes: " + si.torpedoes,
			"Repair: " + si.repair
		};
		list.setListData(info);
		invalidate();
		validate();
		repaint();
	}
	
	private JList list;
	private ShipInfo si;
}
