import java.io.*;
import java.util.*;

/**
 * Reads map from any kind of Input Stream, which may read data from anywhere. 
 * Version 2.0. Revised for actual map files (containing bytes)
 */
public class StreamMapProvider implements MapProvider
{	
	/** Tryes to read all the data into array
	 * @param is Input Stream to read from
	 */
	public StreamMapProvider(InputStream is) {
		
		// make it capable of reading primitives properly
		DataInputStream dis = new DataInputStream(is);
		
		
		// get the size
		try {		
		sx = dis.readInt();
		sy = dis.readInt();
		
		System.out.println(":" + sx + ":" + sy);
		
		// get the data
		// outer cycle is Y
		// inner cycle is X, as defined in (protocol.txt)
		mapData = new byte[sx][sy];
		for ( int i=0; i<sy; i++) {
			
			for ( int k=0; k<sx; k++) {
				mapData[k][i] = dis.readByte();
			}
			
		}
		
		} catch (Exception ex)
		{ ex.printStackTrace();	}
	}
	
	private byte mapData[][];
	private int sx, sy;
	
	public int getFieldAt(int x, int y)
	{		
		return mapData[x][y];
	}

	public int getMapSizeX()
	{		
		return sx;
	}

	public int getMapSizeY()
	{				return sy;
	}
}