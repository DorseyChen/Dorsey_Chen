//Model

public class MatrixOperation
{		
	public static Matrix transpose(Matrix matrix) throws Exception {
		Matrix transposedMatrix = new Matrix(matrix.getNcols(), matrix.getNrows());
		for (int i=0;i<matrix.getNrows();i++) {
			for (int j=0;j<matrix.getNcols();j++) {
				transposedMatrix.setValueAt(j, i, matrix.getValueAt(i, j));
			}
		}
		return transposedMatrix;
	}
	
	public static double determinant(Matrix matrix) throws Exception{
		if (!matrix.isSquare())
			throw new Exception("In determinant, matrix need to be square.");
		if (matrix.size() == 1) {
			return matrix.getValueAt(0, 0);
		}
		if (matrix.size()==2) {
			return (matrix.getValueAt(0, 0) * matrix.getValueAt(1, 1)) - ( matrix.getValueAt(0, 1) * matrix.getValueAt(1, 0));
		}
		double sum = 0.0;
		for (int i=0; i<matrix.getNcols(); i++) {
			sum += changeSign(i) * matrix.getValueAt(0, i) * determinant(createSubMatrix(matrix, 0, i));
		}
		return sum;
	}
	
	private static int changeSign(int i) //returns 1 if i is even and -1 otherwise. 
	{
		return (i%2==0)?1:-1;
	}
	
	public static Matrix createSubMatrix (Matrix matrix, int excluding_row, int excluding_col) throws Exception{
		Matrix mat = new Matrix(matrix.getNrows()-1, matrix.getNcols()-1);
		int r = -1;
		for (int i=0;i<matrix.getNrows();i++) {
			if (i==excluding_row)
				continue;
				r++;
				int c = -1;
			for (int j=0;j<matrix.getNcols();j++) {
				if (j==excluding_col)
					continue;
				try{
					mat.setValueAt(r, ++c, matrix.getValueAt(i, j));
				}
				catch(Exception e){
					throw new Exception("In createSubMatrix setValueAt statement",e);
				}
			}
		}
		return mat;
	} 
	
	public static Matrix cofactor(Matrix matrix) throws Exception {
		Matrix mat = new Matrix(matrix.getNrows(), matrix.getNcols());
		for (int i=0;i<matrix.getNrows();i++) {
			for (int j=0; j<matrix.getNcols();j++) {
				try{
					mat.setValueAt(i, j, changeSign(i) * changeSign(j) * 
								 determinant(createSubMatrix(matrix, i, j)));
				}
				catch(Exception e)
				{
					throw new Exception("In cofactor",e);
				}
			}
		}
		return mat;
	}
	public static void displayMatrix(Matrix m)
	{
		for(int i=0;i<m.getNrows();i++)
		{
			for(int j=0;j<m.getNcols();j++)
				try{
					System.out.print(String.valueOf(m.getValueAt(i,j))+" ");
				}
				catch(Exception exc)
				{
					System.out.print("--");
				}
			System.out.println("");
		}
	}
	public static Matrix inverse(Matrix matrix) throws Exception
	{
		try{
			return (transpose(cofactor(matrix)).multiplyByConstant(1.0/determinant(matrix)));
		}
		catch(Exception e)
		{
			throw new Exception("In inverse",e);
		}
	}
	
}