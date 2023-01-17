import javax.swing.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.text.Text;
import javafx.scene.Group;

public class Product2 extends Application
{
	int p, n, d, q, price, change, a;
	String input;
	public void init()
	{
		input = JOptionPane.showInputDialog("Enter price of item: ");
		price = Integer.parseInt(input);
		change = 100 - price;
		while(change>=25){
			q++;
			change-=25;
		}
		while(change>=10){
			d++;
			change-=10;
		}
		while(change>=5){
			n++;
			change-=5;
		}
		while(change>0){
			p++;
			change--;
		}
	}
	
	public void start(Stage stage)
	{
		String s="You bought an item for "+input+" cents and gave me one dollar."+
							"\nSo your change is\n";
		if(q!=0){
			s+=Integer.toString(q);
			if(q==1)
				s+=" quarter";
			else
				s+=" quarters";
		}
		if(d==0&&n==0&&p==0)
			s+=".";
		else if((n==0&&p==0)||(d==0&&n==0)||(d==0&&p==0)&&(a!=1)&&(q!=0)){
			a=1;
			s+=", and\n";
		}
		if(d!=0){
			s+=Integer.toString(d);
			if(d==1)
				s+=" dime";
			else
				s+=" dimes";
		}
		if(n==0&&p==0)
			s+=".";
		else if((p==0||n==0)&&(p+n!=0)&&(a!=1)){
			a=1;
			s+=", and\n";
		}
		else if(a!=1)
			s+=",\n";
		if(n!=0){
			s+=Integer.toString(n);
			if(n==1)
				s+=" niclel";
			else
				s+=" niclels";
		}
		if(a!=1)
			s+=",and\n";
		if(p!=0){
			s+=Integer.toString(p);
			if(p==1)
				s+=" penny.";
			else
				s+=" pennies.";
		}		
		
		Text text = new Text(s);
		text.setX(50);
		text.setY(50);
		Group root = new Group(text);
		Scene scene = new Scene(root,400,300);
		
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