
 // 链表节点结构如下
 struct Node {
     int val;
      struct Node *next;
 };
 //Title: reverse the list
//Thre editions with two ideas.One by recurrsion and another by loop.
#include<iostream>
using namespace std;

struct Node* reverse(struct Node* pre,struct Node* head)
{
  if(head==NULL)return pre;
  struct Node* temp=head->next;
  head->next=pre;
  return reverse(head,temp);
}
struct Node* solve(struct Node* head)
{	
  #if 1
  struct Node * pre = NULL; // 指向新链表头节点
    struct Node* cur=head;
    struct Node *next;              // 指向挪动节点
   
    while (cur != NULL) {
        next = cur;
        cur = cur->next;
        next->next = pre;
        pre = next;
    }
    return pre;
  #endif
  #if 1
	struct Node* pre=NULL;
  	struct Node* cur=head;
  	struct Node* L_next=head->next;
  	while(cur)
    {
      L_next=cur->next;
      cur->next=pre;
       pre=cur;//pre 下移
      cur=L_next;//cur下移  
    }
  return pre;
  #endif
  struct Node* pre=NULL;
   return reverse(pre,head);
     
}

