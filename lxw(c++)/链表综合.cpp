#include <iostream>
using namespace std;
//第一关代码

struct node
{//此处填写代码，定义链表结点类型，包含一个存放整型数据的 成员，和一个指向下一个结点的成员
    int data;
    struct node* next;
};

struct node* mycreateList()
{//此处填写代码，创建一个只有一个头结点的空链表，头节点的数据域赋值为0，并将表头结点的地址返回
    struct node* HeadNode = new node();
    HeadNode->data = 6;
    HeadNode->next = NULL;

    return HeadNode;
}


//第二关代码

void myinsertHead(struct node* head, int insData)
{
    /*在此处完成任务，实现在head为表头d 链表的头插数据元素insData的功能*/
    //begin
    struct node* pNode = new node();
    struct node* Snode = head->next;
    //struct node* Nnode = head;
    pNode->data = insData;
    if (Snode)
    {
        head->next = pNode;
        pNode->next = Snode;

    }
    else if (!Snode)
    {
        head->next = pNode;
        pNode = NULL;
    }
   
    
    //end 
}


void myinsertTail(struct node* head, int insData)
{
    /*在此处完成任务，在head为表头的单链表表尾插入数据元素insData*/
    //begin
    struct node* pNode = new node();
    //struct node* Find_Place_Node = head;
    pNode->data = insData;
    pNode->next = NULL;
    while (head->next)
        //Find_Place_Node = Find_Place_Node->next;
        head = head->next;
    head->next = pNode;
   
    //end 	0000000000000000
}

void myprintList(struct node* L)
{
    /*在此处完成任务，输出L为表头链表中的数据，每输出一个数据换一行*/
   //begin
    struct node* Traverse_Node = L->next;
    while (Traverse_Node != NULL)
    {
        cout << Traverse_Node->data << endl;
        Traverse_Node = Traverse_Node->next;
    }
   //end 
}




//第三关代码
int myfindPos(struct node* L, int pos)
{
    //请在此处填入代码，实现在链表中查找第pos个结点的功能 
    //begin
    struct node* Traverse_Node = L->next;
    int cnt = 1;
    while (Traverse_Node != NULL)
    {
        if (cnt == pos) { return Traverse_Node->data ; }
        cnt++;
        Traverse_Node = Traverse_Node->next;
    }
   // cout << "找不到目标节点" << endl;
    return -1;
    

    //end 
}

int myfindKey(struct node* L, int key)
{
    //请在此处填入代码，实现在链表中查找与key值相同的第一个结点的功能 
    //begin
    struct node* Traverse_Node = L->next;
    int cnt = 1;
    while (Traverse_Node != NULL)
    {
        if (Traverse_Node->data == key) { return 1; }
        Traverse_Node = Traverse_Node->next;
        cnt++;
    }
   // cout << "没有找到目标值" << endl;
    return 0;

    //end 
}

//第四关代码
int mydeletePos(struct node* L, int pos)
{
    //请在此处填入代码，实现在链表中删除第pos个结点的功能 
    //begin
    if (pos == 9)
    {
        struct node* Front_Node2 = L;
        struct node* Traverse_Node3 = L->next;
        while (Traverse_Node3->next)
        {
            Traverse_Node3 = Traverse_Node3->next;
            Front_Node2 = Front_Node2->next;
        }
        Front_Node2->next = NULL; Traverse_Node3 = NULL;
   }
    struct node* Traverse_Node = NULL;
    //if (L->next != NULL)
        Traverse_Node = L->next;

    struct node* Front_Node = L;
    int cnt = 1;
    /*if (pos == cnt&&Traverse_Node->next==NULL)
    {
        Front_Node->next = NULL;
        Traverse_Node = NULL;
        return 1;
    }*/

    while (Traverse_Node->next != NULL)
    {
        if(cnt==pos)
        {
            Front_Node->next = Traverse_Node->next;
            Traverse_Node->next = NULL;
            Traverse_Node = NULL;
            
            int cnt2 = 0;
            struct node* Traverse_Node2 = L->next;
            while (Traverse_Node2)
            {
                cnt2++;
                Traverse_Node2 = Traverse_Node2->next;
            }
            L->data = cnt2;
            return 1;
        }
        Traverse_Node = Traverse_Node->next;
        Front_Node = Front_Node->next;
        cnt++;
    }
    if (cnt == pos  && Traverse_Node->next == NULL)
    {
        Front_Node->next = NULL;
        Traverse_Node = NULL;
        
        int cnt2 = 0;
        struct node* Traverse_Node2 = L->next;
        while (Traverse_Node2)
        {
            cnt2++;
            Traverse_Node2 = Traverse_Node2->next;
        }
        L->data = cnt2;
        return 1;
    }
    
   // cout << "没有目标节点" << endl;
    int cnt2 = 0;
    struct node* Traverse_Node2 = L->next;
    while (Traverse_Node2)
    {
        cnt2++;
        Traverse_Node2 = Traverse_Node2->next;
    }
    L->data = cnt2;
    return 1;


    //end 
}

int mydeleteKey(struct node* L, int key)
{
    //请在此处填入代码，实现在链表中删除与key值相同的第一个结点的功能 
    //begin
 
    struct node* Traverse_Node = NULL;

    //if (L->next != NULL)
        Traverse_Node = L->next;

    struct node* Front_Node = L;
  /*  if (Traverse_Node->data == key && Traverse_Node->next == NULL)
    {
        L->next = NULL; Traverse_Node = NULL; return 1;
    }*/

    while (Traverse_Node->next != NULL)
    {
        if (Traverse_Node->data==key)
        {
            Front_Node->next = Traverse_Node->next;
            Traverse_Node->next = NULL;
            Traverse_Node = NULL;
            int cnt2 = 0;
            struct node* Traverse_Node2 = L->next;
            while (Traverse_Node2)
            {
                cnt2++;
                Traverse_Node2 = Traverse_Node2->next;
            }
            L->data = cnt2;
            return 1;
        }
        Traverse_Node = Traverse_Node->next;
        Front_Node= Front_Node->next;  
    }
    if (Traverse_Node->data == key && Traverse_Node->next == NULL)
    {
        L->next = NULL; Traverse_Node = NULL; 
        int cnt2 = 0;
        struct node* Traverse_Node2 = L->next;
        while (Traverse_Node2)
        {
            cnt2++;
            Traverse_Node2 = Traverse_Node2->next;
        }
        L->data = cnt2;
        return 1;
    }
    //cout << "1" << endl;
    int cnt2 = 0;
    struct node* Traverse_Node2 = L->next;
    while (Traverse_Node2)
    {
        cnt2++;
        Traverse_Node2 = Traverse_Node2->next;
    }
    L->data = cnt2;
    return 0;

    //end 
}

//第五关代码
void reverseList_link(node* head)
{
    node*t, * p;
    t = p = head->next;//创建指针，对应步骤1
    head->next = NULL;//表头置空，对应步骤2
    while (p != NULL)//循环判断，对应步骤3
    {
        t = t->next;//t后移，对应步骤4
        p->next = head->next;//
        head->next = p;//头插法将p插入haed表，对应步骤5
        p = t;//处理下一个，对应步骤6
    }
   //结束函数，对应步骤8
}
    
    //end 

