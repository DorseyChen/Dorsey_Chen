import javax.swing.JOptionPane;

public class Product1
{
	public static void main(String args[])
	{
		double x, y, z;
		String xVal, yVal, zVal;
		xVal = JOptionPane.showInputDialog("Enter the first double: ");
		yVal = JOptionPane.showInputDialog("Enter the second double: ");
		zVal = JOptionPane.showInputDialog("Enter the third double: ");
		
		x = Double.parseDouble(xVal);
		y = Double.parseDouble(yVal);
		z = Double.parseDouble(zVal);
		
		JOptionPane.showMessageDialog(null,"The sum is " + sum(x,y,z) +
									"\nThe average is " + average(x,y,z) +
									"\nThe product is " + product(x,y,z) +
									"\nThe minimum is " + min(x,y,z)+
									"\nThe maximum is " + max(x,y,z));
		System.exit(0);
	}
	
	public static double sum(double x, double y, double z){
		return x + y + z;
	}
	
	public static double average(double x, double y, double z){
		return (x + y + z)/3;
	}
	
	public static double product(double x, double y, double z){
		return x*y*z;
	}
	
	public static double min(double x, double y, double z){
		double smallest = x;
		if(y<smallest)
			smallest = y;
		if(z<smallest)
			smallest = z;
		return smallest;
	}
	
	public static double max(double x, double y, double z){
		double biggest = x;
		if(y>biggest)
			biggest = y;
		if(z>biggest)
			biggest = z;
		return biggest;
	}
}