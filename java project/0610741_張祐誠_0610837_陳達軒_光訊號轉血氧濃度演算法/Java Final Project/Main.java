// Main application class that loads and displays the Project's GUI.
import javafx.application.Application ;
import javafx.fxml.FXMLLoader ;
import javafx.scene.Parent ;
import javafx.scene.Scene ;
import javafx.stage.Stage ;

public class Main extends Application {
	private static Stage stage;
	private static Scene scene;
    @Override
    public void start ( Stage primaryStage ) throws Exception {
		stage = primaryStage;
        Parent root = FXMLLoader.load ( getClass (). getResource ("sample.fxml"));
        Scene primaryscene = new Scene ( root );
		scene = primaryscene;
        stage . setTitle ( "Project" ); // displayed in window's title bar
        stage . setScene ( primaryscene );
        stage . show ();
    }
    public static void main ( String [] args ) {
        launch ( args );
    }
	public static Stage getStage() { return stage; }
	public static Scene getScene() { return scene; }
}