#include<iostream>
#include<ctime>
using namespace std;


class DATE {
public:
	DATE() {};
	void ShowDate();
	void Set_Date(int YEAR,int MONTH,int DAY);
	void Add_Date();

private:
	long YEAR;
	long MONTH;
	long DAY;
};

void DATE::ShowDate() 
{
	struct tm t;
	time_t now; time(&now);
	localtime_s(&t, &now);
	YEAR = t.tm_year+1900; MONTH = t.tm_mon+1; DAY = t.tm_mday;

	cout <<"������" << YEAR << "��" << MONTH << "��" << DAY << "��" << endl;
}

void DATE::Set_Date(int YEAR, int MONTH, int DAY)
{
	this->YEAR = YEAR;
	this->MONTH = MONTH;
	this->DAY = DAY;
	cout << "�������" << endl;
}
void DATE::Add_Date()
{
	cout << "\n\n" << "���ڵ�������" << YEAR << "��" << MONTH << "��" << DAY << "��" << endl;
	DAY++;
	cout << "����ǰ��һ��..." << endl;
	cout << "������" << YEAR << "��" << MONTH << "��" << DAY << "��\n" << endl;
}

int main()
{
	DATE date;
	date.ShowDate();
	cout << "�����µ�����" << endl;
	int year, month, day;
	cout << "��:"; cin >> year;
	cout << "��:"; cin >> month;
	cout << "��:"; cin >> day;
	date.Set_Date(year, month, day);

	date.Add_Date();
	date.Add_Date();

	return 0;
}
