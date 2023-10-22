#include<iostream>
#include<error.h>
#define ElementType int
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
int empty(Stack s);
void make_empty(Stack s);
Stack create_Stack();
void push(ElementType x,Stack s);
void pop(Stack s);
void mypop(Stack s);
ElementType Top(Stack s);
void show_top(Stack s);
struct Node
{
	ElementType Element;
	PtrToNode next;
};
int main()
{
	
	Stack stack_;
	stack_=create_Stack();
	push(23,stack_);
	push(3,stack_);
	
	mypop(stack_);
	show_top(stack_);
	return 0;
}
int empty(Stack s)
{
	return s->next==NULL;
}
void make_empty(Stack s)
{
	if(s==NULL)
	{
		std::cerr<<"must use createstack first";
	}
	else while(!empty(s))
	{
		pop(s);
	}
}
Stack create_Stack()
{
	Stack s;
	s=(struct Node*)malloc(sizeof(struct Node));
	if(s==NULL)
	std::cerr<<("out of space");
	s->next=NULL;
	make_empty(s);
	return s;
}
void push(ElementType x,Stack s)
{
	PtrToNode TmpCell;
	TmpCell=(Stack)malloc(sizeof(Stack));
	if(TmpCell==NULL)
		std::cerr<<("out of space");
		else {
			TmpCell->Element=x;
			TmpCell->next=s->next;
			s->next=TmpCell;
		}
}
ElementType Top(Stack s)
{
	if(!empty(s))
	{
		return s->next->Element;
	}
	std::cerr<<"Empty stack";
	return 0;
}
void mypop(Stack s)
{
	PtrToNode first_Node;
	if(!empty(s))
	{
		first_Node=s->next;
		s->next=s->next->next;
		free(first_Node);
	}
	else {
		std::cerr<<"Empty stack";
	}
}
void pop(Stack s)
{
	PtrToNode firstCell;
	if(empty(s))
	{
		std::cerr<<"empty stack";
	}
	else {
		firstCell=s->next;
		s->next=s->next->next;
		free(firstCell);
	}
}
void show_top(Stack s)
{
	std::cout<<Top(s);
}