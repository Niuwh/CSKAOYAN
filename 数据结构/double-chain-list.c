// 双链表
#include <stdio.h>
#include <stdlib.h>   // 存放malloc函数
#include <stdbool.h>

typedef struct DNode {
  int date;                 // 每个节点存放一个数据元素
  struct DNode* prior;      // 指针指向前一个节点
  struct DNode* next;       // 指针指向下一个节点
}DNode, * DLinkList;

DLinkList InitDLinkList(DLinkList* L) {    // 初始化双链表
  *L = (DNode*)malloc(sizeof(DNode));
  if (*L == NULL)
    return NULL;
  (*L)->prior = NULL;
  (*L)->next = NULL;
  return *L;
}

bool Empty(DLinkList L) {        // 判断双链表是否为空
  if (L->next != NULL) {
    puts("双链表不为空");
    return true;
  }
  puts("双链表为空");
  return false;
}

bool InsertNextDNode(DNode* i, DNode* j) {    // 向指定节点i后插入节点j
  if (i == NULL || j == NULL)
    return false;
  if (i->next != NULL)          // i节点后面不是空节点
    i->next->prior = j;
  j->next = i->next;
  j->prior = i;
  i->next = j;
  return true;
}

bool DeleteNextDNode(DNode* i) {    // 删除i节点的后续节点
  if (i == NULL)
    return false;
  DNode* p = i->next;       // 待删除节点
  if (p == NULL)
    return false;
  DNode* q = p->next;       // 待删除节点的下一个节点
  if (q != NULL)
    q->prior = p->prior;
  i->next = p->next;
  free(p);
  return true;
}

void DestroyDList(DLinkList* L) {   // 销毁链表
  while ((*L)->next != NULL) {
    DeleteNextDNode(L);
  }
  free(*L);       // 清除链表内存
  *L = NULL;      // 链表指针赋值为空
}

int main() {
  DLinkList L;
  InitDLinkList(&L);
  Empty(L);
}