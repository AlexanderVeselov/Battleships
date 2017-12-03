public class TestMapProvider implements MapProvider
{	
		
	public int getFieldAt(int x, int y)
	{		
		return MapConstants.FLEET;
	}

	public int getMapSizeX()
	{		
		return 25;
	}

	public int getMapSizeY()
	{				return 25;
	}
}
