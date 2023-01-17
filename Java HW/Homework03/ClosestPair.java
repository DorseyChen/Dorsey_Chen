import java.math.*;
import javax.swing.*;
import java.util.Scanner;

public class ClosestPair
{	
	public static int num;
	public static void main(String args[])
	{
		//set the program
		int n; 		
		Scanner input = new Scanner(System.in);
		n = input.nextInt();
		int [][]num = new int [n][2];
		int [][]distance = new int [n][n];
		
		//enter pairs
		for(int i=0;i<n;i++) {
			int num1 = input.nextInt();
			num[i][0] = num1;
			int num2 = input.nextInt();
			num[i][1] = num2;
		}
		
		//find the distance of each pairs
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(i!=j) {
					int x = num[i][0] - num[j][0];
					int y = num[i][1] - num[j][1];
					distance[i][j] = x*x + y*y;
				}
				else
					distance[i][j] = -1;
				System.out.printf("%d\n", distance[i][j]);
			}
		}
		
		//find minimum place
		/*int minimum = distance[0][0];
		for(int i=0;i<n;i++) {
			for
		}*/
		
		//output
		
		System.exit(0);
	}
}