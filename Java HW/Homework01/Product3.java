import javax.swing.JOptionPane;

public class Product3
{
	public static void main(String args[])
	{
		int p=0, n=0, d=0, q=0, price, change;
		String price_string;
		
		price_string = JOptionPane.showInputDialog("Enter price of item: ");
		price = Integer.parseInt(price_string);
		
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
		JOptionPane.showMessageDialog(null,"The change is " +q+" quarters, "+d+" dimes, "+n+" nickels, "+p+" pennies.");
		System.exit(0);
	}
}