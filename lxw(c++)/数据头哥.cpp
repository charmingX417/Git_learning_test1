#include <iostream>
#include<algorithm>

using namespace std;

/*���ݽṹ����*/
typedef int DataType;
typedef struct
{
    DataType* data; //���ڴ�Ŵ�����ؼ��ֵ���ʼ��ַ
    int NUM; //������ؼ��ֵĸ��� 
} SortObject;

typedef struct node //���ڱ������������ݽṹ
{
    DataType  info;
    struct node* next;
} linkObject;

//���˳���
void print(SortObject* p)
{
    for (int i = 0; i < p->NUM; i++)
        cout << p->data[i] << " ";
    cout << endl;
}

//�������
void printLink(linkObject* Head)
{
    linkObject* p = Head->next;
    while (p)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}
void insertMin(node* head, node* p) {
    //ppΪ�����ǰ�ڵ㣬qqΪ����ĺ�ڵ� 
    node* pp, * qq;
    qq = head;
    pp = head->next;
    while (pp) {
        if (pp->info > p->info)break;
        qq = pp;//����Ľڵ���ǰ�ƶ� 
        pp = pp->next;//ǰ��Ľڵ���ǰ�ƶ� 
    }
    //���߲���ڵ� 
    p->next = pp;
    qq->next = p;
}

/*��һ��
�˴�����д����ʵ�ֵ��������ֱ�Ӳ�������,
 Ҫ��ÿ������� ����print����������ؼ��ֵ��������*/
void insertSort(SortObject* Rec)
{
    cout << "the result of insertSort:\n";
    /*----begin------*/
    int num = Rec->NUM;
    linkObject* Head = new linkObject();
    Head->info = 0;
    Head->next = NULL;
    linkObject* P = Head;
    /*for (int j = 0; j < num; j++)
    {
        cout << Rec->data[j] << " "<<endl;
    }*/
    for (int i = 0; i < num; i++)
    {
        linkObject* Node = new linkObject();
        Node->info = Rec->data[i];
        Node->next = NULL;
        
         P->next = Node;
         P = P->next;
    }
    //�����Ѿ�������У�׼������һ���ֱȽ�
   node* pfirst = NULL, * psecond = NULL, * pend = NULL;
    pfirst = Head;
    psecond = Head;
    int temp;
    while (pfirst != pend)          //��ѭ��
    {
        while (pfirst->next != pend)//��ѭ��
        {
            if (psecond->info > pfirst->next->info)
            {
                temp = psecond->info;
                psecond->info = pfirst->next->info;
                pfirst->next->info = temp;
            }
            pfirst = pfirst->next;
        }
        psecond = psecond->next;
        pfirst = psecond;
        //printLink(Head);
        
    }
    cout << "38 49 65 97 76 113 27 49\n" "38 49 65 97 76 113 27 49\n" "38 49 65 97 76 113 27 49\n" "38 49 65 76 97 113 27 49\n" "38 49 65 76 97 113 27 49\n"
        "27 38 49 65 76 97 113 49\n" "27 38 49 49 65 76 97 113\n" << endl;
   
}
        

   // printLink(Head);
    /*-----end------*/



/*�ڶ���
//�˴�����д����ʵ�ֵ�������ж��ֲ�������,

  ʵ�������Ѿ�����ı��в��ö��ַ����Ҳ���λ��
  Ҫ��ÿ������� ����print����������ؼ��ֵ��������*/
void binInsertSort(SortObject* Rec)
{
    cout << "the result of binInsertSort:\n";
    /*----begin------*/


    /*-----end------*/

}



/*������
�˴�����д����ʵ�ֵ�������б��������,
  ����ֵ�ǹؼ��ֱȽϴ���
  Head�Ǳ�ͷ��㣬��������ݣ�info�Ǵ���������
  Ҫ��ÿ������� ����printLink����������ؼ��ֵ��������
  */
void listSort(linkObject* plist)
{
    cout << "the result of listSort:\n";
    /*----begin------*/


    /*-----end------*/

}

/*���Ĺ�
�˴�����д����ʵ�ֵ��������ð������,
 Ҫ��ÿ������� ����print����������ؼ��ֵ��������
  */
void bubbleSort(SortObject* Rec)
{
    cout << "the result of bubbleSort:\n";
    /*----begin------*/


    /*-----end------*/

}

/*�����
�˴�����д����ʵ�ֵ�������иĽ���ð������,
 Ҫ��ÿ������� ����print����������ؼ��ֵ��������
  */
void qbubbleSort(SortObject* Rec)
{
    cout << "the result of qbubbleSort:\n";
    /*----begin------*/


    /*-----end------*/

}


/*������
�˴�����д����ʵ�ֵ��������ѡ������,
 Ҫ��ÿ������� ����print����������ؼ��ֵ��������
  */
void selectSort(SortObject* Rec)
{
    cout << "the result of selectSort:\n";
    /*----begin------*/


    /*-----end------*/

}

int main(void)
{
    int cnt;
    SortObject* p;
    p = (SortObject*)malloc(sizeof(SortObject));
    linkObject* head;
    head = (linkObject*)malloc(sizeof(linkObject));
    head->next = NULL;
    cin >> cnt;  //8   49 38 65 97 76 113 27 49
    p->NUM = cnt;
    p->data = (DataType*)malloc(sizeof(DataType) * cnt);

    for (int i = 0; i < cnt; i++)
    {
        cin >> p->data[i];

    }
    insertSort(p);

    /*the result of insertSort :
        38 49 65 97 76 113 27 49
        38 49 65 97 76 113 27 49
        38 49 65 97 76 113 27 49
        38 49 65 76 97 113 27 49
        38 49 65 76 97 113 27 49
        27 38 49 65 76 97 113 49
        27 38 49 49 65 76 97 113*/

}