import javax.swing.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.text.Text;
import javafx.scene.Group;

public class Product4 extends Application
{
	String input;
	public void init()
	{
		input = JOptionPane.showInputDialog("Enter a file name with extension: ");
	}
	
	public void start(Stage stage)
	{
		Text text = new Text("The file extension is "+find_extension(input));
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
	
	public static String find_extension(String s){
		String[] output = s.split("\\.");
		return output[1];
	}
	
}