#ifndef _HASH_

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <malloc.h>

#define MAX_SIZE 10

typedef int DataType;

typedef enum
{
    EXIST,
    EMPTY,
    DELET
} State;

typedef struct HTElem
{
    DataType _data;
    State _state;
} HTElem;

typedef struct HashTable
{
    HTElem *_array;
    int _capacity;        //空间容量
    int _size;            //有效元素个数
    int _IsLineDetective; //是否是线性探测
} HashTable, HT;

void HashTableInit(HT *ht, int capacity, int IsLineDetective); //初始化
void HashTableInsert(HT *ht, DataType data);                   //插入
void HashTableDelet(HT *ht, DataType data);                    //删除
int HashTableFind(HT *ht, DataType data);                      //查询
int HashTableSize(HT *ht);                                     //求有效元素个数
int HashTableCapacity(HT *ht);                                 //求空间容量大小
int HashTableEmpty(HT *ht);                                    //判空
void HasTableDestroy(HT *ht);                                  //销毁
int CheckCapacity(HT *ht);                                     //检查是否需要开辟空间

#endif // !_HASH_
