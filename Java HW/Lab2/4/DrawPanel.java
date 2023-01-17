import java.awt.*;
import javax.swing.*;
import java.util.Scanner;

public class DrawPanel extends JPanel {
	public int num;
	public int rad;
	public DrawPanel(int num, int rad) {
		this.num = num;
		this.rad = rad;
	}
	public void paintComponent(Graphics g) {
		super.paintComponent(g);	
		Graphics2D g2 = (Graphics2D) g;
		g2.setStroke(new BasicStroke(3));
		
		Dimension dim = this.getSize();
	
		int width = dim.width;
		int height = dim.height;
		
		g.drawLine(0,height/2,width,height/2);
		g.drawLine(width/2,0,width/2,height);
		g.setColor(Color.RED);
		g.drawOval(width/2-rad,height/2-rad,rad*2,rad*2);
		g.setColor(Color.BLUE);

		for(int i=0;i<num;i++) {
			double x1 = width/2 - rad*Math.sin(i*2*Math.PI/num);
			double y1 = height/2 - rad*Math.cos(i*2*Math.PI/num);
			double x2 = width/2 - rad*Math.sin((i+1)*2*Math.PI/num);
			double y2 = height/2 - rad*Math.cos((i+1)*2*Math.PI/num);
			g.drawLine((int)x1, (int)y1, (int)x2, (int)y2);
		}
	}
}
