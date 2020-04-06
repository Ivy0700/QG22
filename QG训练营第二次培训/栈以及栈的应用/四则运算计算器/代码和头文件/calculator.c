#include "calculator.h"
using namespace std;

string InfixToPostfix(string expression)
{
	stack<char> S;
	string postfix = "";
	for(int i = 0;i< expression.length();i++) {
		if(expression[i] == ' ' || expression[i] == ',') continue;
		else if(IsOperator(expression[i]))
		{	postfix+=" ";//将每个数值隔开
			while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),expression[i]))
			{
				postfix+= S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		//如果是数值的话，直接加到后缀表达式中
		else if(IsNumber(expression[i]))
		{
			postfix +=expression[i];
		}
		//是'('的话先push到栈中
		else if (expression[i] == '(')
		{
			S.push(expression[i]);
		}
		else if(expression[i] == ')')
		{
			//把'('上面的符号都pop出来
			while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			//pop掉'('
			S.pop();
		}
		else{
		cout<<"ERROR1"<<endl;
		judge =-1;
		break;

		}
	}

	//把栈中剩余符号的都pop出来
	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

//判断数值
bool IsNumber(char C)
{
	if(C >= '0' && C <= '9') {
		return true;}
	if(C >= 'a' && C <= 'z'){
		return false;}
	if(C >= 'A' && C <= 'Z'){
		return false;
	}
	return false;
}


bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' )
		return true;

	return false;
}

int CompareValue(char op)
{
	int value = -1;
	switch(op)
	{
	case '+':
	case '-':
		value = 1;
		break;
	case '*':
	case '/':
		value = 2;
		break;
	}
	return value;
}


int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = CompareValue(op1);
	int op2Weight = CompareValue(op2);
	if(op1Weight>=op2Weight){
		return 1;
	}
	else{
		return 0;
	}
}

int EvaluatePostfix(string expression)
{
	stack<int> S;
	for(int i = 0;i< expression.length();i++) {
		if(expression[i] == ' ' || expression[i] == ',') continue;
		else if(IsOperator2(expression[i])) {
			//如果是符号的话，就pop最上面的值出来计算
			int number2 = S.top();
			S.pop();
			int number1 = S.top();
			S.pop();
			int result = Perform(expression[i], number1, number2);
			S.push(result);
		}
		else if(IsNumericDigit(expression[i])){
			int number = 0;
			while(i<expression.length() && IsNumericDigit(expression[i])) {
				number = (number*10) + (expression[i] - '0');
				i++;
			}
			i--;
			S.push(number);
		}

	}
	return S.top();
}
bool IsNumericDigit(char C)
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

bool IsOperator2(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/'){
		return true;
	}
	return false;

}
int Perform(char operation, int number1, int number2)
{
	if(operation == '+')
	{return number1 +number2;}
	else if(operation == '-')
	{return number1 - number2;}
	else if(operation == '*') {
	return number1 * number2;}
	else if(operation == '/'){
	return number1 / number2;}
	else cout<<"Error"<<endl;
	return -1;
}
