import java.io.*;
import java.util.*;

public class FileMapProvider implements MapProvider
{	
	private BufferedReader br;
	
	public FileMapProvider(Reader rd) {
		br = new BufferedReader(rd);
		// get the size
		try {
		String size = br.readLine();
		StringTokenizer st = new StringTokenizer(size, ";", false);
		sx = Integer.parseInt(st.nextToken());
		sy = Integer.parseInt(st.nextToken());	
		// get the data
		mapData = new int[sx][sy];
		for ( int i=0; i<sx; i++) {
			String str = br.readLine();
			st = new StringTokenizer(str, ";", false);
			for ( int k=0; k<sy; k++) {
				mapData[i][k] = Integer.parseInt(st.nextToken());
			}
		}		
		} catch (Exception ex)
		{ ex.printStackTrace();	}
	}
	
	private int mapData[][];
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
