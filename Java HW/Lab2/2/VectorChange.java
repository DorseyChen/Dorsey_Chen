import javax.swing.*;
import java.util.Scanner;

public class VectorChange
{	
	public static int num;
	public static void main(String args[])
	{
		int opt;
		double x, y, theta, a;
		
		Scanner input = new Scanner(System.in);
		while(input.hasNextLine()){
			opt = input.nextInt();
			int num1 = input.nextInt();
			int num2 = input.nextInt();
			if(opt == 1) {
				x = num1;
				y = num2;
				a = Math.sqrt(x*x+y*y);
				theta = 180 * Math.atan2(y,x)/Math.PI;
				System.out.printf(a + " " + theta + "\n");
			}
			else {
				a = num1;
				theta = num2*Math.PI/180;
				x = a * Math.cos(theta);
				y = a * Math.sin(theta);
				System.out.printf(x + " " + y + "\n");
			}
		}
		System.exit(0);
	}
}