//controller
//package sample
import javafx.scene.control.TextInputDialog;
import javafx.scene.control.Alert.*;
import java.util.Optional;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.fxml.FXMLLoader ;
import javafx.scene.Parent ;
import javafx.scene.Group ;
import javafx.scene.Scene ;
import javafx.stage.Stage ;
import javafx.scene.layout.Pane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.BorderPane;
//Javafx Default:
        import javafx.event.ActionEvent;
        import javafx.event.EventHandler;
        import javafx.fxml.FXML;
        import javafx.scene.control.*;
        import javafx.scene.input.MouseEvent;
        import javafx.scene.text.Text;
        import javafx.scene.paint.Material;
		import javafx.scene.chart.LineChart;
		import javafx.scene.chart.NumberAxis;
		import javafx.scene.chart.CategoryAxis;
		import javafx.scene.chart.XYChart;
		import javafx.scene.chart.XYChart.Series;
        import javafx.application.Application;
		import javafx.scene.layout.StackPane;
		import javafx.scene.control.Tooltip;
		import javafx.scene.image.WritableImage;
		import javafx.scene.SnapshotParameters;
		import java.awt.image.BufferedImage;

//File Opeing:
        import java.awt.Desktop;
        import java.io.*;
        import java.util.List;
		import java.util.ArrayList;
        import java.util.logging.Level;
        import java.util.logging.Logger;
        import javafx.geometry.Insets;
        import javafx.stage.FileChooser;

//Excel tools:
        import javafx.stage.Stage;
        import java.util.ArrayList;
        import java.util.List;
		import java.util.HashMap; 
        import org.apache.poi.hssf.usermodel.HSSFWorkbook;
        import org.apache.poi.ss.usermodel.Row;
        import org.apache.poi.ss.usermodel.Sheet;
        import org.apache.poi.ss.usermodel.Workbook;
        import org.apache.poi.ss.usermodel.WorkbookFactory;
        import org.apache.poi.xssf.usermodel.XSSFCell;
        import org.apache.poi.xssf.usermodel.XSSFRow;
        import org.apache.poi.xssf.usermodel.XSSFSheet;
        import org.apache.poi.xssf.usermodel.XSSFWorkbook;

//Math tools:
		import java.lang.*;
		import java.text.NumberFormat;
		
		
		import javafx.stage.DirectoryChooser;
		import javafx.stage.FileChooser.*;
		
		import javafx.event.ActionEvent;
        import javafx.event.EventHandler;
		
		import javafx.application.Application;
		import javafx.embed.swing.*;
		import javax.imageio.ImageIO;
		
public class Controller {
	//Parent root2;
	final double[]startFreq1={0},stopFreq1={0.3};
	final double[]startFreq2={0},stopFreq2={0.3};
	final double[]startFreq3={0},stopFreq3={0.3};
	
	final double[]a1=new double[1];
	final double[]a2=new double[1];
	final double[]a3=new double[1];
	final double EPSILON_O2HB_760=1.4864e5,EPSILON_HHB_760=3.8430e5;
	final double EPSILON_O2HB_850=2.5259e5,EPSILON_HHB_850=1.7983e5;
	double Iout_760_t0_L1,Iout_850_t0_L1,sampleRate=50;//sampling rate 50Hz
	double Iout_760_t0_L2,Iout_850_t0_L2;
	double Iout_760_t0_L3,Iout_850_t0_L3;
	final double L1=30e-3,L2=35e-3,L3=40e-3;//column 1,2 apply L1 column 3,4 apply L2 column 5,6 apply L3
	final double DPF=6;
	//the unit of concentration is uM
	double[] deltaHHb1,deltaO2Hb1;// calculated from TX1
	double[] deltaHHb2,deltaO2Hb2;//calculated from TX2
	double[] deltaHHb3,deltaO2Hb3;//calculated from TX3
	
	ArrayList<String> eventAnnotation;
	ArrayList<Integer> eventIndex;
	HashMap<Integer,String> map;
	
	
	//Matrix of modified beer lamber's law
	Matrix A=new Matrix(2,2);
	Matrix C;
	Matrix M;
	Matrix A_PRIME;
	
	//Tools for xlsx
    Workbook wb;
    Sheet sh;
    FileInputStream fis;
    FileOutputStream fos;
    Row row;
    Cell cell;

	// array for data storage
	int numOfRows;
	int startRow;
    double[][] data;
	
	//SR_NIRS algorithm for StO2(TOI)
	double TOI[];
	
	//FFT algorithm
	int fftLength;
	//channel1
	Complex[]Channel1HHbIn,Channel1O2HbIn;
	Complex[]Channel1HHbOut,Channel1O2HbOut;
	//channel2
	Complex[]Channel2HHbIn,Channel2O2HbIn;
	Complex[]Channel2HHbOut,Channel2O2HbOut;
	//channel3
	Complex[]Channel3HHbIn,Channel3O2HbIn;
	Complex[]Channel3HHbOut,Channel3O2HbOut;
	
    //Buttons for file opening
    @FXML
    Button Choose, SaveImg;
    //TextField to show path of files
    @FXML
    TextField Path;
    //Text for stat checking
    @FXML
    Text ProcessText;
    //Checkbox for user option
    @FXML
    CheckBox HbBox1, HbBox2, HbBox3, HbO2Box1, HbO2Box2, HbO2Box3, TOIBox;
	@FXML CheckBox VCBox;
    FileChooser fileChooser;
    Stage selectFile;
	//LineChart to show data
	@FXML
	LineChart lineChart;
	@FXML
	CategoryAxis xAxis;
	@FXML
	NumberAxis yAxis;
	@FXML
	CheckBox FftBox1,FftBox2,FftBox3;
	

    private Desktop desktop = Desktop.getDesktop();
    public void initialize() {
        final FileChooser fileChooser = new FileChooser();
    }

	public static boolean isNumeric(String s)
	{
		try {
			Double.parseDouble(s);
		}
		catch(NumberFormatException n) {
			return false;
		}
		return true;
	}
	public static  double averageOutArray(double[] a)
	{
		double sum=0;
		for(double t:a)
			sum+=t;
		return sum/a.length;
	}
	public static<T> void displayArray(T[] a)
	{
		for(T t:a)
			System.out.print(""+t+"  ");
		System.out.println("");
	}
	
	public int downSampling(int n,int samplingInterval)
	{//return the index after down-sampling
		return ((n+samplingInterval)/samplingInterval)*samplingInterval;
	}
	
	private double evaluateTOI(int sampleNumber)
	{
		double deltaOD_760,deltaOD_850;
		double ua_760,ua_850;
		double slope_760,slope_850;
		double TOIValue=-1;;
		
		deltaOD_760=Math.log10(data[sampleNumber][1]/data[sampleNumber][5]);
		slope_760=deltaOD_760/(L3-L1);
		ua_760=slope_760*slope_760;
		
		deltaOD_850=Math.log10(data[sampleNumber][2]/data[sampleNumber][6]);
		slope_850=deltaOD_850/(L3-L1);
		ua_850=slope_850*slope_850;
		
		Matrix Ua=new Matrix(2,1);
		try{
			Ua.setValueAt(0,0,ua_760);
			Ua.setValueAt(1,0,ua_850);
		}
		catch(Exception exc)
		{
			exc.printStackTrace();
		}
		Matrix E=new Matrix(2,2);
		double[][] E_data=new double[2][2];
		E_data[0][0]=EPSILON_HHB_760;
		E_data[0][1]=EPSILON_O2HB_760;
		E_data[1][0]=EPSILON_HHB_850;
		E_data[1][1]=EPSILON_O2HB_850;
		try{
			E.setData(E_data);
		}
		catch(Exception exc)
		{
			exc.printStackTrace();
		}
		Matrix Concentration=new Matrix(2,1);
		try{
			Concentration=MatrixOperation.inverse(E).multiply(Ua);
		}
		catch(Exception exc)
		{
			exc.printStackTrace();
		}
		try{
			TOIValue=Concentration.getValueAt(1,0)/(Concentration.getValueAt(0,0)+Concentration.getValueAt(1,0));
		}
		catch(Exception exc)
		{
			exc.printStackTrace();
		}
		return TOIValue;
		
	}
    @FXML
    private void ChooseButtonPressed(ActionEvent e) {
		//Test method "multiply"
		/*double T1_data[][]={{1,2},{3,4}};
		Matrix T1=new Matrix(T1_data);
		System.out.println("Matrix T1");
		try{
			MatrixOperation.displayMatrix(MatrixOperation.inverse(T1));
		}
		catch(Exception exc)
		{
			exc.printStackTrace();
		}*/
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Choose ExcelFiles");
        Stage selectFile = new Stage();
        fileChooser.setInitialDirectory(new File(System.getProperty("user.home")));
        fileChooser.getExtensionFilters().addAll(new FileChooser.ExtensionFilter("All Excel", "*.xlsx"),
                new FileChooser.ExtensionFilter("XLS", "*.xls"), new FileChooser.ExtensionFilter("XLSX", "*.xlsx"));
		try {
			File file = fileChooser.showOpenDialog(selectFile);
			if (file != null) {

					//Write something here
					System.out.println("success");
					fis = new FileInputStream(file);
					//System.out.println("A");
					wb = WorkbookFactory.create(fis);
					sh = wb.getSheetAt(0);
					if(sh==null)
						System.out.println("null sheet");
					//System.out.println("B");
					numOfRows = sh.getLastRowNum();
					startRow=43;
					data = new double[numOfRows-startRow+1][7];
					deltaHHb1 = new double[numOfRows-startRow+1];
					deltaO2Hb1 = new double[numOfRows-startRow+1];
					deltaHHb2 = new double[numOfRows-startRow+1];
					deltaO2Hb2 = new double[numOfRows-startRow+1];
					deltaHHb3 = new double[numOfRows-startRow+1];
					deltaO2Hb3 = new double[numOfRows-startRow+1];
					map = new HashMap<>();
					System.out.println("numOfRows="+numOfRows);
					
					eventAnnotation=new ArrayList<>();
					eventIndex=new ArrayList<>();
					try {
						
						for(int i=startRow;i<=numOfRows;i++)
						{
							for(int j=0;j<7;j++)
							{
								//System.out.println(sh.getRow(i).getCell(j));
								data[i-startRow][j] = Double.parseDouble(sh.getRow(i).getCell(j).toString());	
							}   
							//System.out.println(sh.getRow(i).getCell(7).toString());
							try{
								eventAnnotation.add(sh.getRow(i).getCell(7).toString());
								if(!eventAnnotation.get(eventAnnotation.size()-1).equals(""))
								{
									System.out.println("eventAnnotation");
									
									eventIndex.add((int)data[i-startRow][0]);
									System.out.println("A1");
									int closestPaintedData=(int)data[0][0]+downSampling(eventIndex.get(eventIndex.size()-1)-(int)data[0][0],50);
									System.out.println("A2");
									if(map.containsKey(closestPaintedData))
										map.put(closestPaintedData,map.get(closestPaintedData)+"\n"+eventAnnotation.get(eventAnnotation.size()-1));
									//System.out.println(""+closestPaintedData+" "+eventAnnotation.get(eventAnnotation.size()-1));
									else
										map.put(closestPaintedData,eventAnnotation.get(eventAnnotation.size()-1));
									//System.out.println(""+closestPaintedData+" "+eventAnnotation.get(eventAnnotation.size()-1));
									System.out.println(""+closestPaintedData+" "+map.get(closestPaintedData));
									System.out.println("A3");
								}
							}
							catch(NullPointerException npexc)
							{
								//npexc.printStackTrace();
							}
						}  
						
					}
					catch(NumberFormatException n)
					{
						n.printStackTrace();
					}
					
					ProcessText.setText("Choosing done.");
					Path.setText(file.getName());
			}	
		}
		catch(NullPointerException nullPointerException) {
			System.out.println("fail to open the file");
			nullPointerException.printStackTrace();
		}
        catch(IOException ioe) {
			// TODO Auto-generated catch block
			ioe.printStackTrace();
		}
		dataProcessing();
    }

    public void fftPlotting(int channel,LineChart<String,Number> fftLineChart,XYChart.Series HHbfft1,XYChart.Series O2Hbfft1,double startFrequency,double stopFrequency,double scale,double f0)
	{
		fftLineChart.getData().removeAll(HHbfft1,O2Hbfft1);	
		fftLineChart.getData().clear();
		HHbfft1.getData().clear();
		O2Hbfft1.getData().clear();
		if(channel==1)
		{
			for(int i=(int)(startFrequency/f0);i<(int)(stopFrequency/f0);i++){
				HHbfft1.getData().add(new XYChart.Data(Double.toString(f0*i),scale*Channel1HHbOut[i].abs()));//f0=1/(NT)
				O2Hbfft1.getData().add(new XYChart.Data(Double.toString(f0*i),scale*Channel1O2HbOut[i].abs()));
			}
		}
		else if(channel==2)
		{
			for(int i=(int)(startFrequency/f0);i<(int)(stopFrequency/f0);i++){
				HHbfft1.getData().add(new XYChart.Data(Double.toString(f0*i),scale*Channel2HHbOut[i].abs()));//f0=1/(NT)
				O2Hbfft1.getData().add(new XYChart.Data(Double.toString(f0*i),scale*Channel2O2HbOut[i].abs()));
			}
		}
		else
		{
			for(int i=(int)(startFrequency/f0);i<(int)(stopFrequency/f0);i++){
				HHbfft1.getData().add(new XYChart.Data(Double.toString(f0*i),scale*Channel3HHbOut[i].abs()));//f0=1/(NT)
				O2Hbfft1.getData().add(new XYChart.Data(Double.toString(f0*i),scale*Channel3O2HbOut[i].abs()));
			}
		}
		
		/*for(int i=0;i<fftLength/index_interval;i++)
			HHbfft1.getData().add(new XYChart.Data(Double.toString(sampleRate*i*index_interval/fftLength),scale*Channel1HHbOut[i*index_interval].abs()));//f0=1/(NT)*/
		fftLineChart.getData().add(HHbfft1);
		fftLineChart.getData().add(O2Hbfft1);
		for (int i=0;i< fftLineChart.getData().size();i++) {
			XYChart.Series<String, Number> series=(XYChart.Series<String, Number>)fftLineChart.getData().get(i);
			//for all series, take date, each data has Node (symbol) for representing point
			for (int j=0;j< series.getData().size();j++) {
				// this node is StackPane
				XYChart.Data<String, Number> chartData=(XYChart.Data<String, Number>)series.getData().get(j);
				StackPane stackPane =  (StackPane) chartData.getNode();
				
				String toolTipString=String.valueOf(chartData.getXValue())+", "+String.valueOf(chartData.getYValue());
				System.out.println(String.valueOf(chartData.getXValue())+", "+String.valueOf(chartData.getYValue()));
				
				Tooltip.install(stackPane, new Tooltip(toolTipString));
				
				//Text annotation=new Text();
			
			}
		}
	}
	
    private void dataProcessing() {
		//Math.log10(x) statement for log10
		//setup matrix
		double A_data[][]=new double[2][2];
		
		A_data[0][0]=EPSILON_O2HB_760;
		A_data[0][1]=EPSILON_HHB_760;
		A_data[1][0]=EPSILON_O2HB_850;
		A_data[1][1]=EPSILON_HHB_850;
		try{
			A.setData(A_data);
		}
		catch(Exception exc)
		{
			exc.printStackTrace();
		}
		
		try{
			A_PRIME=MatrixOperation.transpose(A).multiply(A);
			A_PRIME=MatrixOperation.inverse(A_PRIME);
			A_PRIME=A_PRIME.multiply(MatrixOperation.transpose(A));
			//A_PRIME=MatrixOperation.inverse(MatrixOperation.transpose(A).multiply(A)).multiply(MatrixOperation.transpose(A));//C=A_PRIME*M
		}
		catch(Exception exc)
		{
			exc.printStackTrace();
		}
		//System.out.println("Matrix A_PRIME");
		//MatrixOperation.displayMatrix(A_PRIME);
		
		
		//for TX1,L1
		Iout_760_t0_L1=data[0][1];
		Iout_850_t0_L1=data[0][2];
		for(int i=0;i<data.length;i++)//i is the index of sample data
		{
			double intensity_760=data[i][1];
			double intensity_850=data[i][2];
			if(i<=10){
				System.out.print("intensity_760="+intensity_760);
				System.out.println(" intensity_850="+intensity_850);
			}
			// error here 
			double deltaOD_760=Math.log10(Iout_760_t0_L1/intensity_760);
			double deltaOD_850=Math.log10(Iout_850_t0_L1/intensity_850);
			/*if(i<=10){
				System.out.print("deltaOD_760="+deltaOD_760);
				System.out.println("	deltaOD_850="+deltaOD_850);
			}*/
			/*System.out.println("deltaOD_760="+deltaOD_760);
			System.out.println("deltaOD_850="+deltaOD_850);*/
			double [][]M_data=new double[2][1];
			M_data[0][0]=deltaOD_760;
			M_data[1][0]=deltaOD_850;
			M=new Matrix(M_data);
			/*System.out.println("Matrix M");
			MatrixOperation.displayMatrix(M);*/
			try{
				C=A_PRIME.multiply(M);
			}
			catch(Exception exc)
			{
				exc.printStackTrace();
			}
			try{
				deltaO2Hb1[i]=C.getValueAt(0,0)/(L1*DPF);
				deltaHHb1 [i]=C.getValueAt(1,0)/(L1*DPF);
				//System.out.printf("%f %f%n",deltaO2Hb1[i],deltaHHb1 [i]);
			}
			catch(Exception exc)
			{
				exc.printStackTrace();
			}
		
		}
		/*System.out.println("Matrix C");
		MatrixOperation.displayMatrix(C);*/
		System.out.printf("%-7s %-7s%n","O2Hb","HHb");
		for(int i=0;i<10;i++)
		{
			System.out.printf("%-8.5f %-8.5f%n",deltaO2Hb1[i],deltaHHb1 [i]);
			
		}
		
		//for TX2,L2
		Iout_760_t0_L2=data[0][3];
		Iout_850_t0_L2=data[0][4];
		for(int i=0;i<data.length;i++)//i is the index of sample data
		{
			double intensity_760=data[i][3];
			double intensity_850=data[i][4];
			/*System.out.println("intensity_760="+intensity_760);
			System.out.println("intensity_850="+intensity_850);*/
			// error here 
			double deltaOD_760=Math.log10(Iout_760_t0_L2/intensity_760);
			double deltaOD_850=Math.log10(Iout_850_t0_L2/intensity_850);
			/*System.out.println("deltaOD_760="+deltaOD_760);
			System.out.println("deltaOD_850="+deltaOD_850);*/
			double [][]M_data=new double[2][1];
			M_data[0][0]=deltaOD_760;
			M_data[1][0]=deltaOD_850;
			M=new Matrix(M_data);
			/*System.out.println("Matrix M");
			MatrixOperation.displayMatrix(M);*/
			try{
				C=A_PRIME.multiply(M);
			}
			catch(Exception exc)
			{
				exc.printStackTrace();
			}
			try{
				deltaO2Hb2[i]=C.getValueAt(0,0)/(L2*DPF);
				deltaHHb2 [i]=C.getValueAt(1,0)/(L2*DPF);
				//System.out.printf("%-8.5f %-8.5f%n",deltaO2Hb1[i],deltaHHb1 [i]);
			}
			catch(Exception exc)
			{
				exc.printStackTrace();
			}
		
		}
		/*System.out.println("Matrix C");
		MatrixOperation.displayMatrix(C);*/
		/*System.out.printf("%-7s %-7s%n","O2Hb","HHb");
		for(int i=0;i<5;i++)
		{
			System.out.printf("%-8.5f %-8.5f%n",deltaO2Hb2[i]*1e6,deltaHHb2 [i]*1e6);
			
		}*/
		
		//for TX3,L3
		Iout_760_t0_L3=data[0][5];
		Iout_850_t0_L3=data[0][6];
		for(int i=0;i<data.length;i++)//i is the index of sample data
		{
			double intensity_760=data[i][5];
			double intensity_850=data[i][6];
			/*System.out.println("intensity_760="+intensity_760);
			System.out.println("intensity_850="+intensity_850);*/
			// error here 
			double deltaOD_760=Math.log10(Iout_760_t0_L3/intensity_760);
			double deltaOD_850=Math.log10(Iout_850_t0_L3/intensity_850);
			/*System.out.println("deltaOD_760="+deltaOD_760);
			System.out.println("deltaOD_850="+deltaOD_850);*/
			double [][]M_data=new double[2][1];
			M_data[0][0]=deltaOD_760;
			M_data[1][0]=deltaOD_850;
			M=new Matrix(M_data);
			/*System.out.println("Matrix M");
			MatrixOperation.displayMatrix(M);*/
			try{
				C=A_PRIME.multiply(M);
			}
			catch(Exception exc)
			{
				exc.printStackTrace();
			}
			try{
				deltaO2Hb3[i]=C.getValueAt(0,0)/(L3*DPF);
				deltaHHb3 [i]=C.getValueAt(1,0)/(L3*DPF);
				//System.out.printf("%-8.5f %-8.5f%n",deltaO2Hb1[i],deltaHHb1 [i]);
			}
			catch(Exception exc)
			{
				exc.printStackTrace();
			}
		
		}
		/*System.out.println("Matrix C");
		MatrixOperation.displayMatrix(C);*/
		/*System.out.printf("%-7s %-7s%n","O2Hb","HHb");
		for(int i=0;i<5;i++)
		{
			System.out.printf("%-8.5f %-8.5f%n",deltaO2Hb3[i]*1e6,deltaHHb3 [i]*1e6);
		}*/
		for(int i=0;i<data.length;i++)
		{
			//change the unit from M to uM
			deltaO2Hb1[i]*=1e6;
			deltaHHb1 [i]*=1e6;
			deltaO2Hb2[i]*=1e6;
			deltaHHb2 [i]*=1e6;
			deltaO2Hb3[i]*=1e6;
			deltaHHb3 [i]*=1e6;
		}
		TOI=new double[data.length];
		for(int i=0;i<data.length;i++)
		{
			TOI[i]=evaluateTOI(i);
			/*NumberFormat percentageFormat = NumberFormat.getPercentInstance();
			percentageFormat.setMinimumFractionDigits(2);
			System.out.println(percentageFormat.format(TOI[i]));*/
		}
		//FFT algorithm
		Complex[]tmp=new Complex[deltaHHb1.length];
		//channel1
		//HHb
		for(int i=0;i<deltaHHb1.length;i++)
		{
			tmp[i]=new Complex(deltaHHb1[i],0);
		}
		Channel1HHbIn=FFT.zeroPadding(tmp);
		Channel1HHbOut=FFT.fft(Channel1HHbIn);
		fftLength=Channel1HHbIn.length;
		//O2Hb
		tmp=new Complex[deltaO2Hb1.length];
		for(int i=0;i<deltaO2Hb1.length;i++)
		{
			tmp[i]=new Complex(deltaO2Hb1[i],0);
		}
		Channel1O2HbIn=FFT.zeroPadding(tmp);
		Channel1O2HbOut=FFT.fft(Channel1O2HbIn);
		
		//channel2
		//HHb
		tmp=new Complex[deltaHHb2.length];
		for(int i=0;i<deltaHHb2.length;i++)
		{
			tmp[i]=new Complex(deltaHHb2[i],0);
		}
		Channel2HHbIn=FFT.zeroPadding(tmp);
		Channel2HHbOut=FFT.fft(Channel2HHbIn);
		//O2Hb
		tmp=new Complex[deltaO2Hb2.length];
		for(int i=0;i<deltaO2Hb2.length;i++)
		{
			tmp[i]=new Complex(deltaO2Hb2[i],0);
		}
		Channel2O2HbIn=FFT.zeroPadding(tmp);
		Channel2O2HbOut=FFT.fft(Channel2O2HbIn);
		
		//channel3
		//HHb
		tmp=new Complex[deltaHHb3.length];
		for(int i=0;i<deltaHHb3.length;i++)
		{
			tmp[i]=new Complex(deltaHHb3[i],0);
		}
		Channel3HHbIn=FFT.zeroPadding(tmp);
		Channel3HHbOut=FFT.fft(Channel3HHbIn);
		//O2Hb
		tmp=new Complex[deltaO2Hb3.length];
		for(int i=0;i<deltaO2Hb3.length;i++)
		{
			tmp[i]=new Complex(deltaO2Hb3[i],0);
		}
		Channel3O2HbIn=FFT.zeroPadding(tmp);
		Channel3O2HbOut=FFT.fft(Channel3O2HbIn);
		
		System.out.println("Test fft");
		Complex[]x={new Complex(-0.03480425839330703,0),new Complex(0.07910192950176387,0),new Complex(0.7233322451735928,0),new Complex(0.1659819820667019,0)};
		Complex[]y=FFT.fft(x);
		FFT.show(y,"fftx");
		
/*	 x
 *  -------------------
 *	-0.03480425839330703
 *  0.07910192950176387
 *  0.7233322451735928
 *  0.1659819820667019
 *
 *  y = fft(x)
 -------------------
 *  0.9336118983487516
 *  -0.7581365035668999 + 0.08688005256493803i
 *  0.44344407521182005
 *  -0.7581365035668999 - 0.08688005256493803i
*/
		


		System.out.println("<Channel1 FFT>");
		FFT.show(Channel1HHbOut,"HHb");
		FFT.show(Channel1O2HbOut,"O2Hb");
		System.out.println("<Channel2 FFT>");
		FFT.show(Channel2HHbOut,"HHb");
		FFT.show(Channel2O2HbOut,"O2Hb");
		System.out.println("<Channel3 FFT>");
		FFT.show(Channel3HHbOut,"HHb");
		FFT.show(Channel3O2HbOut,"O2Hb");
		
    }
	
	@FXML
	private void CheckBoxChecked(ActionEvent e) {
		System.out.println("Box checked.");
		
		lineChart.getXAxis().setAutoRanging(true);
		lineChart.getYAxis().setAutoRanging(true);
		xAxis.setLabel("xAxis-sample number");
		yAxis.setLabel("yAxis");
		
		
		XYChart.Series series1 = new XYChart.Series();
		series1.setName("HHb1");
		XYChart.Series series2 = new XYChart.Series();
		series2.setName("O2Hb1");
		XYChart.Series series3 = new XYChart.Series();
		series3.setName("HHb2");
		XYChart.Series series4 = new XYChart.Series();
		series4.setName("O2Hb2");
		XYChart.Series series5 = new XYChart.Series();
		series5.setName("HHb3");
		XYChart.Series series6 = new XYChart.Series();
		series6.setName("O2Hb3");
		XYChart.Series series7 = new XYChart.Series();
		series7.setName("TOI");
		
		XYChart.Series HHbfft1 = new XYChart.Series();
		HHbfft1.setName("fft of HHb1");
		XYChart.Series O2Hbfft1 = new XYChart.Series();
		O2Hbfft1.setName("fft of O2Hb1");
		
		XYChart.Series HHbfft2 = new XYChart.Series();
		HHbfft2.setName("fft of HHb2");
		XYChart.Series O2Hbfft2 = new XYChart.Series();
		O2Hbfft2.setName("fft of O2Hb2");
		
		XYChart.Series HHbfft3 = new XYChart.Series();
		HHbfft3.setName("fft of HHb3");
		XYChart.Series O2Hbfft3 = new XYChart.Series();
		O2Hbfft3.setName("fft of O2Hb3");
		//if(!lineChart.getData().isEmpty())
		//	lineChart.getData().remove((int)(lineChart.getData().size()-1));
		//menuItem handler
		
		int index_interval=50;
		if(HbBox1.isSelected())
			for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
				series1.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaHHb1[i*index_interval]));
		else
			lineChart.getData().clear();
		if(HbO2Box1.isSelected())
			for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
				series2.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaO2Hb1[i*index_interval]));
		else
			lineChart.getData().clear();
		if(HbBox2.isSelected())
			for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
				series3.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaHHb2[i*index_interval]));
		else
			lineChart.getData().clear();
		if(HbO2Box2.isSelected())
			for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
				series4.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaO2Hb2[i*index_interval]));	
		else
			lineChart.getData().clear();
		if(HbBox3.isSelected())
			for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
				series5.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaHHb3[i*index_interval]));
		else
			lineChart.getData().clear();
		if(HbO2Box3.isSelected())
			for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
				series6.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaO2Hb3[i*index_interval]));	
		else
			lineChart.getData().clear();
		if(TOIBox.isSelected())
			for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
				series7.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), 100*TOI[i*index_interval]));
		else
			lineChart.getData().clear();
		if(FftBox1.isSelected())
		{
			
			BorderPane canvas = new BorderPane();
			Group root3=new Group();
			final CategoryAxis fftXAxis=new CategoryAxis();
			final NumberAxis fftYAxis = new NumberAxis();
			
			//creating the chart
			final LineChart<String,Number> fftLineChart = 
					new LineChart<String,Number>(fftXAxis,fftYAxis);
					
			fftLineChart.setTitle("FFT");
			
			if(fftLineChart==null)
				System.out.println("fftLineChart=null");
			double scale=1;
			/*try{
				root2 = FXMLLoader.load ( getClass (). getResource ("sample2.fxml"));
				//root3.getChildren().add(root2);
			}
			catch(IOException exception)
			{
				exception.printStackTrace();
			}*/
			ScrollPane sp = new ScrollPane();
			sp.setContent(root3);
			sp.setPannable(true);
			Stage stage2 = new Stage();
			Scene scene2=new Scene(sp,720,480);
			stage2.setScene(scene2);
			//stage2.sizeToScene();
			stage2.show();
			Menu menu = new Menu("Tool");

			Menu subMenu = new Menu("Scale");
			MenuItem menuItem11 = new MenuItem("x0.1");
			MenuItem menuItem12 = new MenuItem("x1.0");
			MenuItem menuItem13 = new MenuItem("x10.0");
			MenuItem menuItem3  = new MenuItem("select range");
			subMenu.getItems().add(menuItem11);
			subMenu.getItems().add(menuItem12);
			subMenu.getItems().add(menuItem13);
			menu.getItems().add(subMenu);
			menu.getItems().add(menuItem3);
			Menu menu2=new Menu("File");
			MenuItem menuItem2=new MenuItem("save");
			menu2.getItems().add(menuItem2);

			

			MenuBar menuBar = new MenuBar();
			menuBar.getMenus().add(menu2);
			menuBar.getMenus().add(menu);
			
			a1[0]=scale;
			menuItem11.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					a1[0]=0.1;
					//scale=a[0];
					double f0=sampleRate/fftLength;
					canvas.setCenter(null);
					fftPlotting(1,fftLineChart,HHbfft1,O2Hbfft1,startFreq1[0],stopFreq1[0],a1[0],f0);
					canvas.setCenter(fftLineChart);
				}
			});
			menuItem12.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					a1[0]=1;
					//scale=a[0];
					double f0=sampleRate/fftLength;
					canvas.setCenter(null);
					fftPlotting(1,fftLineChart,HHbfft1,O2Hbfft1,startFreq1[0],stopFreq1[0],a1[0],f0);
					canvas.setCenter(fftLineChart);
				}
			});
			menuItem13.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					a1[0]=10;
					//scale=a[0];
					double f0=sampleRate/fftLength;
					canvas.setCenter(null);
					fftPlotting(1,fftLineChart,HHbfft1,O2Hbfft1,startFreq1[0],stopFreq1[0],a1[0],f0);
					canvas.setCenter(fftLineChart);
				}
			});
			menuItem3.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					double f0=sampleRate/fftLength;
					TextInputDialog dialog = new TextInputDialog("");
					dialog.setTitle("Text Input Dialog");
					dialog.setHeaderText("frequency range");
					dialog.setContentText("Please enter start frequency:");

					// Traditional way to get the response value.
					Optional<String> result = dialog.showAndWait();
					
					dialog = new TextInputDialog("");
					dialog.setTitle("Text Input Dialog");
					dialog.setHeaderText("frequency range");
					dialog.setContentText("Please enter stop frequency:");

					// Traditional way to get the response value.
					Optional<String> result2 = dialog.showAndWait();
					
					if (result.isPresent()&&result2.isPresent()){
						String t=result.get();
						String t2=result2.get();
						//System.out.println( result.get());
						double startF=Double.parseDouble(t);
						System.out.println(startF);
						double stopF=Double.parseDouble(t2);
						stopFreq1[0]=stopF;
						startFreq1[0]=startF;
						if(startF>0&&stopF>startF&&stopF<fftLength*f0)
						{
							canvas.setCenter(null);
							fftPlotting(1,fftLineChart,HHbfft1,O2Hbfft1,startF,stopF,a1[0],f0);
							canvas.setCenter(fftLineChart);
						}
						
					}
					
				}
			});
			menuItem2.setOnAction(
				(ev)->{
					
					FileChooser fileChooser = new FileChooser();
					fileChooser.setTitle("Saving image");
					fileChooser.setInitialDirectory(new File("C:"+File.separator));
					fileChooser.setInitialFileName("*.png");
					File selectedDirectory = fileChooser.showSaveDialog(Main.getStage());
					if(selectedDirectory!=null) {
						try {
							final CategoryAxis newXAxis = new CategoryAxis();
							final NumberAxis newYAxis = new NumberAxis();
							final LineChart<String,Number> newChart = 
								new LineChart<String,Number>(newXAxis,newYAxis);
							newChart.setAnimated(false);
							
							
							
							
							XYChart.Series sr1 = new XYChart.Series();
							sr1.setName("fft of HHb1");
							XYChart.Series sr2 = new XYChart.Series();
							sr2.setName("fft of O2Hb1");
							
							
							//if(!lineChart.getData().isEmpty())
							//	lineChart.getData().remove((int)(lineChart.getData().size()-1));
							//menuItem handler
							
							//int index_interval=50;
							
							
							
							
							double f0=sampleRate/fftLength;
							fftPlotting(1,newChart,sr1,sr2,startFreq1[0],stopFreq1[0],a1[0],f0);
							Stage newStage = new Stage();
							Scene newScene = new Scene(newChart,(int)lineChart.getWidth(),(int)lineChart.getHeight());
							newScene.getStylesheets().add("sample.css");
							newStage.setScene(newScene);
							newStage.show();
							SnapshotParameters parameters = new SnapshotParameters();
							//storage image
							WritableImage wim = newChart.snapshot(new SnapshotParameters(),null);
							//WritableImage wim = new WritableImage((int) lineChart.getWidth(),(int) lineChart.getHeight());
							newScene.snapshot(wim);
							BufferedImage bufferedImage = SwingFXUtils.fromFXImage(wim, null);
							ImageIO.write(bufferedImage, "png", selectedDirectory);
							newStage.close();
						}
						catch(IOException ioevent) {
							throw new RuntimeException(ioevent);
						}
					}
				}
			);
			
			scene2.getStylesheets().add("sample.css");
			//scene2.getStyleClass().add("background");
			canvas.getStyleClass().add("tex-field");
			fftLineChart.getXAxis().setAutoRanging(true);
			fftLineChart.getYAxis().setAutoRanging(true);
			fftXAxis.setLabel("frequency (Hz)");
			fftYAxis.setLabel("yAxis");
			
			canvas.setTop(menuBar);
			canvas.setCenter(fftLineChart);
			canvas.setPrefSize(1200,700);
			//canvas.getChildren().add(menuBar);
			//canvas.getChildren().add(fftLineChart);
			root3.getChildren().add(canvas);
			double f0=sampleRate/fftLength;
			scale=a1[0];
			fftPlotting(1,fftLineChart,HHbfft1,O2Hbfft1,0,100*f0,scale,f0);
			
		}
		
		if(FftBox2.isSelected())
		{
			BorderPane canvas = new BorderPane();
			Group root3=new Group();
			final CategoryAxis fftXAxis=new CategoryAxis();
			
			final NumberAxis fftYAxis = new NumberAxis();
			
			//creating the chart
			final LineChart<String,Number> fftLineChart = 
					new LineChart<String,Number>(fftXAxis,fftYAxis);
					
			fftLineChart.setTitle("FFT");
 
			if(fftLineChart==null)
				System.out.println("fftLineChart=null");
			double scale=1;
			
			ScrollPane sp = new ScrollPane();
			sp.setContent(root3);
			sp.setPannable(true);
			Stage stage2 = new Stage();
			Scene scene2=new Scene(sp,720,480);
			stage2.setScene(scene2);
			//stage2.sizeToScene();
			stage2.show();
			Menu menu = new Menu("Tool");

			Menu subMenu = new Menu("Scale");
			MenuItem menuItem11 = new MenuItem("x0.1");
			MenuItem menuItem12 = new MenuItem("x1.0");
			MenuItem menuItem13 = new MenuItem("x10.0");
			MenuItem menuItem3  = new MenuItem("select range");
			subMenu.getItems().add(menuItem11);
			subMenu.getItems().add(menuItem12);
			subMenu.getItems().add(menuItem13);
			menu.getItems().add(subMenu);
			menu.getItems().add(menuItem3);
			Menu menu2=new Menu("File");
			MenuItem menuItem2=new MenuItem("save");
			menu2.getItems().add(menuItem2);

			

			MenuBar menuBar = new MenuBar();
			menuBar.getMenus().add(menu2);
			menuBar.getMenus().add(menu);
			
			a2[0]=scale;
			menuItem11.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					a2[0]=0.1;
					double f0=sampleRate/fftLength;
					canvas.setCenter(null);
					fftPlotting(2,fftLineChart,HHbfft2,O2Hbfft2,startFreq2[0],stopFreq2[0],a2[0],f0);
					canvas.setCenter(fftLineChart);
				}
			});
			menuItem12.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					a2[0]=1;
					double f0=sampleRate/fftLength;
					canvas.setCenter(null);
					fftPlotting(2,fftLineChart,HHbfft2,O2Hbfft2,startFreq2[0],stopFreq2[0],a2[0],f0);
					canvas.setCenter(fftLineChart);
				}
			});
			menuItem13.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					a2[0]=10;
					double f0=sampleRate/fftLength;
					canvas.setCenter(null);
					fftPlotting(2,fftLineChart,HHbfft2,O2Hbfft2,startFreq2[0],stopFreq2[0],a2[0],f0);
					canvas.setCenter(fftLineChart);
				}
			});
			menuItem3.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					double f0=sampleRate/fftLength;
					TextInputDialog dialog = new TextInputDialog("");
					dialog.setTitle("Text Input Dialog");
					dialog.setHeaderText("frequency range");
					dialog.setContentText("Please enter start frequency:");

					// Traditional way to get the response value.
					Optional<String> result = dialog.showAndWait();
					
					dialog = new TextInputDialog("");
					dialog.setTitle("Text Input Dialog");
					dialog.setHeaderText("frequency range");
					dialog.setContentText("Please enter stop frequency:");

					// Traditional way to get the response value.
					Optional<String> result2 = dialog.showAndWait();
					
					if (result.isPresent()&&result2.isPresent()){
						String t=result.get();
						String t2=result2.get();
						//System.out.println( result.get());
						double startF=Double.parseDouble(t);
						System.out.println(startF);
						double stopF=Double.parseDouble(t2);
						startFreq2[0]=startF;
						stopFreq2[0]=stopF;
						if(startF>0&&stopF>startF&&stopF<fftLength*f0)
						{
							canvas.setCenter(null);
							fftPlotting(2,fftLineChart,HHbfft2,O2Hbfft2,startF,stopF,a2[0],f0);
							canvas.setCenter(fftLineChart);
						}
						
					}
					
				}
			});
			menuItem2.setOnAction(
				(ev)->{
					
					FileChooser fileChooser = new FileChooser();
					fileChooser.setTitle("Saving image");
					fileChooser.setInitialDirectory(new File("C:"+File.separator));
					fileChooser.setInitialFileName("*.png");
					File selectedDirectory = fileChooser.showSaveDialog(Main.getStage());
					if(selectedDirectory!=null) {
						try {
							final CategoryAxis newXAxis = new CategoryAxis();
							final NumberAxis newYAxis = new NumberAxis();
							final LineChart<String,Number> newChart = 
								new LineChart<String,Number>(newXAxis,newYAxis);
							newChart.setAnimated(false);
							
							
							
							
							XYChart.Series sr1 = new XYChart.Series();
							sr1.setName("fft of HHb2");
							XYChart.Series sr2 = new XYChart.Series();
							sr2.setName("fft of O2Hb2");
							
							
							//if(!lineChart.getData().isEmpty())
							//	lineChart.getData().remove((int)(lineChart.getData().size()-1));
							//menuItem handler
							
							//int index_interval=50;
							
							
							
							
							double f0=sampleRate/fftLength;
							fftPlotting(2,newChart,sr1,sr2,startFreq2[0],stopFreq2[0],a2[0],f0);
							Stage newStage = new Stage();
							Scene newScene = new Scene(newChart,(int)lineChart.getWidth(),(int)lineChart.getHeight());
							newScene.getStylesheets().add("sample.css");
							newStage.setScene(newScene);
							newStage.show();
							SnapshotParameters parameters = new SnapshotParameters();
							//storage image
							WritableImage wim = newChart.snapshot(new SnapshotParameters(),null);
							//WritableImage wim = new WritableImage((int) lineChart.getWidth(),(int) lineChart.getHeight());
							newScene.snapshot(wim);
							BufferedImage bufferedImage = SwingFXUtils.fromFXImage(wim, null);
							ImageIO.write(bufferedImage, "png", selectedDirectory);
							newStage.close();
						}
						catch(IOException ioevent) {
							throw new RuntimeException(ioevent);
						}
					}
				}
			);
			
			scene2.getStylesheets().add("sample.css");
			//scene2.getStyleClass().add("background");
			canvas.getStyleClass().add("tex-field");
			fftLineChart.getXAxis().setAutoRanging(true);
			fftLineChart.getYAxis().setAutoRanging(true);
			fftXAxis.setLabel("frequency (Hz)");
			fftYAxis.setLabel("yAxis");
			
			canvas.setTop(menuBar);
			canvas.setCenter(fftLineChart);
			canvas.setPrefSize(1200,700);
			//canvas.getChildren().add(menuBar);
			//canvas.getChildren().add(fftLineChart);
			root3.getChildren().add(canvas);
			double f0=sampleRate/fftLength;
			scale=a2[0];
			fftPlotting(2,fftLineChart,HHbfft2,O2Hbfft2,0,100*f0,scale,f0);
		}
		if(FftBox3.isSelected())
		{
			BorderPane canvas = new BorderPane();
			Group root3=new Group();
			final CategoryAxis fftXAxis=new CategoryAxis();
			
			final NumberAxis fftYAxis = new NumberAxis();
			
			//creating the chart
			final LineChart<String,Number> fftLineChart = 
					new LineChart<String,Number>(fftXAxis,fftYAxis);
					
			fftLineChart.setTitle("FFT");
 
			if(fftLineChart==null)
				System.out.println("fftLineChart=null");
			double scale=1;
			
			ScrollPane sp = new ScrollPane();
			sp.setContent(root3);
			sp.setPannable(true);
			//sp.setPrefSize(700,800);
			Stage stage2 = new Stage();
			Scene scene2=new Scene(sp,720,480);
			stage2.setScene(scene2);
			stage2.sizeToScene();
			stage2.show();
			Menu menu = new Menu("Tool");

			Menu subMenu = new Menu("Scale");
			MenuItem menuItem11 = new MenuItem("x0.1");
			MenuItem menuItem12 = new MenuItem("x1.0");
			MenuItem menuItem13 = new MenuItem("x10.0");
			MenuItem menuItem3  = new MenuItem("select range");
			subMenu.getItems().add(menuItem11);
			subMenu.getItems().add(menuItem12);
			subMenu.getItems().add(menuItem13);
			menu.getItems().add(subMenu);
			menu.getItems().add(menuItem3);
			Menu menu2=new Menu("File");
			MenuItem menuItem2=new MenuItem("save");
			menu2.getItems().add(menuItem2);

			MenuBar menuBar = new MenuBar();
			menuBar.getMenus().add(menu2);
			menuBar.getMenus().add(menu);

			a3[0]=scale;
			menuItem11.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					a3[0]=0.1;
					double f0=sampleRate/fftLength;
					canvas.setCenter(null);
					fftPlotting(3,fftLineChart,HHbfft3,O2Hbfft3,startFreq3[0],stopFreq3[0],a3[0],f0);
					canvas.setCenter(fftLineChart);
				}
			});
			menuItem12.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					a3[0]=1;
					double f0=sampleRate/fftLength;
					canvas.setCenter(null);
					fftPlotting(3,fftLineChart,HHbfft3,O2Hbfft3,startFreq3[0],stopFreq3[0],a3[0],f0);
					canvas.setCenter(fftLineChart);
				}
			});
			menuItem13.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					a3[0]=10;
					double f0=sampleRate/fftLength;
					canvas.setCenter(null);
					fftPlotting(3,fftLineChart,HHbfft3,O2Hbfft3,startFreq3[0],stopFreq3[0],a3[0],f0);
					canvas.setCenter(fftLineChart);
				}
			});
			menuItem3.setOnAction(new EventHandler<ActionEvent>() {
				@Override public void handle(ActionEvent e) {
					double f0=sampleRate/fftLength;
					TextInputDialog dialog = new TextInputDialog("");
					dialog.setTitle("Text Input Dialog");
					dialog.setHeaderText("frequency range");
					dialog.setContentText("Please enter start frequency:");

					// Traditional way to get the response value.
					Optional<String> result = dialog.showAndWait();
					
					dialog = new TextInputDialog("");
					dialog.setTitle("Text Input Dialog");
					dialog.setHeaderText("frequency range");
					dialog.setContentText("Please enter stop frequency:");

					// Traditional way to get the response value.
					Optional<String> result2 = dialog.showAndWait();
					
					if (result.isPresent()&&result2.isPresent()){
						String t=result.get();
						String t2=result2.get();
						//System.out.println( result.get());
						double startF=Double.parseDouble(t);
						System.out.println(startF);
						double stopF=Double.parseDouble(t2);
						startFreq3[0]=startF;
						stopFreq3[0]=stopF;
						if(startF>0&&stopF>startF&&stopF<fftLength*f0)
						{
							canvas.setCenter(null);
							fftPlotting(3,fftLineChart,HHbfft3,O2Hbfft3,startF,stopF,a3[0],f0);
							canvas.setCenter(fftLineChart);
						}
						
					}
					
				}
			});
			menuItem2.setOnAction(
				(ev)->{
					
					FileChooser fileChooser = new FileChooser();
					fileChooser.setTitle("Saving image");
					fileChooser.setInitialDirectory(new File("C:"+File.separator));
					fileChooser.setInitialFileName("*.png");
					File selectedDirectory = fileChooser.showSaveDialog(Main.getStage());
					if(selectedDirectory!=null) {
						try {
							final CategoryAxis newXAxis = new CategoryAxis();
							final NumberAxis newYAxis = new NumberAxis();
							final LineChart<String,Number> newChart = 
								new LineChart<String,Number>(newXAxis,newYAxis);
							newChart.setAnimated(false);
							
							
							
							
							XYChart.Series sr1 = new XYChart.Series();
							sr1.setName("fft of HHb3");
							XYChart.Series sr2 = new XYChart.Series();
							sr2.setName("fft of O2Hb3");
							
							
							//if(!lineChart.getData().isEmpty())
							//	lineChart.getData().remove((int)(lineChart.getData().size()-1));
							//menuItem handler
							
							//int index_interval=50;
							
							
							
							
							double f0=sampleRate/fftLength;
							fftPlotting(3,newChart,sr1,sr2,startFreq3[0],stopFreq3[0],a3[0],f0);
							Stage newStage = new Stage();
							Scene newScene = new Scene(newChart,(int)lineChart.getWidth(),(int)lineChart.getHeight());
							newScene.getStylesheets().add("sample.css");
							newStage.setScene(newScene);
							newStage.show();
							SnapshotParameters parameters = new SnapshotParameters();
							//storage image
							WritableImage wim = newChart.snapshot(new SnapshotParameters(),null);
							//WritableImage wim = new WritableImage((int) lineChart.getWidth(),(int) lineChart.getHeight());
							newScene.snapshot(wim);
							BufferedImage bufferedImage = SwingFXUtils.fromFXImage(wim, null);
							ImageIO.write(bufferedImage, "png", selectedDirectory);
							newStage.close();
						}
						catch(IOException ioevent) {
							throw new RuntimeException(ioevent);
						}
					}
				}
			);
			
			scene2.getStylesheets().add("sample.css");
			//scene2.getStyleClass().add("background");
			canvas.getStyleClass().add("tex-field");
			fftLineChart.getXAxis().setAutoRanging(true);
			fftLineChart.getYAxis().setAutoRanging(true);
			fftXAxis.setLabel("frequency (Hz)");
			fftYAxis.setLabel("yAxis");
			fftLineChart.setPrefSize(720,460);
			canvas.setTop(menuBar);
			canvas.setCenter(fftLineChart);
			canvas.setPrefSize(1000,800);
			//canvas.getChildren().add(menuBar);
			//canvas.getChildren().add(fftLineChart);
			root3.getChildren().add(canvas);
			double f0=sampleRate/fftLength;
			scale=a3[0];
			fftPlotting(3,fftLineChart,HHbfft3,O2Hbfft3,0,100*f0,scale,f0);
		}
		
		if(false)
		{
			final double T=0.05;
			final int N=256;
			XYChart.Series testSeries = new XYChart.Series();
			Complex testSamples[]=new Complex[N];
			for(int n=0;n<N;n++){
				testSamples[n]=new Complex(Math.cos(4*Math.PI*T*n),0);//f0=1/(NT)
				
			}
			//fft operation
			Complex[] testResult=FFT.zeroPadding(testSamples);
			testResult=FFT.fft(testResult);
			testSeries.setName("fft of cos");
			Group root3=new Group();
			final CategoryAxis fftXAxis=new CategoryAxis();
			
			final NumberAxis fftYAxis = new NumberAxis();
			
			//creating the chart
			final LineChart<String,Number> fftLineChart = 
					new LineChart<String,Number>(fftXAxis,fftYAxis);
					
			fftLineChart.setTitle("FFT");
 
			if(fftLineChart==null)
				System.out.println("fftLineChart=null");
			double scale=1;
			
			Stage stage2 = new Stage();
			Scene scene2=new Scene(root3,700,600);
			stage2.setScene(scene2);
			stage2.sizeToScene();
			stage2.show();
			Menu menu = new Menu("Tool");

			Menu subMenu = new Menu("Scale");
			MenuItem menuItem11 = new MenuItem("x0.1");
			MenuItem menuItem12 = new MenuItem("x1.0");
			MenuItem menuItem13 = new MenuItem("x10.0");
			subMenu.getItems().add(menuItem11);
			subMenu.getItems().add(menuItem12);
			subMenu.getItems().add(menuItem13);
			menu.getItems().add(subMenu);
			Menu menu2=new Menu("File");
			MenuItem menuItem2=new MenuItem("save");
			menu2.getItems().add(menuItem2);

			

			MenuBar menuBar = new MenuBar();
			menuBar.getMenus().add(menu2);
			menuBar.getMenus().add(menu);
			
			BorderPane canvas = new BorderPane();
			scene2.getStylesheets().add("sample.css");
			//scene2.getStyleClass().add("background");
			canvas.getStyleClass().add("tex-field");
			fftLineChart.getXAxis().setAutoRanging(true);
			fftLineChart.getYAxis().setAutoRanging(true);
			fftXAxis.setLabel("frequency (Hz)");
			fftYAxis.setLabel("yAxis");
			fftLineChart.getData().clear();	
			 
			for(int n=0;n<N;n++){//T=0.05,N=10
				testSeries.getData().add(new XYChart.Data(Double.toString(n*1./N/T),testResult[n].abs()));//f0=1/(NT)
				
			}
			/*for(int i=0;i<fftLength/index_interval;i++)
				HHbfft1.getData().add(new XYChart.Data(Double.toString(sampleRate*i*index_interval/fftLength),scale*Channel1HHbOut[i*index_interval].abs()));//f0=1/(NT)*/
			fftLineChart.getData().add(testSeries);
			
			canvas.setTop(menuBar);
			canvas.setCenter(fftLineChart);
			canvas.setPrefSize(1200,700);
			//canvas.getChildren().add(menuBar);
			//canvas.getChildren().add(fftLineChart);
			root3.getChildren().add(canvas);
			for (int i=0;i< fftLineChart.getData().size();i++) {
				XYChart.Series<String, Number> series=(XYChart.Series<String, Number>)fftLineChart.getData().get(i);
				//for all series, take date, each data has Node (symbol) for representing point
				for (int j=0;j< series.getData().size();j++) {
					// this node is StackPane
					XYChart.Data<String, Number> chartData=(XYChart.Data<String, Number>)series.getData().get(j);
					StackPane stackPane =  (StackPane) chartData.getNode();
					
					String toolTipString=String.valueOf(chartData.getXValue())+", "+String.valueOf(chartData.getYValue());
					System.out.println(String.valueOf(chartData.getXValue())+", "+String.valueOf(chartData.getYValue()));
					
					Tooltip.install(stackPane, new Tooltip(toolTipString));
					
					//Text annotation=new Text();
				
				}
			}
		}
		
		lineChart.getData().add(series1);
		lineChart.getData().add(series2);
		lineChart.getData().add(series3);
		lineChart.getData().add(series4);
		lineChart.getData().add(series5);
		lineChart.getData().add(series6);
		lineChart.getData().add(series7);
		
		for (int i=0;i< lineChart.getData().size();i++) {
			XYChart.Series<String, Double> series=(XYChart.Series<String, Double>)lineChart.getData().get(i);
			//for all series, take date, each data has Node (symbol) for representing point
			for (int j=0;j< series.getData().size();j++) {
				// this node is StackPane
				XYChart.Data<String, Double> chartData=(XYChart.Data<String, Double>)series.getData().get(j);
				StackPane stackPane =  (StackPane) chartData.getNode();
				
				String toolTipString=String.valueOf(chartData.getXValue())+", "+String.valueOf(chartData.getYValue());
				//System.out.println(String.valueOf(chartData.getXValue())+map.get(chartData.getXValue()))
				if(map.get(Integer.parseInt(chartData.getXValue()))!=null)
				{
					System.out.println(String.valueOf(chartData.getXValue())+map.get(Integer.parseInt(chartData.getXValue())));
					stackPane.setPrefWidth(15);
					stackPane.setPrefHeight(15);
					stackPane.setStyle("-fx-background-color: yellow, white;-fx-background-radius: 0;-fx-background-insets: 0, 2.5;-fx-padding: 7px 5px 7px 5px;-fx-shape: \"M5,0 L10,9 L5,18 L0,9 Z\";");
					toolTipString+="\n"+map.get(Integer.parseInt(chartData.getXValue()));
					
				}
				/*if(Integer.parseInt(chartData.getXValue())<=23500) {
					XYChart.Data<String, Double> chartData2=(XYChart.Data<String, Double>)series.getData().get(j+1000);
					double y1 = Double.parseDouble(String.valueOf(chartData.getYValue()));
					double y2 = Double.parseDouble(String.valueOf(chartData2.getYValue()));
					double y3 = y1 - y2;
					System.out.println(y3);
					if(y3>=1&&y3<2)
						toolTipString += "\nStart vein binding.";
				}*/
				Tooltip.install(stackPane, new Tooltip(toolTipString));
				
				//Text annotation=new Text();
				
			}
		}
		//find start point and stop point automatically
		double[]s1,s2,s3,s4,s5,s6,s7;
		s1=new double[(numOfRows-startRow+1)/index_interval];
		s2=new double[(numOfRows-startRow+1)/index_interval];
		s3=new double[(numOfRows-startRow+1)/index_interval];
		s4=new double[(numOfRows-startRow+1)/index_interval];
		s5=new double[(numOfRows-startRow+1)/index_interval];
		s6=new double[(numOfRows-startRow+1)/index_interval];
		s7=new double[(numOfRows-startRow+1)/index_interval];
	
		for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
		{
			s1[i]=deltaHHb1[i*index_interval];
			s2[i]=deltaO2Hb1[i*index_interval];
			s3[i]=deltaHHb2[i*index_interval];
			s4[i]=deltaO2Hb2[i*index_interval];
			s5[i]=deltaHHb3[i*index_interval];
			s6[i]=deltaO2Hb3[i*index_interval];
			s7[i]=100*TOI[i*index_interval];
		}
		double[][]s={s1,s2,s3,s4,s5,s6,s7};
		
		double prevSlope,nextSlope,slopeVariation,maxSlopeVariation[],startPointIndex[],minSlopeVariation[],stopPointIndex[];
		minSlopeVariation=new double[lineChart.getData().size()];
		stopPointIndex=new double[lineChart.getData().size()];
		maxSlopeVariation=new double[lineChart.getData().size()];
		startPointIndex=new double[lineChart.getData().size()];
		for (int i=0;i< s.length;i++) {
			//XYChart.Series<String, Double> series=(XYChart.Series<String, Double>)lineChart.getData().get(i);
			prevSlope=0;
			nextSlope=0;
			slopeVariation=0;
			//for all series, take date, each data has Node (symbol) for representing point
			final int slopeResolution=10;
			for (int j=slopeResolution;j< s1.length-slopeResolution;j++) {
				
				
				prevSlope=(s[i][j]-s[i][j-slopeResolution])/slopeResolution;
				nextSlope=(s[i][j+slopeResolution]-s[i][j])/slopeResolution;
				slopeVariation=nextSlope-prevSlope;
				if(slopeVariation>=maxSlopeVariation[i]&&nextSlope>1e-3&&prevSlope<4.5e-4&&prevSlope>-4.5e-4)
				{
					boolean flag=true;
					for(int k=j+2;k<j+slopeResolution;k+=2)
						if(s[i][j]>s[i][k])flag=false;
					if(flag){
						maxSlopeVariation[i]=slopeVariation;
						startPointIndex[i]=j;
					}
				}
				if(slopeVariation<=minSlopeVariation[i]&&nextSlope<-6e-3&&prevSlope>0)
				{
					boolean flag=true;
					for(int k=j+2;k<j+20;k+=2)
						if(s[i][j]<s[i][k])flag=false;
					if(flag){
						minSlopeVariation[i]=slopeVariation;
						stopPointIndex[i]=j;
					}
				}
				
				
			}
		}
		double startIndex=0,stopIndex=0;
		startIndex=averageOutArray(startPointIndex);
		stopIndex=averageOutArray(stopPointIndex);
		if(VCBox.isSelected()){
			Alert alert = new Alert(AlertType.INFORMATION);
			alert.setTitle("Information Dialog");
			alert.setHeaderText(null);
			alert.setContentText("Start index: "+(startIndex*50+9750)+"\nStop index: "+(9750+50*stopIndex));
			alert.showAndWait();
		}
	}
	@FXML
    private void SaveImgButtonPressed(ActionEvent e)
	{
		FileChooser fileChooser = new FileChooser();
		fileChooser.setTitle("Saving image");
		fileChooser.setInitialDirectory(new File("C:"+File.separator));
		fileChooser.setInitialFileName("*.png");
		File selectedDirectory = fileChooser.showSaveDialog(Main.getStage());
		if(selectedDirectory!=null) {
			try {
				final CategoryAxis newXAxis = new CategoryAxis();
				final NumberAxis newYAxis = new NumberAxis();
				final LineChart<String,Number> newChart = 
					new LineChart<String,Number>(newXAxis,newYAxis);
				newChart.setAnimated(false);
				
				XYChart.Series series1 = new XYChart.Series();
				series1.setName("HHb1");
				XYChart.Series series2 = new XYChart.Series();
				series2.setName("O2Hb1");
				XYChart.Series series3 = new XYChart.Series();
				series3.setName("HHb2");
				XYChart.Series series4 = new XYChart.Series();
				series4.setName("O2Hb2");
				XYChart.Series series5 = new XYChart.Series();
				series5.setName("HHb3");
				XYChart.Series series6 = new XYChart.Series();
				series6.setName("O2Hb3");
				XYChart.Series series7 = new XYChart.Series();
				series7.setName("TOI");
				
				XYChart.Series HHbfft1 = new XYChart.Series();
				HHbfft1.setName("fft of HHb1");
				XYChart.Series O2Hbfft1 = new XYChart.Series();
				O2Hbfft1.setName("fft of O2Hb1");
				
				XYChart.Series HHbfft2 = new XYChart.Series();
				HHbfft2.setName("fft of HHb2");
				XYChart.Series O2Hbfft2 = new XYChart.Series();
				O2Hbfft2.setName("fft of O2Hb2");
				
				XYChart.Series HHbfft3 = new XYChart.Series();
				HHbfft3.setName("fft of HHb3");
				XYChart.Series O2Hbfft3 = new XYChart.Series();
				O2Hbfft3.setName("fft of O2Hb3");
				//if(!lineChart.getData().isEmpty())
				//	lineChart.getData().remove((int)(lineChart.getData().size()-1));
				//menuItem handler
				
				int index_interval=50;
				if(HbBox1.isSelected())
					for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
						series1.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaHHb1[i*index_interval]));
				if(HbO2Box1.isSelected())
					for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
						series2.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaO2Hb1[i*index_interval]));
				if(HbBox2.isSelected())
					for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
						series3.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaHHb2[i*index_interval]));
				if(HbO2Box2.isSelected())
					for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
						series4.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaO2Hb2[i*index_interval]));	
				if(HbBox3.isSelected())
					for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
						series5.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaHHb3[i*index_interval]));
				if(HbO2Box3.isSelected())
					for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
						series6.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), deltaO2Hb3[i*index_interval]));	
				if(TOIBox.isSelected())
					for(int i=0;i<(numOfRows-startRow+1)/index_interval;i++)
						series7.getData().add(new XYChart.Data(Integer.toString((int)this.data[i*index_interval][0]), 100*TOI[i*index_interval]));
				
				/*for (int i=0;i< lineChart.getData().size();i++) {
					XYChart.Series<String, Double> series = (XYChart.Series<String, Double>)lineChart.getData().get(i);
					//for all series, take date, each data has Node (symbol) for representing point
					for (int j=0;j< series.getData().size();j++) {
						// this node is StackPane
						XYChart.Data<String, Double> chartData = (XYChart.Data<String, Double>)series.getData().get(j);
						StackPane stackPane =  (StackPane) chartData.getNode();
						String toolTipString=String.valueOf(chartData.getXValue())+", "+String.valueOf(chartData.getYValue());
						//System.out.println(String.valueOf(chartData.getXValue())+map.get(chartData.getXValue()))
						if(map.get(Integer.parseInt(chartData.getXValue()))!=null)
						{
							System.out.println(String.valueOf(chartData.getXValue())+map.get(Integer.parseInt(chartData.getXValue())));
							stackPane.setPrefWidth(15);
							stackPane.setPrefHeight(15);
							stackPane.setStyle("-fx-background-color: yellow, white;-fx-background-radius: 0;-fx-background-insets: 0, 2.5;-fx-padding: 7px 5px 7px 5px;-fx-shape: \"M5,0 L10,9 L5,18 L0,9 Z\";");
							toolTipString+="\n"+map.get(Integer.parseInt(chartData.getXValue()));
						}
						Tooltip.install(stackPane, new Tooltip(toolTipString));
						//Text annotation=new Text();
					}
				}*/
				
				newChart.getData().add(series1);
				newChart.getData().add(series2);
				newChart.getData().add(series3);
				newChart.getData().add(series4);
				newChart.getData().add(series5);
				newChart.getData().add(series6);
				newChart.getData().add(series7);
				
				Stage newStage = new Stage();
				Scene newScene = new Scene(newChart,(int)lineChart.getWidth(),(int)lineChart.getHeight());
				newScene.getStylesheets().add("sample.css");
				newStage.setScene(newScene);
				newStage.show();
				SnapshotParameters parameters = new SnapshotParameters();
				//storage image
				WritableImage wim = newChart.snapshot(new SnapshotParameters(),null);
				//WritableImage wim = new WritableImage((int) lineChart.getWidth(),(int) lineChart.getHeight());
				newScene.snapshot(wim);
				BufferedImage bufferedImage = SwingFXUtils.fromFXImage(wim, null);
				ImageIO.write(bufferedImage, "png", selectedDirectory);
				newStage.close();
			}
			catch(IOException ioevent) {
				throw new RuntimeException(ioevent);
			}
		}
	}
}
