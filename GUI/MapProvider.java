/**
 * Providers for map data. Can get map data from various sources. Used by BattleField.
 */
public interface MapProvider
{
	int getFieldAt(int x, int y);
	int getMapSizeX();
	int getMapSizeY();
}
