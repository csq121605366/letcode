#include <stdio.h>

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); //查找换行符
        if (find)                //如果地址不为NULL
            *find = '\0';        //在此处放一个空字符
        else
            while (getchar != '\n')
                continue; //处理输入行的剩余字符
    }
    return ret_val;
}