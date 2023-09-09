#include <iostream>
#include<algorithm>

using namespace std;

/*数据结构定义*/
typedef int DataType;
typedef struct
{
    DataType* data; //用于存放待排序关键字的起始地址
    int NUM; //待排序关键字的个数 
} SortObject;

typedef struct node //用于表插入排序的数据结构
{
    DataType  info;
    struct node* next;
} linkObject;

//输出顺序表
void print(SortObject* p)
{
    for (int i = 0; i < p->NUM; i++)
        cout << p->data[i] << " ";
    cout << endl;
}

//输出链表
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
    //pp为链表的前节点，qq为链表的后节点 
    node* pp, * qq;
    qq = head;
    pp = head->next;
    while (pp) {
        if (pp->info > p->info)break;
        qq = pp;//后面的节点向前移动 
        pp = pp->next;//前面的节点向前移动 
    }
    //连线插入节点 
    p->next = pp;
    qq->next = p;
}

/*第一关
此处请填写代码实现递增序进行直接插入排序,
 要求每趟排序后 调用print函数，输出关键字的排列情况*/
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
    //现在已经插入表中，准备进行一轮轮比较
   node* pfirst = NULL, * psecond = NULL, * pend = NULL;
    pfirst = Head;
    psecond = Head;
    int temp;
    while (pfirst != pend)          //外循环
    {
        while (pfirst->next != pend)//内循环
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



/*第二关
//此处请填写代码实现递增序进行二分插入排序,

  实质是在已经有序的表中采用二分法查找插入位置
  要求每趟排序后 调用print函数，输出关键字的排列情况*/
void binInsertSort(SortObject* Rec)
{
    cout << "the result of binInsertSort:\n";
    /*----begin------*/


    /*-----end------*/

}



/*第三关
此处请填写代码实现递增序进行表插入排序,
  返回值是关键字比较次数
  Head是表头结点，不存放数据，info是待插入数据
  要求每趟排序后 调用printLink函数，输出关键字的排列情况
  */
void listSort(linkObject* plist)
{
    cout << "the result of listSort:\n";
    /*----begin------*/


    /*-----end------*/

}

/*第四关
此处请填写代码实现递增序进行冒泡排序,
 要求每趟排序后 调用print函数，输出关键字的排列情况
  */
void bubbleSort(SortObject* Rec)
{
    cout << "the result of bubbleSort:\n";
    /*----begin------*/


    /*-----end------*/

}

/*第五关
此处请填写代码实现递增序进行改进的冒泡排序,
 要求每趟排序后 调用print函数，输出关键字的排列情况
  */
void qbubbleSort(SortObject* Rec)
{
    cout << "the result of qbubbleSort:\n";
    /*----begin------*/


    /*-----end------*/

}


/*第六关
此处请填写代码实现递增序进行选择排序,
 要求每趟排序后 调用print函数，输出关键字的排列情况
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