import java.awt.*;
import javax.swing.*;
import java.util.Scanner;

public class DrawPanelTest {
	public static void main(String[] args){
		JFrame application = new JFrame();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Scanner input = new Scanner(System.in);
		int rad = input.nextInt();
		int num = input.nextInt();
		
		DrawPanel panel = new DrawPanel(num,rad);
		application.add(panel);
		
		application.setSize(500, 500);
		application.setVisible(true);
	}
}
