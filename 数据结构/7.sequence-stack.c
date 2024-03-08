// 顺序栈
#include <stdio.h>
#include <stdbool.h>  // 存放bool类型
#include <stdlib.h>   // 存放malloc函数

#define MAXSIZE 10

typedef struct {
  int data[MAXSIZE];
  int top;                // 存储栈顶元素数组下标
}SqStack;

void InitStack(SqStack S) {
  S.top = -1;       // 初始化栈顶指针，无元素指向-1
}

bool StackEmpty(SqStack S) {      // 判断是否为空栈
  if (S.top = -1) {
    puts("是空栈");
    return true;
  }
  return false;
}

bool Push(SqStack S, int e) {     // 新元素入栈
  if (S.top == MAXSIZE - 1)       // 栈满了
    return false;
  S.data[++S.top] = e;            // 新元素入栈
  return true;
}

bool Pop(SqStack S, int* e) {     // 元素出栈
  if (S.top == -1)    // 空栈
    return false;
  *e = S.data[S.top--];
  return true;
}

bool GetTop(SqStack S, int* e) {      // 读取栈顶元素
  if (S.top == -1)  // 空栈
    return false;
  *e = S.data[S.top];
  return true;
}

int main() {
  SqStack S;
  InitStack(S);
  StackEmpty(S);
}