import javax.swing.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.text.Text;
import javafx.scene.Group;

public class Product2 extends Application
{
	int x, y, z, sum, pro;
	double avg;
	public void init()
	{
		String xVal, yVal, zVal;
		xVal = JOptionPane.showInputDialog("Enter the first integer: ");
		yVal = JOptionPane.showInputDialog("Enter the second integer: ");
		zVal = JOptionPane.showInputDialog("Enter the third integer: ");
		
		x = Integer.parseInt(xVal);
		y = Integer.parseInt(yVal);
		z = Integer.parseInt(zVal);
		
		sum = x + y + z;
		avg = sum/3.;
		pro = x*y*z;
	}
	
	public void start(Stage stage)
	{
		Text text = new Text("The sum is " + sum +
							"\n\nThe average is " + avg +
							"\n\nThe product is " + pro +
							"\n\nThe biggest int is " +big(x,y,z)+
							"\n\nThe smallest int is " +small(x,y,z));
		text.setX(50);
		text.setY(50);
		Group root = new Group(text);
		Scene scene = new Scene(root,400,300);
		
		stage.setTitle("I hate JavaFX");
		stage.setScene(scene);
		stage.show();
	}
	
	public static void main(String[] args){
		System.out.println("Enter main. Before launch");
		launch(args);
		System.out.println("After launch. End of the main");
	}
	
	public static int small(int x, int y, int z){
		int smallest = x;
		if(y<smallest)
			smallest = y;
		if(z<smallest)
			smallest = z;
		return smallest;
	}
	
	public static int big(int x, int y, int z){
		int biggest = x;
		if(y>biggest)
			biggest = y;
		if(z>biggest)
			biggest = z;
		return biggest;
	}
}