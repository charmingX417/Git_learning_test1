#include<iostream>
#include<ctime>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
using namespace std;

class MYGAME {
public:
	MYGAME(unsigned int XH, string name) {};
	virtual void  START();
	virtual void  END();
	virtual void  RESTART();
	~MYGAME() {};
private:
	string NAME="ATRI";
	string DESIGNER="ANIPLEX";
	string VERIMFO="Copyright 2022 ANIPLEX";
	float VER=1.3;
};

void MYGAME::RESTART()
{
	int block = 200;
	cout << "正在重启游戏..." << endl;

	for(int i = 0; i < block;i++ )
	{
		if (i < block - 1)
		{ printf("\r正在加载配置[%.2lf%%]:", i * 100.0 / (block - 1)); }
		else{ { printf("\r加载完成[%.2lf%%]:", i * 100.0 / (block - 1)); } }

		int num = i * 20 / block;
		for (int j = 0; j <=num; j++)
		{cout << "██"; Sleep(10);}
	}

}
void MYGAME::END(){cout << "\n\n已退出游戏\n\n" << endl;}
void MYGAME::START()
{
	cout << "游戏名：" << NAME << endl;
	cout << "开发者：" << DESIGNER<<endl;
	cout << "版号：" << VER << endl;
	cout << VERIMFO << endl;
	cout << "请选择难度：\n" << "1.EASY\n2.NORMAL\n3.HARD" << endl;
	int a;
	while (cin >> a)
	{
		if (a == 1 || a == 2 || a == 3)break;
	}

	cout << "正在进入游戏";
	cout << "."; Sleep(1000); cout << "."; Sleep(1000); cout << "."; Sleep(1000);
	switch (a)
	{
	case 1:cout << "\n成功进入游戏(EASY)" << endl; break;
	case 2:cout << "\n成功进入游戏(NORMAL)" << endl; break;
	case 3:cout << "\n成功进入游戏(HARD)" << endl; break;
	}
}

class Shudu
{
public:

	int m_N;
	int date[64];

	friend int ifhave(const Shudu& a);//判断情况是否有解
	void setdate(int N);//设置初始地图
	void showdate();//打印地图
	void OnKeyboard();//通过w,s,a,d移动拼图；
	bool gameover();//判断游戏是否达到结束条件
};
void Shudu::setdate(int N) {
	m_N = N;
	for (int i = 0; i < m_N * m_N; i++) {
		date[i] = 0;
	}//将所有数据设置为0；
	int number;
	srand(time(0));
	for (int i = 1; i < N * N; i++)
	{
		number = rand() % (N * N - 1);
		if (date[number] == 0)
		{
			date[number] = i;
		}
		else
		{
			for (int j = number + 1;; j++)
			{
				if (j == N * N - 1)
				{
					j = 0;
				}
				if (date[j] == 0)
				{
					date[j] = i;
					break;
				}
			}
		}
	}
}
void Shudu::showdate() {
	for (int j = 0; j < m_N; j++) {
		cout << "----";
	}
	cout << endl;
	cout << "|";
	for (int i = 1; i <= m_N * m_N; i++) {
		if (date[i - 1] == 0) {
			cout << setw(3) << " " << "|";
		}
		else {

			cout << setw(3) << date[i - 1] << "|";
		}
		if (i % m_N == 0) {
			cout << endl;
			for (int j = 0; j < m_N; j++) {
				cout << "----";
			}
			cout << endl;
			if (i <= m_N * m_N - 1)
				cout << "|";
		}
	}
}
void Shudu::OnKeyboard() {
	char c;
	int i, j;
	c = _getch();
	switch (c)
	{
	case 'a':	//左 
	case 'A':
		for (i = 0; i < m_N * m_N; i++)
		{
			if (date[i] == 0 && i % m_N != m_N - 1)
			{
				date[i] = date[i + 1];
				date[i + 1] = 0;
				break;
			}
		}
		break;
	case 'w':	//上 
	case 'W':
		for (i = 0; i < m_N * m_N - m_N; i++)
		{
			if (date[i] == 0)
			{
				date[i] = date[i + m_N];
				date[i + m_N] = 0;
				break;
			}
		}
		break;
	case 's':	//下 
	case 'S':
		for (i = m_N; i < m_N * m_N; i++)
		{
			if (date[i] == 0)
			{
				date[i] = date[i - m_N];
				date[i - m_N] = 0;
				break;
			}
		}
		break;
	case 'd':	//右 
	case 'D':
		for (i = 0; i < m_N * m_N; i++)
		{
			if (date[i] == 0 && i % m_N != 0)
			{
				date[i] = date[i - 1];
				date[i - 1] = 0;
				break;
			}
		}
		break;
	}
}
int ifhave(const Shudu& a)				//判断随机生成的地图是否有解 
{
	int reverse = 0;				//逆序数为奇数时无解，为偶数时有解 
	int i, j;
	for (i = 0; i < a.m_N * a.m_N - 1; i++)
	{
		if (a.date[i] == 0)
			continue;
		for (j = i + 1; j < a.m_N * a.m_N; j++)
		{
			if (a.date[j] == 0)
				continue;
			if (a.date[i] != 0 && a.date[i] > a.date[j])//不是最大的数且又比后面的数字大，逆序数加1 
			{
				reverse++;
			}
		}
	}
	if (reverse % 2 == 0)  //逆序数为偶数，拼图有解 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool Shudu::gameover() {
	int i;
	for (i = 0; i < m_N * m_N - 2; i++)
	{
		if (date[i] > date[i + 1])
		{
			return 0;
		}
		if (date[m_N * m_N - 1] != 0) {
			return 0;
		}
	}
	return 1;
}


int main()
{
	MYGAME mygame(2200311015, "linjianbo");
	mygame.START();
	mygame.END();
	mygame.RESTART();
	Shudu play;


	cout << "请输入您要玩的九宫格拼图长度：";
	int N;
	cin >> N;
	while (1) {
		play.setdate(N);
		if (ifhave(play)) {
			break;
		}
	}
	play.showdate();
	while (1) {
		play.OnKeyboard();
		system("CLS");
		play.showdate();
		if (play.gameover()) {
			cout << "恭喜您，您成功了" << endl;
			break;
		}
	}
	system("pause");
		return 0;
}