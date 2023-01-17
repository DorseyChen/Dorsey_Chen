/*
  Infix to postfix conversion in C++ 
  Input Postfix expression must be in a desired format. 
  Operands and operator, both must be single character.
  Only '+'  ,  '-'  , '*', '/' and '^' (for exponentiation)  operators are expected. 
*/
//Test Example:[ 3*4^(3+5)+5]*2 +3^2^4/2=2.19165865 กั 10^7
//Test Example:{2+2^3^4/2-(2-3)}/2.5=4.835703278458516698824716 กั 10^23
//Test Example:[ 3*2.78^(13+5)/1000+5]*2.54 +3^2.1^4/2=9.51512... กั 10^8
#include<iostream>
#include<stack>
#include<string>
#include<cmath>
#include<stdlib.h>

using namespace std;
//compute the result of a single expression
long double Compute(char Operator,long double operand1,long double operand2);

//calculate the value of the expression
string EvaluatePostfix(string);

//check if the type of open symbol match with the close symbol
bool ParenthesesMatch(char open,char close);

// Function to convert Infix expression to postfix 
string InfixToPostfix(string expression);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not. 
bool IsOperand(char C);

//add space between each operand
string& AddSpace(string&);

//check whether the parentheses are balanced
bool ParenthesesChecking(string);
int main() 
{
	string expression; 
	cout<<"Enter Infix Expression \n";
	getline(cin,expression);
	cout<<"Parentheses checking\n";
	ParenthesesChecking(expression)?cout<<"balanced parentheses":cout<<"unbalanced parentheses";
	cout<<endl;
	cout<<"After adding spaces between operators and operands\n";
	cout<<AddSpace(expression)<<endl;
	string postfix = InfixToPostfix(expression);
	cout<<"Output = "<<postfix<<"\n";
	cout<<"Evaluated value\n";
	cout<<EvaluatePostfix(postfix);
	return 0;
}

bool ParenthesesChecking(string s)
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
		return false;
	return true;
}
bool ParenthesesMatch(char open,char close)
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

string& AddSpace(string& s)
{
	string::size_type pos,prev,len;
	prev=0;
	len=s.length();
	for(pos=1;pos<len;pos++)
	{
		//cout<<"at "<<pos<<" turns"<<endl;
		prev=pos-1;
		//cout<<"pos="<<pos<<endl;
		//cout<<"prev="<<prev<<endl;
		if(IsOperand(s[prev])&&(IsOperator(s[pos])||s[pos]==')'||s[pos]==']'||s[pos]=='}'))
		{
			s.insert(pos,1,' ');
			pos++;
			len++;
		}
		
		//cout<<s<<endl;
	}
	//cout<<s;
	return s;
}
// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
	// Declaring a Stack from Standard template library in C++. 
	stack<char> S;
	string postfix = ""; // Initialize postfix as empty string.
	for(int i = 0;i< expression.length();i++) {

		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if(expression[i] == ' ' || expression[i] == ',') postfix+=" ";

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if(IsOperator(expression[i])) 
		{
			while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),expression[i]))
			{
				postfix+= S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		// Else if character is an operand
		else if(IsOperand(expression[i]))
		{
			postfix +=expression[i];
		}

		else if (expression[i] == '('||expression[i]=='['||expression[i]=='{') 
		{
			S.push(expression[i]);
		}

		else if(expression[i] == ')') 
		{
			while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
		else if(expression[i] == ']') 
		{
			while(!S.empty() && S.top() !=  '[') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
		else if(expression[i] == '}') 
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

	return postfix;
}

// Function to verify whether a character is english letter or numeric digit. 
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	if(C=='.')return true;
	
	return false;
}

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '^')
		return true;

	return false;
}

// Function to verify whether an operator is right associative or not. 
int IsRightAssociative(char op)
{
	if(op == '^') return true;
	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int GetOperatorWeight(char op)
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
	}
	return weight;
}

// Function to perform an operation and return output. 
int HasHigherPrecedence(char op1, char op2)
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
string EvaluatePostfix(string postfix)
{
	string::size_type OperandHead,OperandTail;
	char CurrentOperator;
	stack<long double> operands;
	long double result;
	

	for(int i = 0;i< postfix.length();i++)
	{
		// operandscanning each character from left. 
		
		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		if(IsOperator(postfix[i])) 
		{//fgetc(stdin);
			//cout<<"Opn\n";
			// Pop two operands. 
			long double operand2 = operands.top(); operands.pop();
			long double operand1 = operands.top(); operands.pop();
			// Perform operation
			long double result = Compute(postfix[i], operand1, operand2);
			//Push back result of operation on stack. 
			operands.push(result);
		}
		else if(IsOperand(postfix[i]))
		{
		//fgetc(stdin);
		//	cout<<"Opr\n";
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
			Operand=postfix.substr(OperandHead,OperandTail-OperandHead+1);
			i=OperandTail;

			// Push operand on stack. 
			operands.push(stold(Operand));
		}
	
	

	}
	//fgetc(stdin);
	// If postfix is in correct format, Stack will finally have one element. This will be the output. 
	if(operands.size()!=1)
	{
		cout<<"wrong postfix in 'EvaluatePostfix'\n";
		return string("");
	}
	return to_string(operands.top());
}
long double Compute(char Operator,long double operand1,long double operand2)
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
	}
	return result;
}
