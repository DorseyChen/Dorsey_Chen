/*File Fft02.java Copyright 2004, R.G.Baldwin
Rev 4/30/04

This program DOES NOT implement an FFT algorithm.
Rather, this program illustrates the underlying
FFT concepts in a form that is much more easily
understood than is normally the case with an
actual FFT algorithm.  The steps in the
implementation of a typical FFT algorithm are as
follows:

1. Decompose an N-point complex series into N
individual complex values, each consisting of a
single complex sample.  The order of the
decomposition in an FFT algorithm is rather
complicated.  It is this order of decomposition,
and the order of the subsequent recombination of
transform results that causes the FFT to be so
fast.  It is also that order that makes the
algorithm somewhat difficult to understand. This
program does not implement that order of
decomposition and recombination.

2. Calculate the transform of each of the N
complex samples, treating each as if it were
located at the beginning of the complex series.
This step is trivial.  The real part of the
transform of a single complex sample located at
the beginning of the series is a complex constant
whose values are proportional to the real and
imaginary values that make up the complex sample.

3. Correct each of the N transform results to
reflect the actual position of the complex sample
in the series.  This involves the application of
sine and cosine curves to the real and imaginary
parts of the transform. This step is usually
combined with the recombination step that
follows.

4. Recombine the N transform results into a
single transform result that represents the
transform of the original complex series.  This
is a very complicated operation in a real FFT
algorithm.  It must reverse the order of
decomposition in the first step described
earlier.  As mentioned earlier, it is the order
of the decomposition and subsequent recombination
that minimizes the arithmetic operations required
and gives the FFT its tremendous speed.  This
program does not implement the special order of
decomposition and recombination used in an actual
FFT algorithm.

This program creates three separate complex
series, applies the processes listed above to
each of those series, and displays the results on
the screen.  No attempt is made to manage the
decomposition and the subsequent recombination in
the manner of a true FFT algorithm.  Therefore,
this program is designed to illustrate the
processes involved, and is not designed to
provide the speed of a true FFT algorithm.

The decomposition process in this program takes
the complex samples in the order that they appear
in the input complex series.

The transform of each complex sample is simply
the sample itself.  This is the result that would
be obtained by actually computing the transform
of the complex sample if the sample were the
first sample in the series.

The transform result for each complex sample is
then corrected by applying sine and cosine curves
to reflect the actual position of the complex
sample within the complex series.

The real and imaginary parts of the corrected
transform results are then added to accumulators
that are used to accumulate the corrected real
and imaginary parts from the corrected
transforms for all of the individual complex
samples.

Once the real and imaginary parts have been
accumulated for all of the complex samples, the
real part of the accumulator represents the real
part of the transform of the original complex
series.  The imaginary part of the accumulator
represents the imaginary part of the transform of
the original complex series.

Tested using SDK 1.4.2 under WinXP
************************************************/


class Fft02{

  public static void main(String[] args){

    //Instantiate an object that will implement
    // the processes used in an FFT, but not in
    // the order required by an FFT algorithm.
    Transform transform = new Transform();

    //Prepare the input data and the output
    // arrays for Case A.  Note that for this
    // case, the input complex series contains
    // non-zero values only in the real part.
    // Also, most of the values in the real part
    // are zero.
    System.out.println("Case A");
    double[] realInA =
               {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    double[] imagInA =
               {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    double[] realOutA = new double[16];
    double[] imagOutA = new double[16];

    //Perform the transform and display the
    // transformed results for the original
    // complex series.
    transform.doIt(realInA,imagInA,1.0,realOutA,
                                       imagOutA);
    display(realOutA,imagOutA);


    //Process and display the results for Case B.
    // Note that the input complex series
    // contains non-zero values in both the real
    // and imaginary parts.  However, most of the
    // values in the real and imaginary parts are
    // zero.
    System.out.println("\nCase B");
    double[] realInB =
               {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    double[] imagInB =
             {0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,-1};

    double[] realOutB = new double[16];
    double[] imagOutB = new double[16];

    transform.doIt(realInB,imagInB,2.0,realOutB,
                                       imagOutB);
    display(realOutB,imagOutB);


    //Process and display the results for Case C.
    // Note that the input complex series
    // contains non-zero values in both the real
    // and imaginary parts.  In addition, very
    // few of the values in the complex series
    // have a value of zero.  (The values of the
    // complex samples actually describe a cosine
    // curve and a sine curve.)
    System.out.println("\nCase C");
    double[] realInC =
      {1.0,0.923,0.707,0.382,0.0,-0.382,-0.707,
          -0.923,-1.0,-0.923,-0.707,-0.382,0.0,
           0.382,0.707,0.923};
    double[] imagInC =
      {0.0,-0.382,-0.707,-0.923,-1.0,-0.923,
           -0.707,-0.382,0.0,0.382,0.707,0.923,
            1.0,0.923,0.707,0.382};

    double[] realOutC = new double[16];
    double[] imagOutC = new double[16];

    transform.doIt(realInC,imagInC,16.0,realOutC,
                                       imagOutC);
    display(realOutC,imagOutC);
	System.out.println("Zero Padding Test");
	double[]Test={1,3,5,7};
	Transform.zeroPadding(Test);

  }//end main
  //===========================================//

  //The purpose of this method is to display
  // a real series and an imaginary series,
  // each contained in an incoming array object
  // of type double.  The double values are
  // truncated to no more than four digits
  // before displaying them.  Then they are
  // displayed on a single line.
  public static void display(double[] real,
                      double[] imag){
    System.out.println("Real: ");
    for(int cnt=0;cnt < real.length;cnt++){
      System.out.print(((int)(1000.0*real[cnt]))
                                 /1000.0 + " ");
    }//end for loop
    System.out.println();

    System.out.println("imag: ");
    for(int cnt=0;cnt < imag.length;cnt++){
      System.out.print(((int)(1000.0*imag[cnt]))
                                 /1000.0 + " ");
    }//end for loop
    System.out.println();
  }//end display

}//end class Fft02
//=============================================//

