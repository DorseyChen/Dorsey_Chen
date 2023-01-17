import javax.swing.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.text.Text;
import javafx.scene.Group;
import javafx.scene.text.Font;
import javafx.scene.paint.Color;

public class Product4 extends Application
{
	String input, size, color, height, width, cor_x, cor_y, str;
	int s, h, w, x, y;
	public void init()
	{
		str = JOptionPane.showInputDialog("Enter\n1.text\n2.font size\n3.color(RED/BLUE/GREEN/BLACK)\n4.window height\n5.window width\n6.text x-coordinate\n7.text y-coordinate");
		String[] output = str.split(" ");
		input=output[0];
		size=output[1];
		color=output[2];
		height=output[3];
		width=output[4];
		cor_x=output[5];
		cor_y=output[6];
		
		s = Integer.parseInt(size);
		h = Integer.parseInt(height);
		w = Integer.parseInt(width);
		x = Integer.parseInt(cor_x);
		y = Integer.parseInt(cor_y);
		
	}
	
	public void start(Stage stage)
	{
		String r="RED", b="BLUE", g="GREEN";
		
		Text text = new Text(input);
		text.setFont(Font.font(s));
		text.setX(x);
		text.setY(y);
		
		Text copy = new Text(input);
		copy.setFont(Font.font(s));
		//if((w/2-x)>0)
		copy.setX(w-x);
		//else
		//copy.setX(w/2-(x-w/2));
		copy.setY(h-y);
		
		if(color.equals(r)){
			text.setFill(Color.RED);
			copy.setFill(Color.RED);
		}
		else if(color.equals(b)){
			text.setFill(Color.BLUE);
			copy.setFill(Color.BLUE);
		}
		else if(color.equals(g)){
			text.setFill(Color.GREEN);
			copy.setFill(Color.GREEN);
		}
		else{
			text.setFill(Color.BLACK);
			copy.setFill(Color.BLACK);
		}
		
		Group root = new Group(text,copy);
		Scene scene = new Scene(root,w,h);
		
		stage.setTitle("Lab");
		stage.setScene(scene);
		stage.show();
	}
	
	public static void main(String[] args){
		System.out.println("Enter main. Before launch");
		launch(args);
		System.out.println("After launch. End of the main");
	}
	
}