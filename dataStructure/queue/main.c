#include <stdio.h>
#include <malloc.h>

#include "queue.h"

int main(void)
{
    int value; //用于保存出队的数据
    //创建队列对象
    queue *pQueue = (queue *)malloc(sizeof(queue));
    if (!pQueue->pBase)
    {
        printf("给队列对象分配内存失败\n");
        return -1;
    }
    initQueue(pQueue, MAX_SIZE);
    enQueue(pQueue, 1);
    enQueue(pQueue, 2);
    enQueue(pQueue, 3);
    enQueue(pQueue, 4);
    enQueue(pQueue, 5);
    enQueue(pQueue, 6);
    queueTraverse(pQueue);
    //调用遍历队列的函数
    queueTraverse(pQueue);
    //调用出队函数
    if (deQueue(pQueue, &value))
    {
        printf("出队一次，元素为：%d\n", value);
    }
    queueTraverse(pQueue);
    if (deQueue(pQueue, &value))
    {
        printf("出队一次，元素为：%d\n", value);
    }
    queueTraverse(pQueue);

    free(pQueue);
    pQueue = NULL;

    getchar();
    return 0;
}