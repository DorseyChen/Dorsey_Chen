import javax.swing.*;

public class VectorChange
{
	public static void main(String args[])
	{
		
		int opt;
		double x, y, theta, a;
		String Val1, Val2, optVal;
		
		
		optVal = JOptionPane.showInputDialog("Enter the first integer: ");
		opt = Integer.parseInt(optVal);
		
		if(opt == 1) {
			Val1 = JOptionPane.showInputDialog("Enter x: ");
			Val2 = JOptionPane.showInputDialog("Enter y: ");
			x = Double.parseDouble(Val1);
			y = Double.parseDouble(Val2);
			a = Math.sqrt(x*x+y*y);
			theta = Math.atan(y/x);
			JOptionPane.showMessageDialog(null,"Z = " + a + "<" + theta);
		}
		
		else {
			Val1 = JOptionPane.showInputDialog("Enter a: ");
			Val2 = JOptionPane.showInputDialog("Enter theta: ");
			a = Double.parseDouble(Val1);
			theta = Double.parseDouble(Val2);
			x = a * Math.cos(theta);
			y = a * Math.sin(theta);
			JOptionPane.showMessageDialog(null,"Z = i" + x + " + j" + y);
		}
		System.exit(0);
	}
}