import java.awt.*;
import javax.swing.JPanel;
import java.util.Scanner;

public class DrawPanel extends JPanel {
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
	
		int width = getWidth();
		int height = getHeight();
	
		/*for(int i=1; i<=16; i++) {
			int newwid = i*width/16;
			int newhgt = (16-i)*height/16;
			g.drawLine(0, 0, newwid, newhgt);
			g.drawLine(width, 0, width-newwid, newhgt);
			g.drawLine(0, height, newwid, height-newhgt);
			g.drawLine(width, height, width-newwid, height-newhgt);
		}*/
		
		/*for(int i=1; i<=16; i++) {
			int newwid = i*i*width/256;
			int newhgt = i*i*height/256;
			g.drawLine(newwid, newhgt, newwid, height);
			
		}*/		
	}
}
