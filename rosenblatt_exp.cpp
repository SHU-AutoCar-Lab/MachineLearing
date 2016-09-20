// rosenblatt_exp.cpp : 定义控制台应用程序的入口点。
// 样本为两维度，线性可分
//

#include "stdafx.h"
#include<iostream>
#include<fstream>

using namespace std;

double eta = 0.1;//学习率
double w[2] = { 0.0, 0.0 }, b = 0.0;//定义参数

struct DataSet
{
	double x1;
	double x2;
	int y;
};

int i;
int n = 0;//迭代次数
const int num = 10;//数据集大小（估计）
int Datacount = 0;//数据集大小（实际）
bool flag = true;//是否误分类
DataSet Sampledata[num];

//从文件中读取数据
int readData(DataSet data[])
{
	ifstream file;
	file.open("data.txt");
	int i = 0;
	while (!file.eof())
	{
		file >> data[i].x1 >> data[i].x2 >> data[i].y;
		i++;
	}
	file.close();
	return i;
}

int main()
{

	Datacount=readData(Sampledata);//读入数据

	//输出数据集
	cout << "数据集为：" << endl;
	for (i = 0; i < Datacount; i++)
	{
		cout << Sampledata[i].x1 << "  " << Sampledata[i].x2 << "  " << Sampledata[i].y << endl;
	}

	while (flag)
	{
		for (i = 0; i < Datacount; i++)
		{
			flag = false;
			if (Sampledata[i].y * (w[0] * Sampledata[i].x1 + w[1] * Sampledata[i].x2 + b) <= 0)
			{
				flag = true;
				w[0] = w[0] + eta * Sampledata[i].y * Sampledata[i].x1;
				w[1] = w[1] + eta * Sampledata[i].y * Sampledata[i].x2;
				b = b + eta * Sampledata[i].y;
				n++;
				break;
			}
		}
	}

	cout << endl << "结果：" << endl;
	cout << "w = " << w[0] << ", " << w[1] << " " << "b=" << b << endl;
	cout << "迭代次数：" << n << endl;

	return 0;
}
