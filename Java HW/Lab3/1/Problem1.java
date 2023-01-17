import java.awt.*;	
import java.awt.event.*;
import javax.swing.*;
import java.math.*;
import java.util.Scanner;


public class Problem1 extends JFrame implements ActionListener {

	private enum Actions {
		ADD,
		SUB
	}

	JTextField	num1Field, num2Field, num3Field;
	JButton ADD, SUB;
	JPanel opPanel, sPanel;
	
	public Problem1() {
		super("Problem1");
		opPanel = new JPanel();
		sPanel = new JPanel();
		add(opPanel, BorderLayout.CENTER);
		add(sPanel, BorderLayout.SOUTH);
		opPanel.setLayout(new FlowLayout());
		
		num1Field = new JTextField(10);
		num1Field.setEditable(true);
		opPanel.add(num1Field);
		
		num2Field = new JTextField(10);
		num2Field.setEditable(true);
		opPanel.add(num2Field);
		
		//create button user clicks to ADD
		ADD = new JButton("add");
		ADD.setActionCommand(Actions.ADD.name());
		ADD.addActionListener(this);
		opPanel.add(ADD);
		
		//create button user clicks to SUB
		SUB = new JButton("sub");
		SUB.setActionCommand(Actions.SUB.name());
		SUB.addActionListener(this);
		opPanel.add(SUB);
		
		num3Field = new JTextField(10);
		num3Field.setEditable(false);
		opPanel.add(num3Field);
	}
	
	@Override
	//process one roll of dice
	public void actionPerformed( ActionEvent actionEvent) {
		
		String num1str = num1Field.getText();
		String num2str = num2Field.getText();
		BigInteger num1 = new BigInteger(num1str);
		BigInteger num2 = new BigInteger(num2str);
		
		if(actionEvent.getActionCommand()==Actions.ADD.name()) {
			num1 = num1.add(num2);
			num3Field.setText(num1.toString());
		}
		else {
			num1 = num1.subtract(num2);
			num3Field.setText(num1.toString());
		}
	}
	
	public static void main(String[] args) {
		Problem1 g1 = new Problem1();
		g1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		g1.setSize(320,300);
		g1.setVisible(true);
	}
}