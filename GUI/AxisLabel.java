
import javax.swing.*;
import java.awt.*;

public class AxisLabel {
	// used by the axis to determine its size
	public static int AXIS_SIZE = 15;
	public static int COORDS_GAP = 10;
	// draws axis X
	public static class AxisX extends JLabel {		
		
		private Font font = new Font("Arial", Font.BOLD, 12);
		private BattleField bf;
		
		public AxisX(int size, BattleField bf) {
			// setting our size
			setPreferredSize(new Dimension(size, AXIS_SIZE));
			setBorder(BorderFactory.createEtchedBorder());
			this.bf = bf;
		}
		
		public void paintComponent(Graphics g) {
			// draws an axis with coords
			g.setColor(Color.blue);
			g.fillRect(0, 0, getWidth(), getHeight());
			g.setFont(font);
			g.setColor(Color.white);			
			int i = 0;
			while ( i < bf.getMapProvider().getMapSizeX()  ) {
				g.drawString(""+i, bf.getActualX(i), 12);
				i += COORDS_GAP;
			}
		}
		
	}
	// draws axis Y
	public static class AxisY extends JLabel {		
		
		private Font font = new Font("Arial", Font.BOLD, 12);
		private BattleField bf;
		
		public AxisY(int size, BattleField bf) {
			// setting our size
			setPreferredSize(new Dimension(AXIS_SIZE, size));
			setBorder(BorderFactory.createEtchedBorder());
			this.bf = bf;
		}
		
		public void paintComponent(Graphics g) {
			// draws an axis with coords
			g.setColor(Color.blue);
			g.fillRect(0, 0, getWidth(), getHeight());
			g.setFont(font);
			g.setColor(Color.white);			
			int i = 0;
			while ( i < bf.getMapProvider().getMapSizeY()  ) {
				g.drawString(""+i, 1, bf.getActualY(i) + bf.cellSizeY );
				i += COORDS_GAP;
			}
		}
		
	}
}
