//Ѱ��·��
#include"Header.h"

SqStack *S;
int cnt=1;
int minlength=30000;
ElemType path[STACK_INIT_SIZE];

void Mazepath(Maze M)
{
	ElemType start,end,curpos;
	int find=0;
	cout<<endl<<endl<<"�������������꣺";
	while(1)
	{
		cin>>start.x>>start.y;
		if(!M.matrix[start.x][start.y]) break;
		cout<<"���Ϊ�ϰ������������룡"<<endl;
	}
	cout<<endl<<"�������յ�����꣺";
	while(1)
	{
		cin>>end.x>>end.y;
		if(!M.matrix[end.x][end.y]) break;
		cout<<"�յ�Ϊ�ϰ������������룡"<<endl;
	}
	InitStack(S);
	start.direction=0;
	Push(S,start);
	M.matrix[start.x][start.y]=-1;
	while(!StackEmpty(S))
	{
		GetTop(S,curpos);
		if(curpos.x==end.x&&curpos.y==end.y)
		{
			cout<<"·��"<<cnt++<<": ";
			for(int i=0;i<S->stacksize;i++)
				cout<<"("<<S->data[i].x<<","<<S->data[i].y<<","<<S->data[i].direction<<")";
			cout<<endl<<endl;
			if(S->stacksize+1<minlength)
			{
				for(int i=0;i<S->stacksize;i++) path[i]=S->data[i];
				minlength=S->stacksize+1;
			}
			M.matrix[S->data[S->stacksize].x][S->data[S->stacksize].y]=0;
			S->stacksize--;
			curpos=S->data[S->stacksize];
		}
		find=0;
		while(curpos.direction<5&&!find)
		{
			switch(++curpos.direction)
			{
				case 1:
					curpos.x=S->data[S->stacksize].x-1;
					curpos.y=S->data[S->stacksize].y;
					break;
				case 2:
					curpos.x=S->data[S->stacksize].x;
					curpos.y=S->data[S->stacksize].y+1;
					break;
				case 3:
					curpos.x=S->data[S->stacksize].x+1;
					curpos.y=S->data[S->stacksize].y;
					break;
				case 4:
					curpos.x=S->data[S->stacksize].x;
					curpos.y=S->data[S->stacksize].y-1;
					break;
			}
			if(M.matrix[curpos.x][curpos.y]==0) find=1;
		}

		if(find)
		{
			S->data[S->stacksize++].direction=curpos.direction;
			S->data[S->stacksize].x=curpos.x;
			S->data[S->stacksize].y=curpos.y;
			S->data[S->stacksize].direction=0;
			M.matrix[curpos.x][curpos.y]=-1;
		}
		else
		{
			M.matrix[S->data[S->stacksize].x][S->data[S->stacksize].y]=0;
			S->stacksize--;
		}
	}
	if(minlength==30000) cout<<"�Թ���·����"<<endl<<endl;
	else
	{
		cout<<"���·������Ϊ��"<<minlength-1<<endl<<endl;
		cout<<"���·����";
		for(int i=0;i<minlength-1;i++) cout<<"("<<path[i].x<<","<<path[i].y<<","<<path[i].direction<<")";
		cout<<endl;
		cout<<"ע������1,2,3,4�ֱ��ʾ���򱱡������ϡ�����"<<endl<<endl;
	}
}
