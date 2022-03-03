//Õ»²Ù×÷ÎÄ¼þ
#include"Header.h"

Status InitStack(SqStack *&S)
{
	S=(SqStack*)malloc(sizeof(SqStack));
	S->stacksize=-1;
	return 1;
}

Status StackEmpty(SqStack *S)
{
	if(S->stacksize==-1) return 1;
	return 0;
}

Status GetTop(SqStack *S,ElemType &p)
{
	if(S->stacksize==-1) return 0;
	p=S->data[S->stacksize];
	return 1;
}

Status Push(SqStack *&S,ElemType p)
{
	if(S->stacksize==STACK_INIT_SIZE-1)
	{
		S=(SqStack*)realloc(S,(S->stacksize+STACKINCREMENT)*sizeof(SqStack));
		S->stacksize+=STACKINCREMENT;
		
	}
	S->data[++(S->stacksize)]=p;
	return 1;
}

Status Pop(SqStack *&S,ElemType &p)
{
	if(S->stacksize==-1) return 0;
	p=S->data[S->stacksize--];
	return 1;
}