// 循环单链表
#include <stdio.h>
#include <stdbool.h>

typedef struct CLinkList {
  int date;
  CLinkList* next;
}CNode, * CLinkList;

bool InitCLinkList(CLinkList* L) {     // 初始化单链表
  *L = (CLinkList)malloc(sizeof(CNode));
  if (*L == NULL)
    return false;
  (*L)->next = *L;                     // 最后一个节点尾指针指向头节点
  return true;
}

bool Empty(CLinkList L) {                 // 判断循环链表是否为空
  if (L->next != L)
    return false;
  return true;
}

bool isTail(CLinkList L, CNode* p) {         // 判断p是否为链表尾节点
  if (p->next == L)
    return true;
  return false;
}

int main() {
  CLinkList L;
  InitCLinkList(&L);
  Empty(L);
}