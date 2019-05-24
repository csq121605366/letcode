
#include "queue.h"

status initQueue(queue *pQueue, int queueCapacity)
{
    //给数组指针分配内存
    pQueue->pBase = (ElemType *)malloc(sizeof(ElemType) * queueCapacity);
    if (!pQueue->pBase)
    {
        printf("给数组指针分配内存失败\n");
        return ERROR;
    }
    pQueue->front = 0;
    pQueue->rear = pQueue->front;
    pQueue->maxSize = queueCapacity;
}

void destoryQueue(queue *pQueue)
{
    free(pQueue);  //释放队列数组指针指向的内存
    pQueue = NULL; //队列数组指针重新指向NULL，避免称为野指针
}
void clearQueue(queue *pQueue)
{
    pQueue->front = 0; //队头索引清0
    pQueue->rear = 0;  //队尾索引清0
}

status isEmptyQueue(queue *pQueue)
{
    if (pQueue->front == pQueue->rear) //队头==队尾，说明为空
        return TRUE;
    return FALSE;
}
/*
 *在循环队列中,“队满”和“队空”的条件有可能是相同的，都是front==rear，
 *这种情况下，无法区别是“队满”还是“队空”。
 *针对这个问题，有3种可能的处理方法：
 *（1）另设一个标志以区别是“队满”还是“队空”。（即入队/出队前检查是否“队满”/“队空”）
 *（2）设一个计数器，此时甚至还可以省去一个指针。
 *（3）少用一个元素空间，即约定队头指针在队尾指针的下一位置时就作为“队满”的标志，
 *即“队满”条件为：(PQueue->rear+1)%MAX_SIZE == PQueue->front。
 *  【这里采用了第3种处理方法】
 */
//判断队列是否为满
status isFullQueue(queue *pQueue)
{
    if ((pQueue->rear + 1) % pQueue->maxSize == pQueue->front)
        return TRUE; //队列满
    return FALSE;
}

int getQueueLen(queue *pQueue)
{
    return (pQueue->rear - pQueue->front + pQueue->maxSize) % pQueue->maxSize;
}

status enQueue(queue *pQueue, ElemType element)
{
    if (isFullQueue(pQueue) == TRUE) //队列满了
    {
        printf("队列已满，不能再插入元素了!\n");
        return FALSE;
    }
    pQueue->pBase[pQueue->rear] = element;
    pQueue->rear = (pQueue->rear + 1) % pQueue->maxSize; //将rear赋予新的合适的值
    return TRUE;
}
//新元素出队,同时保存出队的元素 [先进先出原则：在队头的位置删除]
status deQueue(queue *PQueue, ElemType *pElement)
{
    //如果队列为空,则返回false
    if (isEmptyQueue(PQueue) == TRUE)
    {
        printf("队列为空，出队失败!\n");
        return FALSE;
    }

    *pElement = PQueue->pBase[PQueue->front];              //先进先出
    PQueue->front = (PQueue->front + 1) % PQueue->maxSize; //移到下一位置

    return TRUE;
}

//遍历队列
void queueTraverse(queue *pQueue)
{
    int i = pQueue->front; //从头开始遍历
    printf("遍历队列:\n");
    while (i != pQueue->rear)
    {
        printf("%d ", pQueue->pBase[i]);
        i = (i + 1) % pQueue->maxSize; //移到下一位置
    }
    printf("\n");
}
