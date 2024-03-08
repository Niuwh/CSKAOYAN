// 单链栈的实现,不带头节点
#include <stdio.h>
#include <stdbool.h>      // 存放bool类型
#include <stdlib.h>       // 存放malloc函数

typedef struct SNode {
  int data;
  struct SNode* next;
}SNode, * StackList;

bool InitStackList(StackList* S) {   // 创
  *S = NULL;      // 初始化指向NULL
  return true;
}

bool Push(StackList* S, int e) {    // 增
  SNode* p = (SNode*)malloc(sizeof(SNode));   // 创建新节点
  if (p == NULL)
    return false;         // 创建内存失败
  p->next = *S;
  p->data = e;
  *S = p;
  return true;
}

bool Pop(StackList* S, int* e) {       // 删
  if (*S == NULL)
    return false;       // 栈为空
  SNode* p = *S;        // 保存栈顶节点
  *S = p->next;
  free(p);              // 删除节点内存
  printf("删除的元素为%d\n", *e);
  return true;
}

bool GetElem(StackList S, int* e) {       // 查
  if (S == NULL)
    return false;
  *e = S->data;
  printf("查找到的元素为%d\n", *e);
  return true;
}

bool StackEmpty(StackList S) {        // 判空
  if (S != NULL)
    return false;
  return true;
}

// 存储方式为链式存储的栈不存在栈满的情况，除非内存不足了

int main() {
  StackList S;    // 声明一个单链栈
  InitStackList(&S);  // 初始化栈
  int e;    // 保存查找,删除的元素
  Push(&S, 1);
  Push(&S, 2);
  Push(&S, 3);
  Push(&S, 4);
  GetElem(S, &e);
  Pop(&S, &e);
  GetElem(S, &e);
}