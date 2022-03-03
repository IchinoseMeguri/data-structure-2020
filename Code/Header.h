//头文件
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
//定义四个方向代号

typedef struct {
	int row;
	int column;
	int **matrix;
}Maze;
//迷宫矩阵

typedef struct {
	int x;
	int y;
	int direction;
}ElemType;
//位置坐标(i,j,d)

typedef struct {
	int stacksize;
	ElemType data[STACK_INIT_SIZE];
}SqStack;
//栈声明

typedef short Status;

//创建迷宫
Maze Create();
void Show(Maze M);

//栈操作
Status InitStack(SqStack *&S);
Status StackEmpty(SqStack *S);
Status GetTop(SqStack *S,ElemType &p);
Status Push(SqStack *&S,ElemType p);
Status Pop(SqStack *&S,ElemType &p);

//寻找路径
void Mazepath(Maze M);

//递归算法
int Recursion(ElemType pos,Maze &M);
void MazeWay(Maze &M);
