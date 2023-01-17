import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Scanner;

public class Rotate extends JFrame
{  
    private JTextField input = new JTextField("",20);
    private RotatePanel rp = new RotatePanel();
	
    public Rotate ( ) {
   	    JPanel  pl =  new JPanel();
   	    pl.add(input);
   	    input.setHorizontalAlignment(SwingConstants.RIGHT);
		add(rp);
		add(pl, BorderLayout.SOUTH);
		TextFieldHandler handler = new TextFieldHandler();
		input.addActionListener(handler);
    }
	
	private class TextFieldHandler implements ActionListener {
		@Override
		public void actionPerformed( ActionEvent event ){
			String str = input.getText();
			String[] tokens = str.split(" ");
			int length = Integer.parseInt(tokens[0]);
			int width = Integer.parseInt(tokens[1]);
			int rad = Integer.parseInt(tokens[2]);
			String line = tokens[3];
			String fill = tokens[4];
			rp.setValue(length,width,rad,line,fill,0);
			setSize(length*2, length*2);
		}
	}
}

class RotatePanel extends JPanel {
	private int order = 0;
	private int length = 200;
	private int width = 10;
	private double rad = 0;
	private String line = "BLACK";
	private String fill = "BLACK";
	
	public void setValue(int length, int width, int rad, String line, String fill, int order){ 
	    this.length = length;
		this.width = width;
		this.rad = rad;
		this.line = line;
		this.fill = fill;
		this.order = order;
		this.repaint();
	}
    
	public void paintComponent(Graphics g){
	    super.paintComponent(g);
		rad = rad * 0.01745329252;
		int x1 = length - (int)(length*Math.sin(0-rad));
		int y1 = length - (int)(length*Math.cos(0-rad))+ 10;
		int x2 = length - (int)(length*Math.sin(2*Math.PI/3-rad));
		int y2 = length - (int)(length*Math.cos(2*Math.PI/3-rad))+ 10;
		int x3 = length - (int)(length*Math.sin(4*Math.PI/3-rad));
		int y3 = length - (int)(length*Math.cos(4*Math.PI/3-rad))+ 10;
		
		System.out.printf("%d %d", x1, y1);
		
		Graphics2D g2 = (Graphics2D) g;
		g2.setStroke(new BasicStroke(width));
		setpencolor(g, line);
		Dimension dim = this.getSize();
		int width = dim.width;
		int height = dim.height;
		g.drawOval(0,0,width,height);
		
		drawSnow(g, x1, y1, x2, y2, x3, y3);
	}
		
    public void drawSnowLine(Graphics g, int x1, int y1, int x2, int y2){
           g.drawLine(x1, y1, x2, y2);
    } 

	public void drawSnow(Graphics g, int x1, int y1, int x2, int y2, int x3, int y3) {
		drawSnowLine(g, x1, y1, x2, y2);
		drawSnowLine(g, x1, y1, x3, y3);
		drawSnowLine(g, x3, y3, x2, y2);
		setpencolor(g, fill);
		int xArray[] = {x1, x2, x3};
		int yArray[] = {y1, y2, y3};
		g.fillPolygon(xArray, yArray, 3);
	}
	
	public void setpencolor(Graphics g, String color) {
		String r="RED", bu="BLUE", gr="GREEN", bk="BLACK";
		if(color.equals(r))
			g.setColor(Color.RED);
		else if(color.equals(bu))
			g.setColor(Color.BLUE);
		else if(color.equals(gr))
			g.setColor(Color.GREEN);
		else if(color.equals(bk))
			g.setColor(Color.BLACK);
	}
}