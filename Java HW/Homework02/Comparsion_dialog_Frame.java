import java.awt.*;
import javax.swing.*;

public class Comparison_dialog extends JFrame
{
	public Fonts() {
		super("Using fonts");
		setsize(500, 700);
		setVisible(true);
	}
	
	public void paint(Graphics g)
	{
		super.paint(g);
		g.setFont(new Font("Serif", Font.BOLD, 12));
		
		
		
		int x, y, z, sum, pro;
		double avg;
		String xVal, yVal, zVal;
		xVal = JOptionPane.showInputDialog("Enter the first integer: ");
		yVal = JOptionPane.showInputDialog("Enter the second integer: ");
		zVal = JOptionPane.showInputDialog("Enter the third integer: ");
		
		x = Integer.parseInt(xVal);
		y = Integer.parseInt(yVal);
		z = Integer.parseInt(zVal);
		
		sum = x + y + z;
		avg = sum/3.;
		pro = x*y*z;
		
		JOptionPane.showMessageDialog(null,"The sum is " + sum);
		JOptionPane.showMessageDialog(null,"The average is " + avg);
		JOptionPane.showMessageDialog(null,"The product is " + pro);
		JOptionPane.showMessageDialog(null,"The smallest int is " + small(x,y,z));
		JOptionPane.showMessageDialog(null,"The biggest int is " + big(x,y,z));
		System.exit(0);
	}
	
	public static void main(String[] args){
		Fonts application = new Fonts();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}