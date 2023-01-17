// Fig. 2.15: Comparison.java
// Compare integers using if statements, relational operators
// and equality operators
import java.util.Scanner; // program use class Scanner

public class Comparison {
	// main method begins execution of Java application
	public static void main(String[] args) {
		// create Scanner to obtain input from command line
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter first integer: ") //prompt
		int number1 = input.nextInt();
		
		System.out.print("Enter first integer: ") //prompt
		int number2 = input.nextInt();
		
		if (number1 == number2)
			System.out.printf("%d == %d%n", number1, number2);
		
		if (number1 != number2)
			System.out.printf("%d != %d%n", number1, number2);
		
		if (number1 < number2)
			System.out.printf("%d < %d%n", number1, number2);
		
		if (number1 > number2)
			System.out.printf("%d > %d%n", number1, number2);
		
		if (number1 <= number2)
			System.out.printf("%d <= %d%n", number1, number2);
		
		if (number1 >= number2)
			System.out.printf("%d >= %d%n", number1, number2);
		}
}