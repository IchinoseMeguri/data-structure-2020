//主函数文件
#include"Header.h"

int main()
{
	system("color F0");
	cout<<endl<<endl<<"\t\t\t\t\t数据结构课程设计"<<endl;
	cout<<endl<<endl<<"\t\t\t\t\t  迷 宫 问 题 "<<endl;
	cout<<endl<<endl<<"************************************************"<<
		"************************************************"<<endl;
	cout<<endl<<endl<<"1. 生成迷宫"<<endl<<endl;
	Maze M=Create();
	Show(M);
	cout<<endl<<endl<<"************************************************"<<
		"************************************************"<<endl;
	cout<<endl<<endl<<"2. 寻找路径"<<endl<<endl;
	Mazepath(M);
	cout<<endl<<endl<<"************************************************"<<
		"************************************************"<<endl;
	cout<<"程序结束。"<<endl<<endl;
	return 0;
}