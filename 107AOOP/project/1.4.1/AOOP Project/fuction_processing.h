#ifndef FUCTION_PROCESSING_H
#define FUCTION_PROCESSING_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include<iostream>
#include<stack>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<utility>
#include<map>
#include<QObject>

const double PI = 3.14159265358979323846;
using namespace std;
class input_processing  //for function
{        
    public:
        //unused members
        enum type{standard,polar,parameter};

        //polar functions
        typedef map<long double,long double>  pts;
        pts x_y;

        //constructor and destructor
        input_processing();

        input_processing(string str,Ui::MainWindow*ui,type state=standard);
        virtual ~input_processing();

        //function members
        //check if the type of open symbol match with the close symbol
        bool ParenthesesMatch(char open,char close);
        // Function to convert Infix expression to postfix
        void InfixToPostfix();
        // Function to verify whether an operator has higher precedence over other
        int HasHigherPrecedence(char operator1, char operator2);
        // Function to verify whether a character is operator symbol or not
        bool IsOperator(char C);
        //Function to replace math functions symbols
        void MathFunctionReplace();
        // Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
        bool IsOperand(char C);
        bool IsknownOperand(char C);
        bool IsunknownOperand(char C);
        //add Decimal for calculating
        void AddMultiply();
        //add space between each operand
        void AddSpace();
        //check whether the parentheses are balanced
        bool ParenthesesChecking();
        //other functions
        int IsRightAssociative(char);
        int GetOperatorWeight(char);
        void ExpReplace();
        //for Debug
        QString returns();
        QString returnOrgs();
        bool error();
        //eliminate all the white space in the initial input
        void RemoveSpaces();

        //determine whether a character is a white space
        bool IsWhiteSpace(char c);

        bool IsUnaryPlus(size_t pos,const string& p);

        bool IsUnaryMinus(size_t pos,const string& p);

        Ui::MainWindow*& get_ui();

        void SetPolarRange(double start , double end );
        void setS(string);
        static void ResetInput();
        void SetParameterRange(double start,double end);
    protected:
        //function
        void SetState(type);
        static int PolarCnt;
        static int ParameterCnt;
        static int StandardCnt;
        static int TotalCnt;
        int id;
        type state;
        double StartAngle;//for polar;in the unit of pi
        double EndAngle;//for polar;in the unit of pi
        double StartParameter;
        double EndParameter;
        string s;
        string cal;
        string org_s;
        //unused members
        bool input_error;
        Ui::MainWindow* ui;
};

class calculation: public input_processing
{
    public:
        calculation();
        calculation(string str,Ui::MainWindow*ui,type state=standard);
        virtual ~calculation();

        //compute the result of a single expression
        long double Compute(char Operator,long double operand1,long double operand2);

        //calculate the value of the expression
        long double EvaluatePostfix(string) throw(const char*);
        //generate points in cartesian coordinate based on polar equations
        void GenerateXY_Polar() throw(const char*);
        void GenerateXY_Standard()throw(const char*);
        void GenerateXY_Parameter(calculation)throw(const char*);
        void GenerateXY_Fitting()throw(const char*);
};

class graphics:virtual public calculation,public QObject   //use qcustomplots
{
    public:
        graphics();
        graphics(string str,Ui::MainWindow*ui,type state=standard);
        void draw();
        void save_picture();
        virtual ~graphics();

    protected:
        QPixmap *pixmap;
        QPainter *painter;

};

class data_points
{
    protected:
        QPixmap *pixmap;
        QPainter *painter;
        Ui::MainWindow*data_points_ui;
        bool input_error;
        QPointF*pt;
        unsigned int pt_cnt;
    public:
        data_points();
        data_points(Ui::MainWindow*ui);
        void getpoints() throw(const char*);
        void drawpts();
        virtual ~data_points();

};

class fitting:public data_points,public graphics
{
    private:
        unsigned basis_cnt;
        QStringList basis_list;
        double **result;
        double **A;//row=pt_cnt, column=basis_cnt
        unsigned N;
    public:
        fitting(unsigned basis_cnt,QStringList basis_list, string str,Ui::MainWindow*ui,type state=standard)throw(const char*);
        void getMinor(double**A, double**temp, int p, int q, int n);
        double determinant(double**A, int n);
        void adjoint(double**A,double**adj);
        bool inverse(double** A, double** inverse);
        template<class T>
        void display(T** A,int row,int col);
        double** transpose(double**,int r,int c);
        double** mul(int r1,int c1,int r2,int c2,double**p,double**q);
        void FillMatrixA(double x, int, int)throw(const char*);
        double calmatrix()throw(const char*);
        double the_least_squared();

        virtual ~fitting();
};


#endif // FUCTION_PROCESSING_H
