import java.util.Scanner;

public class Problem2 {
	//paths: 0 right, 1 up, 2 left, 3 down
	private static short path = 1;
	private static int posX = 6, posY = 6;
	private static char[][] floor = new char[10][10];

	public static void main(String[] args) {
		newArray(floor);
		floor[5][5] = '#';
		Scanner scanner = new Scanner(System.in);
		String action;
		do {
			printArray();
			String line = scanner.nextLine();
			String[] split_line = line.split(" ");
			action = split_line[0];
			
			if(split_line[0].equals("left")) {
				if(path<3)
					path++;
				else
					path=0;
			}
			else if(split_line[0].equals("right")) {
				if(path==0)
					path=3;
				else
					path--;
			}
			else if(split_line[0].equals("move")) {
				int step = Integer.parseInt(split_line[1]);
				int[] times = new int[step];
				for(int t : times)
					move();
			}
		} while (!action.equals("quit"));
	}

	private static void newArray(char[][] floor) {
		int i = 0;
		for (char[] fi : floor) {
			int j = 0;
			for (char fj : fi) {
				floor[i][j] = '.';
				j++;
			}
			i++;
		}
	}

	private static void printArray() {
		int i = 0;
		for (char[] fi : floor) {
			int j=0;
			for (char fj : fi) {
				if(i==(posX-1)&&j==(posY-1)) {
					if(path==0)
						System.out.print(">");
					if(path==1)
						System.out.print("^");
					if(path==2)
						System.out.print("<");
					if(path==3)
						System.out.print("v");
				}
				else
					System.out.print(floor[i][j]);
				System.out.print("  ");
				j++;
			}
			System.out.println();
			i++;
		}
	}

	private static void move() {
		switch (path) {
		case 0:
			posY++;
			if(posY<=10)
				floor[posX-1][posY-1]='#';
			else
				posY--;
			break;
		case 1:
			posX--;
			if(posX>0)
				floor[posX-1][posY-1]='#';
			else
				posX++;
			break;
		case 2:
			posY--;
			if(posY>0)
				floor[posX-1][posY-1]='#';
			else
				posY++;
			break;
		case 3:
			posX++;
			if(posX<=10)
				floor[posX-1][posY-1]='#';
			else
				posX--;
			break;
		}
	}
}