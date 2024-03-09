// 链式队列  带头结点
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct CqNode {
  int data;
  struct CqNode* next;
}CqNode;

typedef struct {
  CqNode* front, * rear;
}LinkQueue;

void initQueue(LinkQueue* Q) {                              // 初始化队列
  Q->front = Q->rear = (CqNode*)malloc(sizeof(CqNode));     // 首先队顶队尾指针先指向头节点
  Q->front->next = NULL;                                    // 初始化除头节点外无其他节点 
}

bool QueueEmpty(LinkQueue Q) {       // 判空
  if (Q.front == Q.rear)
    return true;
  puts("不为空");
  return false;
}

bool EnQueue(LinkQueue* Q, int x) {      // 入队
  CqNode* s = (CqNode*)malloc(sizeof(CqNode));
  s->data = x;
  s->next = NULL;
  Q->rear->next = s;
  Q->rear = s;
  return true;
}

bool DeQueue(LinkQueue* Q) {          // 出队
  if (Q->front == Q->rear)    // 队空
    return false;
  CqNode* p = Q->front->next;       // 保存要出队的节点
  Q->front->next = p->next;
  if (Q->rear == p)           // 出队的元素为尾节点
    Q->rear = Q->front;       // 修改rear指针为头节点
  free(p);
  return true;
}

int main() {
  LinkQueue Q;
  initQueue(&Q);
  EnQueue(&Q, 123);
}