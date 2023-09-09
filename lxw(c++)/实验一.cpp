#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string test1 = "(1100)";
	string test2 = "(0110)";
	string test3 = "(0011)";
	string a1; string a2;
	string a3; string a4;
	a3 = "(1001)"; a4 = "(0110)";
	cin >> a1;
	//while ((cin.peek() != '\n') && cin >> a2[nn]) { nn++; }

	if (a3 == test1 || a3 == test2 || a3 == test3 || a4 == test1 || a4 == test2 || a4 == test3)
	{
		cout << "error" << endl;

	}
	system("pause");
	return 0;
}
