// rosenblatt_exp.cpp : �������̨Ӧ�ó������ڵ㡣
// ����Ϊ��ά�ȣ����Կɷ�
//

#include "stdafx.h"
#include<iostream>
#include<fstream>

using namespace std;

double eta = 0.1;//ѧϰ��
double w[2] = { 0.0, 0.0 }, b = 0.0;//�������

struct DataSet
{
	double x1;
	double x2;
	int y;
};

int i;
int n = 0;//��������
const int num = 10;//���ݼ���С�����ƣ�
int Datacount = 0;//���ݼ���С��ʵ�ʣ�
bool flag = true;//�Ƿ������
DataSet Sampledata[num];

//���ļ��ж�ȡ����
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

	Datacount=readData(Sampledata);//��������

	//������ݼ�
	cout << "���ݼ�Ϊ��" << endl;
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

	cout << endl << "�����" << endl;
	cout << "w = " << w[0] << ", " << w[1] << " " << "b=" << b << endl;
	cout << "����������" << n << endl;

	return 0;
}
