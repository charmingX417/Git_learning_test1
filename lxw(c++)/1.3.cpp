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
	cout << "�Ƿ�����ڴ�����?(Y/N)��";
	while (cin >> c)
	{
		
		if (c != 'Y' && c != 'N' && c != 'y' && c != 'n')continue;
		else if (c == 'Y' || c == 'y') 
		{
			cout << "�����趨�µ��ڴ棺 "  ;
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
	cout << "�ڴ��������" << endl;
	cout << "�µ��ڴ�Ϊ:" << Memory << "GB" << endl;
}
void Myphone::SetSys()
{
	cout << "�����ֻ���ɹ�������Ϊ�ֻ��趨��Ϣ��" << endl;
	cout << "�ֻ�Ʒ�ƣ� "  ;
	cin.get(Brand, 80);
	cin.get();
	cout << "�ֻ�ϵͳ:  ";
	cin.get(System, 80);
	cout << "�趨�ɹ�!" << endl;
}
void Myphone::BrowseMemo()
{
	cout << "\n���ڲ鿴�ֻ��ڴ�\n���ֻ��ڴ�Ϊ��" << Memory << "GB" << endl;
}
void Myphone::BrowseSys()
{
	cout << "\n���ڲ鿴�ֻ���Ϣ\n���ֻ���Ʒ���ǣ�" << Brand << "  " << "ϵͳ�ǣ�" << System << endl;
}
void Myphone::UpdateSys() 
{
	char b;
	int block = 500;

	cout << "���ڼ�����" << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << "\n��鵽ϵͳ���µĸ��£��Ƿ���и��£���Y/N��" << endl;
		
		
		while (cin >> b)
		{
			if (b == 'Y' || b == 'y')
			{
				for (int i = 0; i < block; i++)
				{
					if (i < block - 1) { printf("\r������[%.2lf%%]:", i * 100.0 / (block - 1)); }
					else { printf("\r�������[%.2lf%%]:", i * 100.0 / (block - 1)); }

					int num = i * 20 / block;
					for (int j = 1; j <= num; j++) { cout << "����"; Sleep(10); }
				}
				cout << endl;
				break;
			}
			else if (b == 'N' || b == 'n')
			{
				cout << "\n�����˳�����ϵͳ������";
				Sleep(2000);
				cout << "\n���˳�" << endl;
				break;
			}
			else { continue; }
		}

}
