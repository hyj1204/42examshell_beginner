#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char	*ft_itoa(int nbr)
{
    char *str;
    int len;
    int i;
    int tmp;  //因为求值过程会变动输入值，所以需要一个临时的int
    int flag;  //1代表正数，-1代表负数

    len = 0;
    flag = 1;
    i = 0;
    if (nbr == -2147483648)
        return ("-2147483648"); //因为下面的方法无法计算出2147483648这个数，而这个数是int需要显示出来，所以需要特殊处理
    if (nbr == 0)
    {
        if (!(str = (char*)malloc(2))) //给返回的字符串分配内存，如果失败返回null
            return NULL;
        str[0] = '0';
        len = 1;
    }
    else
    {
        if (nbr < 0)
        {
            nbr = nbr * (-1); //所有数字作为正数处理
            flag = -1;
        }

        tmp = nbr;   //例如输入数字是1234
        while (tmp > 0) //把输入的数字一直除以10，直到个位数，最后一次例如：1/10 = 0.1 > 0,len++,把1这一位算入
        {
            tmp = tmp / 10;
            len++;
        } /*循环结束，此时得到这个数有多少位，例如4位*/

        if (flag == -1)    
        {
           if (!(str = (char*)malloc(len + 2)))    //负数的时候在开头加-号和terminal的空间
                return NULL;
            i = len;
            while (i > 0)  //从位置1到len
            {
                str[i] = nbr % 10 + '0';
                nbr = nbr / 10;
                i--;
            }
            str[0] = '-';
            str[len + 1] = '\0';
        }
        else 
        {
            if (!(str = (char*)malloc(len + 1)))
                return NULL;
            i = len - 1;
            while (i >= 0)  //从位置0到len - 1
            {
                str[i] = nbr % 10 + '0';
                nbr = nbr / 10;
                i--;
            }
             str[len] = '\0';
        }
    }
    return str;
}

int main()
{
    printf("%s\n", ft_itoa(0));
    return (0);
}