#include<iostream>
#include<cstdlib>
using namespace std;
#define Maxsize 30
//title : using the struct array  to describe a list
struct ListNode {
	int last;
	int value[Maxsize];
};
static int time__ = 1;
struct ListNode* initList();
void initList(ListNode* p);
void push_back(ListNode* p, const int be_push_backed_num);
void insert_nth(ListNode* p, int i, const int be_push_backed_num);
bool isempty(ListNode* p);
size_t ListLength(ListNode* p);
int find(ListNode* p, int be_finded_Element);
int getData(ListNode* p, int i);
void pop_back(ListNode* p);
void del_nth(ListNode* p, int i);
void destroyList(ListNode* p);
void watch(ListNode* p);
void operate(ListNode* l1);
ListNode* attach(ListNode* l1, ListNode* l2);
int main()
{
	printf("(1)顺序表初始化L\n");
	struct ListNode* p = initList();
	printf("(2)依次插入12, 10, 60, 30, 11, 17, 80元素\n");
	push_back(p, 12);
	push_back(p, 10);
	push_back(p, 60);
	push_back(p, 30);
	push_back(p, 11);
	push_back(p, 17);
	push_back(p, 80);
	printf("(3)输出顺序表L:\n");
	watch(p);
	printf("(4)输出顺序表的长度:%zu\n", ListLength(p));
	printf("(5)判断线性表为:%s\n", isempty(p) == 0 ? "空" : "非空");
	printf("(6)输出线性表第3个元素:%d\n", getData(p, 2));
	printf("(7)输出12的位置:%d\n", find(p, 12));
	printf("(8)在第4个元素位置上插入元素999\n");
	insert_nth(p, 4, 999);
	printf("(9)输出线性表:\n");
	watch(p);
	printf("(10)删除L的第3个元素\n");
	del_nth(p, 2);
	printf("(11)输出线性表L:\n");
	watch(p);
	printf("(12)释放顺序表L:\n");
	destroyList(p);
	ListNode* l1 = initList();
	operate(l1);
	ListNode* l2 = initList();
	operate(l2);
	printf("%zu\n", ListLength(l2));
	ListNode* l3 = attach(l1, l2);
	printf("得到合并之后的顺序表：\n");
	watch(l3);
	printf("合并后的长度=%zu\n",ListLength(l3));
	return 0;
}
void operate(ListNode* l1)
{

	int len_of_list;
	printf("输入顺序表%d的长度：\n",time__);
	scanf_s("%d", &len_of_list);
	int val;
	printf("输入顺序表%d的元素（以空格为界）：\n",time__);
	for (int i = 0; i < len_of_list; i++)
	{
		scanf_s("%d", &val);
		push_back(l1, val);
	}
	time__++;
	if (time__ > 2)time__ = 1;
}
ListNode* attach(ListNode* l1, ListNode* l2)
{
	int sumLen = ListLength(l1) + ListLength(l2);
	ListNode* l3 = initList();
	l3->last += sumLen;
	
	for (int i = 0; i < l1->last; i++)
	{
		l3->value[i] = l1->value[i];
	}
	for (int i = l1->last, j = 0; i < l3->last; i++, j++)
	{
		l3->value[i] = l2->value[j];
	}
	
	
	return l3;
}

struct ListNode* initList()
{
	struct ListNode* p = (ListNode*)malloc(sizeof(struct ListNode));
	if (p != NULL)
		p->last = 0;
	return p;
}
#if 1
bool isempty(ListNode* p)
{
	return p->last == 0;
}
void push_back(ListNode* p, const int be_push_backed_num)
{
	int index = p->last++;
	if (p->last < Maxsize)
		p->value[index] = be_push_backed_num;


}
void insert_nth(ListNode* p, int i, const int be_push_backed_num)
{
	p->last++;
	if (p->last < Maxsize)
	{
		for (int j = p->last; j >= i; j--)
		{
			p->value[j] = p->value[j - 1];
		}
		p->value[i - 1] = be_push_backed_num;
	}

}
void pop_back(ListNode* p)
{
	if (!isempty(p))
	{
		p->value[p->last--] = 0;
	}
}
void del_nth(ListNode* p, int i)
{
	for (int j = i; j < p->last; j++)
	{
		p->value[j] = p->value[j + 1];
	}
	p->last--;
}
size_t ListLength(ListNode* p)
{
	return p->last;
}
int find(ListNode* p, int be_finded_Element)
{
	int i;
	for (i = 0; i < p->last; i++)
	{
		if (p->value[i] == be_finded_Element)
		{
			return i + 1;
		}
	}
	return -1;
}
int getData(ListNode* p, int i)
{
	return p->value[i];
}
void watch(ListNode* p)
{
	for (int i = 0; i < p->last; i++)
	{
		printf("%d ", p->value[i]);
	}
	printf("\n");
}
void destroyList(ListNode* p)
{
	for (int i = p->last; i > 0; i--)
	{
		del_nth(p, i);
	}
}
#endif