#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack
{
	ElemType *elem;
	int top;
	int size;
} SqStack;



Status initStack(SqStack *s,int sizes);
Status isEmptyStack(SqStack *s);
Status getTopStack(SqStack *s,ElemType *e); 
Status clearStack(SqStack *s);
Status destroyStack(SqStack *s);
Status stackLength(SqStack *s,int *length);
Status pushStack(SqStack *s,ElemType data);
Status popStack(SqStack *s,ElemType *data);
void inputvalue(ElemType *element,ElemType upperbound,ElemType lowerbound);

#endif
