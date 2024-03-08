// 单链表
#include <stdio.h>
#include <stdlib.h>   // 存放malloc函数
#include <stdbool.h>

typedef struct LNode {
  int date;                 // 每个节点存放一个数据元素
  struct LNode* next;       // 指针指向下一个节点
}LNode, * LinkList;

bool InitList(LinkList* L) {  // 初始化一个单链表，带头结点
  *L = (LNode*)malloc(sizeof(LNode));    // 分配一个头节点
  if (*L == NULL) {
    return false;                       // 内存不足，分配失败
  };
  (*L)->next = NULL;                     // 头节点之后没有节点
  return true;
};

bool AfterInsertList(LNode* p, int e) {     // 向数据后插入值
  LNode* s = (LNode*)malloc(sizeof(LNode));     // 创建节点内存
  if (s == NULL) {
    puts("创建节点失败了\n");
    return false;
  }
  s->date = e;                                // 插入数据
  s->next = p->next;                        // 将新节点下一个次序地址赋值为i-1节点的下一个次序地址
  p->next = s;                                // 将i-1节点的下一个次序地址赋值为新节点地址
  return true;
}

bool InsertList(LinkList L, int i, int e) {    // 向单链表插入数据
  if (i < 1)
    return false;
  LNode* p;         // 指针p扫描到的节点
  int j = 0;        // 指针p保存的是第几个节点
  p = L;            // 指向头节点
  while (p != NULL && j < i - 1) {    // 循环找到第i-1个元素
    p = p->next;
    j++;
  }
  if (p == NULL) {   // 数据不合法，比如插入次序靠后，前面数据为空
    printf("数据不合法，单链表当前最长为%d,您要插入的次序为%d\n", j - 1, i);
    return false;
  }
  AfterInsertList(p, e);
}

LNode* GetElem(LinkList L, int i) {     // 查找单链表值
  if (i < 1)
    return NULL;
  int j = 0;           // 定义查找的节点次序
  LNode* p = L;       // 保存当前节点的地址
  while (j < i && p != NULL) {
    p = p->next;
    j++;
  };
  if (p == NULL) {
    printf("第%d个节点不存在，最大节点次序为%d\n", i, j - 1);
    return NULL;
  }
  printf("第%d个节点的值为%d\n", i, p->date);
  return p;       // 返回节点地址
}

int ListDelete(LinkList L, int i) {     // 删除节点
  if (i < 1) {
    puts("节点应该大于等于1");
  }
  int j = 0;
  LNode* p = L;
  while (j < i - 1 && p != NULL) {
    j++;
    p = p->next;
  }
  if (p == NULL) {
    puts("删除节点失败：i为无效节点");
    return -1;
  }
  if (p->next == NULL) {      // 删除的节点后已经没有节点
    puts("删除节点失败：i为无效节点");
    return -1;
  }
  LNode* q = p->next;         // 保存要删除的节点地址
  int e = q->date;            // 保存删除节点的值
  p->next = q->next;          // 将要删除的前一个节点next赋值为要删除的节点的后一个节点
  free(q);                    // 清除内存
  printf("节点删除成功，节点：%d;值:%d", i, e);
  return e;
}

bool InsertPriorNode(LNode* p, int e) {      // 前插操作
  if (p == NULL) {
    puts("前插操作失败，您输入的节点地址为空");
    return false;
  }
  LNode* s = (LNode*)malloc(sizeof(LNode));
  if (s == NULL) {
    puts("分配内存失败，跳出前插操作");
    return false;
  }
  s->date = p->date;
  s->next = p->next;
  p->date = e;
  p->next = s;
  return true;
}

LinkList List_TailInsert(LinkList* L) {      // 尾插法建立单链表
  int x;
  *L = (LinkList)malloc(sizeof(LNode));
  if (*L == NULL) {
    puts("分配内存错误");
    return NULL;
  }
  LNode* s, * r = *L;        // r指向尾节点
  scanf("%d", &x);
  while (x != 9999) {
    s = (LNode*)malloc(sizeof(LNode));
    r->next = s;
    s->date = x;
    r = s;
    scanf("%d", &x);
  }
  r->next = NULL;
  return *L;
}

bool GetAllElem(LinkList L) {     // 查找所有节点数据
  LNode* p = L;         // 指向表头
  int i = 1;
  while (p->next != NULL) {
    p = p->next;        // 下一个节点存在，保存它
    printf("第%d个节点的值为%d\n", i, p->date);
    i++;
  }
  return true;
}

LinkList List_HeaderInsert(LinkList* L) {     // 头插法建立单链表
  *L = (LinkList)malloc(sizeof(LNode));
  if (*L == NULL) {
    puts("分配内存错误");
    return NULL;
  }
  (*L)->next = NULL;
  int e;
  LNode* s;
  scanf("%d", &e);
  while (e != 9999) {
    s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL)
      return NULL;
    s->next = (*L)->next;
    s->date = e;
    (*L)->next = s;
    scanf("%d", &e);
  }
  return *L;
}

int Length(LinkList L) {
  int i = 0;
  LNode* p = L;
  while (p->next != NULL) {
    i++;
    p = p->next;
  }
  printf("单链表共有%d个数据元素", i);
  return i;
}

LinkList ReverseList(LinkList* L) {     // 翻转单链表数据，清除旧单链表
  LinkList reverse_L = (LNode*)malloc(sizeof(LNode));       // 新的表头节点
  reverse_L->next = NULL;
  LNode* s, * backup;         // s为新节点地址，backup为备份节点，用于清除内存
  LNode* p = *L;
  while (p->next != NULL) {
    backup = p;               // 备份上一个节点
    p = p->next;
    free(backup);             // 清除上一个节点内存
    s = (LNode*)malloc(sizeof(LNode));
    s->date = p->date;              // 新节点保存数据
    s->next = reverse_L->next;      // 保存第一个节点地址
    reverse_L->next = s;            // 更新第一个节点地址
  }
  free(p);                    // 清除最后一个节点内存
  *L = reverse_L;             // 将新表头节点地址赋予*L
}

int main() {
  LinkList L;       // 声明一个指向单链表的**头指针**变量

  List_TailInsert(&L);     // 初始化单链表

  ReverseList(&L);

  GetAllElem(L);

  Length(L);
}