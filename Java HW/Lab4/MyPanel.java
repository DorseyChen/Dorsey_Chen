// MyPanel.java
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
public class MyPanel extends JPanel
	implements MouseListener, MouseMotionListener {
	Color color;
	BasicStroke basicStroke;
	// ...
	int x1, y1, x2, y2, flag;
	int x3, y3, x4, y4, process, shape;
	
	public MyPanel() {
		addMouseListener(this);
		addMouseMotionListener(this);
		// ...
	}
	public void mousePressed(MouseEvent event) {
		System.out.println("mousePressed");
		// ...
		if (SwingUtilities.isLeftMouseButton(event)) {
			x1 = event.getX();
			y1 = event.getY();
			x2 = event.getX();
			y2 = event.getY();
			flag = 1;
		}
	}
	public void mouseReleased(MouseEvent event) {
		System.out.println("mouseReleased");
		// ...
	}
	public void mouseDragged(MouseEvent event) {
		System.out.println("mouseDragged");
		// ...
		if (SwingUtilities.isLeftMouseButton(event)) {
			Graphics g = getGraphics();
			Graphics2D g2 = (Graphics2D)g;
			g2.setColor(color);
			g2.setStroke(basicStroke);
			if(flag==0){
				x1 = event.getX();
				y1 = event.getY();
				flag = 1;
			}
			else {
				x2 = event.getX();
				y2 = event.getY();
				flag = 0;
			}
			g2.drawLine(x1, y1, x2, y2);
		}
	}
	public void mouseClicked(MouseEvent event) {
		System.out.println("mouseClicked");
		// ...
		if (SwingUtilities.isRightMouseButton(event)) {
			if(process==0) {
				x3 = event.getX();
				y3 = event.getY();
				process = 1;
			}
			else {
				x4 = event.getX();
				y4 = event.getY();
				if(shape==0)
					drawTriangle();
				else
					drawOval();
				process = 0;
			}
		}
	}
	public void mouseEntered(MouseEvent event) {
		//System.out.println("mouseEntered");
		// ...
	}
	public void mouseExited(MouseEvent event) {
		//System.out.println("mouseExited");
		// ...
	}
	public void mouseMoved(MouseEvent event) {
		//System.out.println("mouseMoved");
		// ...
	}
	public void setColor(Color c) {
		System.out.println("setColor");
		color = c;
	}
	public void setStroke(BasicStroke b) {
		System.out.println("setStroke");
		basicStroke = b;
	}
	public void setShape(int s) {
		System.out.println("setColor");
		shape = s;
	}
	public void drawTriangle() {
		Graphics g = getGraphics();
		Graphics2D g2 = (Graphics2D)g;
		g2.setColor(color);
		g2.setStroke(basicStroke);
		g2.drawLine(x3, y3, x3, y4);
		g2.drawLine(x3, y3, x4, y3);
		g2.drawLine(x3, y4, x4, y4);
		g2.drawLine(x4, y3, x3, y3);
		g2.drawLine(x4, y4, x4, y3);
	}
	public void drawOval() {
		Graphics g = getGraphics();
		Graphics2D g2 = (Graphics2D)g;
		g2.setColor(color);
		g2.setStroke(basicStroke);
		int w, l;
		if(x3>x4)
			w=x3-x4;
		else
			w=x4-x3;
		if(y3>y4)
			l=y3-y4;
		else
			l=x4-x3;
		g2.drawOval((x3+x4)/2, (y3+y4)/2, w, l);
	}
}