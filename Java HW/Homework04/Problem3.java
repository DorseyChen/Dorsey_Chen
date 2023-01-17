import java.util.Scanner;

public class Problem3 {
	/**
	 * Directions: 0 right, 1 down, 2 left, 3 up
	 */
	private static short direction = 0;
	private static boolean penDown;
	private static int turtleX = 0, turtleY = 0;
	private static int[][] floor = new int[20][20];

	public static void main(String[] args) {
		initFloor(floor);
		Scanner in = new Scanner(System.in);
		printMenu();
		int nextCommand = in.nextInt();
		while (nextCommand != 9) {
			switch (nextCommand) {
			case 1:
				penDown = false;
				break;
			case 2:
				penDown = true;
				break;
			case 3:
				direction++;
				break;
			case 4:
				direction--;
				break;
			case 5:
				System.out.println("How many steps do you want to move?");
				int move = in.nextInt();
				if (move <= 10)
					while (--move != 0)
						move();
				break;
			case 6:
				printArray();
				break;
			default:
				System.err.println("Unknow command, please try again:\n");
				break;
			}
			move();
			System.out.println("What's next?");
			nextCommand = in.nextInt();
		}
	}

	private static void initFloor(int[][] floor) {
		for (int i = 0; i < floor.length; i++) {
			for (int j = 0; j < floor[i].length; j++) {
				floor[i][j] = 0;
			}
		}
	}

	private static void printMenu() {
		System.out
				.println("Commands List:\n\n\t1 Pen up\n"
						+ "\t2 Pen down\n"
						+ "\t3 Turn right\n"
						+ "\t4 Turn left\n"
						+ "\t5 to 10 Move forward 10 spaces (replace 10 for a different number of spaces)\n"
						+ "\t6 Display the 20-by-20 array\n"
						+ "\t9 End of data (sentinel)Please enter a command number:\n");
	}

	private static void printArray() {
		for (int i = 0; i < floor.length; i++) {
			for (int j = 0; j < floor[i].length; j++) {
				System.out.print(floor[i][j]);
				System.out.print("  ");
			}
			System.out.println();
		}
	}

	private static void move() {
		switch (direction) {
		case 0:
			turtleX++;
			break;
		case 1:
			turtleY++;
			break;
		case 2:
			turtleX--;
			break;
		case 3:
			turtleY--;
			break;
		default:
			if (direction < 0)
				direction = 3;
			else
				direction = 4;
			move();
			break;
		}
		if (penDown) {
			if (turtleX < 20 && turtleY < 20)
				floor[turtleX][turtleY] = 1;
			else {
				direction -= 2;
				move();
			}
		}
	}
}