//import java.awt.*;
import java.awt.FlowLayout;
//import java.awt.event.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
//import javax.swing.* ;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JTextArea;
//import javax.swing.event.*;
//import java.util.Scanner;

public class HW4_1 extends JFrame implements ActionListener
{
	JLabel l1, l2;
	JTextField f1;
	JTextArea a1;
	JButton OK;
	String output, str;
	int size, i, j, k;
	int PascalTriangle[][];
	//int a[][];
	
	public HW4_1()
	{
		super("HW4_1");
		setLayout(new FlowLayout());
		l1 = new JLabel("Please Input the number to the size of a Pascal triangle: ");
		add(l1);
		f1 = new JTextField(20);
		add(f1);
		OK = new JButton("OK");
		OK.addActionListener(this);
		add(OK);
		l2 = new JLabel("========= Look on CMD window for more accurate picture =========");
		add(l2);
		a1 = new JTextArea(50,50);
		a1.setEditable(false);
		add(a1);
		setVisible(true);
		setSize(700, 500);
	}
	public static void main(String[] args)
	{
		HW4_1 z = new HW4_1();
		z.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public void actionPerformed(ActionEvent e)
	{
		output="";
		str="";
		size = Integer.parseInt(f1.getText());
		
		//new PascalTriangle array
		PascalTriangle = new int[size][];
		for(i=0; i<size; i++)
		{
			PascalTriangle[i] = new int[i+1];//important
			// 1_set the value of PascalTriangle
			for(j=0; j<=i; j++)
			{
				if(j==0 || j==i)
				{
					PascalTriangle[i][j] = 1;
				}
				else
				{
					PascalTriangle[i][j] = PascalTriangle[i-1][j-1] + PascalTriangle[i-1][j];
				}
			}
			// 2_print on cmd
			for(k=i; k<size-1; k++)
			{
				System.out.printf("    ");
			}
			for(j=0; j<=i; j++)
			{
				System.out.printf("%4d    ",PascalTriangle[i][j]);
			}
			System.out.println();
			// 3_print the value
			for(k=i; k<size-1; k++)
			{
				str = String.format("    ");
				output += str;
			}
			for(j=0; j<=i; j++)
			{
				str = String.format("%4d    ",PascalTriangle[i][j]);
				output += str;
			}
			output += "\n";
			
		}
//		System.out.printf("%s",output);
		a1.setText(output);
		
	}
	
}