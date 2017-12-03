
import java.net.*;
import java.io.*;

// dummy server. Later will be replaced by SDL
public class DummyServer implements TransferProtocol
{
	private ServerSocket serverSocket;
	private Socket socket;
	private int port = 5040; // default port value
	
	public static final String TEST_MAP = "map2.map";
	
	// this method waits for connections coming
	public void service() {
		try {
			serverSocket = new ServerSocket(port);
			while (true) {
				// now we wait for incoming call
				Socket socket = serverSocket.accept();
				// we've got it, run handler
				new ProtocolHandler(socket);
			}			
		}
		catch (Exception ex) {
				System.out.println("Error + " + ex);
				System.exit(-1);
		}
	}
	
	// this thread is responsible for transferring data
	class ProtocolHandler extends Thread {
		
		private Socket socket;
		private DataOutputStream dos;
		private DataInputStream dis;
		
		ProtocolHandler(Socket s) {
			socket = s;
			try {
				dos = new DataOutputStream(socket.getOutputStream());
				dis = new DataInputStream(socket.getInputStream());
			}
			catch (Exception ex) { ex.printStackTrace(); }
			start();
		}
		
		public final String HELLO_STRING = "Hello";
		
		public void run() {
			try {
				// first of ALL,
				// perform hello
				byte[] data = new byte[5];
				dis.readFully(data);
				String hello = new String(data, "ASCII");
				if ( ! hello.equals(HELLO_STRING) ) {
					System.err.println("Wrong client request: " + hello);
					return;
				}
				// send the ACK
				dos.writeByte(ACK);
				dos.writeInt(0);
				// now strategy count
				dos.writeByte(INIT);
				dos.writeInt(0);
				dos.writeInt(2); // strategy count
				// then, send map info
				dos.writeByte(MAP);
				dos.writeInt(0);
				sendMapData(dos);
				// and wait for further commands
				sleep(2000);
				int y = 8;
				int wp = 0;
				while ( true ) {
					
					dos.writeByte(SHIPS); // cmd
					dos.writeInt(0); // cmdlen
					dos.writeInt(3); // ship count
					//System.out.println("Sending data");
					
					dos.writeInt(0); // id
					dos.writeInt(0); // strategy					
					dos.writeInt(0); // type
					dos.writeInt(1); // speed
					dos.writeInt(ShipInfo.NORTH); // heading
					dos.writeInt(10); // resource
					dos.writeInt(65); // x
					dos.writeInt(++y); // y
					// weapons
					for (int j=0; j<4; j++) dos.writeInt(1);
					// visibility
					for (int j=0; j<2; j++) dos.writeByte(1);
					
					dos.writeInt(0); // id
					dos.writeInt(1); // strategy					
					dos.writeInt(0); // type
					dos.writeInt(1); // speed
					dos.writeInt(ShipInfo.NORTH_EAST); // heading
					dos.writeInt(10); // resource
					dos.writeInt(y); // x
					dos.writeInt(y); // y
					// weapons
					for (int j=0; j<4; j++) dos.writeInt(1);
					// visibility
					for (int j=0; j<2; j++) dos.writeByte(1);
					
					dos.writeInt(0); // id
					dos.writeInt(2); // strategy					
					dos.writeInt(0); // type
					dos.writeInt(1); // speed
					dos.writeInt(ShipInfo.EAST); // heading
					dos.writeInt(10); // resource
					dos.writeInt(y); // x
					dos.writeInt(80); // y
					// weapons
					for (int j=0; j<4; j++) dos.writeInt(1);
					// visibility
					for (int j=0; j<2; j++) dos.writeByte(1);
					
					// WEAPONS
					dos.writeByte(SHOTS); // cmd
					dos.writeInt(0); // cmdlen
					dos.writeInt(1); // shots count
					dos.writeInt(0); // type
					dos.writeInt(10+wp); // x
					dos.writeInt(10+wp); // y
					dos.writeInt(20); // dx
					dos.writeInt(20); // dy
					wp++;
					if ( wp == 10 ) wp = 0;
					
					//System.out.println("Sending complete");
					
					sleep(1000);
				}
			}
			catch (Exception ex) {
				ex.printStackTrace();
			}
		}
	
		void sendMapData(DataOutputStream dos) throws Exception {
			// just sending file containing data			
			FileInputStream fis = new FileInputStream(TEST_MAP);
			while ( fis.available() > 0 ) {
				dos.writeByte((byte)fis.read());
			}			
			fis.close();
		}
		
	}
	
	public static void main(String[] args) {		
		DummyServer ds = new DummyServer();
		// checking for optional argument
		if ( args.length > 0) {
			ds.port = Integer.parseInt(args[0]);
		}
		ds.service();
	}
}
