#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include <stdio.h>
#include <malloc.h>

typedef enum
{
    OK = 0,    //正确
    ERROR = 1, //出错
    TRUE = 2,  //为真
    FALSE = 3, //为假
} status;

typedef int ElemType; //宏定义队列的数据结构
//链式队列：是指采用链式存储结构的队列，队列中每一个元素对应链表中的节点。
//和链式栈类似，一般采用单链表来实现链式队列

//链式队列节点结构
typedef struct Node
{
    ElemType data;     //节点数据
    struct Node *next; //后继节点
} LQNode;
//链式队列结构
typedef struct
{
    LQNode *front; //链式队列的队头指针，总是指向队列的头结点
    LQNode *rear;  //链式队列的队尾指针，入队时指向新插入节点
} LinkQueue;

//创建空队列
status initQueue(LinkQueue *pQHead);
//销毁队列
void destoryQueue(LinkQueue *pQHead);
//清空队列
void clearQueue(LinkQueue *pQHead);
//判断队列是否为空
status isEmptyQueue(LinkQueue *pQHead);
//获得队列长度
int getQueueLen(LinkQueue *pQHead);
//新元素入队【先进先出原则：在队尾的位置插入】element-要插入的元素
status enQueue(LinkQueue *pQHead, ElemType *pElement);
//遍历队列
void queueTraverse(LinkQueue *pQHead);

#endif