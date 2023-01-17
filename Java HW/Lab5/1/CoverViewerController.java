// Controller for Cover Viewer application
import javafx.beans.value.ChangeListener ;
import javafx.beans.value.ObservableValue ;
import javafx.collections.FXCollections ;
import javafx.collections.ObservableList ;
import javafx.fxml.FXML ;
import javafx.scene.control.ListView ;
import javafx.scene.image.Image ;
import javafx.scene.image.ImageView ;
public class CoverViewerController {
	// instance variables for interacting with GUI
	@FXML private ListView < Book > booksListView ;
	
	@FXML private ImageView coverImageView1 ;
	@FXML private ImageView coverImageView2 ;
	@FXML private ImageView coverImageView3 ;
	@FXML private ImageView coverImageView4 ;
	@FXML private ImageView coverImageView5 ;
	@FXML private ImageView coverImageView6 ;
	@FXML private ImageView coverImageView7 ;
	@FXML private ImageView coverImageView8 ;
	@FXML private ImageView coverImageView9 ;
	int[] imageset = new int[9];
	
	// stores the list of Book Objects
	private final ObservableList < Book > books =
	FXCollections . observableArrayList ();
	// initialize controller
	public void initialize () {
		// populate the ObservableList<Book>
		books . add ( new Book ( "Android How to Program" ,
		"/images/small/androidhtp.jpg" , "/images/large/androidhtp.jpg" ));
		books . add ( new Book ( "C How to Program" ,
		"/images/small/chtp.jpg" , "/images/large/chtp.jpg" ));
		books . add ( new Book ( "C++ How to Program" ,
		"/images/small/cpphtp.jpg" , "/images/large/cpphtp.jpg" ));
		books . add ( new Book ( "Internet and World Wide Web How to Program" ,
		"/images/small/iw3htp.jpg" , "/images/large/iw3htp.jpg" ));
		books . add ( new Book ( "Java How to Program" ,
		"/images/small/jhtp.jpg" , "/images/large/jhtp.jpg" ));
		books . add ( new Book ( "Visual Basic How to Program" ,
		"/images/small/vbhtp.jpg" , "/images/large/vbhtp.jpg" ));
		books . add ( new Book ( "Visual C# How to Program" ,
		"/images/small/vcshtp.jpg" , "/images/large/vcshtp.jpg" ));
		booksListView . setItems ( books ); // bind booksListView to books
		// when ListView selection changes, show large cover in ImageView
		booksListView . getSelectionModel (). selectedItemProperty ().
		addListener (
			new ChangeListener < Book >() {
				@Override
				public void changed ( ObservableValue <? extends Book > ov ,
				Book oldValue , Book newValue ) {
					int i;
					for(i=0;i<9;i++){
						if(imageset[i]==0){
							imageset[i]=1;
							break;
						}
					}
					switch(i){
						case 0:
							coverImageView1 . setImage (new Image ( newValue . getLargeImage ()));
							break;
						case 1:
							coverImageView2 . setImage (new Image ( newValue . getLargeImage ()));
							break;
						case 2:
							coverImageView3 . setImage (new Image ( newValue . getLargeImage ()));
							break;
						case 3:
							coverImageView4 . setImage (new Image ( newValue . getLargeImage ()));
							break;
						case 4:
							coverImageView5 . setImage (new Image ( newValue . getLargeImage ()));
							break;
						case 5:
							coverImageView6 . setImage (new Image ( newValue . getLargeImage ()));
							break;
						case 6:
							coverImageView7 . setImage (new Image ( newValue . getLargeImage ()));
							break;
						case 7:
							coverImageView8 . setImage (new Image ( newValue . getLargeImage ()));
							break;
						case 8:
							coverImageView9 . setImage (new Image ( newValue . getLargeImage ()));
							break;
						case 9:
							for(i=0;i<9;i++)
								imageset[i]=0;
							coverImageView1 . setImage(null);
							coverImageView2 . setImage(null);
							coverImageView3 . setImage(null);
							coverImageView4 . setImage(null);
							coverImageView5 . setImage(null);
							coverImageView6 . setImage(null);
							coverImageView7 . setImage(null);
							coverImageView8 . setImage(null);
							coverImageView9 . setImage(null);
							coverImageView1 . setImage (new Image ( newValue . getLargeImage ()));
							break;
					}
				}
			}
		);
	}
}