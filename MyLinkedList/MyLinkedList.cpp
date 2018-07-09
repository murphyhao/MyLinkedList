#include "iostream"

using namespace std;


typedef struct tagNode
{
	int nNum;
	double dScore;
	struct tagNode* pNext;

	tagNode(int num=0, double score=0)
	{
		nNum = num;
		dScore = score;
		pNext = NULL;
	}
}Node;

void PrintList(Node* pHead);
Node* CreateList(void);
Node* CreateList2(void);
Node* DeleteList(Node* pHead, int nNum);
Node* InsertList(Node* pHead, Node* insert);

void PrintList(Node* pHead)
{
	Node* p = pHead;
	if (NULL == p)
	{
		return;
	}
	while (p != NULL)
	{
		cout << "Num:" << p->nNum << " Score:" << p->dScore << " " << endl;
		p = p->pNext;
	}
}

Node* CreateList(void)
{
	Node* head = NULL;
	Node* p1 = NULL;
	Node* p2 = NULL;
	int nLen = sizeof(Node);
	int n = 0;

	p1 = new Node[nLen];
	cin >> p1->nNum >> p1->dScore;

	while (0 != p1->nNum)
	{
		++n;
		if (1 == n)
		{
			head = p1;
		}
		else
		{
			p2->pNext = p1;
		}
		p2 = p1;

		p1 = new Node[nLen];
		cin >> p1->nNum >> p1->dScore;
	}
	p2->pNext = NULL;

	return head;
}

Node* CreateList2(void)
{
	Node* head = NULL;
	Node* p1 = NULL;
	Node* p2 = NULL;
	int nLen = sizeof(Node);

	p1 = new Node[nLen];
	p1->nNum = 10;
	p1->dScore = 1.1;
	head = p1;
	p2 = p1;

	p1 = new Node[nLen];
	p1->nNum = 20;
	p1->dScore = 2.2;
	p2->pNext = p1;
	p2 = p1;

	p1 = new Node[nLen];
	p1->nNum = 30;
	p1->dScore = 3.3;
	p2->pNext = p1;
	p2 = p1;

	p2->pNext = NULL;

	return head;
}

Node* DeleteList(Node* pHead, int nNum)
{
	Node* p1;
	Node* p2;

	if (NULL == pHead)
	{
		return NULL;
	}
	
	p1 = pHead;
	while (nNum != p1->nNum && p1->pNext != NULL)
	{
		p2 = p1;
		p1 = p1->pNext;
	}
	if (nNum == p1->nNum)
	{
		if (p1 == pHead)
		{
			pHead = p1->pNext;
		}
		else
		{
			p2->pNext = p1->pNext;
		}
	}
	else
	{
		cout << "Not found!" << endl;
	}
	return pHead;
}

Node* InsertList(Node* pHead, Node* insert)
{
	Node* p0 = insert;
	Node* p1 = pHead;
	Node* p2 = pHead;

	if (NULL == pHead)
	{
		pHead = p0;
		p0->pNext = NULL;
	}

	while (p0->nNum > p1->nNum && p1->pNext != NULL)
	{
		p2 = p1;
		p1 = p1->pNext;
	}
	if (p0->nNum <= p1->nNum)
	{
		if (pHead == p1)
		{
			pHead = p0;
			p0->pNext = p1;
		}
		else
		{
			p2->pNext = p0;
			p0->pNext = p1;
		}
	}
	else
	{
		p1->pNext = p0;
		p0->pNext = NULL;
	}

	return pHead;
}
/*
void main(void)
{
	Node* p = NULL;
	p = CreateList2();
	//PrintList(p);

	//p = DeleteList(p, 2);
	//PrintList(p);

	Node ins(5, 1.5);
	p = InsertList(p, &ins);
	PrintList(p);
}
*/