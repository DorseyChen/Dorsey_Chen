import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;

public class DrawLinesController {
	@FXML private Canvas canvas;
	@FXML
	void drawLinesButtonPressed(ActionEvent event) {
		GraphicsContext gc = canvas.getGraphicsContext2D();
		//gc.strokeLine(0, 0, canvas.getWidth(), canvas.getHeight());
		//gc.strokeLine(canvas.getWidth(), 0, 0, canvas.getHeight());
		
		int width = canvas.getWidth();
		int height = canvas.getHeight();
		int shtwid = width/20;
		int shthgt = height/20;
		
		//Case1
		for(int i=1; i<=20; i++) {
			int newwid = i*width/20;
			int newhgt = (20-i)*height/20;
			gc.strokeLine(0, 0, newwid, newhgt);
			gc.strokeLine(width, 0, width-newwid, newhgt);
			gc.strokeLine(0, height, newwid, height-newhgt);
			gc.strokeLine(width, height, width-newwid, height-newhgt);
		}	
		
		//Case2
		/*for(int i=0; i<20; i++) {
			gc.strokeLine(0, i*shthgt, (i+1)*shtwid, height);
			gc.strokeLine(0, height-i*shthgt, (i+1)*shtwid, 0);
			gc.strokeLine(i*shtwid, 0, width, (i+1)*shthgt);
			gc.strokeLine(i*shtwid, height, width, height-(i+1)*shthgt);
		}*/
	}
}