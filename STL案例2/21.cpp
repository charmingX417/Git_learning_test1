//STL����2 Ա�����顣
//��Ƹ10��Ա����ָ��Ա�����벿�Ź��� ����Ա����Ϣ�� ������������ɣ����ŷ�Ϊ�߻��������з�
//��10Ա��������䲿�ź͹���
//ͨ��multimap������Ϣ�Ĳ��룬key�����ű�ţ� value��Ա����
//�ֲ�����ʾԱ����Ϣ

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
		worker.name = "Ա��";
		worker.name += nameseed[i];

		worker.salary = rand() % 10000 + 10001;

		v.push_back(worker);
	}
}
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//ÿһ��ѭ����ָ��һ��Ա������

		int deptID = rand() % 3 + 1;//������1��2��3

		//��Ա�����뵽������
		m.insert(make_pair(deptID, *it));//insert ���涼�Ƕ��飬��make_pair����

	}
}
void showWorker_ByGroup(multimap<int,Worker>&m)
{
	// ��multimap���������ݴ洢���Ϊ��1(key) A B C    2(key) D E   3(key) F G.....
	
	cout << "�߻�����:" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA); //���ùؼ�ֵ����,pos��ָ�����A
	int cnt = m.count(CEHUA); //ͳ�����ڹؼ�ֵCEHUA�ĳ�Ա�ж��ٸ�
	
	for (int index = 0; pos != m.end() && index < cnt; pos++, index++)//�������������ֻ����ĳ��KEY�µĳ�Ա
	{
		cout << "����:" << pos->second.name << "\t����:" << pos->second.salary<<endl;
		//POSĿǰ��ָ���λ����map�����е�Ԫ�أ���mapԪ���е�Ԫ�ض��Ƕ��飬������Ԫ�أ���һ����key
		//�����Ҫ������mapԪ������ĳ�Ա����Ҫ���õ��ڶ���Ԫ��
	}
	cout << "---------------------" << endl;
	
	cout << "��������:" << endl;
	pos = m.find(MEISHU); 
	cnt = m.count(MEISHU); 

	for (int index = 0; pos != m.end() && index < cnt; pos++, index++)
	{
		cout << "����:" << pos->second.name << "\t����:" << pos->second.salary<<endl;
	}
	cout << "---------------------" << endl;

	cout << "�з�����:" << endl;
	pos = m.find(YANFA);
	cnt = m.count(YANFA); 

	for (int index = 0; pos != m.end() && index < cnt; pos++, index++)
	{
		cout << "����:" << pos->second.name << "\t����:" << pos->second.salary<<endl;
	}
}
int main()
{
	//1.����Ա��
	vector<Worker> vec;
	creatWorker(vec);
	////����
	//for (vector<Worker>::iterator it = vec.begin(); it != vec.end(); it++)
	//{
	//	cout << "����:" << it->name << "����" << it->salary << endl;
	//}
	// 
	//2.Ա������
	multimap<int,Worker> map; //multimap �ĳ�ʼ����������������һ����key�����ͣ�һ���Ǵ洢����������
	setGroup(vec,map);
	//3. Ա����ʾ
	showWorker_ByGroup(map);

	system("pause");

	return 0;

}