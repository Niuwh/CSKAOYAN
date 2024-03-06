#include <stdio.h>
#include <stdbool.h>  // 存放bool类型
#include <stdlib.h>   // 存放malloc函数

typedef struct {
  int* data;         // 存放数据元素的指针
  int MaxSize;       // 顺序表的最大长度
  int length;				 // 顺序表的当前长度
} Sqlist;			 			 // 顺序表的类型定义

bool InitList(Sqlist* L, int length, int max) {  // 参数:数据表，数据表大小,数据表上限
  (*L).MaxSize = max;
  if (length > max)
    return false;
  (*L).data = (int*)malloc(sizeof("int") * length);   // 分配数组空间
  for (int i = 0; i < length; i++) {	          // 遍历数组元素为0
    (*L).data[i] = 0;
  }
  (*L).length = length;                 // 当前长度初始化
}

bool ListInsert(Sqlist* L, int i, int e) {
  if (i<1 || i>(*L).length + 1)	// 检查元素i的范围是否有效
    return false;
  if ((*L).length >= (*L).MaxSize)		// 检查元素是否满了
    return false;
  for (int j = (*L).length; j >= i; j--) {
    (*L).data[j] = (*L).data[j - 1];
  }
  (*L).data[i - 1] = e;		// 插入元素
  (*L).length++;					// 长度加一
  return true;
}

bool ListDelete(Sqlist* L, int i, int* e) {
  if (i<1 || i>(*L).length)			// 检查元素i的范围是否有效
    return false;
  *e = (*L).data[i - 1];
  for (int j = i; j < (*L).length; j++) {
    (*L).data[j - 1] = (*L).data[j];
  }
  (*L).data[(*L).length - 1] = 0;				// 最后的空元素补零
  (*L).length--;					// 长度加一
  return true;
}

int GetElem(Sqlist* L, int i) {
  if (i > (*L).MaxSize)
    return -1;
  return (*L).data[i - 1];
}

int LocateElem(Sqlist* L, int i) {
  for (int j = 0;j < (*L).length;j++) {
    if ((*L).data[j] == i)
      return j + 1;
  }
  return -1;
}

int main() {
  Sqlist L;				//生成数据表
  InitList(&L, 10, 10);		//初始化数据表

  L.data[0] = 1111;
  L.data[1] = 2222;
  L.data[2] = 3333;
  L.data[3] = 4444;
  L.data[4] = 5555;
  L.length = 5;

  int e = -1;

  ListInsert(&L, 3, 666);
  ListDelete(&L, 1, &e);

  printf("%d\n", LocateElem(&L, 3333));

  for (int i = 0; i < L.MaxSize; i++) {
    printf("data[%d]=%d\n", i, L.data[i]);
  }

  printf("%d", GetElem(&L, 14));

  return 0;
}
