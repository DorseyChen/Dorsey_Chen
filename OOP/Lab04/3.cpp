#include <stdio.h>

class Matrix {
    private:
        int row,col;
        int** content;
        
    public:
    	// Create a n x m Matrix as a dynamic array
    	// Initalize the Matrix as a zero matrix
        Matrix(int n,int m);
        
        // Give a value to each entry of the matrix with a series of numbers
        void input(int M[]);
        
        // Display the matrix on the screen
        void display();
        
        // Return its transposed matrix
        Matrix transpose();
        
        // Return the product of two Matrices
        Matrix operator*(const Matrix&);
};

int main(){
	
	// Sample Data
	int M1[] = {1,5,9,2,6,10,3,7,11,4,8,12};
	int M2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	
    Matrix m1(4,3), m2(4,5);
    m1.input(M1);
    m2.input(M2);
    
    puts("Matrix 1:");
    m1.display();
    puts("Matrix 1 Transpose:");
    m1.transpose().display();
    puts("Matrix 2:");
    m2.display();
    puts("Inner Product:");
    (m1.transpose()*m2).display();
    
    return 0;
}

Matrix::Matrix(int n, int m) {
    // Write here
	row=n;
	col=m;
	int i,j;
	 content=new int *[row];
	     for(i=0;i<row;i++)
			content[i]=new int [col];
		 for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				 content[i][j]=0;
}

void Matrix::input(int M[]) {
	// Write here
	int i,j,t=0;
    for(i=0;i<row;i++)
		for(j=0;j<col;j++){
			content[i][j]=M[t];
			t++;
		}
}

void Matrix::display() {
    for(int i=0; i<row ;i++){
        printf("| ");
        for( int j=0; j<col ;j++){
            printf("%4d ",content[i][j]);
        }
        printf("|\n");
    }
}

Matrix Matrix::operator*(const Matrix& tar) {
    // Write here.
	int i,j;
	Matrix x(row,tar.col);
	for(i=0;i<row;i++)
		for(j=0;j<tar.col;j++)
			for(int k=0;k<col;k++)
				x.content[i][j]+=content[i][k]*tar.content[k][j];
	return x;
}

Matrix Matrix::transpose() {
    // Write here.
	int i,j;
	Matrix x(col,row);
	x.content=new int *[col];
	for(i=0;i<col;i++)
		x.content[i]=new int [row];
	for(i=0;i<col;i++)
		for(j=0;j<row;j++)
			x.content[i][j]=content[j][i];
	return x;
}

