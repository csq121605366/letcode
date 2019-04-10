#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode
{
    int data;              //数据域
    struct ListNode *next; //后继节点指针
} Node, *LinkList;
/*
首节点：存放第一个有效数据的结点
头结点：在单链表第一个结点之前设置的一个结点，没有直接前驱，称之为头结点，
    头结点的数据域可以不存储任何信息，指针域指向第一个结点地址。头结点的作用是使所有
    链表（包括空表）的头指针非空
头指针：指向头结点的指针
尾结点：存放最后一个有效数据的结点
尾指针：指向尾结点的指针
*/

//不带头结点的单链表的初始化
LinkList LinkedListInit1(int n)
{
    if (n <= 0)
        return NULL;
    for (; n > 0; n--)
    {
        
    }
}
//带头结点的单链表的初始化
LinkList LinkedListInit2(int n)
{
    if (n <= 0)
        return NULL;
    LinkList pHead = (LinkList)malloc(sizeof(LinkList));
    LinkList pTail = pHead;
    if (pHead == NULL)
    {
        printf("申请内存失败!");
        exit(0);
    }
    for (; n > 0; n--)
    {
        LinkList pNode = (LinkList)malloc(sizeof(LinkList));
        pNode->data = NULL;
        pTail->next = pNode;
        pTail = pNode;
        pTail->next = NULL;
    }
    return pHead;
}

int main()
{
    LinkList l1;
    l1 = LinkedListInit2(10);
    printf("%d", l1->next->data);
    return 0;
}
