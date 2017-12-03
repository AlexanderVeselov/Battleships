
/**
 * Ship Information Object, used to hold information received from the server.
 * See (protocol.txt)
 */
public class ShipInfo {
	int id;
	int strategy_id;	
	int type;
	int speed;
	int heading;
	int resource;	
	int x;
	int y;	
	int missiles, torpedoes, shells, repair;
	// additional storage initalized by protocol handler
	byte[] visibility;
	
	// heading constants
	public static final int NORTH = 0;
	public static final int NORTH_EAST = 1;
	public static final int EAST = 2;
	// still don't need full list
	
	// human readable data about ship
	public static String[] HEADING_NAME = {
		"N", "NE", "E", "SE", "S", "SW", "W", "NW"
	};
	public static String[] SHIP_NAME = {
		"Battle Ship", "Cruiser", "Destroyer", "Missile Cutter", "Repair Boat"
	};
}
