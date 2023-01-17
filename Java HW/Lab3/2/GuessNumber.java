import java.awt.*;	
import java.awt.event.*;
import javax.swing.*;

public class GuessNumber extends JFrame {	
	final int WON=0, HIGH=1, LOW=2, CONTINUE=3;
	boolean firstRoll=true;
	int realPoint=0;
	int myPoint=0;
	int gameStatus=WON;
	
	JLabel guessLabel, sumLabel, pointLabel, statusLabel;
	JTextField	guessField, die2Field, sumField, pointField;
	JButton rollButton;
	JPanel opPanel, sPanel;
	
	public GuessNumber() {
		super("GuessNumber");
		opPanel = new JPanel();
		sPanel = new JPanel();
		add(opPanel, BorderLayout.CENTER);
		add(sPanel, BorderLayout.SOUTH);
		opPanel.setLayout(new FlowLayout());
		
		//create label and text field for die1
		guessLabel = new JLabel("Your guess");
		opPanel.add(guessLabel);
		guessField = new JTextField(10);
		guessField.setEditable(true);
		opPanel.add(guessField);
		
		//create label for prompt
		statusLabel = new JLabel("Game Start");
		sPanel.add(statusLabel);
		
		TextFieldHandler handler = new TextFieldHandler();
		guessField.addActionListener(handler);
	}
	
	private class TextFieldHandler implements ActionListener {
	@Override
	//process one roll of dice
		public void actionPerformed(ActionEvent actionEvent) {
			if(gameStatus==WON) {
				realPoint = (int)(Math.random()*2000) + 1;
				System.out.printf("%d\n", realPoint);
			}
			String enterValue = guessField.getText();
			int guessValue = Integer.valueOf(enterValue);
			if(guessValue==realPoint)
				gameStatus=WON;
			else if (guessValue>realPoint)
				gameStatus=HIGH;
			else if (guessValue<realPoint)
				gameStatus=LOW;
			guessField.setText("");
			displayMessage();
		}
	}
	
	//display appropriate message in status bar
	public void displayMessage() {
		//game should LOW
		if(gameStatus == WON)
			statusLabel.setText("Congratulations. You guessed the number!!");
		else {
			if(gameStatus == HIGH)
				statusLabel.setText("Too high. Try again.");
			else
				statusLabel.setText("Too low. Try again");
		}
	}
	
	public static void main(String[] args) {
		GuessNumber g1 = new GuessNumber();
		g1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		g1.setSize(320,300);
		g1.setVisible(true);
	}
}