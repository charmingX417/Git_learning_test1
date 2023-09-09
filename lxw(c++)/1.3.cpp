#include<iostream>
#include<windows.h>
using namespace std;

class Myphone 
{
public:
	Myphone(int pri, int mem) { Price = pri; Memory = mem; };
	void BrowseMemo();
	void SetMemo();
	void BrowseSys();
	void UpdateSys();
	void SetSys();
	~Myphone();
private:
	char Brand[80];
	char System[80];
	int  Memory;
	int Price;
};

int main()
{
	int price = 2000;
	int memo = 64;
	char c;
	Myphone myphone(price,memo);

	myphone.SetSys();
	myphone.BrowseMemo();
	cout << "是否进行内存设置?(Y/N)：";
	while (cin >> c)
	{
		
		if (c != 'Y' && c != 'N' && c != 'y' && c != 'n')continue;
		else if (c == 'Y' || c == 'y') 
		{
			cout << "正在设定新的内存： "  ;
			myphone.SetMemo();
			break;
		}
		else if(c=='N'||c=='n') break;
	}
	myphone.BrowseSys();
	myphone.UpdateSys();


	return 0;
}

void Myphone::SetMemo()
{
	int num;
	cin >> num;
	Memory = num;
	cout << "内存设置完毕" << endl;
	cout << "新的内存为:" << Memory << "GB" << endl;
}
void Myphone::SetSys()
{
	cout << "创建手机类成功，正在为手机设定信息：" << endl;
	cout << "手机品牌： "  ;
	cin.get(Brand, 80);
	cin.get();
	cout << "手机系统:  ";
	cin.get(System, 80);
	cout << "设定成功!" << endl;
}
void Myphone::BrowseMemo()
{
	cout << "\n正在查看手机内存\n该手机内存为：" << Memory << "GB" << endl;
}
void Myphone::BrowseSys()
{
	cout << "\n正在查看手机信息\n该手机的品牌是：" << Brand << "  " << "系统是：" << System << endl;
}
void Myphone::UpdateSys() 
{
	char b;
	int block = 500;

	cout << "正在检查更新" << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << "\n检查到系统有新的更新，是否进行更新？（Y/N）" << endl;
		
		
		while (cin >> b)
		{
			if (b == 'Y' || b == 'y')
			{
				for (int i = 0; i < block; i++)
				{
					if (i < block - 1) { printf("\r更新中[%.2lf%%]:", i * 100.0 / (block - 1)); }
					else { printf("\r更新完成[%.2lf%%]:", i * 100.0 / (block - 1)); }

					int num = i * 20 / block;
					for (int j = 1; j <= num; j++) { cout << "██"; Sleep(10); }
				}
				cout << endl;
				break;
			}
			else if (b == 'N' || b == 'n')
			{
				cout << "\n正在退出更新系统。。。";
				Sleep(2000);
				cout << "\n已退出" << endl;
				break;
			}
			else { continue; }
		}

}
