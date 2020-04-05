#include "SqStack.h"
#include "SqStack.c"
#include<stdio.h>
#include<stdlib.h>
void Print(){
	printf("*************************************\n");
	printf("**************栈设计*****************\n");
	printf("*************************************\n");
	printf("*           0 退出                  *\n");
	printf("*           1 初始化栈              *\n");
	printf("*           2 判断栈是否为空        *\n");
	printf("*           3 得到栈顶元素          *\n");
	printf("*           4 清空栈                *\n");
	printf("*           5 销毁栈                *\n");
	printf("*           6 检测栈长度            *\n");
	printf("*           7 入栈                  *\n");
	printf("*           8 出栈                  *\n");
	printf("*************************************\n");
	}
int main()
{	SqStack S;
	Print();
	printf("请选择功能(一次一个)\n");
	int choice;
	int upperbound1 = 8;
	int lowerbound1 = 0;
	inputvalue(&choice,upperbound1,lowerbound1);
	while(choice){
		switch(choice){
		case 0:
			choice = 0;
			printf("已退出\n");
			break;
		case -1:
			printf("\n请选择功能(0表示退出):\n");
			inputvalue(&choice,upperbound1,lowerbound1);
			break;
		case 1:
			printf("请问想要设定的栈数组的大小为?\n");
			int sizes;
			int upperbound = 100;
			int lowerbound = 1;
			inputvalue(&sizes,upperbound,lowerbound);
			if(initStack(&S,sizes)){
				printf("初始化成功\n");
			}
			else{
				printf("初始化失败\n");
			}
			choice = -1;
			break;

		case 2:
			if(isEmptyStack(&S)){
				printf("栈为空\n");
			}
			else{
				printf("栈不为空\n");
			}
			choice =-1;
			break;
		case 3:
			printf("\n");
			ElemType num;
			if(getTopStack(&S,&num)){
				printf("得到栈顶值，为%d",num);
			}
			else{
				printf("栈顶为空,无法得到栈顶元素\n");
			}
			choice = -1;
			break;
		case 4:
			if(clearStack(&S)){
				printf("栈已清空\n");
			}
			else{
				printf("栈已为空\n");
			}
			choice = -1;
			break;
		case 5:
			if(destroyStack(&S)){
				printf("栈已销毁\n");
			}
			else{
				printf("错误\n");
			}
			choice = -1;
			break;
		case 6:
			printf("\n");
			int length = 0;
			if(stackLength(&S,&length)){
				printf("得到栈的长度,为%d",length);
			}
			else{
				printf("栈为空\n");
			}
			choice = -1;
			break;
		case 7:
			printf("\n");
			int upperbound2 = 100;
			int lowerbound2 = -100;
			ElemType data;
			printf("请输入需要入栈的值\n");
			inputvalue(&data,upperbound2,lowerbound2);
			if(pushStack(&S,data)){
				printf("入栈成功\n");
			}
			else{
				printf("入栈失败,请初始化栈\n");
			}
			choice = -1;
			break;
		case 8:
			printf("\n");
			ElemType data1;
			if(popStack(&S,&data1)){
				printf("出栈成功,值为%d",data1);
			}
			else{
				printf("出栈失败,请初始化栈\n");
			}
			choice = -1;
			break;
		default:
				fflush(stdin);
			printf("请输入正确的数字\n");
			scanf("%d",&choice);
	}
}
			printf("已退出\n");
			system("pause");

}
