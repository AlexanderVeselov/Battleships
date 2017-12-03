
import java.io.*;
import java.net.*;
import java.util.*;

public class NetworkMapProvider implements MapProvider, TransferProtocol
{	
	private StreamMapProvider smp;
	
	// allows to read data from TCP networks
	public NetworkMapProvider(Socket s) {
		
		try {
			
		// connecting		
		byte cmd = new DataInputStream(s.getInputStream()).readByte();
		int cmdlen = new DataInputStream(s.getInputStream()).readInt();
		if ( cmd != MAP ) {
			System.out.println("Incompatible protocol");
			return;
		}
		
		// redirecting to stream map provider
		smp = new StreamMapProvider(s.getInputStream());
		
		} catch (Exception ex)
		{ ex.printStackTrace();	}
	}	
	
	public int getFieldAt(int x, int y)
	{		
		return smp.getFieldAt(x,y);
	}

	public int getMapSizeX()
	{		
		return smp.getMapSizeX();
	}

	public int getMapSizeY()
	{				return smp.getMapSizeY();
	}
}
