#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
int *twoSum(int *nums, int numsSize, int target);

int main()
{
   // sum();
   int nums[] = {2, 7, 11, 15};
   int target = 9;
   int *res = twoSum(nums, 4, target);
   printf("%d,%d\n", res[0], res[1]);
   // getchar();
   return 0;
}

// int *twoSum(int *nums, int numsSize, int target)
// {

//    for (int i = 0; i < numsSize; i++)
//    {
//       int num = target - nums[i];
//       for (int j = i + 1; j < numsSize; j++)
//       {
//          if (nums[j] == num)
//          {
//             static int resArray[2];
//             resArray[0] = i;
//             resArray[1] = j;
//             return resArray;
//          }
//       }
//    }
//    return 0;
// }

struct node
{
   int val;           //值
   int index;         //index
   struct node *next; //下一个node地址
};
void insert(struct node **hashTable, int val, int index, int n)
{
   int t = abs(val) % n;
   struct node *temp = hashTable[t];
   while (temp)
   {
      temp = temp->next;
   }
   struct node *add = (struct node *)malloc(sizeof(struct node));
   add->val = val;
   add->index = index;
   add->next = temp->next;
   temp->next = add;
}
//在hashTable中查找 目标值的index
int search(struct node **hashTable, int target, int n)
{
   //获取要对比的hash下标
   int index = abs(target) % n;
   struct node *temp = hashTable[index]->next;
   while (temp)
   {
      if (temp->val == target)
      {
         return temp->index;
      }
      temp = temp->next;
   }
   return -1;
}
void freeHashTable(struct node **hashTable, int n)
{
   int i = 0;
   struct node *temp = NULL, *delete = NULL;
   for (i = 0; i < n; i++)
   {
      temp = hashTable[i];
      delete = temp;
      while (temp)
      {
         delete = temp;
         temp = temp->next;
         free(delete);
      }
   }
   free(hashTable);
}
int *twoSum(int *nums, int numsSize, int target)
{
   int i = 0, j = 0;
   int n = numsSize, index = 0;
   int *result = NULL;
   //分配hash表空间
   struct node **hashTable = (struct node **)malloc(n * sizeof(struct node *));
   // init head node
   for (i = 0; i < n; i++)
      hashTable[i] = (struct node *)calloc(1, sizeof(struct node));
   for (i = 0; i < n; i++)
   {
      //获取hashTable中的值下标
      index = search(hashTable, target - nums[i], n);
      //未找到目标值则将当前值插入到hashTable中
      if (-1 == index)
         insert(hashTable, nums[i], i, n);
      else
      {
         result = (int *)malloc(sizeof(int) * 2);
         result[0] = index;
         result[1] = i;
         freeHashTable(hashTable, n);
         return result;
      }
   }
   freeHashTable(hashTable, n);
   return result;
}

// struct node
// {
//    int val;
//    int index;
// };
// int comp(const void *a, const void *b)
// {
//    return (((struct node *)a)->val > ((struct node *)b)->val ? 1 : -1);
// }
// int *twoSum(int *nums, int numsSize, int target)
// {
//    int i = 0;
//    int n = numsSize;
//    int begin = 0, end = n - 1;
//    int *result = NULL;
//    struct node *nodes = (struct node *)malloc(n * sizeof(struct node));
//    // init nodes
//    for (i = 0; i < n; i++)
//    {
//       nodes[i].val = nums[i];
//       nodes[i].index = i;
//    }
//    qsort(nodes, n, sizeof(struct node), comp);
//    while (begin < end)
//    {
//       if (nodes[begin].val + nodes[end].val == target)
//       {
//          result = (int *)malloc(sizeof(int) * 2);
//          result[0] = nodes[begin].index;
//          result[1] = nodes[end].index;
//          free(nodes);
//          return result;
//       }
//       else if (nodes[begin].val + nodes[end].val > target)
//          end--;
//       else
//          begin++;
//    }
//    free(nodes);
//    return result;
// }
