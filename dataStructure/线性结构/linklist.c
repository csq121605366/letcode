// 链表
#include <stdlib.h>

typedef int ElementType; //ElementType
//单链表
typedef struct Linklist
{
    ElementType data;
    struct Linklist *next;
} * List, Node;
//多重链表
typedef struct GLinkList
{
    ElementType tag; //标志域 0代表单元素 1表示节点为广义表
    union {          //子表指针域subList 与单元素数据域data复用，即公用存储单元
        ElementType data;
        struct GLinkList *subList;
    };
    struct GLinkList *next;
} * GList, GNode;

int Length(List head);
//获取链表长度
int Length(List head)
{
    List p = head;
    int i = 0;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}
//查找指定下标的节点地址
List FindKth(ElementType k, List head)
{
    //p指向链表头指针
    List p = head;
    int i = 0;
    while (p != NULL && i < k)
    {
        p = p->next;
        i++;
    }
    if (i == k)
        return p;
    else
        return NULL;
}
//查找指定值的节点地址
List Find(ElementType x, List head)
{
    List p = head;
    while (p != NULL && p->data != x)
    {
        p = p->next;
    }
    return p;
}

//插入 在第i-1个节点后插入一个值为X的新节点
List Insert(ElementType x, ElementType i, List head)
{
    List pHead, pNew;
    if (i == 1)
    {
        pNew = (List)malloc(sizeof(Node));
        pNew->data = x;
        pNew->next = head;
        return pNew;
    }
    //查找第i-1个元素的指针
    pHead = FindKth(i - 1, head);
    if (pHead == NULL)
    {
        printf("参数错误");
        return NULL;
    }
    else
    {
        pNew = (List)malloc(sizeof(Node));
        pNew->data = x;
        pNew->next = pHead->next; //新节点next指向替换找到的节点的next指向
        pHead->next = pNew;
        return head;
    }
}

List Del(ElementType i, List head)
{
    List p, s;
    //删除头结点
    if (i == 1)
    {
        s = head;
        //头结点不为空
        if (head != NULL)
            head = head->next; //头结点指向变化
        else
            return NULL; //头结点为空 返回NULL
        free(s);         //删除节点
        return head;     //返回新的头结点
    }
    p = FindKth(i - 1, head);
    if (p == NULL || p->next == NULL)
    {
        return NULL;
    }
    else
    {
        s = p->next;
        p->next = s->next;
        free(p);
        return head;
    }
}

int main()
{

    return 0;
}