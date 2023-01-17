import java.awt.*;
import javax.swing.*;
import java.util.Scanner;

public class DrawPanel extends JPanel {
	public int num;
	public int rad;
	public DrawPanel(int num) {
		this.num = num;
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
		g.drawOval(0,0,width,height);
		g.setColor(Color.BLUE);
		for(int i=num-1;i>0;i--) {
			int xrad = width*i/num;
			int yrad = height*i/num;
			g.drawOval(width/2-xrad/2,height/2-yrad/2,xrad,yrad);
		}
	}
}
