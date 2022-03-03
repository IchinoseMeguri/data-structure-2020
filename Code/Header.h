//ͷ�ļ�
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#define up 1
#define right 2
#define down 3
#define left 4
//�����ĸ��������

typedef struct {
	int row;
	int column;
	int **matrix;
}Maze;
//�Թ�����

typedef struct {
	int x;
	int y;
	int direction;
}ElemType;
//λ������(i,j,d)

typedef struct {
	int stacksize;
	ElemType data[STACK_INIT_SIZE];
}SqStack;
//ջ����

typedef short Status;

//�����Թ�
Maze Create();
void Show(Maze M);

//ջ����
Status InitStack(SqStack *&S);
Status StackEmpty(SqStack *S);
Status GetTop(SqStack *S,ElemType &p);
Status Push(SqStack *&S,ElemType p);
Status Pop(SqStack *&S,ElemType &p);

//Ѱ��·��
void Mazepath(Maze M);

//�ݹ��㷨
int Recursion(ElemType pos,Maze &M);
void MazeWay(Maze &M);
