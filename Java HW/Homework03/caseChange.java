import java.awt.*;	
import java.awt.event.*;
import javax.swing.*;

public class caseChange extends JFrame implements ActionListener {

	private enum Actions {
		Uppercase,
		Lowercase
	}

	JTextField	textField;
	JButton uppercase, lowercase;
	JPanel opPanel, sPanel;
	
	public caseChange() {
		super("caseChange");
		opPanel = new JPanel();
		sPanel = new JPanel();
		add(opPanel, BorderLayout.CENTER);
		add(sPanel, BorderLayout.SOUTH);
		opPanel.setLayout(new FlowLayout());
		
		textField = new JTextField(10);
		textField.setEditable(true);
		opPanel.add(textField);
		
		//create button user clicks to uppercase
		uppercase = new JButton("Uppercase");
		uppercase.setActionCommand(Actions.Uppercase.name());
		uppercase.addActionListener(this);
		opPanel.add(uppercase);
		
		//create button user clicks to lowercase
		lowercase = new JButton("Lowercase");
		lowercase.setActionCommand(Actions.Lowercase.name());
		lowercase.addActionListener(this);
		opPanel.add(lowercase);
	}
	
	@Override
	//process one roll of dice
	public void actionPerformed( ActionEvent actionEvent) {
		String enterValue = textField.getText();
		if(actionEvent.getActionCommand()==Actions.Uppercase.name()) 
			textField.setText(enterValue.toUpperCase());
		else
			textField.setText(enterValue.toLowerCase());
	}
	
	public static void main(String[] args) {
		caseChange g1 = new caseChange();
		g1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		g1.setSize(320,300);
		g1.setVisible(true);
	}
}