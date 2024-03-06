#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10 // 定义数组最大长度

typedef struct {
	int data[MAXSIZE]; // 用静态数组存放数据元素
	int length;				 // 顺序表的当前长度
} Sqlist;			 			 // 顺序表的类型定义

void InitList(Sqlist* L) {
	for (int i = 0; i < MAXSIZE; i++) {	// 遍历数组元素为0
		(*L).data[i] = 0;
	}
	(*L).length = 0; // 当前长度初始化为0
}

bool ListInsert(Sqlist* L, int i, int e) {
	if (i<1 || i>(*L).length + 1)	// 检查元素i的范围是否有效
		return false;
	if ((*L).length >= MAXSIZE)		// 检查元素是否满了
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

int main() {
	Sqlist L;				//生成数据表
	InitList(&L);		//初始化数据表

	L.data[0] = 1111;
	L.data[1] = 2222;
	L.data[2] = 3333;
	L.data[3] = 4444;
	L.data[4] = 5555;
	L.length = 5;

	int e = -1;

	ListInsert(&L, 3, 666);
	ListDelete(&L, 1, &e);

	for (int i = 0; i < MAXSIZE; i++) {
		printf("data[%d]=%d\n", i, L.data[i]);
	}
	return 0;
}
