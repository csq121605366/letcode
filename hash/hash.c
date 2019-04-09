
#include "hash.h";

int HashFunc(DataType data) //得到哈希地址（用于插入和查询）
{
    return data % MAX_SIZE;
}

int DetectiveLine(int hashAddr) //线性探测（用于插入和查询）
{
    hashAddr++;

    if (hashAddr == MAX_SIZE)
        hashAddr = 0;

    return hashAddr;
}

int Detective2(int hashAddr, int i) //二次探测（用于插入和查询）
{
    hashAddr = hashAddr + 2 * i + 1;

    if (hashAddr >= MAX_SIZE)
        hashAddr %= MAX_SIZE;

    return hashAddr;
}

void Swap(HT *lht, HT *rht) //交换函数（用于空间扩展）
{
    int temp;
    assert(lht);
    assert(rht);

    temp = (DataType)lht->_array;
    lht->_array = rht->_array;
    rht->_array = (HTElem *)temp;

    temp = lht->_capacity;
    lht->_capacity = rht->_capacity;
    rht->_capacity = temp;

    temp = lht->_size;
    lht->_size = rht->_size;
    rht->_size = temp;

    temp = lht->_IsLineDetective;
    lht->_IsLineDetective = rht->_IsLineDetective;
    rht->_IsLineDetective = temp;
}
int CheckCapacity(HT *ht)
{
    assert(ht);
    if (10 * ht->_size / ht->_capacity >= 7) //负载因子
    {
        //开辟新空间   /新建一个哈希表
        int newCapacity = ht->_capacity * 2;
        HT newHT;

        HashTableInit(&newHT, newCapacity, ht->_IsLineDetective);

        //数据拷贝
        for (int i = 0; i <= ht->_capacity; i++)
        {
            if (EXIST == ht->_array[i]._state)
                HashTableInsert(&newHT, ht->_array[i]._data);
        }

        Swap(ht, &newHT); //使旧的哈希表指针指向新的空间，新的哈希表指针指向旧空间

        HasTableDestroy(&newHT);

        return 1;
    }
    else
        return -1;
}

void HashTableInit(HT *ht, int capacity, int IsLineDetective)
{
    int i = 0;
    ht->_array = (HTElem *)malloc(capacity * sizeof(HTElem));
    if (NULL == ht->_array)
    {
        assert(0);
        return;
    }

    for (; i < capacity; ++i)
        ht->_array[i]._state = EMPTY;

    ht->_capacity = capacity;
    ht->_size = 0;
    ht->_IsLineDetective = IsLineDetective;
}

void HashTableInsert(HT *ht, DataType data) //插入
{
    int hashAddr = 0;
    int i = 0;
    assert(ht);

    CheckCapacity(ht); //判断是否增容

    //计算哈希地址
    hashAddr = HashFunc(data);

    while (EMPTY != ht->_array[hashAddr]._state)
    {
        if (EXIST == ht->_array[hashAddr]._state)
        {
            if (data == ht->_array[hashAddr]._data)
                return;
        }

        if (ht->_IsLineDetective)
            hashAddr = DetectiveLine(hashAddr);
        else
            hashAddr = Detective2(hashAddr, ++i);
    }

    //插入元素
    ht->_array[hashAddr]._data = data;
    ht->_array[hashAddr]._state = EXIST;
    ht->_size++;
}

void HashTableDelete(HT *ht, DataType data)
{
    int ret = -1;
    assert(ht);

    ret = HashTableFind(ht, data);
    if (-1 != ret)

    {
        ht->_array[ret]._state = DELET;
        ht->_size--;
    }
}

int HashTableFind(HT *ht, DataType data)
{
    int hashAddr = -1, starAddr = -1;
    int i = 0;
    assert(ht);

    hashAddr = HashFunc(data);
    starAddr = hashAddr;

    while (EMPTY != ht->_array[hashAddr]._state)
    {
        if (EXIST == ht->_array[hashAddr]._state)
        {
            if (data == ht->_array[hashAddr]._data)
                return hashAddr; //找到了
        }

        if (ht->_IsLineDetective)
        {
            hashAddr = DetectiveLine(hashAddr);
            //找了一圈没有找到
            if (hashAddr == starAddr)
                return -1;
        }
        else
            hashAddr = Detective2(hashAddr, ++i);
    }
    return -1;
}

void HashTableDelet(HT *ht, DataType data)
{
    int ret = -1;
    assert(ht);

    ret = HashTableFind(ht, data);
    if (-1 != ret)

    {
        ht->_array[ret]._state = DELET;
        ht->_size--;
    }
}

int HashTableCapacity(HT *ht)
{
    printf("\n空间大小为：%d\n", ht->_capacity);
    return ht->_capacity;
}

int HashTableSize(HT *ht)
{
    assert(ht);
    return ht->_size;
}

int HashTableEmpty(HT *ht)
{
    assert(ht);
    return 0 == ht->_size;
}

void HasTableDestroy(HT *ht)
{
    assert(ht);
    if (ht->_array)
    {
        free(ht->_array);
        ht->_array = NULL;
        ht->_capacity = 0;
        ht->_size = 0;
    }
}

void PrintfHashBucket(HT *ht)
{
    int i = 0;
    for (; i < ht->_capacity; i++)
    {
        if (EXIST == ht->_array[i]._state)
            printf("哈希地址为%d的数据为：%d\n", i, ht->_array[i]._data);
    }
}
