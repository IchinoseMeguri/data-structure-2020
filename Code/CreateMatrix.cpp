//�����Թ�
#include"Header.h"

Maze Create()
{
	Maze M;
	int x,y;
	cout<<"�������Թ����������������Կո������";
	cin>>x>>y;
	M.row=x+2;M.column=y+2;
	M.matrix=(int**)malloc(sizeof(int*)*M.row);
	for(int i=0;i<M.row;i++) M.matrix[i]=(int*)malloc(sizeof(int)*M.column);
	if(!M.matrix)
	{
		cout<<"ERROR������ռ�ʧ�ܣ�";exit(1);
	}
	for(int i=0;i<M.row;i++)
		for(int j=0;j<M.column;j++) M.matrix[i][j]=1;
	cout<<endl<<"�������Թ�����Ԫ�أ�ͨ·Ϊ0���ϰ�Ϊ1���Կո���и�����"<<endl;
	for(int i=1;i<M.row-1;i++)
		for(int j=1;j<M.column-1;j++)
			cin>>M.matrix[i][j];
	return M;
}

void Show(Maze M)
{
	cout<<endl<<endl<<"�������Թ�����ͼ��ʾ��"<<endl;
	for(int i=0;i<M.row;i++)
	{
		for(int j=0;j<M.column;j++)
			if(M.matrix[i][j]) cout<<"��";
			else cout<<"  ";
		cout<<endl;
	}
}