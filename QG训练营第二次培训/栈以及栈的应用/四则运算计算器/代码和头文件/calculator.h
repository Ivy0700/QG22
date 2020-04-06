using namespace std;
//将中缀表达式转化为后缀表达式
string InfixToPostfix(string expression);
//比较优先级
int HasHigherPrecedence(char operator1, char operator2);
//判断符号
bool IsOperator(char C);
//判断数值
bool IsNumber(char C);
//计算后缀表达式
int EvaluatePostfix(string expression);
//计算
int Perform(char operation, int number1, int number2);

bool IsOperator2(char C);

bool IsNumericDigit(char C);