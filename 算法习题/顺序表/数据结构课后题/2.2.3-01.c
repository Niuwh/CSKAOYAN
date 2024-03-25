/*
2.2.3-01题目：
从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除的值。空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
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
bool Delete_min(SqList* L, ElemType* x) {    // 参数：表地址，要传出去的最小值地址
  if (L->length == 0)   // 满足题意，数组为空，返回错误
    return false;
  int min = 0;        // 保存最小值数组下标
  for (int i = 1;i < L->length; i++) {
    if (L->data[min] > L->data[i])
      min = i;
  }
  *x = L->data[min];
  // printf("删除的最小值为：%d\n", *x);
  L->data[min] = L->data[--L->length];    // 你懂的！
  return true;
}

int main() {
  SqList L;
  InitList(&L);
  int x;
  // logList(L);
  Delete_min(&L, &x);
  // logList(L);
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