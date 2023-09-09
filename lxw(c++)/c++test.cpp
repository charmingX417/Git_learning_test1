#include<iostream>
using namespace std;

class STU {
public :
	void stuget(int* p1, int* p2, int n);
	double Stu_Averrage(int* p2, int n);
	void Stu_search(int* p1, int* p2, int n, double ave);
	double ave;
	STU();
	~STU();

};

STU::STU():ave(0) { cout << "STU::STU()" << endl; }
STU::~STU() { cout << "STU::~STU()" << endl; }
void STU::stuget(int* p1, int* p2, int n)
{
	cout << "请输入学号" << endl;
	for (int i = 0; i < n; i++)
	{
		int xh;
		cin >> xh;
		*(p1 + i) = xh;
	}
	cout << "请输入成绩" << endl;
	for (int j = 0; j < n; j++)
	{
		int grade;
		cin >> grade;
		*(p2 + j) = grade;
	}
}
double STU:: Stu_Averrage(int* p2, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += *(p2 + i);
	}
	return (double)sum / n;
}
void STU::Stu_search(int* p1, int* p2, int n, double ave)
{
	cout << "大于平均分的学生的学号为：" << endl;
	for (int i = 0; i < n; i++)
	{
		double num = (double)*(p2 + i);
		if (num > ave)
			//printf("%d-%d分\n", *(p1 + i), *(p2 + i));
		cout << *(p1 + i) << "-" << *(p2 + i) << "分" << endl;
	}
}

int main()
{
	STU stu;
	int xh[10] = { 0 };
	int cj[10] = { 0 };
	int* p1 = xh;
	int* p2 = cj;
	stu.stuget(p1,p2,10);
	stu.ave = stu.Stu_Averrage(p2, 10);
	cout <<fixed<< "平均分为" << stu.ave << endl;
	stu.Stu_search(p1, p2, 10, stu.ave);

	return 0;
}