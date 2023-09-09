#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define N 5
#define M 10

struct Node {
	char name[80];
	int price;
	struct Node* next;
};

//创建链表
struct Node* Createlist() {
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode 变为结构体变量
	if (headNode == NULL) {
		printf("分配内存失败！");
		exit(0);
	}
	headNode->next = NULL;
	return headNode;
}

//创建结点
struct Node* CreateNode(char* p, int date) { //需要初始化数据域
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	int i = 0;
	if (newNode == NULL) {
		printf("分配内存失败！\n");
		exit(0);
	}
	newNode->price = date;
	//printf("%d", newNode->price);
	while (*p != '\0') {
		newNode->name[i] = *p;
		//printf("%c", newNode->name[i]);
		p++, i++;
	}
	newNode->name[i] = '\0';
	//printf("%s\n", newNode->name);
	newNode->next = NULL;

	return newNode;
}

//插入结点
void InsertAnPoint(struct Node* headNode, int date, char* p) {
	struct Node* aNode = CreateNode(p, date);
	struct Node* NodeFront = headNode;
	struct Node* NodeNow = headNode->next;
	if (headNode->next == NULL) {
		aNode->next = headNode->next;
		headNode->next = aNode;

	}
	else if (headNode->next != NULL) {
		while (NodeNow) {
			if (NodeNow->price < aNode->price || NodeNow->price == aNode->price) {
				NodeFront->next = aNode;
				aNode->next = NodeNow;
				return;
			}
			NodeFront = NodeNow;
			NodeNow = NodeNow->next;
		}
		NodeFront->next = aNode;
		aNode->next = NULL;
		//NodeFront = NULL, NodeNow = NULL;
	}
}

//打印链表
void PrintNodeList(struct Node* headNode) {
	struct Node* pMove = headNode->next;  //pMove指针指向第二个结构体，即开始有数据的结构体
	while (pMove) {

		printf("%s\t", pMove->name);
		printf("%d\n", pMove->price);
		pMove = pMove->next;
	}
	printf("\n");
}

//删除结点
void deleteAnPoint(struct Node* headNode, char* p) {
	struct Node* pointedNode = headNode->next;
	struct Node* Nodefront = headNode;
	if (pointedNode == NULL)
		printf("无法删除结点!\n");
	else {
		while (strcmp(pointedNode->name, p)) {
			Nodefront = pointedNode;
			pointedNode = pointedNode->next;
			if (pointedNode->next == NULL) {
				printf("无法找到符合结点删除！");
				return;
			}
		}
		//while循环用于找到含有指定数据的结点
		Nodefront->next = pointedNode->next;
		printf("图书信息已删除\n");
		//free(pointedNode);
		pointedNode = NULL;
	}
}



//修改结点
void ChangePoiNode(struct Node* headNode, char* p) {
	struct Node* pointedNode = headNode->next;
	struct Node* Nodefront = headNode;
	if (pointedNode == NULL)
		printf("无法修改!\n");
	else {
		while (strcmp(pointedNode->name, p)) {
			Nodefront = pointedNode;
			pointedNode = pointedNode->next;
			if (pointedNode->name == NULL) {
				printf("无法找到符合书籍修改！");
				return;
			}
		}
		/*printf("请输入新的书名：");
		scanf("%s", pointedNode->name)*/;
		printf("请输入新的价格：");
		scanf_s("%d", &pointedNode->price);
		printf("-------修改成功-------\n");
		printf("修改后书名为%s  价格为%d\n", pointedNode->name, pointedNode->price);

	}



}

//查找结点
void FindThePoint(struct Node* headNode, char* p) {
	struct Node* pointedNode = headNode->next;
	struct Node* Nodefront = headNode;
	if (pointedNode == NULL)
		printf("无法查找书名!\n");
	else {
		while (strcmp(pointedNode->name, p)) {
			Nodefront = pointedNode;
			pointedNode = pointedNode->next;
			if (pointedNode->name == NULL) {
				printf("无法找到符合名称！\n");
				return;
			}
		}
		printf("已找到书籍，该书名字为：%s\t价格为：%d\n", pointedNode->name, pointedNode->price);
	}
}

//排序结点
void SortPointInfo(struct Node* headNode) {
	struct Node* pprice = headNode->next;
	struct Node* CntNode = headNode->next;
	int a[M] = { 0 };
	char* p[M] = { 0 };
	int i = 0, cnt = 0;
	while (CntNode)
	{
		cnt++;
		CntNode = CntNode->next;
	}
	/*int* a = (int*)malloc(sizeof(int) * cnt);
	char** p = (char**)malloc(sizeof(char*) * cnt);
	int num = cnt * 4;
	memset(a, 0, num);*/

	while (pprice) {
		a[i] = pprice->price;
		p[i] = pprice->name;
		pprice = pprice->next;
		i++;
	}
	for (int l = 0; l < cnt; l++)
	{
		for (int j = 0; j < cnt - 1 - l; j++)
		{
			char* temp = NULL;
			if (a[j] < a[j + 1])
			{
				a[j] ^= a[j + 1];
				a[j + 1] ^= a[j];
				a[j] ^= a[j + 1];

				temp = p[j + 1];
				p[j + 1] = p[j];
				p[j] = temp;

			}
		}
	}
	//排完序后a[0]到a[9]为从小到大
	for (int k = 0; k < cnt; k++)
	{
		printf("%s\t", p[k]);
		printf("%d\n", a[k]);
	}

}
//统计链表
void AccountInfo(struct Node* headNode) {
	int num = 0, pri = 0;
	struct Node* pFind = headNode->next;
	while (pFind) {
		num++;
		pri += pFind->price;
		pFind = pFind->next;
	}
	SortPointInfo(headNode);
	printf("书本总数为%d\t总价为%d\n", num, pri);
}
//系统信息提醒
void SystemInfo() {
	printf("正在登入系统，请稍后...\n");
	Sleep(3000);
	printf("登录成功！现在请进行操作：\n");
	printf("---------******-----------\n");
	printf("1.图书信息录入\n");
	printf("2.图书信息排序\n");
	printf("3.图书信息插入\n");
	printf("4.图书信息修改\n");
	printf("5.图书信息删除\n");
	printf("6.图书信息查找\n");
	printf("7.图书信息统计\n");
	printf("8.退出系统\n");
	printf("---------******-----------\n");
}

void LinkPointNode(struct Node* headNode, int date, char* p)
{
	struct Node* aNode = CreateNode(p, date);
	aNode->next = headNode->next;
	headNode->next = aNode;
}
int main(void) {
	struct Node* Books = Createlist();
	SystemInfo();
	char nam[5][80];//={"《线性代数》","《高等数学》","《C语言》","《大学英语》","《汇编语言》"};
	char aaa[80] = { 0 };
	//int pri[5] = { 39, 49, 19, 69, 99 };
	int pri[5] = { 0 };
	while (1) {
		int a;
		printf("请輸入要操作的代号:");
		scanf_s("%d", &a);
		//char* nam[5][80];
		//char aaa[80] = { 0 };
		switch (a) {
		case 1: //memset(nam, 0, sizeof(nam));
			printf("将录入5本图书的信息...\n");
			Sleep(1000);
			for (int cnt1 = 0; cnt1 < N; cnt1++)
			{
				printf("请输入要录入的书籍名称和价格：\n");
				printf("名称：");
				scanf_s("%s", &nam[cnt1]);
				getchar();
				printf("价格：");
				scanf_s("%d", &pri[cnt1]);
			}
			printf("...\n");
			Sleep(2000);
			printf("--------消息录入完毕！--------\n");
			for (int cnt2 = 0; cnt2 < N; cnt2++)
				LinkPointNode(Books, pri[cnt2], &nam[cnt2]);
			PrintNodeList(Books);
			break;

		case 2:
			printf("将对图书信息进行排序...\n");
			Sleep(3000);
			printf("书的价格从大到小为：\n");
			SortPointInfo(Books);
			printf("------排序完毕！------\n");

			break;
		case 3:
			printf("将对图书信息进行插入...\n请輸入要插入的书籍:\n");
			//Sleep(3000);
			while (1)
			{
				char ch;
				int pr = 0;
				char name[80] = { 0 };
				printf("名称：");
				scanf_s("%s", name);
				getchar();
				printf("价格：");
				scanf_s("%d", &pr);
				getchar();
				InsertAnPoint(Books, pr, name);
				//LinkPointNode(Books, pr, name);
				//SortPointInfo(Books);
				printf("插入成功！是否继续插入书籍？\n");
			loop:scanf_s("%c", &ch);
				getchar();
				if (ch == 'Y' || ch == 'y')
					continue;
				else if (ch == 'N' || ch == 'n')
					break;
				else if (ch != 'y' && ch != 'Y' && ch != 'N' && ch != 'n')
				{
					printf("无效字符！重新輸入\n");
					goto loop;
				}
			}
			printf("--------信息插入完毕--------\n");
			SortPointInfo(Books);
			break;
		case 4:
			printf("将对图书信息进行修改...\n请輸入要修改的书名:\n");
			scanf_s("%s", aaa);
			ChangePoiNode(Books, aaa);
			SortPointInfo(Books);
			break;
		case 5:
			printf("将对图书信息进行删除...\n请输入要删除的书名：\n");
			Sleep(3000);
			scanf_s("%s", aaa);
			deleteAnPoint(Books, aaa);
			SortPointInfo(Books);
			break;
		case 6:
			printf("将对图书信息进行查找...\n请输入查找书名：\n");
			scanf_s("%s", aaa);
			printf("."); Sleep(1000); printf("."); Sleep(1000); printf(".\n"); Sleep(1000);
			FindThePoint(Books, aaa);
			break;
		case 7:
			printf("将对图书信息进行统计...\n");
			Sleep(3000);
			AccountInfo(Books);
			break;
		case 8:
			goto END;

		default:
			printf("无效操作代码，请重新輸入！");
			continue;
		}
	}

END:
	return 0;
}