import java.awt.*;	
import java.awt.event.*;
import javax.swing.*;

public class Problem2 extends JFrame implements ActionListener {

	private enum Actions {
		yes,
		no
	}

	JTextField	textField;
	JLabel msg;
	JButton yes, no;
	JPanel opPanel;
	boolean[] seat;
	int check, num;
	
	public Problem2() {
		super("Problem2");
		opPanel = new JPanel();
		add(opPanel, BorderLayout.CENTER);
		opPanel.setLayout(new FlowLayout());
		
		textField = new JTextField(10);
		textField.setEditable(true);
		opPanel.add(textField);
		
		msg = new JLabel("type 1 or 2");
		opPanel.add(msg);
		
		//create button user clicks to yes
		yes = new JButton("yes");
		yes.setActionCommand(Actions.yes.name());
		yes.addActionListener(this);
		opPanel.add(yes);
		
		//create button user clicks to no
		no = new JButton("no");
		no.setActionCommand(Actions.no.name());
		no.addActionListener(this);
		opPanel.add(no);
		
		seat = new boolean[10];
	}
	
	@Override
	//process one roll of dice
	public void actionPerformed( ActionEvent actionEvent) {
		String enter = textField.getText();
		if(check!=0&&actionEvent.getActionCommand()==Actions.yes.name()) {
			if(check==1)
				check=2;
			else
				check=1;
			getseat();
			if(num==11&&check==2)
				msg.setText("no more seats.");
			else if(num==6&&check==1)
				msg.setText("no more seats.");
			else {
				msg.setText("your seat : " + Integer.toString(num));
				check = 0;
			}
		}
		else if(check!=0) {
			msg.setText("it flies away.");
			check = 0;
		}
		else if(actionEvent.getActionCommand()==Actions.yes.name()) {
			if(enter.equals("1"))
				check=1;
			else 
				check=2;
			getseat();
			if(num==11&&check==2)
				msg.setText("place in the first-class section?");
			else if(num==6&&check==1)
				msg.setText("place in the first-class section?");
			else {
				msg.setText("your seat : " + Integer.toString(num));
				check = 0;
			}
		}
	}
	
	public void getseat() {
		if(check==1) 
			for(int i=0;i<5;i++) {
				num=i+1;
				if(seat[i]==false) {
					seat[i]=true;
					break;
				}
				if(i==4)
					num=6;
			}	
		else
			for(int i=5;i<10;i++) {
				num=i+1;
				if(seat[i]==false) {
					seat[i]=true;
					break;
				}
				if(i==10)
					num=11;
			}
	}
	
	public static void main(String[] args) {
		Problem2 g1 = new Problem2();
		g1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		g1.setSize(320,300);
		g1.setVisible(true);
	}
}