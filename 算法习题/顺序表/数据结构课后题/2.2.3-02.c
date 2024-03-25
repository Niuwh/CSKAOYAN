/*
2.2.3-02题目：
设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1).
*/
#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef int ElemType;      // 假设数据类型为int

typedef struct {    // 定义顺序表类，一定要注意类的格式(一个数组，一个数组长度，数组下标从零开始)
  ElemType data[MAXSIZE];
  int length;
}SqList;

void InitList(SqList* L);
void logList(SqList L);

// 解题代码
void ReverseList(SqList* L) {   // reverse -> 反转，扭转
  ElemType temp;    // 中转元素
  for (int i = 0;i < L->length / 2;i++) {
    temp = L->data[i];
    L->data[i] = L->data[L->length - 1 - i];
    L->data[L->length - 1 - i] = temp;
  }
}

int main() {
  SqList L;
  InitList(&L);
  logList(L);
  ReverseList(&L);
  logList(L);
}

void InitList(SqList* L) {    // 初始化表数据
  for (int i = 0;i < 10;i++) {
    L->data[i] = 100 - i;
  }
  L->length = 10;
}

void logList(SqList L) {      // 打印列表
  for (int i = 0;i < L.length;i++) {
    printf("%d,", L.data[i]);
  }
  printf("长度为%d\n", L.length);
}