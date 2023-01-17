import javax.swing.JOptionPane;

public class Product1
{
	public static void main(String args[])
	{
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
	
	public static int small(int x, int y, int z){
		int smallest = x;
		if(y<smallest)
			smallest = y;
		if(z<smallest)
			smallest = z;
		return smallest;
	}
	
	public static int big(int x, int y, int z){
		int biggest = x;
		if(y>biggest)
			biggest = y;
		if(z>biggest)
			biggest = z;
		return biggest;
	}
}