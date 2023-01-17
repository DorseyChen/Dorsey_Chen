import java.awt.*;	
import java.awt.event.*;
import javax.swing.*;

public class Problem1 extends JFrame {
	int size;
	
	JLabel sizeLabel;
	JTextField	sizeField;
	JPanel opPanel;
	JButton outButton;
	
	public Problem1() {
		super("Problem1");
		opPanel = new JPanel();
		add(opPanel, BorderLayout.CENTER);
		opPanel.setLayout(new FlowLayout());
		
		//create label and text field for die1
		sizeLabel = new JLabel("Enter a size");
		opPanel.add(sizeLabel);
		sizeField = new JTextField(10);
		sizeField.setEditable(true);
		opPanel.add(sizeField);
		
		//create label for prompt
		outButton = new JButton(" ");
		opPanel.add(outButton);
		
		TextFieldHandler handler = new TextFieldHandler();
		sizeField.addActionListener(handler);
	}
	
	private class TextFieldHandler implements ActionListener {
	@Override
	//process one roll of dice
		public void actionPerformed(ActionEvent actionEvent) {
			String enterValue = sizeField.getText();
			int sizevalue = Integer.valueOf(enterValue) + 1;
			int[] row = new int[sizevalue];
			String text = "<html>";
			
			int c=1,i=0,j=0;
			for(int r:row)
			{
				int[] space = new int[sizevalue-i+1];
					for(int s:space)
						text += "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
				/*if(i<=5){
					int[] space2 = new int[5];
					for(int s:space2)
						text += "&nbsp;&nbsp;";
				}*/
				int[] col = new int [i+1];
				for(int co:col)
				{
					if (j==0||i==0)
						c=1;
					else
					c=c*(i-j+1)/j;
					if(c<10)
						text += "&nbsp;&nbsp;";
					if(c<100)
						text += "&nbsp;&nbsp;";
					text += "&nbsp;&nbsp;&nbsp;&nbsp;" + Integer.toString(c);
					j++;
				}
				j=0;
				i++;
				text += "<br>";
			}
			text += "<html>";
			outButton.setText(text);
		}
	}
	
	
	
	public static void main(String[] args) {
		Problem1 g1 = new Problem1();
		g1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		g1.setSize(320,300);
		g1.setVisible(true);
	}
}