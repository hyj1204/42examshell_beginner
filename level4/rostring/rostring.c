#include <stdlib.h>
#include <unistd.h>

void putchar(char c) {
  write(1, &c, 1);
}

void putstr(char *str) {
    int i;

    i = 0;
    while (str[i])
    {
        putchar(str[i]);
        i++;
    }
}

int words_num(char *str) //计算有几个单词
{
    int i;
    int num;
    int flag;

    i = 0;
    num = 0;
    flag = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
        i++;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
        {
            flag = 1;
            i++;
        }
        if (flag == 1)
        {
            num++;
            flag = 0;
        }
    }
    return (num);
}

int rostring(char *str)
{
    int i;
    int x;
    int y;
    int num;
    int len; //代表每个单词的长度
    char **words;


    i = 0;
    num = words_num(str);//得到一共有多少个单词
    len = 0;
    x = 0;
    y = 0;

    if (!(words = (char**)malloc(sizeof(char*) * (num + 1)))) //每个单词放一行，一共有（num + 1)行
        return (0);
    words[num] = NULL;
    while (str[i] != '\0')
    {
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
        { 
            len++;
            i++;
        }
        if (!(words[x] = (char*)malloc(sizeof(char) * len + 1))) //为每个单词创建空间
                return (0);
        x++;
        len = 0;
        if(str[i])
            i++;
    }

    i = 0;
    x = 0;
    while (str[i]!= '\0')
    {
        y = 0;
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
        {
            words[x][y] = str[i];   //把每个单词放入相应的空间words[0] 代表第一个单词
            i++;
            y++;
        }
        words[x][y] = '\0';
        x++;
        if(str[i])
            i++;
    }
    
    if (num == 1)
        putstr(words[0]);
    else if (num == 0)
        return (0);
    else 
    {
        i = 1;
        while (i < num)
        {
            putstr(words[i]);
            putchar(' ');
            i++;
        }
        putstr(words[0]);       
    }

    return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		rostring(av[1]);
        write(1, "\n", 1);
	}
	return (0);
}
