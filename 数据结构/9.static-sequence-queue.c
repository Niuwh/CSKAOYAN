// 静态队列
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct {
  int data[MAXSIZE];
  int rear, front;      // 保存队列队头指针和队尾的后一个节点指针
}SqQueue;

void InitSqQueue(SqQueue* Q) {     // 初始化
  Q->front = Q->rear = 0;       // 初始化指向0
}

bool QueueEmpty(SqQueue Q) {      // 判空操作
  if (Q.rear == Q.front)   // 队尾指针指向队头指针即为空
    return true;
  puts("不为空");
  return false;
}

bool EnQueue(SqQueue* Q, int e) {       // 入队操作
  if ((Q->rear + 1) % MAXSIZE == Q->front) {         // 队列已满，会空闲一个位置，否则Q->rear==Q->front.会影响判空操作，除非加入一个辅助变量解决
    return false;
  }
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAXSIZE;      // 如果恰好为MAXSIZE长度，则重置为0
  printf("已添加元素：%d\n", e);
  return true;
}

bool DeQueue(SqQueue* Q, int* e) {       // 出队操作
  if (Q->rear == Q->front) {         // 队列清空
    return false;
  }
  *e = Q->data[Q->front];
  Q->front = (Q->front + 1) % MAXSIZE;
  printf("已删除元素：%d\n", *e);
  return true;
}

bool GetHead(SqQueue* Q, int* e) {      // 查队头元素
  if (Q->rear == Q->front) {         // 队列清空
    return false;
  }
  *e = Q->data[Q->front];
  printf("查找到%d\n", *e);
  return true;
}

bool Length(SqQueue Q, int* e) {    // 得到队列长度
  *e = (Q.rear + MAXSIZE - Q.front) % MAXSIZE;
  printf("队列长度为%d\n", *e);
  return true;
}

int main() {
  SqQueue Q;    // 声明队列
  InitSqQueue(&Q);     // 初始化队列
  int e;
  EnQueue(&Q, 1);
  EnQueue(&Q, 2);
  EnQueue(&Q, 3);
  GetHead(&Q, &e);
  DeQueue(&Q, &e);
  GetHead(&Q, &e);
  Length(Q, &e);
  QueueEmpty(Q);
}


/*
队列元素：(rear+MAXSIZE-front)%MAXSIZE
*/