//import java.awt.*;
import java.awt.FlowLayout;
import java.awt.BorderLayout;
//import java.awt.event.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
//import javax.swing.* ;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JTextArea;

public class HW4_2 extends JFrame
{
	int type, y=0, z=5, c=0;
	String str = "";
	JLabel l1, l2, l3, l4;
	JTextField f1;
	boolean[] seat = new boolean[10];
	
	public HW4_2()
	{
		super("HW4_2");
		setLayout(new FlowLayout());
		
		l1 = new JLabel("1 for First Class and 2 for Economy: ");
		add(l1);
		f1 = new JTextField(5);
		add(f1);
		l2 = new JLabel("");
		add(l2);
		l3 = new JLabel("");
		add(l3);
		
		setVisible(true);
		setSize(400, 250);
		
		for(int i=0; i<10; i++)
		{
			seat[i] = false;
		}
		
		fieldHandler handle = new fieldHandler();
		f1.addActionListener(handle);
	}
	private class fieldHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			int i;
			type = Integer.parseInt(e.getActionCommand());
			if(type==1)
			{
				if(y==0)
				{
					str = String.format("Your seat is %d in First Class",y+1);
					l2.setText(str);
					y++;
				}
				else if(y==1)
				{
					str = String.format("Your seat is %d in First Class",y+1);
					l2.setText(str);
					y++;
				}
				else if(y==2)
				{
					str = String.format("Your seat is %d in First Class",y+1);
					l2.setText(str);
					y++;
				}
				else if(y==3)
				{
					str = String.format("Your seat is %d in First Class",y+1);
					l2.setText(str);
					y++;
				}
				else if(y==4)
				{
					str = String.format("Your seat is %d in First Class",y+1);
					l2.setText(str);
					y++;
				}
				else
				{
					l2.setText("Next flight leaves in 3 hours");
				}
			}
			else if(type==2)
			{
				if(z==5)
				{
					str = String.format("Your seat is %d in Economy",z+1);
					l2.setText(str);
					z++;
				}
				else if(z==6)
				{
					str = String.format("Your seat is %d in Economy",z+1);
					l2.setText(str);
					z++;
				}
				else if(z==7)
				{
					str = String.format("Your seat is %d in Economy",z+1);
					l2.setText(str);
					z++;
				}
				else if(z==8)
				{
					str = String.format("Your seat is %d in Economy",z+1);
					l2.setText(str);
					z++;
				}
				else if(z==9)
				{
					str = String.format("Your seat is %d in Economy",z+1);
					l2.setText(str);
					z++;
				}
				else
				{
					if(c==0)
					{
						l2.setText("there is no seat for economy do you want to update?(yes/1 no/2)");
						c=1;
					}
					else
						l2.setText("Next flight leaves in 3 hours");
				}
			}	
			else
			{
				l2.setText("wrong number please enter again");
			}
		}
	}
	public static void main(String[] args)
	{
		HW4_2 z = new HW4_2();
		z.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}