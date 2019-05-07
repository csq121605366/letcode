/*
前缀表达式（波兰式）特点是运算符号在前边，运算数在后边
后缀表达式（逆波兰式）特点是运算符号在后边，运算数在前边
中缀表达式 便于人看的表达式

以“X=A+B*(C-D)/E”为例，介绍中缀---->前缀和中缀---->后缀。

中缀—->前缀

1初始化2个栈s1和s2，s1存放运算数，s2存放运算符；
2从表达式右边开始，遍历表达式；
3遇到运算数放入s1中，遇到运算符放入s2中，
3.1如果s2是空或者“）”直接方进去；
3.2如果s2不为空或者不为“）”当前运算符和栈顶运算符进行比较
3.2.1如果当前运算符优先级大于栈顶运算符，直接放入；
3.2.2如果当前运算符优先级小于栈顶运算符，将栈顶运算符取出放入s1中重复3.2
3.3遇到“（”运算符出s2，入s1，直到遇到“）”，丢弃“（）”重复3.2、3.3；
4s2依次出栈，放入s1栈；
5s1出栈重新组成表达式，即前缀表达式；


中缀->后缀
1.运算数 直接输出
2.左括号 压入栈
3.右括号 将栈顶的运算符弹出并输出 直到遇到左括号
4.运算符如果优先级大于栈顶运算符时，压栈，反之则出栈并输出，再比较新的栈顶运算符直到大于
栈顶运算符优先级为止，然后压入栈中



Stack CreateStack(int MaxSize);
int isFull(Stack s,int MaxSize);//判断堆栈S是否已满
void Push(Stack s,ElementType item);//将元素item压入堆栈；
int IsEmpty(Stack s);//判断堆栈是否为空
ElementType Pop(Stack s);//删除并返回栈顶元素


*/

#include <stdlib.h>

#define MaxSize 10

typedef int ElementType;
//堆栈
typedef struct SArray
{
    ElementType data[MaxSize];
    int top;
} Stack;
//双堆栈
typedef struct SsArray
{
    ElementType data[MaxSize];
    int top1; //堆栈1的栈顶下标
    int top2; //堆栈2的栈顶下标
} Stacks;
//堆栈的链式存储实现
typedef struct SNode
{
    ElementType data;
    struct SNode *next;
} LinkedStack;

void Push(Stack *head, ElementType item)
{
    if (head->top == MaxSize - 1)
    {
        return;
    }
    else
    {
        head->data[++(head->top)] = item;
        return;
    }
}

ElementType Pop(Stack *head)
{
    if (head->top == -1)
    {
        return NULL;
    }
    else
    {
        return (head->data[(head->top)--]);
    }
}

//对双堆栈的push操作
void DPush(Stacks *head, ElementType item, int Tag)
{
    if ((head->top2) - (head->top1) == 1)
    {
        return NULL;
    }
    else if (Tag == 1)
    {
        head->data[++(head->top1)] = item; //对第一个堆栈操作
    }
    else
    {
        head->data[--(head->top2)] = item; //对第二个堆栈操作
    }
}
ElementType DPop(Stacks *head, int Tag)
{
    if (Tag == 1)
    {
        if (head->top1 == -1)
            return NULL;
        else
            return head->data[(head->top1)--];
    }
    else
    {
        if (head->top2 == MaxSize)
            return NULL;
        else
            return head->data[(head->top2)++];
    }
};

LinkedStack *CreateStack()
{
    LinkedStack *s;
    s = (LinkedStack *)malloc(sizeof(struct SNode));
    s->next = NULL;
    return s;
}

void LPush(LinkedStack *top, ElementType item)
{
    LinkedStack *tmpCell;
    tmpCell = (LinkedStack *)malloc(sizeof(LinkedStack)); //分配内存空间
    tmpCell->data = item;                                 //插入的值赋值给结点
    tmpCell->next = top->next;                            //将已存在链表链接到插入的结点
    top->next = tmpCell;                                  //改变top节点
}
int isEmpty(LinkedStack *top)
{ //注意s结点没有值，只有一个单链表的头指针
    return (top->next == NULL);
}
ElementType Pop(LinkedStack *top)
{
    LinkedStack *firstCell;
    ElementType topElem;
    if (isEmpty(top))
    {
        return NULL;
    }
    else
    {
        firstCell = top->next;
        top->next = firstCell->next;
        topElem = firstCell->data;
        free(firstCell);
        return topElem;
    }
}

int main()
{
    Stacks *stacks;
    stacks->top1 = -1;
    stacks->top2 = MaxSize; //初始化两个堆栈头指针

    return 0;
}