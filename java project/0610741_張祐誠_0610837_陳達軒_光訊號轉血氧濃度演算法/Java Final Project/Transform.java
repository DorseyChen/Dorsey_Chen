//This class applies the processes normally used
// in an FFT algorithm.  However, this class does
// not apply those processes in the special order
// required of an FFT algorithm.  It is that
// special order that minimizes the arithmetic
// requirements of an FFT algorithm and causes it
// to be very fast.  The purpose of an object of
// this class is to illustrate the processes in a
// more easily understood fashion that is often
// the case with an actual FFT algorithm.
class Transform{

  public static double[] zeroPadding(double[]array)
  {
	  double[]result;
	  int l=array.length-1;
	  int pow=1;
	  while(l>0)
	  {
		  pow=pow<<1;
		  l/=2;
	  }
	  result=new double[pow];
	  for(int i=0;i<array.length;i++)
	  {
		  result[i]=array[i];  
	  }
	  for(int i=0;i<result.length;i++)
	  {
		  System.out.print(""+result[i]+" "); 
	  }
	  
	  System.out.println("");
	  return result;
  }
  void doIt(double[] realIn,double[] imagIn,
            double scale,double[] realOut,
            double[] imagOut){
    //Each complex value in the incoming arrays
    // represents both a complex sample and the
    // transform of that complex sample under the
    // assumption that the complex sample appears
    // at the beginning of the series.
    //Correct the transform result for each of
    // the complex samples in the series to
    // reflect the actual position of the complex
    // sample in the series.  Add the corrected
    // transform result into accumulators in
    // order to produce the transform of the
    // original complex series.
    for(int cnt = 0;cnt < realIn.length;cnt++){
      correctAndRecombine(realIn[cnt],
                          imagIn[cnt],
                          cnt,
                          realIn.length,
                          scale,
                          realOut,
                          imagOut);
    }//end for loop
  }//end doIt

  //===========================================//

  //This method accepts an incoming complex
  // sample value and the position in the series
  // associated with that sample. The method
  // calculates the real and imaginary transform
  // values associated with that complex sample
  // when it is located at the specified
  // position.  Then it updates the corresponding
  // real and imaginary values contained in array
  // objects used to accumulate the real and
  // imaginary values for all of the samples.
  // References to the array objects are received
  // as input parameters. Outgoing results are
  // scaled by an incoming parameter in an
  // attempt to cause the output values to fall
  // within a reasonable range in case someone
  // wants to plot them.
  void correctAndRecombine(
            double realSample,double imagSample,
            int position,int length,double scale,
            double[] realOut,double[] imagOut){
    //Calculate the complex transform values for
    // each sample in the complex output series.
    for(int cnt = 0; cnt < length; cnt++){
      double angle =
               (2.0*Math.PI*cnt/length)*position;
      //Calculate output based on real input
      realOut[cnt] +=
                realSample*Math.cos(angle)/scale;
      imagOut[cnt] +=
                realSample*Math.sin(angle)/scale;

      //Calculate output based on imag input
      realOut[cnt] -=
                imagSample*Math.sin(angle)/scale;
      imagOut[cnt] +=
                imagSample*Math.cos(angle)/scale;
    }//end for loop
  }//end correctAndRecombine

}//end class transform

//=============================================//