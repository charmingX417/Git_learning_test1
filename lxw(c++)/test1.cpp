#include<iostream>
#include<string>

class Lovers
{
public:
	Lovers(std::string thename);
	void kiss(Lovers* lover);
	void ask(Lovers* lover, std::string something);

protected:
	std::string name;

	friend class Others;
};
class Boyfriend : public Lovers
{
public:
	Boyfriend(std::string thename);
};
class Girlfriend :public Lovers
{
public:
	Girlfriend(std::string thename);
};
class Others
{
public:
	Others(std::string thename);
	void kiss(Lovers* lovers);
protected:
	std::string name;
};

Lovers::Lovers(std::string thename) { name = thename; }
void Lovers::kiss(Lovers* lover)
{
	std::cout << name << "����" << lover->name << std::endl;
}
void Lovers::ask(Lovers* lover, std::string something)
{
	std::cout << "������" << lover->name << "����" << something << std::endl;
}

Boyfriend::Boyfriend(std::string thename):Lovers(thename){}
Girlfriend::Girlfriend(std::string thename) :Lovers(thename) {}
Others::Others(std::string thename) { name = thename; }

void Others::kiss(Lovers* lover)
{
	std::cout << name << "��һ��" << lover->name << std::endl;
}

int main()
{
	Boyfriend boyfriend("A��");
	Girlfriend girlfriend("B��");

	Others others("·��C");

	girlfriend.kiss(&boyfriend);//����boyfriend�����ַ���ں�������Ҫ���Ǹö���ġ����֡���Ա
	girlfriend.ask(&boyfriend, "ϴ�·���");

	others.kiss(&girlfriend);
	return 0;
}