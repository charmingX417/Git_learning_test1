#include <iostream>
using namespace std;
//��һ�ش���

struct node
{//�˴���д���룬�������������ͣ�����һ������������ݵ� ��Ա����һ��ָ����һ�����ĳ�Ա
    int data;
    struct node* next;
};

struct node* mycreateList()
{//�˴���д���룬����һ��ֻ��һ��ͷ���Ŀ�����ͷ�ڵ��������ֵΪ0��������ͷ���ĵ�ַ����
    struct node* HeadNode = new node();
    HeadNode->data = 6;
    HeadNode->next = NULL;

    return HeadNode;
}


//�ڶ��ش���

void myinsertHead(struct node* head, int insData)
{
    /*�ڴ˴��������ʵ����headΪ��ͷd �����ͷ������Ԫ��insData�Ĺ���*/
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
    /*�ڴ˴����������headΪ��ͷ�ĵ������β��������Ԫ��insData*/
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
    /*�ڴ˴�����������LΪ��ͷ�����е����ݣ�ÿ���һ�����ݻ�һ��*/
   //begin
    struct node* Traverse_Node = L->next;
    while (Traverse_Node != NULL)
    {
        cout << Traverse_Node->data << endl;
        Traverse_Node = Traverse_Node->next;
    }
   //end 
}




//�����ش���
int myfindPos(struct node* L, int pos)
{
    //���ڴ˴�������룬ʵ���������в��ҵ�pos�����Ĺ��� 
    //begin
    struct node* Traverse_Node = L->next;
    int cnt = 1;
    while (Traverse_Node != NULL)
    {
        if (cnt == pos) { return Traverse_Node->data ; }
        cnt++;
        Traverse_Node = Traverse_Node->next;
    }
   // cout << "�Ҳ���Ŀ��ڵ�" << endl;
    return -1;
    

    //end 
}

int myfindKey(struct node* L, int key)
{
    //���ڴ˴�������룬ʵ���������в�����keyֵ��ͬ�ĵ�һ�����Ĺ��� 
    //begin
    struct node* Traverse_Node = L->next;
    int cnt = 1;
    while (Traverse_Node != NULL)
    {
        if (Traverse_Node->data == key) { return 1; }
        Traverse_Node = Traverse_Node->next;
        cnt++;
    }
   // cout << "û���ҵ�Ŀ��ֵ" << endl;
    return 0;

    //end 
}

//���Ĺش���
int mydeletePos(struct node* L, int pos)
{
    //���ڴ˴�������룬ʵ����������ɾ����pos�����Ĺ��� 
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
    
   // cout << "û��Ŀ��ڵ�" << endl;
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
    //���ڴ˴�������룬ʵ����������ɾ����keyֵ��ͬ�ĵ�һ�����Ĺ��� 
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

//����ش���
void reverseList_link(node* head)
{
    node*t, * p;
    t = p = head->next;//����ָ�룬��Ӧ����1
    head->next = NULL;//��ͷ�ÿգ���Ӧ����2
    while (p != NULL)//ѭ���жϣ���Ӧ����3
    {
        t = t->next;//t���ƣ���Ӧ����4
        p->next = head->next;//
        head->next = p;//ͷ�巨��p����haed����Ӧ����5
        p = t;//������һ������Ӧ����6
    }
   //������������Ӧ����8
}
    
    //end 

