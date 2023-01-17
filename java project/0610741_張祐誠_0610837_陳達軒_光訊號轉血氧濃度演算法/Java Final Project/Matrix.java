
public class Matrix implements Cloneable{
		private int nrows;
		private int ncols;
		private double[][] data;

		@Override
		protected Object clone()throws CloneNotSupportedException//use deep copy
		{
			Matrix copyMatrix=(Matrix)super.clone();
			copyMatrix.data=new double[this.nrows][this.ncols];
			for(int i=0;i<this.nrows;i++)
				for(int j=0;j<this.ncols;j++)
				{
					copyMatrix.data[i][j]=this.data[i][j];
				}
			return copyMatrix;
		}
		
		public Matrix multiplyByConstant(double scale)throws Exception
		{
			Matrix scaledMatrix;
			try{
				scaledMatrix=(Matrix)this.clone();//overridden version of clone
			}
			catch(CloneNotSupportedException ce)
			{
				throw new Exception("In multiplyByConstant",ce);
			}
			
			for(int i=0;i<nrows;i++)
				for(int j=0;j<ncols;j++)
				{
					scaledMatrix.data[i][j]*=scale;
				}
			return scaledMatrix;
		}
		public Matrix multiply(Matrix other) throws Exception
		{
			if(this.ncols!=other.nrows)
				throw new Exception("illegal multiplication");
			Matrix result=new Matrix(this.nrows,other.ncols);
			double product;
			for(int i=0;i<this.nrows;i++)
			{
				for(int j=0;j<other.ncols;j++)
				{
					product=0;
					for(int k=0;k<this.ncols;k++)
					{
						product+=this.data[i][k]*other.data[k][j];
					}
					result.setValueAt(i,j,product);
				}
		
			}
			return result;
		}
		public Matrix(double[][] dat) {
			this.data = dat;
			this.nrows = dat.length;
			this.ncols = dat[0].length;
		}

		public Matrix(int nrow, int ncol) {
			this.nrows = nrow;
			this.ncols = ncol;
			data = new double[nrow][ncol];
		}
		
		public void setData(double d[][])throws Exception
		{
			if(d.length!=nrows)
				throw new Exception("In setData, mismatched row number");
			for(int i=0;i<d.length;i++)
				if(d[i].length!=ncols)
					throw new Exception("In setData,mismatched column number");
			for(int i=0;i<d.length;i++)
				for(int j=0;j<d[i].length;j++)
					data[i][j]=d[i][j];
		}
		
		public void setValueAt(int a,int b,double value) throws Exception
		{
			try{
				this.data[a][b]=value;
			}
			catch(ArrayIndexOutOfBoundsException ae){
				throw new Exception("In setValueAt, ArrayIndexOutOfBoundsException",ae);
			}
		}
		
		public double getValueAt(int a,int b) throws Exception
		{
			double v;
			try{
				v=data[a][b];
				return v;
			}
			catch(ArrayIndexOutOfBoundsException ae){
				throw new Exception("In getValueAt, ArrayIndexOutOfBoundsException",ae);
			}
		}
		
		public int getNrows()
		{
			return nrows;
		}
		
		public int getNcols()
		{
			return ncols;
		}
		
		public int size()//return number of rows times number of columns
		{
			return this.nrows*this.ncols;
		}
		
		public boolean isSquare()
		{
			return this.nrows==this.ncols;
		}
	}