// Main application class that loads and displays the Project's GUI.
import javafx.application.Application ;
import javafx.fxml.FXMLLoader ;
import javafx.scene.Parent ;
import javafx.scene.Scene ;
import javafx.stage.Stage ;

public class Project extends Application {
	@Override
	public void start ( Stage stage ) throws Exception {
		Parent root = FXMLLoader . load ( getClass (). getResource ( "Project.fxml" ));
		Scene scene = new Scene ( root );
		stage . setTitle ( "Project" ); // displayed in window's title bar
		stage . setScene ( scene );
		stage . show ();
	}
	public static void main ( String [] args ) {
		launch ( args );
	}
}