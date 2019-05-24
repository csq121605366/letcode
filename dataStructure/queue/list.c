
typedef int ElemType;
// 链式队列结点结构
typedef struct Node
{
    ElemType data; //结点数据
    //【负责建立队列各结点之间的联系，前一个结点的next指向后一个结点，形成链式队列】
    struct Node *next; //后继结点
} LQNode;
// 链式队列结构
typedef struct
{
    LQNode *front; //链式队列的队头指针，总是指向队列的头结点(出队一次，第二个结点变为头结点)
    LQNode *rear;  //链式队列的队尾指针，入队时指向新插入结点(总是指向队列的最后一个结点)
} LinkQueue;

main()
{
    LinkQueue *PtrQ;
    return 0;
}

ElemType DeleteQ(LinkQueue *PtrQ);
{
    struct Node *FrontCell;
    ElemType FrontElem;
    if (PtrQ->front == NULL)
    {
        printf("队列空");
        return ERROR;
    }

    return FrontElem;
}