#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <malloc.h>

/* 队列: 只允许在表的一端(队尾rear)进行插入操作，而在另一端(队头front)进行删除操作的线性表
 * 插入操作简称为入队  删除操作简称为出队   队列具有先进先出的特点
 */

/*=====队列的入队、出队示意图========
 *
 *  出队 ----------------- 入队
 *   <--- a1,a2,a3,...,an <---
 *      -----------------
 *
 *================================*/

typedef enum
{
    OK = 0,    //正确
    ERROR = 1, //出错
    TRUE = 2,  //为真
    FALSE = 3, //为假
} status;

#define ElemType int //宏定义队列的数据类型
#define MAX_SIZE 20  //定义队列最大容量

/*一、使用数组存储队列的称为静态顺序队列
 *二、使用动态分配的指针的称为动态顺序队列*/
// 【这里的是动态顺序队列】
typedef struct
{
    ElemType *pBase; //数组指针
    ElemType front;  //队头索引
    ElemType rear;   //队尾索引
    int maxSize;     //当前分配的最大容量
} queue;

/**
 * 创建空队列
 *  queueCapacity-队列容量
 **/
status initQueue(queue *pQueue, int queueCapacity);
//销毁队列
void destoryQueue(queue *pQueue);
//清空队列
void clearQueue(queue *pQueue);
//判断队列是否为空
status isEmptyQueue(queue *pQueue);
//判断队列是否为满
status isFullQueue(queue *pQueue);
//获得队列长度
int getQueueLen(queue *pQueue);
//新元素入队（先进先出原则，在队尾的位置插入）
//element要插入的元素
status enQueue(queue *pQueue, ElemType element);
//新元素出队，同时保存出队元素（先进先出原则，在队头的位置删除）
status deQueue(queue *PQueue, ElemType *pElement);
//遍历队列
void queueTraverse(queue *pQueue);

#endif