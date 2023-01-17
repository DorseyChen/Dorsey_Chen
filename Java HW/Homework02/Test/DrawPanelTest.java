import java.awt.Graphics;
import javax.swing.JFrame;

public class DrawPanelTest {
	public static void main(String[] args){
		JFrame application = new JFrame();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		DrawPanel panel = new DrawPanel();
		application.add(panel);
		
		Scanner input = new Scanner(System.in);
		int length = input.nextInt();
		application.setSize(length, length);
		application.setVisible(true);
	}
}
