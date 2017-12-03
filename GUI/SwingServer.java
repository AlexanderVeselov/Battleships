public class SwingServer
{
	public static void main(String[] args)
	{
		if ( args.length < 2 ) {
			System.err.println("Two arguments needed");
			System.exit(-1);
		}
		String addr = args[0];
		int port = Integer.parseInt(args[1]);
		new SwingServerFrame(addr, port);
	}
}
