// 给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出：7 -> 0 -> 8
// 原因：342 + 465 = 807

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int data;
 *     struct ListNode *next;
 * };
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct ListNode
{
    int data;
    struct ListNode *next;
} Node, *LinkList;

LinkList addTwoNumbers(LinkList l1, LinkList l2)
{
    //head用于返回
    LinkList head = (LinkList)malloc(sizeof(Node));
    LinkList tail = head;
    int count = 0, sum = 0;
    //sum用来判断是否需要进位,如果需要进位sum自减10,count值1用于和下一位相加
    for (; l1 && l2; l1 = l1->next, l2 = l2->next)
    {
        sum = l1->data + l2->data + count;
        //判断是否进位
        if (sum > 9)
        {
            sum -= 10;
            count = 1;
        }
        else
            count = 0;
        tail->next = (LinkList)malloc(sizeof(Node));
        tail = tail->next;
        tail->data = sum;
    }
    //求出两个链表中没有走完的链表,如果有将链表剩余部分加在新链表的后边
    //注意也需要判断进位问题
    l1 = l1 ? l1 : l2;
    for (; l1; l1 = l1->next)
    {
        sum = l1->data + count;
        if (sum > 9)
        {
            sum -= 10;
            count = 1;
        }
        else
            count = 0;
        tail->next = (LinkList)malloc(sizeof(Node));
        tail = tail->next;
        tail->data = sum;
    }
    //判断最后一位是否需要进位
    if (count)
    {
        tail->next = (LinkList)malloc(sizeof(Node));
        tail = tail->next;
        tail->data = count;
    }
    //返回链表的尾节点
    tail->next = NULL;
    tail = head;
    head = head->next;
    free(tail);
    return head;
}

void addTwoNumbers2(LinkList l1, LinkList l2, int num)
{
    //head用于返回
    LinkList head = (LinkList)malloc(sizeof(Node));
    LinkList tail = head;
    int sum = 0, sum1 = 0, sum2 = 0, per = pow(10, num - 1);
    //sum用来判断是否需要进位,如果需要进位sum自减10,count值1用于和下一位相加
    for (; l1; l1 = l1->next, l2 = l2->next, per /= 10)
    {
        sum1 += l1->data * per;
        sum2 += l2->data * per;
    }
    sum = sum1 + sum2;
    for (; num; num--)
    {
        tail->next = (LinkList)malloc(sizeof(Node));
        tail = tail->next;
        tail->data = sum % ();
    }
}
// 不带头结点的未插入法创建链表。
// 创建这样的链表，首先指向头结点的指针不能移动，所以需要创建一个一直指向尾结点的指针rear。
LinkList createLinklist(int array[], int num)
{
    LinkList head;  //创建头结点
    Node *p, *rear; //p为临时节点 rear总指向尾指针
    rear = head = NULL;
    // printf("%d\n", sizeof(array));
    for (int i = 0; i < num; i++)
    {
        p = (Node *)malloc(sizeof(Node)); //创建空节点
        p->data = array[i];               //将数据传入空节点
        p->next = NULL;
        if (head == NULL)
        {
            head = p; //如果创建的是第一个节点
        }
        else
        {
            rear->next = p; //尾指针的下一位为新创建的节点
        }
        rear = p; //移动尾指针到新创建的节点
    }
    rear->next = NULL; //最后将链表的结尾设置为NULL。
    return head;
}

int main()
{
    int l1array[3] = {2, 4, 3};
    int l2array[3] = {5, 6, 4};
    printf("%d", sizeof(Node));
    LinkList l1 = createLinklist(l1array, sizeof(l1array) / sizeof(l1array[0]));
    LinkList l2 = createLinklist(l2array, sizeof(l2array) / sizeof(l2array[0]));

    LinkList l3 = addTwoNumbers(l1, l2);
    addTwoNumbers2(l1, l2, 3);
    printf("%d\n", l3->data);

    return 0;
}