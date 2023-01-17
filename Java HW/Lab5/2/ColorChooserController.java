// Controller for the ColorChooser app
import javafx.beans.value.ChangeListener ;
import javafx.beans.value.ObservableValue ;
import javafx.fxml.FXML ;
import javafx.scene.control.Slider ;
import javafx.scene.control.TextField ;
import javafx.scene.paint.Color ;
import javafx.scene.shape.Box;
import javafx.scene.transform.Rotate; 
import javafx.scene.paint.PhongMaterial;

public class ColorChooserController {
	// instance variables for interacting with GUI components
	@FXML private Slider redSlider ;
	@FXML private Slider greenSlider ;
	@FXML private Slider blueSlider ;
	@FXML private Slider rotateSlider ;
	@FXML private TextField redTextField ;
	@FXML private TextField greenTextField ;
	@FXML private TextField blueTextField ;
	@FXML private TextField rotateTextField ;
	@FXML private Box box ;
	// instance variables for managing
	private int red = 0;
	private int green = 0;
	private int blue = 0;
	private double rotate = 1.0;
	public void initialize () {
		// bind TextField values to corresponding Slider values
		redTextField . textProperty (). bind (
		redSlider . valueProperty (). asString ( "%.0f" ));
		greenTextField . textProperty (). bind (
		greenSlider . valueProperty (). asString ( "%.0f" ));
		blueTextField . textProperty (). bind (
		blueSlider . valueProperty (). asString ( "%.0f" ));
		rotateTextField . textProperty (). bind (
		rotateSlider . valueProperty (). asString ( "%.2f" ));
		// listeners that set Rectangle's fill based on Slider changes
		redSlider . valueProperty (). addListener (
		new ChangeListener < Number >() {
				@Override
				public void changed ( ObservableValue <? extends Number > ov ,
				Number oldValue , Number newValue ) {
						red = newValue . intValue ();
						PhongMaterial material = new PhongMaterial();
						material.setDiffuseColor(Color . rgb ( red , green , blue));
						box . setMaterial ( material);
				}
			}
		);
		greenSlider . valueProperty (). addListener (
			new ChangeListener < Number >() {
			@Override
			public void changed ( ObservableValue <? extends Number > ov ,
			Number oldValue , Number newValue ) {
			green = newValue . intValue ();
			PhongMaterial material = new PhongMaterial();
						material.setDiffuseColor(Color . rgb ( red , green , blue));
						box . setMaterial ( material);
			}
			}
		);
		blueSlider . valueProperty (). addListener (
			new ChangeListener < Number >() {
			@Override
			public void changed ( ObservableValue <? extends Number > ov ,
			Number oldValue , Number newValue ) {
			blue = newValue . intValue ();
			PhongMaterial material = new PhongMaterial();
						material.setDiffuseColor(Color . rgb ( red , green , blue));
						box . setMaterial ( material);
			}
			}
		);
		rotateSlider . valueProperty (). addListener (
			new ChangeListener < Number >() {
			@Override
			public void changed ( ObservableValue <? extends Number > ov ,
			Number oldValue , Number newValue ) {
			rotate = newValue . doubleValue ();
			//box . setMaterial ( Color . rgb ( red , green , blue , 1 ));
			/*box . setRotationAxis(Rotate.X_AXIS);
			box . setRotate(rotate);
			box . setRotationAxis(Rotate.Y_AXIS);
			box . setRotate(rotate);
			box . setRotationAxis(Rotate.Z_AXIS);
			box . setRotate(rotate);*/
			Rotate rxBox = new Rotate(0, 0, 0, 0, Rotate.X_AXIS);
			Rotate ryBox = new Rotate(0, 0, 0, 0, Rotate.Y_AXIS);
			Rotate rzBox = new Rotate(0, 0, 0, 0, Rotate.Z_AXIS);
			rxBox.setAngle(30);
			ryBox.setAngle(50);
			rzBox.setAngle(30);
			box.getTransforms().addAll(rxBox, ryBox, rzBox);
			}
			}
		);
	}
}