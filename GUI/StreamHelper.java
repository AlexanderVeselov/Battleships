import java.io.InputStream;

/**
 * Has to write this class because of different byte order
 * used in simulator and this GUI. Fixes integer problems.
 */
public class StreamHelper {
	public static int readInt(InputStream is) throws Exception {
		int ch1 = is.read();
		int ch2 = is.read();
		int ch3 = is.read();
		int ch4 = is.read();
		if ((ch1 | ch2 | ch3 | ch4) < 0)
			throw new Exception("EOF");
		return ((ch4 << 24) + (ch3 << 16) + (ch2 << 8) + (ch1 << 0));
	}
}
