// 循环双链表
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct CDLinkList {
  int date;
  struct CDLinkList* next;
  struct CDLinkList* prior;
}CDNode, * CDLinkList;

bool InitCLinkList(CDLinkList* L) {     // 初始化单链表
  *L = (CDNode*)malloc(sizeof(CDNode));
  if (*L == NULL)
    return false;
  (*L)->next = *L;                     // 最后一个节点尾指针指向头节点
  (*L)->prior = *L;                    // 表头节点的头指针指向为尾节点
  return true;
}

bool Empty(CDLinkList L) {                 // 判断循环链表是否为空
  if (L->next != L)
    return false;
  return true;
}

bool isTail(CDLinkList L, CDNode* p) {         // 判断p是否为链表尾节点
  if (p->next == L)
    return true;
  return false;
}

bool isHeader(CDLinkList L, CDNode* p) {         // 判断p是否为链表头节点
  if ((p->prior)->next == L)                     // 头节点的上一个节点的下一个节点指向头节点
    return true;
  return false;
}

int main() {
  CDLinkList L;
  InitCLinkList(&L);
  Empty(L);
}