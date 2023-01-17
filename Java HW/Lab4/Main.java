// Main.java
import javax.swing.*;
import java.awt.*;
public class Main {
	public static void main(String[] args) {
		MyPanel panel = new MyPanel();
		JFrame frame1 = new JFrame();
		JFrame frame2 = new JFrame();
		JFrame frame3 = new JFrame();
		JFrame frame4 = new JFrame();
		
		JButton button1 = new JButton("Red");
		JButton button2 = new JButton("Green");
		JButton button3	= new JButton("Blue");
		JButton button4	= new JButton("1");
		JButton button5	= new JButton("2");
		JButton button6	= new JButton("3");
		JButton button7	= new JButton("Rectangle");
		JButton button8	= new JButton("Oval");

		JLabel label1 = new JLabel("Color");
		JLabel label2 = new JLabel("Width");
		JLabel label3 = new JLabel("Shape");
		
		button1.setFont(new Font("Arial",Font.BOLD,30));
		button2.setFont(new Font("Arial",Font.BOLD,30));
		button3.setFont(new Font("Arial",Font.BOLD,30));
		button4.setFont(new Font("Arial",Font.BOLD,30));
		button5.setFont(new Font("Arial",Font.BOLD,30));
		button6.setFont(new Font("Arial",Font.BOLD,30));
		button7.setFont(new Font("Arial",Font.BOLD,30));
		button8.setFont(new Font("Arial",Font.BOLD,30));
		
		label1.setFont(new Font("Arial",Font.BOLD,30));
		label2.setFont(new Font("Arial",Font.BOLD,30));
		label3.setFont(new Font("Arial",Font.BOLD,30));
		
		button1.addActionListener((e)->{ panel.setColor(Color.RED); });
		button2.addActionListener((e)->{ panel.setColor(Color.GREEN); });
		button3.addActionListener((e)->{ panel.setColor(Color.BLUE); });
		button4.addActionListener((e)->{ panel.setStroke(new BasicStroke(1)); });
		button5.addActionListener((e)->{ panel.setStroke(new BasicStroke(2)); });
		button6.addActionListener((e)->{ panel.setStroke(new BasicStroke(3)); });
		button7.addActionListener((e)->{ panel.setShape(0); });
		button8.addActionListener((e)->{ panel.setShape(1); });
		
		frame2.setLayout(new FlowLayout());
		frame3.setLayout(new FlowLayout());
		frame4.setLayout(new FlowLayout());
		
		frame1.add(panel);
		frame2.add(label1);
		frame2.add(button1);
		frame2.add(button2);
		frame2.add(button3);
		frame3.add(label2);
		frame3.add(button4);
		frame3.add(button5);
		frame3.add(button6);
		frame4.add(label3);
		frame4.add(button7);
		frame4.add(button8);
		
		frame1.pack();
		frame2.pack();
		frame3.pack();
		frame4.pack();
		
		frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame4.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		frame1.setSize(800, 800);
		frame2.setSize(500, 100);
		frame3.setSize(500, 100);
		frame4.setSize(500, 100);
		
		frame1.setVisible(true);
		frame2.setVisible(true);
		frame3.setVisible(true);
		frame4.setVisible(true);
	}
}
