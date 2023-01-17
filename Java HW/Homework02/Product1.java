import javax.swing.JOptionPane;
import java.util.Scanner;

public class Product1
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter the radius: ");
		int radius = input.nextInt();
		int diameter = 2*radius;
		double circumference = Math.PI*2*radius;
		double area = Math.PI*radius*radius;
		System.out.printf("The diameter of the circle is : %d%n", diameter);
		System.out.printf("The circumference of the circle is : %f%n", circumference);
		System.out.printf("The area of the circle is : %f%n", area);
		
		System.exit(0);
	}
}