//递归算法
#include"Header.h"

static int move[4][2]={(-1,0),(0,1),(1,0),(0,-1)};
ElemType start,end;

int Recursion(ElemType curpos,Maze &M)
{
	if(curpos.x<=0||curpos.x>=M.row||curpos.y<=0||curpos.y>=M.column) return 0;
	if(curpos.x==::end.x&&curpos.y==::end.y) return 1;
	ElemType nextpos;
	int flag=0;
	for(int i=0;i<4;i++)
	{
		nextpos.x=curpos.x+::move[i][0];
		nextpos.y=curpos.y+::move[i][1];
		if(M.matrix[nextpos.x][nextpos.y]==0)
		{
			M.matrix[nextpos.x][nextpos.y]=-1;
			flag=Recursion(nextpos,M);
			if(flag)
			{
				cout<<"("<<nextpos.x<<","<<nextpos.y<<","<<i+1<<")<-";
				return 1;
			}
			M.matrix[nextpos.x][nextpos.y]=0;
		}
	}
	return 0;
}

void MazeWay(Maze &M)
{
	cout<<endl<<endl<<"请输入起点的坐标：";
	while(1)
	{
		cin>>start.x>>start.y;
		if(!M.matrix[start.x][start.y]) break;
		cout<<"起点为障碍，请重新输入！"<<endl;
	}
	cout<<endl<<"请输入终点的坐标：";
	while(1)
	{
		cin>>::end.x>>::end.y;
		if(!M.matrix[::end.x][::end.y]) break;
		cout<<"起点为障碍，请重新输入！"<<endl;
	}
	Recursion(start,M);
}