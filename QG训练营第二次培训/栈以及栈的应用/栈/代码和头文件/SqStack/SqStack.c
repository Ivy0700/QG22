#include "SqStack.h"
#include<stdio.h>
#include<stdlib.h>
void inputvalue(ElemType *element,ElemType upperbound,ElemType lowerbound){
		int number;
		scanf("%d",&number);
		while(number < lowerbound||number > upperbound){
			fflush(stdin);	//避免输入char型导致无限循环
			printf("ERROR,请输入正确的数字\n");
			scanf("%d",&number);
		}
		*element = number;
		printf("输入成功\n");
	}

Status initStack(SqStack *s,int sizes){
        s->size = sizes;
		s->elem = (ElemType*)malloc(sizeof(ElemType)*sizes);
		s->top = -1;
		if(s->elem==NULL){
			return ERROR;
		}
		return SUCCESS;
}
Status isEmptyStack(SqStack *s){
		if(s->top==-1){
			return SUCCESS;
		}
		return ERROR;
	}
 
  
    Status getTopStack(SqStack *s,ElemType *e){
		if(s->top==-1){
			return ERROR;
		}
		*e = s->elem[s->top];
		return SUCCESS;

	}
	Status clearStack(SqStack *s){
		if(s->top==-1){
			return ERROR;
		}
		s->top=-1;
		return SUCCESS;
	}

	Status destroyStack(SqStack *s){
		while(s->top!=-1){
        
		free(s->elem+(s->top --));
		}
		s->size = 0;
		return SUCCESS;
	}

	Status stackLength(SqStack *s,int *length){
		if(s->top==-1||s->size){
			return ERROR;
		}
		*length = s->top +1;
		return SUCCESS;

	}

	Status pushStack(SqStack *s,ElemType data){
		if(s->top==s->size-1){
			return ERROR;
		}
			s->elem[++s->top] = data;
	}

	Status popStack(SqStack *s,ElemType *data){
		if(s==NULL||s->top==-1){
			return ERROR;
		}
		*data = s->elem[s->top];
		s->top --;
		return SUCCESS;
	}