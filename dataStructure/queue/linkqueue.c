#include "linkqueue.h"

/*********************************************************************
 * 刚开始创建空队列时，队列的队头和队尾指针相等都指向头结点，头结点的数据域不存放数据
 * 第一次入队，创建新结点，其数据域保存新插入元素，头结点的next指向新结点,
 * 并且队列的队尾指针指向新结点,队列的队头指针仍然指向头结点,依次类推
 * 第一次出队，则队列的队头指针指向头结点的next,依次类推
 *********************************************************************/

//创建空队列：pQHead即为队列头结点
status initQueue(LinkQueue *pQHead)
{
    //队列头结点的队头和队尾指针申请内存
    pQHead->front = pQHead->rear = (LQNode *)malloc(sizeof(LQNode));
    if (!pQHead->front) //检测是否申请失败
    {
        printf("内存申请失败");
        return ERROR;
    }
    //设置头结点指针域为空
    pQHead->front->next = NULL;
    return OK;
}
//销毁队列
void destoryQueue(LinkQueue *pQHead)
{
    free(pQHead->front);
    free(pQHead->rear);
    pQHead->front = pQHead->rear = NULL;
}
//清空队列
void clearQueue(LinkQueue *pQHead)
{
    pQHead->front = pQHead->rear;
}


