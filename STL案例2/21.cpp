//STL案例2 员工分组。
//招聘10个员工，指派员工进入部门工作 其中员工信息有 姓名，工资组成，部门分为策划美术和研发
//给10员工随机分配部门和工资
//通过multimap进行信息的插入，key（部门编号） value（员工）
//分部门显示员工信息

#include<iostream>
#include<vector>
#include<ctime>
#include<string>
#include<map>

#define CEHUA 1
#define MEISHU 2
#define YANFA 3

using namespace std;

class Worker {
public:

	string name;
	int salary;
};

void creatWorker(vector<Worker>& v)
{
	srand((unsigned int)time(NULL));
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.name = "员工";
		worker.name += nameseed[i];

		worker.salary = rand() % 10000 + 10001;

		v.push_back(worker);
	}
}
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//每一次循环都指向一个员工个体

		int deptID = rand() % 3 + 1;//随机编号1，2，3

		//将员工插入到分组中
		m.insert(make_pair(deptID, *it));//insert 里面都是队组，用make_pair制造

	}
}
void showWorker_ByGroup(multimap<int,Worker>&m)
{
	// 现multimap容器中数据存储情况为：1(key) A B C    2(key) D E   3(key) F G.....
	
	cout << "策划部门:" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA); //利用关键值索引,pos的指向就是A
	int cnt = m.count(CEHUA); //统计属于关键值CEHUA的成员有多少个
	
	for (int index = 0; pos != m.end() && index < cnt; pos++, index++)//添加条件来限制只遍历某个KEY下的成员
	{
		cout << "姓名:" << pos->second.name << "\t工资:" << pos->second.salary<<endl;
		//POS目前所指向的位置是map容器中的元素，而map元素中的元素都是队组，有两个元素，第一个是key
		//因此想要索引到map元素里面的成员，就要引用到第二个元素
	}
	cout << "---------------------" << endl;
	
	cout << "美术部门:" << endl;
	pos = m.find(MEISHU); 
	cnt = m.count(MEISHU); 

	for (int index = 0; pos != m.end() && index < cnt; pos++, index++)
	{
		cout << "姓名:" << pos->second.name << "\t工资:" << pos->second.salary<<endl;
	}
	cout << "---------------------" << endl;

	cout << "研发部门:" << endl;
	pos = m.find(YANFA);
	cnt = m.count(YANFA); 

	for (int index = 0; pos != m.end() && index < cnt; pos++, index++)
	{
		cout << "姓名:" << pos->second.name << "\t工资:" << pos->second.salary<<endl;
	}
}
int main()
{
	//1.创建员工
	vector<Worker> vec;
	creatWorker(vec);
	////测试
	//for (vector<Worker>::iterator it = vec.begin(); it != vec.end(); it++)
	//{
	//	cout << "姓名:" << it->name << "工资" << it->salary << endl;
	//}
	// 
	//2.员工分组
	multimap<int,Worker> map; //multimap 的初始化，有两个参数，一个是key的类型，一个是存储的数据类型
	setGroup(vec,map);
	//3. 员工显示
	showWorker_ByGroup(map);

	system("pause");

	return 0;

}