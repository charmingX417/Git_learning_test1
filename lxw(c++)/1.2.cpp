#include<iostream>

using namespace std;

class ISBN {
public:
	unsigned int isbn;
	char is[100] = { 0 };
	int legal10(int i);
	int legal13(int n);
};
int main()
{
	ISBN I;
	int result;
	int n = 0;

	
		cout << "输入一个ISBN号" << endl;
		while ((cin.peek() != '\n') && cin >> I.is[n]) { n++; }

		if (n != 10 && n != 13)
		{
			cout << "该ISBN号不合法" << endl;
			goto leap;
		}

		if (n == 10)
		{
			result = I.legal10(n);
			if (result % 11 == 0)
				cout << "该ISBN号合法" << endl;
			else if (result % 11 != 0)
				cout << "该ISBN号非法" << endl;
		}
		else if (n == 13)
		{
			result = I.legal13(n);
			if (result % 10 == 0)
				cout << "该ISBN号合法" << endl;
			else if (result % 10 != 0)
				cout << "该ISBN号非法" << endl;
		}
	
leap:	return 0;
}
int ISBN::legal10(int i)
{
	int cnt = i;
	int sum = 0;
	for (int j = 0;j<i;j++)
	{
		sum += (is[j]-'0') * cnt;
		cnt--;
	}
	return sum;
}
int ISBN::legal13(int n)
{
	int cnt = n;
	int sum = 0;
	for (int j = 0; j < n; j++)
	{
		if ((j + 1) % 2 != 0)
		{
			sum += (is[j] - '0') * 1;
		}
		else if ((j + 1) % 2 == 0)
		{
			sum += (is[j] - '0') * 3;
		}
	}
	return sum;
}