

#define ElementType int
#define MaxSize 50

typedef struct QNode
{
    ElementType data[MaxSize];
    int rear;  //队尾指针
    int front; //队头指针
} * Queue;

typedef struct 
{
    /* data */
};


void AddQueue(Queue p, ElementType item)
{
    if ((p->rear + 1) % MaxSize == p->front)
    {
        printf("队列满!");
        return;
    }
    p->rear = (p->rear + 1) % MaxSize;
    p->data[p->rear] = item;
}

ElementType DeleteQueue(Queue p)
{
    if (p->front == p->rear)
    {
        printf("队列空");
        return;
    }
    else
    {
        p->front = (p->front + 1) % MaxSize;
        return p->data[p->front];
    }
}