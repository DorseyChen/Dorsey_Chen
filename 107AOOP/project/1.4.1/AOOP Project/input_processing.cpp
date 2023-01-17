#include"fuction_processing.h"
#include"mainwindow.h"
#include"qcustomplot.h"
//test:3(e^cos(3x+5))ln(x)/e^x
//test:3cos(3x+5)ln(x)
//test:0.0347594 *x *2.71828183 ^x +1.90551 *1
//test:(10^-1)xe^x
//test:(10^-2)xe^x
const char*Exp=" 2.71828183 ";
const size_t Exp_Len=10;
int input_processing::PolarCnt=0;
int input_processing::ParameterCnt=0;
int input_processing::StandardCnt=0;
int input_processing::TotalCnt=0;

void input_processing::setS(string t)
{
    s=t;
}

void input_processing::SetParameterRange(double start,double end)
{
    StartParameter=start;
    EndParameter=end;
}

void input_processing::SetPolarRange(double start,double end)
{
    StartAngle=start;
    EndAngle=end;
}

void input_processing::ResetInput()
{
    PolarCnt=0;
    ParameterCnt=0;
    StandardCnt=0;
    TotalCnt=0;
}

void input_processing:: SetState(input_processing::type tp)
{
    state=tp;
    if(tp==polar)
        PolarCnt++;
    else if(tp==parameter)
        ParameterCnt++;
    else if(tp==standard)
        StandardCnt++;

}

Ui::MainWindow*& input_processing::get_ui()
{
    return ui;
}

input_processing::input_processing()
{
    cout<<"input_processing() is called\n";
    input_error=false;
    org_s=s;
}



input_processing::input_processing(string str,Ui::MainWindow*ui,type state)
{
    s=str;
    SetState(state);
    org_s=s;
    this->ui=ui;
    input_error=false;
    if(str.empty())
        input_error=true;
    id=TotalCnt;
    TotalCnt++;
    //qDebug()<<"id in constructor:"<<id<<endl;
}

input_processing::~input_processing()
{
    cout<<"\ninput_processing is destroyed.\n";
    if(state==polar)
        PolarCnt--;
    if(state==parameter)
        ParameterCnt--;
    else if(state==standard)
        StandardCnt--;
}
bool input_processing::error()
{
    return input_error;
}

QString input_processing::returns(){
    QString qs=QString::fromStdString(s);
    return qs;
}

bool input_processing::ParenthesesChecking()
{
    string p;
    bool adjoinOperator=false;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('||s[i]==')'||s[i]=='['||s[i]==']'||s[i]=='{'||s[i]=='}')
            p+=s[i];
    }
    cout<<p<<endl;
    stack<char> S;
    for(int i=0;i<p.length();i++)
    {
        if(p[i]=='('||p[i]=='['||p[i]=='{')
            S.push(p[i]);
        else if(p[i]==')'||p[i]==']'||p[i]=='}')
        {
            if(S.empty())
                return false;
            else if(!ParenthesesMatch(S.top(),p[i]))
                return false;
            else
                S.pop();
        }
    }
    if(!S.empty())
    {
        return false;
        input_error=true;
    }
    return true;
}

bool input_processing::ParenthesesMatch(char open,char close)
{
    bool match=false;
    switch(open)
    {
        case '(':
            match=(close==')');
        break;
        case '[':
            match=(close==']');
            break;
        case '{':
            match=(close=='}');
            break;
        default:
            cout<<"wrong open symbol\n";
    }
    return match;
}

void input_processing::MathFunctionReplace(){
    string::size_type pos,len;
    if(s.empty())
        return;
    s.append("   ");
    len=s.length();
    qDebug()<<"In mathfunctionreplace begin\n";
    for(pos=0;pos<len-3;pos++)
    {
        if((s[pos]=='s')&&(s[pos+1]=='i')&&(s[pos+2]=='n'))
            s.replace(pos,3," 0~ ");//spaces at begin and end is necessary
        if((s[pos]=='c')&&(s[pos+1]=='o')&&(s[pos+2]=='s'))
            s.replace(pos,3," 0@ ");
        if((s[pos]=='t')&&(s[pos+1]=='a')&&(s[pos+2]=='n'))
            s.replace(pos,3," 0# ");
        if((s[pos]=='c')&&(s[pos+1]=='s')&&(s[pos+2]=='c'))
            s.replace(pos,3," 0$ ");
        if((s[pos]=='s')&&(s[pos+1]=='e')&&(s[pos+2]=='c'))
            s.replace(pos,3," 0% ");
        if((s[pos]=='c')&&(s[pos+1]=='o')&&(s[pos+2]=='t'))
            s.replace(pos,3," 0& ");
        if((s[pos]=='l')&&(s[pos+1]=='n'))
            s.replace(pos,2," 0| ");
        if(IsUnaryPlus(pos,s))
            s.erase(pos,1);
        if(IsUnaryMinus(pos,s))
            s.replace(pos,1," 0! ");

    }
    ExpReplace();
    qDebug()<<"In mathfunctionreplace end"<<endl;
}
bool input_processing::IsWhiteSpace(char c)
{
    if(c==' '||c=='\n'||c=='\t')
        return true;
    return false;
}
void input_processing::RemoveSpaces()
{
    string res;
    int n=0;
    if(s.empty())return;
    for(int i=0;i<s.length();i++)
    {

        if(!IsWhiteSpace(s[i]))
            res.append(1,s[i]);

    }

    s=res;
}
bool input_processing::IsUnaryPlus(size_t pos,const string& p)
{
    string s=p;
    size_t prev=-1;//prev : previous operator or parenthesis
    for(int i=pos-1;i>=0;i--)
        if(IsOperator(s[i])||s[i]=='('||s[i]=='['||s[i]=='{'||IsOperand(s[i]))
        {
            prev=i;
            break;
        }

    //RemoveSpaces(s);
    if(s[pos]!='+')
        return false;
    else if(prev==-1)//'+' at the head
        return true;
    else if(IsOperator(s[prev]) )
        return true;
    else if(s[prev]=='('||s[prev]=='['||s[prev]=='{')
        return true;
    return false;
}
bool input_processing:: IsUnaryMinus(size_t pos,const string& p)
{
    string s=p;
    size_t prev=-1;//prev : previous non-whitespace character
    for(int i=pos-1;i>=0;i--)
        if(IsOperator(s[i])||s[i]=='('||s[i]=='['||s[i]=='{'||IsOperand(s[i]))
        {
            prev=i;
            break;
        }

    //RemoveSpaces(s);
    if(s[pos]!='-')
        return false;
    else if(prev==-1)//'+' at the head
        return true;
    else if(IsOperator(s[prev]) )
        return true;
    else if(s[prev]=='('||s[prev]=='['||s[prev]=='{')
        return true;
    return false;
}

void input_processing::AddMultiply()
{
    string::size_type pos,len;
    int prev=0,next;
    len=s.length();
    for(pos=1;pos<len;pos++)
    {
        for (prev=pos-1;prev>=0;prev--) {
            if( !IsWhiteSpace( s[prev]) )
                break;
        }
        for (next=pos+1;next<s.length();next++)
            if( !IsWhiteSpace( s[next]) )
                break;
        if(prev==-1)
            continue;
        qDebug()<<"prev="<<s[prev]<<"pos"<<s.at(pos);
        if(s[pos]=='2'&&s.substr(pos,Exp_Len)=="2.71828183"&&IsOperand(s[prev]))
        {
            qDebug()<<"type1";
            s.insert(pos,1,'*');
            pos++;
            len++;
        }
        else if(s[pos]=='0'&&next<s.length())
        {
            if(GetOperatorWeight(s[next])==4&&IsOperand(s[prev]))
            {
                qDebug()<<"type2";
                s.insert(pos,1,'*');
                pos++;
                len++;

            }

        }
        else if(IsknownOperand(s[prev])&&IsunknownOperand(s[pos]))
        {
            qDebug()<<"type3";
            s.insert(pos,1,'*');
            pos++;
            len++;
        }
        else if(IsunknownOperand(s[prev])&&IsknownOperand(s[pos]))
        {
            qDebug()<<"type4";
            s.insert(pos,1,'*');
            pos++;
            len++;
        }
        if(IsOperand(s[prev])&&(s[pos]=='('||s[pos]=='['||s[pos]=='{'))
        {
            qDebug()<<"typed5";
            s.insert(pos,1,'*');
            pos++;
            len++;
        }
        else if(IsOperand(s[pos])&&(s[prev]==')'||s[prev]==']'||s[prev]=='}'))
        {
            qDebug()<<"type6";
            s.insert(pos,1,'*');
            pos++;
            len++;
        }
        /*
        else if(IsOperand(s[prev])&& (IsOperator(s[pos])))
        {
            if(s[prev]!='0'||GetOperatorWeight(s[pos])!=4 )//0@ or 0#
            {
                if(GetOperatorWeight(s[pos])==4)
                {
                    s.insert(pos,1,'*');
                    pos++;
                    len++;
                }
            }
        }
        */
    }
}

void input_processing::AddSpace()
{
    string::size_type pos,prev,len;
    prev=0;
    len=s.length();
    for(pos=1;pos<len;pos++)
    {
        prev=pos-1;
        if(IsOperand(s[prev])&&(IsOperator(s[pos])||s[pos]==')'||s[pos]==']'||s[pos]=='}'))
        {
            s.insert(pos,1,' ');
            pos++;
            len++;
        }
    }
}

void input_processing::ExpReplace()
{
    string::size_type pos=0;
    while((pos=s.find_first_of('e',pos))!=string::npos)
    {
        s.replace(pos,1, Exp);
        pos+=9;
    }
}

// Function to evaluate Postfix expression and return output
void input_processing::InfixToPostfix()
{
    // Declaring a Stack from Standard template library in C++.
    stack<char> S;
    string postfix = ""; // Initialize postfix as empty string.
    for(int i = 0;i< s.length();i++) {

        // Scanning each character from left.
        // If character is a delimitter, move on.
        if(s[i] == ' ' || s[i] == ',') postfix+=" ";

        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(s[i]))
        {
            while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),s[i]))
            {
                postfix+= S.top();
                S.pop();
            }
            S.push(s[i]);
        }
        // Else if character is an operand
        else if(IsOperand(s[i]))
        {
            postfix +=s[i];
        }

        else if (s[i] == '('||s[i]=='['||s[i]=='{')
        {
            S.push(s[i]);
        }

        else if(s[i] == ')')
        {
            while(!S.empty() && S.top() !=  '(') {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
        else if(s[i] == ']')
        {
            while(!S.empty() && S.top() !=  '[') {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
        else if(s[i] == '}')
        {
            while(!S.empty() && S.top() !=  '{') {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }

    while(!S.empty()) {
        postfix += S.top();
        S.pop();
    }
    s=postfix;
}

// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool input_processing::IsOperand(char C)
{
    if(IsknownOperand(C)) return true;
    if(IsunknownOperand(C)) return true;
    if(C=='.')return true;

    return false;
}

bool input_processing::IsknownOperand(char C)
{
    if(C >= '0' && C <= '9'||C=='.') return true;
    return false;
}

bool input_processing::IsunknownOperand(char C)
{
    if(C >= 'a' && C <= 'z') return true;
    if(C >= 'A' && C <= 'Z') return true;

    return false;
}

// Function to verify whether a character is operator symbol or not.
bool input_processing::IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' || C== '^'
    || C== '~'|| C== '@'|| C== '#'|| C== '$'|| C== '%'|| C== '&'|| C== '|'||C=='!')
        return true;

    return false;
}

// Function to verify whether an operator is right associative or not.
int input_processing::IsRightAssociative(char op)
{
    if(op == '^') return true;
    if(op == '~') return true;
    if(op == '@') return true;
    if(op == '#') return true;
    if(op == '$') return true;
    if(op == '%') return true;
    if(op == '&') return true;
    if(op == '|') return true;
    if(op == '!') return true;
    return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int input_processing::GetOperatorWeight(char op)
{
    int weight = -1;
    switch(op)
    {
    case '+':
    case '-':
        weight = 1;
        break;
    case '*':
    case '/':
        weight = 2;
        break;
    case '^':
        weight = 3;
        break;
    case '~':
    case '@':
    case '#':
    case '$':
    case '%':
    case '&':
    case '|':
    case '!':
        weight = 4;
        break;
    }
    return weight;
}

// Function to perform an operation and return output.
int input_processing::HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if(op1Weight == op2Weight)
    {
        if(IsRightAssociative(op1)) return false;
        else return true;
    }
    return op1Weight > op2Weight ?  true: false;
}

QString input_processing::returnOrgs(){
    return QString(org_s.c_str());
}
