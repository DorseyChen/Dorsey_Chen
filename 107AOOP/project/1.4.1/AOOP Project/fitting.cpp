#include "fuction_processing.h"
#include"mainwindow.h"
#include"qcustomplot.h"
#include"QDebug"

fitting::fitting(unsigned basis_cnt,QStringList basis_list, string str,Ui::MainWindow*ui,type state)throw(const char*):graphics (str,ui,state),data_points(ui)
{
    try {
        getpoints();
    } catch (const char* s) {
        throw s;
    }
    qDebug()<<"fitting constructor";
    this->basis_cnt=basis_cnt;
    this->basis_list=basis_list;
    N=basis_cnt;
    A = new double *[pt_cnt];

    for(int i=0;i<pt_cnt;i++)//construct matrix A here
    {
        A[i] = new double[basis_cnt];
        for(int j=0;j<basis_cnt;j++)
        {
            s = this->basis_list.at(j).toStdString();
            if(ParenthesesChecking()==false)
            {
                char*exception=new char[50];
                if(j+1==1)
                    sprintf(exception,"Unbalanced parentheses at the 1st basis.");
                else if(j+1==2)
                    sprintf(exception,"Unbalanced parentheses at the 2nd basis.");
                else if(j+1==3)
                    sprintf(exception,"Unbalanced parentheses at the 3rd basis.");
                else
                    sprintf(exception,"Unbalanced parentheses at the %dth basis.",j+1);
                throw exception;
            }
            if(ParenthesesChecking()&&(s!=""))
            {
                MathFunctionReplace();
                AddMultiply();
                AddSpace();
                ExpReplace();

                InfixToPostfix();
                qDebug()<<"postfix:\n";
                qDebug()<<"s="<<returns()<<"\n";
                try {
                    FillMatrixA(pt[i].x(),i,j);
                } catch (const char*s1) {
                    qDebug()<<"At fitting()catch,s1="<<s1;
                    throw "incorrect input";
                }

            }
        }
    }
    display(A,pt_cnt,basis_cnt);
}

fitting::~fitting()
{
    qDebug()<<"fitting is destroyed\n";
}

void fitting::FillMatrixA(double x,int ptcnt, int basislist)throw(const char*)
{
    qDebug()<<"At fill matrix begin";
    string tmp=s;//the angular variables in tmp are to be replaced with real value.
    qDebug()<<s.c_str();
    for(int j=0;j<tmp.length();j++)
    {
        if(IsunknownOperand(tmp.at(j)))
        {
            if(x<0 )//replace the alphabetic variables with real angular values
            {
                string p = to_string(x);
                p.erase(0,1);
                p="0 "+p+"!";
                tmp.replace(j,1,p);
            }
            else
                tmp.replace(j,1,to_string(x));
        }
    }
    qDebug()<<"Af fill matrix middle";
    try {
        A[ptcnt][basislist]=EvaluatePostfix(tmp);
    } catch (const char*s1) {
        qDebug()<<"At fill matrix catch";
        throw s1;
    }
    qDebug()<<"At fill matrix end";
}

double fitting::calmatrix()throw(const char*)
{
    //new transpose of A
    double **At = new double *[basis_cnt];
    for(int i=0;i<basis_cnt;i++)
        At[i] = new double [pt_cnt];
    qDebug()<<"D1";
    //display(A,pt_cnt,basis_cnt);
    At = transpose(A, pt_cnt, basis_cnt);
    qDebug()<<"D2";

    //find the inverse of At and A for At
    double **inverseA,**ATA;
    inverseA=new double*[N];
    for(int i=0;i<N;i++)
        inverseA[i]=new double[N];
    ATA = mul(basis_cnt, pt_cnt, pt_cnt, basis_cnt, At, A);
    qDebug()<<"Before inversion,AT*A:";
    display(ATA,basis_cnt,basis_cnt);
    bool invertible=true;
    invertible= inverse(ATA, inverseA);
    if(pt_cnt<basis_cnt)throw"The number of basis elements cannot be less than the number of data points";
    else if(!invertible)throw"The basis cannot be linearly dependent";
    qDebug()<<"After inversion,(AT*A)^-1:";
    display(inverseA,basis_cnt,basis_cnt);

    double **Att;
    /*for(int i=0;i<basis_cnt;i++)
        Att[i] = new double [pt_cnt];*/
    Att = mul(basis_cnt, basis_cnt, basis_cnt, pt_cnt, inverseA, At);

    qDebug()<<"Att:";
    display(Att,basis_cnt,pt_cnt);

    //multiply b
    double **b = new double *[pt_cnt];
    for(int i=0;i<pt_cnt;i++)
    {
        b[i] = new double [1];
        b[i][0] = pt[i].y();
    }
    result = new double *[basis_cnt];
    for(int i=0;i<basis_cnt;i++)
        result[i] = new double [1];
    result = mul(basis_cnt, pt_cnt, pt_cnt, 1, Att, b);
    qDebug()<<"coefficient:";
    display(result,basis_cnt,1);
    QString fitting_function;
    for(int i=0;i<basis_cnt;i++)
    {
        QString s=QString::number(result[i][0]);
        for(int i=0;i<s.size();i++)
            if(s.at(i)=='e')
                s.replace(i,1,"*10^");
        if(basis_list.at(i).at(0)>='0'&&basis_list.at(i).at(0)<='9')
            fitting_function.append(s+"*"+basis_list.at(i));
        else
            fitting_function.append(s+basis_list.at(i));
        if(i!=basis_cnt-1)
            fitting_function.append("+");
    }
    s=fitting_function.toStdString();
    qDebug()<<"s="<<s.c_str();
}

double fitting::the_least_squared()
{
    double ans=0;
    double **square = new double *[basis_cnt];
    for(int i=0;i<basis_cnt;i++)
        square[i] = new double [1];
    square = mul(pt_cnt, basis_cnt, basis_cnt, 1, A, result);

    //-b
    double **b = new double *[pt_cnt];
    for(int i=0;i<pt_cnt;i++)
    {
        b[i] = new double [1];
        b[i][0] = pt[i].y();
    }
    for(int i=0;i<pt_cnt;i++)
    {
        square[i][0] -= b[i][0];
        cout<<"2"<<endl;
        ans += square[i][0]*square[i][0];
        cout<<"3"<<endl;
    }
    cout<<"4"<<endl;
    return ans;
}

// Function to get cofactor of A[p][q] in temp[][]. n is current
// dimension of A[][]
void fitting::getMinor(double**A, double**temp, int p, int q, int n)
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // Copying into temporary matrix only those element
            // which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/* Recursive function for finding determinant of matrix.
n is current dimension of A[][]. */
double fitting::determinant(double**A, int n)
{
    double D = 0; // Initialize result

    // Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];

    double**temp=new double*[N]; // To store cofactors
    for(int i=0;i<N;i++)
        temp[i]=new double[N];

    int sign = 1; // To store sign multiplier

    // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getMinor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}

// Function to get adjoint of A[N][N] in adj[N][N].
void fitting::adjoint(double**A,double**adj)
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }

    // temp is used to store cofactors of A[][]
    int sign = 1;
    double** temp=new double*[N];
    for(int i=0;i<N;i++)
        temp[i]=new double[N];

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            // Get cofactor of A[i][j]
            getMinor(A, temp, i, j, N);

            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;

            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}

// Function to calculate and store inverse, returns false if
// matrix is singular
bool fitting::inverse(double** A, double** inverse)
{
    // Find determinant of A[][]
    double det = determinant(A, N);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }

    // Find adjoint
    double** adj=new double*[N];
    for(int i=0;i<N;i++)
        adj[i]=new double[N];
    adjoint(A, adj);
    /*qDebug()<<"in inverse,adj:";
    display(adj,N,N);*/
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            inverse[i][j] = adj[i][j]/det;

    return true;
}

// Generic function to display the matrix. We use it to display
// both adjoin and inverse. adjoin is integer matrix and inverse
// is a float.
template<class T>
void fitting::display(T** A,int row,int col)
{
    QString dis;
    qDebug()<<"In display";
    for (int i=0; i<row; i++)
    {
        dis.clear();
        for (int j=0; j<col; j++)
            dis.append(QString::number( A[i][j] ) + " ");
        qDebug()<<dis.toStdString().c_str();
    }
}

double** fitting:: mul(int r1,int c1,int r2,int c2,double**p,double**q)
{
    if(c1!=r2)return NULL;
    double**s;
    int i,j,k;
    s=new double*[r1];
    for(i=0;i<r1;i++)
        s[i]=new double[c2];
    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            s[i][j]=0;
    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            for(k=0;k<c1;k++)
                s[i][j]+=p[i][k]*q[k][j];
    return s;
}

double** fitting::transpose(double**a,int r,int c)
{
    // Finding transpose of matrix a[][] and storing it in array trans[][].
    double**trans=new double*[c];
    qDebug()<<"D3";
    int i,j;
    for(i=0;i<c;++i)
    {
        trans[i]=new double[r];
    }
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            trans[j][i]=a[i][j];
        }

    return trans;
}
