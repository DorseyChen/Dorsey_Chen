#include"fuction_processing.h"
#include"mainwindow.h"
#include"qcustomplot.h"
#include<typeinfo>
using namespace std;
//typedef map<long double,long double>  pts;
calculation::calculation(string str,Ui::MainWindow*ui,type state):input_processing(str,ui,state)
{
}

calculation::calculation()
{
    cout<<"calculation() is called\n";
}

long double calculation::EvaluatePostfix(string postfix) throw(const char*)
{
    string::size_type OperandHead,OperandTail;
    char CurrentOperator;
    stack<long double> operands;
    long double result;
    const char* exception;
    for(int i = 0;i< postfix.length();i++)
    {
        if(IsWhiteSpace(postfix[i]) )
            continue;
        // operandscanning each character from left.

        // If character is operator, pop two elements from stack, perform operation and push the result back.
        if(IsOperator(postfix[i]))
        {
            // Pop two operands.
            long double operand1;
            long double operand2;
            if(operands.empty())
            {
                input_error=true;
                throw "incorrect input";
            }
            else
                operand2 = operands.top(); operands.pop();
            if(operands.empty())
            {
                input_error=true;
                throw "incorrect input";
            }
            else
                operand1 = operands.top(); operands.pop();
            // Perform operation
            long double result = Compute(postfix[i], operand1, operand2);
            //Push back result of operation on stack.
            operands.push(result);
        }
        else if(IsOperand(postfix[i]))
        {
            string Operand;
            OperandHead=i;
            for(int j=OperandHead;j<postfix.length();j++)
            {
                if(!IsOperand(postfix[j]))
                {
                    OperandTail=j-1;
                    break;
                }
            }
            /*qDebug()<<"postfix:"<<postfix.c_str()<<endl;
            qDebug()<<"OperandHead:"<<postfix[OperandHead]<<endl;
            qDebug()<<"OperandTail:"<<postfix[OperandTail]<<endl;*/
            Operand=postfix.substr(OperandHead,OperandTail-OperandHead+1);
            i=OperandTail;

            // Push operand on stack.
            long double p;
            try {

                p=stold(Operand);


            } catch (std::exception& e) {
                qDebug()<<"Operand:\n"<<Operand.c_str()<<endl;
                input_error=true;
                throw e.what();
                qDebug()<<"D\n";


            }
            catch(...){
                input_error=true;
                qDebug()<<"E\n";
                throw "unknown error\n";
            }

            operands.push(p);

        }


    }

    // If postfix is in correct format, Stack will finally have one element. This will be the output.
    if(operands.size()!=1)
    {
        cout<<"wrong postfix in 'EvaluatePostfix'\n";
        input_error=true;
        exception="In EvaluatePostfix :error input";

        throw exception;
    }
    return (operands.top());
}

void calculation::GenerateXY_Polar()throw(const char*)
{
    pts theta_r;//to store poitns of the polar equation under polar coordinates (theta,r) .
    pts::iterator ptsItr;
    string tmp=s;//the angular variables in tmp are to be replaced with real value.
    x_y.clear();
    qDebug()<<"In GenerateXY_Polar";
    qDebug()<<"start angle="<<StartAngle<<endl;
    qDebug()<<"end angle="<<EndAngle<<endl;
    for(long double i=StartAngle*PI;i<=EndAngle*PI;i+=0.001)
    {
            for(int j=0;j<tmp.length();j++)
            {
                if(IsunknownOperand(tmp.at(j)) )//replace the alphabetic variables with real angular values
                {
                    if(i<0)
                    {
                        string p(to_string(i));
                        p.erase(0,1);
                        p="0 "+p+"!";
                        tmp.replace(j,1,p);
                    }
                    else
                        tmp.replace(j,1,to_string(i));
                    //cout<<tmp<<endl;
                }
            }
            long double value;
            try{
                value=EvaluatePostfix(tmp);
            }
            catch(const char* exception)
            {
                qDebug()<<"In GenerateXY_Polar:\n";
                qDebug()<<exception<<endl;
                throw;
            }
            theta_r.insert(make_pair(i,value));
            tmp=s;
    }
    for(ptsItr=theta_r.begin();ptsItr!=theta_r.end();ptsItr++)
    {
        long double theta=ptsItr->first;
        long double radius=ptsItr->second;
        x_y.insert(make_pair(radius*cos(theta),radius*sin(theta)));
    }
}

void calculation::GenerateXY_Standard()throw(const char*)
{
    pts points;
    pts::iterator ptsItr;
    string tmp=s;//the angular variables in tmp are to be replaced with real value.
    x_y.clear();
    bool ok=true;
    double Xstart=ui->XstartlineEdit->text().toInt(&ok);
    double Xend=ui->XendlineEdit->text().toInt(&ok);
    if(!ok)
    {
        Xstart=0;
        Xend=10;
    }

    for(long double i=Xstart;i<=Xend;i+=0.001)
    {
            for(int j=0;j<tmp.length();j++)
            {
                if(IsunknownOperand(tmp.at(j)))
                {
                    if(i<0 )//replace the alphabetic variables with real angular values
                    {
                        string p(to_string(i));
                        p.erase(0,1);
                        p="0 "+p+"!";
                        tmp.replace(j,1,p);
                    }
                    else
                        tmp.replace(j,1,to_string(i));
                }
            }
            long double value;
            try {
                value=EvaluatePostfix(tmp);
            } catch (const char*s) {
                throw;
            }

            //qDebug()<<"C\n";
            x_y.insert(make_pair(i,value));
            tmp=s;
    }

    qDebug()<<"In GenerateXY_Standard end\n";
}

void calculation::GenerateXY_Parameter(calculation y)throw(const char*)
{
    pts points;
    pts::iterator ptsItr;
    string tmp1;//the angular variables in tmp are to be replaced with real value.
    string tmp2;
    x_y.clear();
    double Tstart=StartParameter;
    double Tend=EndParameter;
    for(long double i=Tstart;i<=Tend;i+=0.001)
    {
            tmp1=s;

            for(int j=0;j<tmp1.length();j++)
            {
                if(IsunknownOperand(tmp1.at(j)))
                {
                    if(i<0 )//replace the alphabetic variables with real angular values
                    {
                        string p(to_string(i));
                        p.erase(0,1);
                        p="0 "+p+"!";
                        tmp1.replace(j,1,p);
                    }
                    else
                        tmp1.replace(j,1,to_string(i));
                }
            }

            tmp2=y.s;

            for(int j=0;j<tmp2.length();j++)
            {
                if(IsunknownOperand(tmp2.at(j)) )//replace the alphabetic variables with real angular values
                {
                    if(i<0 )//replace the alphabetic variables with real angular values
                    {
                        string p(to_string(i));
                        p.erase(0,1);
                        p="0 "+p+"!";
                        tmp2.replace(j,1,p);
                    }
                    else
                        tmp2.replace(j,1,to_string(i));
                }

            }
            long double value1,value2;
            try {
                value1=EvaluatePostfix(tmp1);
                value2=EvaluatePostfix(tmp2);
            } catch (const char* exception) {
                qDebug()<<"In GenerateXY_Parameter:\n";
                qDebug()<<exception<<endl;
                throw;
            }

            x_y.insert(make_pair(value1,value2));
    }

}

long double calculation::Compute(char Operator,long double operand1,long double operand2)
{
    long double result;

    switch(Operator)
    {
        case '+':
            result=operand1+operand2;
            break;
        case '-':
            result=operand1-operand2;
            break;
        case '*':
            result=operand1*operand2;
            break;
        case '/':
            result=operand1/operand2;
            break;
        case '^':
            result=pow(operand1,operand2);
            break;
        case '~':
            result=sin(operand2);
            break;
        case '@':
            result=cos(operand2);
            break;
        case '#':
            result=tan(operand2);
            break;
        case '$':
            result=1./sin(operand2);
            break;
        case '%':
            result=1./cos(operand2);
            break;
        case '&':
            result=1./tan(operand2);
            break;
        case '|':
            result=log(operand2);
            break;
        case '!':
            result=-operand2;
            break;
    }
    return result;
}

calculation::~calculation()
{
    cout<<"\ncalculation is destroyed.\n";
}

void calculation::GenerateXY_Fitting()throw(const char*)
{
    pts points;
    pts::iterator ptsItr;
    string tmp=s;//the angular variables in tmp are to be replaced with real value.

    x_y.clear();

    bool ok1=true;
    bool ok2=true;
    int Xstart=ui->fitting_leftx->text().toInt(&ok1);
    //qDebug()<<Xstart;
    int Xend=ui->fitting_rightx->text().toInt(&ok2);
    qDebug()<<"A\n";
    if(!ok1||!ok2)
    {
        Xstart=0;
        Xend=10;
    }

    for(long double i=Xstart;i<=Xend;i+=0.001)
    {
            for(int j=0;j<tmp.length();j++)
            {
                if(IsunknownOperand(tmp.at(j)))
                {
                    if(i<0 )//replace the alphabetic variables with real angular values
                    {
                        string p(to_string(i));
                        p.erase(0,1);
                        p="0 "+p+"!";
                        tmp.replace(j,1,p);
                    }
                    else
                        tmp.replace(j,1,to_string(i));
                }
            }

            long double value;
            try {
                value=EvaluatePostfix(tmp);
            } catch (const char*s) {
                throw;
            }

            //qDebug()<<"C\n";
            x_y.insert(make_pair(i,value));
            tmp=s;
    }

    qDebug()<<"In GenerateXY_Fitting end\n";
}
