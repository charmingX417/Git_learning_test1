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

//��������
struct Node* Createlist() {
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode ��Ϊ�ṹ�����
	if (headNode == NULL) {
		printf("�����ڴ�ʧ�ܣ�");
		exit(0);
	}
	headNode->next = NULL;
	return headNode;
}

//�������
struct Node* CreateNode(char* p, int date) { //��Ҫ��ʼ��������
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	int i = 0;
	if (newNode == NULL) {
		printf("�����ڴ�ʧ�ܣ�\n");
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

//������
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

//��ӡ����
void PrintNodeList(struct Node* headNode) {
	struct Node* pMove = headNode->next;  //pMoveָ��ָ��ڶ����ṹ�壬����ʼ�����ݵĽṹ��
	while (pMove) {

		printf("%s\t", pMove->name);
		printf("%d\n", pMove->price);
		pMove = pMove->next;
	}
	printf("\n");
}

//ɾ�����
void deleteAnPoint(struct Node* headNode, char* p) {
	struct Node* pointedNode = headNode->next;
	struct Node* Nodefront = headNode;
	if (pointedNode == NULL)
		printf("�޷�ɾ�����!\n");
	else {
		while (strcmp(pointedNode->name, p)) {
			Nodefront = pointedNode;
			pointedNode = pointedNode->next;
			if (pointedNode->next == NULL) {
				printf("�޷��ҵ����Ͻ��ɾ����");
				return;
			}
		}
		//whileѭ�������ҵ�����ָ�����ݵĽ��
		Nodefront->next = pointedNode->next;
		printf("ͼ����Ϣ��ɾ��\n");
		//free(pointedNode);
		pointedNode = NULL;
	}
}



//�޸Ľ��
void ChangePoiNode(struct Node* headNode, char* p) {
	struct Node* pointedNode = headNode->next;
	struct Node* Nodefront = headNode;
	if (pointedNode == NULL)
		printf("�޷��޸�!\n");
	else {
		while (strcmp(pointedNode->name, p)) {
			Nodefront = pointedNode;
			pointedNode = pointedNode->next;
			if (pointedNode->name == NULL) {
				printf("�޷��ҵ������鼮�޸ģ�");
				return;
			}
		}
		/*printf("�������µ�������");
		scanf("%s", pointedNode->name)*/;
		printf("�������µļ۸�");
		scanf_s("%d", &pointedNode->price);
		printf("-------�޸ĳɹ�-------\n");
		printf("�޸ĺ�����Ϊ%s  �۸�Ϊ%d\n", pointedNode->name, pointedNode->price);

	}



}

//���ҽ��
void FindThePoint(struct Node* headNode, char* p) {
	struct Node* pointedNode = headNode->next;
	struct Node* Nodefront = headNode;
	if (pointedNode == NULL)
		printf("�޷���������!\n");
	else {
		while (strcmp(pointedNode->name, p)) {
			Nodefront = pointedNode;
			pointedNode = pointedNode->next;
			if (pointedNode->name == NULL) {
				printf("�޷��ҵ��������ƣ�\n");
				return;
			}
		}
		printf("���ҵ��鼮����������Ϊ��%s\t�۸�Ϊ��%d\n", pointedNode->name, pointedNode->price);
	}
}

//������
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
	//�������a[0]��a[9]Ϊ��С����
	for (int k = 0; k < cnt; k++)
	{
		printf("%s\t", p[k]);
		printf("%d\n", a[k]);
	}

}
//ͳ������
void AccountInfo(struct Node* headNode) {
	int num = 0, pri = 0;
	struct Node* pFind = headNode->next;
	while (pFind) {
		num++;
		pri += pFind->price;
		pFind = pFind->next;
	}
	SortPointInfo(headNode);
	printf("�鱾����Ϊ%d\t�ܼ�Ϊ%d\n", num, pri);
}
//ϵͳ��Ϣ����
void SystemInfo() {
	printf("���ڵ���ϵͳ�����Ժ�...\n");
	Sleep(3000);
	printf("��¼�ɹ�����������в�����\n");
	printf("---------******-----------\n");
	printf("1.ͼ����Ϣ¼��\n");
	printf("2.ͼ����Ϣ����\n");
	printf("3.ͼ����Ϣ����\n");
	printf("4.ͼ����Ϣ�޸�\n");
	printf("5.ͼ����Ϣɾ��\n");
	printf("6.ͼ����Ϣ����\n");
	printf("7.ͼ����Ϣͳ��\n");
	printf("8.�˳�ϵͳ\n");
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
	char nam[5][80];//={"�����Դ�����","���ߵ���ѧ��","��C���ԡ�","����ѧӢ�","��������ԡ�"};
	char aaa[80] = { 0 };
	//int pri[5] = { 39, 49, 19, 69, 99 };
	int pri[5] = { 0 };
	while (1) {
		int a;
		printf("��ݔ��Ҫ�����Ĵ���:");
		scanf_s("%d", &a);
		//char* nam[5][80];
		//char aaa[80] = { 0 };
		switch (a) {
		case 1: //memset(nam, 0, sizeof(nam));
			printf("��¼��5��ͼ�����Ϣ...\n");
			Sleep(1000);
			for (int cnt1 = 0; cnt1 < N; cnt1++)
			{
				printf("������Ҫ¼����鼮���ƺͼ۸�\n");
				printf("���ƣ�");
				scanf_s("%s", &nam[cnt1]);
				getchar();
				printf("�۸�");
				scanf_s("%d", &pri[cnt1]);
			}
			printf("...\n");
			Sleep(2000);
			printf("--------��Ϣ¼����ϣ�--------\n");
			for (int cnt2 = 0; cnt2 < N; cnt2++)
				LinkPointNode(Books, pri[cnt2], &nam[cnt2]);
			PrintNodeList(Books);
			break;

		case 2:
			printf("����ͼ����Ϣ��������...\n");
			Sleep(3000);
			printf("��ļ۸�Ӵ�СΪ��\n");
			SortPointInfo(Books);
			printf("------������ϣ�------\n");

			break;
		case 3:
			printf("����ͼ����Ϣ���в���...\n��ݔ��Ҫ������鼮:\n");
			//Sleep(3000);
			while (1)
			{
				char ch;
				int pr = 0;
				char name[80] = { 0 };
				printf("���ƣ�");
				scanf_s("%s", name);
				getchar();
				printf("�۸�");
				scanf_s("%d", &pr);
				getchar();
				InsertAnPoint(Books, pr, name);
				//LinkPointNode(Books, pr, name);
				//SortPointInfo(Books);
				printf("����ɹ����Ƿ���������鼮��\n");
			loop:scanf_s("%c", &ch);
				getchar();
				if (ch == 'Y' || ch == 'y')
					continue;
				else if (ch == 'N' || ch == 'n')
					break;
				else if (ch != 'y' && ch != 'Y' && ch != 'N' && ch != 'n')
				{
					printf("��Ч�ַ�������ݔ��\n");
					goto loop;
				}
			}
			printf("--------��Ϣ�������--------\n");
			SortPointInfo(Books);
			break;
		case 4:
			printf("����ͼ����Ϣ�����޸�...\n��ݔ��Ҫ�޸ĵ�����:\n");
			scanf_s("%s", aaa);
			ChangePoiNode(Books, aaa);
			SortPointInfo(Books);
			break;
		case 5:
			printf("����ͼ����Ϣ����ɾ��...\n������Ҫɾ����������\n");
			Sleep(3000);
			scanf_s("%s", aaa);
			deleteAnPoint(Books, aaa);
			SortPointInfo(Books);
			break;
		case 6:
			printf("����ͼ����Ϣ���в���...\n���������������\n");
			scanf_s("%s", aaa);
			printf("."); Sleep(1000); printf("."); Sleep(1000); printf(".\n"); Sleep(1000);
			FindThePoint(Books, aaa);
			break;
		case 7:
			printf("����ͼ����Ϣ����ͳ��...\n");
			Sleep(3000);
			AccountInfo(Books);
			break;
		case 8:
			goto END;

		default:
			printf("��Ч�������룬������ݔ�룡");
			continue;
		}
	}

END:
	return 0;
}