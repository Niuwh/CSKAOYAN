/*
2.2.3-03题目：
对长度为n的顺序表L,编写一个时间复杂度为O(n),空间复杂度为O(1)的算法，该算法删除顺序表中所有值为x的数据元素。
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
void Delete_x(SqList* L, ElemType x) {  // x表示要删除的元素值
  int num = 0;    // 标记删除的x的个数
  for (int i = 0;i < L->length;i++) {
    if (L->data[i] == x)
      num++;
    else
      L->data[i - num] = L->data[i];
  }
  L->length -= num;
}

int main() {
  SqList L;
  InitList(&L);
  // logList(L);
  Delete_x(&L, 4);
  // logList(L);
}

void InitList(SqList* L) {    // 初始化表数据
  L->length = 100;
  for (int i = 0;i < L->length;i++) {
    L->data[i] = i / 2;
  }
}

void logList(SqList L) {      // 打印列表
  for (int i = 0;i < L.length;i++) {
    printf("%d,", L.data[i]);
  }
  printf("长度为%d\n", L.length);
}