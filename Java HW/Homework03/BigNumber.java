import java.math.*;
import javax.swing.*;
import java.util.Scanner;

public class BigNumber {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		
		//case I
		String num1str = input.nextLine();
		String num2str = input.nextLine();
		BigInteger num1 = new BigInteger(num1str);
		BigInteger num2 = new BigInteger(num2str);
		
		num1 = num1.add(num2);
		System.out.printf("Add: " + num1.toString() + "\n");
		
		//num2.multiply("2");
		num1 = num1.subtract(num2);
		num1 = num1.subtract(num2);
		System.out.printf("Sub: " + num1.toString() + "\n");

		//case II
		System.out.print("Enter n: ");
		int num3 = input.nextInt();
		BigInteger num4 = new BigInteger("1");
		BigInteger num5 = new BigInteger("1");
		
		for(int i=0;i<num3;i++) {
			num4 = num4.multiply(num5);
			num5 = num5.add(BigInteger.ONE);
		}
		System.out.printf(num4.toString());
		
		System.exit(0);
	}
}