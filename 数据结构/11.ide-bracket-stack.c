// 用栈实现IDE自动判别{[()]}是否配对的问题
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct {
  char data[MAXSIZE];
  int top;            // 定义top指向栈顶元素的下一个元素的数组下标
}Stack;

void InitStack(Stack* S) {      // 初始化栈
  S->top = 0;    // 表示为空栈
}

bool StactEmpty(Stack S) {      // 判断栈是否为空
  if (S.top == 0)
    return true;
  // puts("栈不为空");
  return false;
}

bool Push(Stack* S, char x) {     // 进栈,X为要进栈的元素值
  if (S->top == MAXSIZE)          // 要进栈的元素超过静态数组最大值
    return false;
  S->data[(S->top)++] = x;
  printf("进栈元素为：'%c'\n", x);
  return true;
}

bool Pop(Stack* S, char* x) {     // 出栈,x为要出栈的元素
  if (S->top == 0)    // 空栈
    return false;
  *x = S->data[--(S->top)];
  printf("出栈元素为：'%c'\n", *x);
  return true;
}

bool BracketCheck(char str[], int length) {
  Stack S;    // 声明一个栈
  InitStack(&S);  // 初始化栈
  for (int i = 0;i < length;i++) {
    char sign = str[i];           // 当前需要比较或者进栈的元素
    if (sign == '{' || sign == '(' || sign == '[') {      // 匹配到左括号入栈
      Push(&S, sign);
    } else {                                              // 匹配到右括号出栈比较
      if (StactEmpty(S))      // 栈空了
        return false;
      char topElem;       // 声明一个字符保存出栈元素
      Pop(&S, &topElem);
      if (topElem == '{' && sign != '}')    // 不满足{}配对条件
        return false;
      if (topElem == '(' && sign != ')')    // 不满足()配对条件
        return false;
      if (topElem == '[' && sign != ']')    // 不满足[]配对条件
        return false;
      printf("元素：'%c'配对成功：'%c'\n", topElem, sign);
    }
  }
  return StactEmpty(S);       // 遍历完字符数组后，判断栈内是否还剩元素
}

int main() {
  static char str[] = { '{','[','(',')',']','}' };
  bool a = BracketCheck(str, 6);
  if (a) {
    puts("合法字符串");
  } else {
    puts("违法字符串");
  }
}