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
	cout << "请输入学号" << endl;
	cin >> xh;
	cin.get();
}

void LIN::Input_name() {
	cout << "请输入姓名" << endl;
	cin.get(name, 20);
	cin.get();
}

void LIN::Input_motto() {
	cout << "请输入你最喜欢的名言" << endl;
	cin.get(MOTTO, 80);
}

void LIN::Print() {
	cout << "\n\n姓名:" << name << endl << "学号:" << xh << endl << "喜欢的格言:" << MOTTO << endl;
}

int main() {
	LIN lin;
	lin.Input_xh();
	lin.Input_name();
	lin.Input_motto();
	lin.Print();

	return 0;
}