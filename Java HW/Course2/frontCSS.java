// FontCSS.java
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class FontCSS extends Application {
	@Override
	public void start(Stage stage) throws Exception {
		// loads FontCSS.fxml and confiugres the Drwa
		Parent root = FXMLLoader.load(getClass().getResource("FontCSS.fxml"));
	
		Scene scene = new Scene(root); // attach scene graph ot scene
		stage.setTitle("Show Fonts"); // displayed in window's title bar
		stage.setScene(scene); // attach scene to stage
		stage.show(); // display the stage
	}
	
	// application execution starts here
	public static void main(String[] args) {
		launch(args); // create a FontCSS object and call its start method
	}
}