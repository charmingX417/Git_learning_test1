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
	std::cout << name << "亲亲" << lover->name << std::endl;
}
void Lovers::ask(Lovers* lover, std::string something)
{
	std::cout << "宝贝儿" << lover->name << "帮我" << something << std::endl;
}

Boyfriend::Boyfriend(std::string thename):Lovers(thename){}
Girlfriend::Girlfriend(std::string thename) :Lovers(thename) {}
Others::Others(std::string thename) { name = thename; }

void Others::kiss(Lovers* lover)
{
	std::cout << name << "亲一亲" << lover->name << std::endl;
}

int main()
{
	Boyfriend boyfriend("A君");
	Girlfriend girlfriend("B妹");

	Others others("路人C");

	girlfriend.kiss(&boyfriend);//传入boyfriend对象地址，在函数中需要的是该对象的“名字”成员
	girlfriend.ask(&boyfriend, "洗衣服拉");

	others.kiss(&girlfriend);
	return 0;
}