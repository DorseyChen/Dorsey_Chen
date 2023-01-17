import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.*;

public class PainterController {
	//3
	@FXML
	ToggleGroup color,action;
	@FXML RadioButton redRadioButton,blueRadioButton,greenRadioButton,blackRadioButton;
	//modify to your fxml
	@FXML RadioButton movebutton,rectanglebutton;
	@FXML Pane drawarea;
	Color drawcolor=Color.BLACK;
	Rectangle nowdrawrec;
	Rectangle nowmouseonrec;
	double drawx1,drawy1;
	//4
	enum NowAction {Move,Rect};
	double mousestartx,mousestarty;
	double reclayoutx,reclayouty;
	boolean ismove=false; //Moving the rectangle
	NowAction nowaction=NowAction.Rect;
	
	public void initialize() {
		//initial some data
		blackRadioButton . setUserData ( Color.BLACK );
		redRadioButton . setUserData ( Color.RED );
		greenRadioButton . setUserData ( Color.GREEN );
		blueRadioButton . setUserData ( Color.BLUE );
		movebutton . setUserData( NowAction.Move );
		rectanglebutton . setUserData( NowAction.Rect );
	}
	@FXML
	public void colorClick(ActionEvent e) {
		//change rectangle color
		drawcolor = (Color)color.getSelectedToggle().getUserData();
	}
	@FXML
	public void actionClick(ActionEvent e) {
		//you can use userdata here
		if(e.getSource()==movebutton)
			nowaction=NowAction.Move;
		else if(e.getSource()==rectanglebutton)
			nowaction=NowAction.Rect;
	}
	@FXML
	public void mousePressed(MouseEvent e) {
		if(nowaction==NowAction.Rect) {
			nowdrawrec=new Rectangle();
			drawarea.getChildren().add(nowdrawrec);
			//......... problem3
			nowdrawrec.setFill(drawcolor);
			mousestartx= e.getX();
			mousestarty= e.getY();
		}
		else if(nowaction==NowAction.Move) {
			if(nowmouseonrec!=null) {
				//............ problem4
				ismove=true;
			}
		}
	}
	@FXML
	public void mouseDragged(MouseEvent e) {
		if(nowaction==NowAction.Rect) {
			//...... problem3
			drawx1= e.getX();
			drawy1= e.getY();
			if(drawx1<mousestartx){
				nowdrawrec.setLayoutX(drawx1);
				nowdrawrec.setWidth(mousestartx-drawx1);
			}
			else{
				nowdrawrec.setLayoutX(mousestartx);
				nowdrawrec.setWidth(drawx1-mousestartx);
			}
			if(drawy1<mousestarty){
				nowdrawrec.setLayoutY(drawy1);
				nowdrawrec.setHeight(mousestarty-drawy1);
			}
			else{
				nowdrawrec.setLayoutY(mousestarty);
				nowdrawrec.setHeight(drawy1-mousestarty);
			}
		}
		else if(nowaction==NowAction.Move) {
			if(nowmouseonrec!=null) {
				//......... problem4
			}
		}
	}
	@FXML
	public void mouseReleased(MouseEvent e) {
		if(nowaction==NowAction.Rect) {
			//lambda in java
			nowdrawrec.setOnMouseEntered((event)->{
				//use(Rectangle)event.getSource() to get Rectangle
				//when mouse enter rectangle
				// .... problem4
			});
			nowdrawrec.setOnMouseExited(
			new EventHandler<MouseEvent>() {
				//when mouse leave rectangle
				@Override
				public void handle(MouseEvent event) {
				//....problem4
				}
			});
		}
		else if(nowaction==NowAction.Move) {
			ismove=false;
		}
	}
}