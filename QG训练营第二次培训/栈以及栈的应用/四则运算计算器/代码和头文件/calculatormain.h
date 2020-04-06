
#include<iostream>
#include<stack>
#include<string>
#include "calculator.h"
#include "calculator.c"
using namespace std;
int judge = 1;
int main()
{	int choice = 1;
	string expression;
	cout<<"请输入表达式(输入0退出) \n";
	getline(cin,expression);//获得中缀表达式
	if(expression=="0"){
		choice = 0;
	}
	while(choice){
		switch(choice){
	case -1:
	cout<<"请输入表达式(输入0 退出)\n";
	getline(cin,expression);//获得中缀表达式
	if(expression=="0"){
		choice = 0;
	}
	else{
	choice = 1;}
	break;
	case 0:
		choice = 0;
		break;
	case 1:
	string postfix = InfixToPostfix(expression);
	if(judge!=-1){
	cout<<"后缀表达式为 = "<<postfix<<endl;
	int result1 = EvaluatePostfix(postfix);
	cout<< result1<<endl;
	}
	else{
		cout<< "输入错误，请重试"<<endl;
	}
	choice =-1;
	break;
	}
	}
	cout<<"已退出"<<endl;
	system("pause");

}