import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
//import javafx.scene.layout.Pane;
//import javafx.scene.layout.GridPane;
//import javafx.scene.layout.Pane;
//import javafx.scene.layout.VBox;
import javafx.application.Application;

//File Opeing
import java.awt.Desktop;
import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.geometry.Insets;
import javafx.stage.FileChooser;

//Excel tools:
//package oa.util;
import java.util.ArrayList;
import java.util.List;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.xssf.usermodel.XSSFCell;
import org.apache.poi.xssf.usermodel.XSSFRow;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import oa.bean.Materiel;


public class ProjectController {
	//Buttons for file opening
	@FXML Button Choose, OpenFile;
	//TextField to show path of files 
	@FXML TextField Path;
	//Text for stat checking  
	@FXML Text FileName, ProcessText;
	//Checkbox for user option
	@FXML Checkbox Box1, Box2, Box3;
	FileChooser fileChooser;
	Stage selectFile;
	Materiel materiel;
	List<Materiel> BOM;
	
	private Desktop desktop = Desktop.getDesktop();
	
	
	public void initialize() {
		final FileChooser fileChooser = new FileChooser();
	}
	
	@FXML
	private void ChooseButtonPressed(ActionEvent e){
		fileChooser = new FileChooser();
        fileChooser.setTitle("Choose Excel file");
		selectFile = new Stage();
		fileChooser.setInitialDirectory(new File(System.getProperty("user.home")));
		fileChooser.getExtensionFilters().addAll(new FileChooser.ExtensionFilter("All Excel", "*.xlsx"),
                new FileChooser.ExtensionFilter("XLS", "*.xls"), new FileChooser.ExtensionFilter("XLSX", "*.xlsx"));
        File file = fileChooser.showOpenDialog(selectFile);
		if (file != null) {
            try {
                bom.initBOM(ExcelUtil.importExcel(Util.getWorkbok(new FileInputStream(file), file)));
                session.commit();
                session.close();
            } catch (FileNotFoundException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
		ProcessText.setText("Choosing done.");
	}
	
	@FXML
	private void OpenFileButtonPressed(ActionEvent e){
		BOM = new ArrayList<>();
		if (wb instanceof HSSFWorkbook) {
			return null;
		} 
		/*else if (wb instanceof XSSFWorkbook) {
			XSSFWorkbook xs = (XSSFWorkbook) wb;
			for (int s = 0; s < xs.getNumberOfSheets(); s++) {
				XSSFSheet sheet = xs.getSheetAt(s);
				int lastRowNum = sheet.getLastRowNum();
				System.out.println("data:" + xs.getSheetName(s));
				for (int i = 0; i < lastRowNum; i++) {
					System.out.println(lastRowNum);
					XSSFRow row = sheet.getRow(i);
					 materiel = new Materiel();
					for (int j = 0; j < row.getLastCellNum(); j++) {
						XSSFCell cell = row.getCell(j);
						switch (cell.getColumnIndex()) {
						case 0:
							System.out.println(Integer.parseInt(cell.getRawValue()));
							materiel.setMateriel_id(Integer.parseInt(cell.getRawValue()));
							break;
						case 1:
							materiel.setMateriel_detail(cell.toString());
							break;
						case 2:
							System.out.println();
							materiel.setMateriel_package(Float.valueOf(cell.getRawValue()));
							break;
						case 3:
							materiel.setMateriel_supplier(cell.toString());
							break;
						default:
							//TODO there are errors in data
							break;
						}
					}
					materiel.setMateriel_type(sheet.getSheetName());
					BOM.add(materiel);
				}
			}
		}
		ProcessText.setText("opening done.");*/
	}
}