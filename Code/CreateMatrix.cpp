//创建迷宫
#include"Header.h"

Maze Create()
{
	Maze M;
	int x,y;
	cout<<"请输入迷宫的行数与列数，以空格隔开：";
	cin>>x>>y;
	M.row=x+2;M.column=y+2;
	M.matrix=(int**)malloc(sizeof(int*)*M.row);
	for(int i=0;i<M.row;i++) M.matrix[i]=(int*)malloc(sizeof(int)*M.column);
	if(!M.matrix)
	{
		cout<<"ERROR：分配空间失败！";exit(1);
	}
	for(int i=0;i<M.row;i++)
		for(int j=0;j<M.column;j++) M.matrix[i][j]=1;
	cout<<endl<<"请输入迷宫各个元素，通路为0，障碍为1，以空格或换行隔开："<<endl;
	for(int i=1;i<M.row-1;i++)
		for(int j=1;j<M.column-1;j++)
			cin>>M.matrix[i][j];
	return M;
}

void Show(Maze M)
{
	cout<<endl<<endl<<"创建的迷宫如下图所示。"<<endl;
	for(int i=0;i<M.row;i++)
	{
		for(int j=0;j<M.column;j++)
			if(M.matrix[i][j]) cout<<"█";
			else cout<<"  ";
		cout<<endl;
	}
}