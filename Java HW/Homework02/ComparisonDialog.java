import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class ComparisonDialog 
{
	public static void main(String args[])
	{
		int number1, number2;
		String num1, num2, text="";
		num1 = JOptionPane.showInputDialog("Enter first integer: ");
		num2 = JOptionPane.showInputDialog("Enter first integer: ");
		
		number1 = Integer.parseInt(num1);
		number2 = Integer.parseInt(num2);
		
		JTextArea textArea = new JTextArea(text);
		textArea.setColumns(30);
		textArea.setLineWrap(true);
		textArea.setWrapStyleWord(true);
		
		if (number1 == number2){
			text = num1 + "==" + num2 + "\n";
			textArea.append(text);
		}
		
		if (number1 != number2){
			text = num1 + "!=" + num2 + "\n";
			textArea.append(text);
		}
		
		if (number1 > number2){
			text = num1 + ">" + num2 + "\n";
			textArea.append(text);
		}
		
		if (number1 < number2){
			text = num1 + "<" + num2 + "\n";
			textArea.append(text);
		}
		
		if (number1 >= number2){
			text = num1 + ">=" + num2 + "\n";
			textArea.append(text);
		}
		
		if (number1 <= number2){
			text = num1 + "<=" + num2 + "\n";
			textArea.append(text);
		}
		
		textArea.setSize(textArea.getPreferredSize().width, 1);
		JOptionPane.showMessageDialog(null, new JScrollPane( textArea), "Not Truncated!",
        JOptionPane.WARNING_MESSAGE);
		System.exit(0);
	}
}