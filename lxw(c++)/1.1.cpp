#include <iostream>
#include <string>
using namespace std;

class LIN {
public:
	void Input_xh();
	void Input_name();
	void Input_motto();
	void Print();
private:
	unsigned int xh;
	char name[20];
	char MOTTO[80];

};

void LIN::Input_xh() {
	cout << "������ѧ��" << endl;
	cin >> xh;
	cin.get();
}

void LIN::Input_name() {
	cout << "����������" << endl;
	cin.get(name, 20);
	cin.get();
}

void LIN::Input_motto() {
	cout << "����������ϲ��������" << endl;
	cin.get(MOTTO, 80);
}

void LIN::Print() {
	cout << "\n\n����:" << name << endl << "ѧ��:" << xh << endl << "ϲ���ĸ���:" << MOTTO << endl;
}

int main() {
	LIN lin;
	lin.Input_xh();
	lin.Input_name();
	lin.Input_motto();
	lin.Print();

	return 0;
}