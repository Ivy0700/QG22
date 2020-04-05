#include "LinkStack.h"
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
	Status initLStack(LinkStack *s){
		s->top =(LinkStackPtr)malloc(sizeof(StackNode));
		s->top->next =NULL;
		if(s->top==NULL){
			return ERROR;
		}
		s->count=0;
	}

	Status isEmptyLStack(LinkStack *s){
		if(s->top==NULL||s->top->next==NULL){
			return SUCCESS;
		}
		return ERROR;
	}

	Status getTopLStack(LinkStack *s,ElemType *e){
		if(s->top==NULL||s->top->next==NULL){
			return ERROR;
		}
		*e = s->top->next->data;

	}

	Status clearLStack(LinkStack *s){
		if(s->top==NULL||s->top->next==NULL){
			return ERROR;
		}
		LinkStackPtr temp= s->top->next;
		LinkStackPtr temp2;
		while(temp!=NULL){
			temp2 = temp->next;
			free(temp);
			temp=temp2;
		}
		s->top->next=NULL;
	}

	Status destroyLStack(LinkStack *s){
		if(s->top==NULL){
			return ERROR;
		}
		LinkStackPtr temp= s->top;
		LinkStackPtr temp2;
		while(temp!=NULL){
			temp2 = temp->next;
			free(temp);
			temp=temp2;
		}
		s->top=NULL;
	}

	Status LStackLength(LinkStack *s,int *length){
		LinkStackPtr temp = s->top;
		if(temp==NULL){
			return ERROR;
		}

		while(temp->next!=NULL){
			temp=temp->next;
			s->count ++;
		}
		*length = s->count;
	}

	Status pushLStack(LinkStack *s,ElemType data){
		LinkStackPtr Node = (LinkStackPtr)malloc(sizeof(StackNode));
		LinkStackPtr temp = s->top;
		if(temp==NULL){
			return ERROR;
		}
		Node->next = s->top->next;
		s->top->next = Node;
		Node->data = data;
	}
	Status popLStack(LinkStack *s,ElemType *data){
		if(s->top==NULL)
			return ERROR;
		LinkStackPtr temp = s->top->next;
		s->top->next = s->top->next->next;
		*data = temp->data;
		free(temp);
	}