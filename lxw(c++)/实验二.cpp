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

	cout <<"现在是" << YEAR << "年" << MONTH << "月" << DAY << "日" << endl;
}

void DATE::Set_Date(int YEAR, int MONTH, int DAY)
{
	this->YEAR = YEAR;
	this->MONTH = MONTH;
	this->DAY = DAY;
	cout << "设置完毕" << endl;
}
void DATE::Add_Date()
{
	cout << "\n\n" << "现在的日期是" << YEAR << "年" << MONTH << "月" << DAY << "日" << endl;
	DAY++;
	cout << "日期前进一天..." << endl;
	cout << "现在是" << YEAR << "年" << MONTH << "月" << DAY << "日\n" << endl;
}

int main()
{
	DATE date;
	date.ShowDate();
	cout << "输入新的日期" << endl;
	int year, month, day;
	cout << "年:"; cin >> year;
	cout << "月:"; cin >> month;
	cout << "日:"; cin >> day;
	date.Set_Date(year, month, day);

	date.Add_Date();
	date.Add_Date();

	return 0;
}
