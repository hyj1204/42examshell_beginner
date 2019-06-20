#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    int i;
    int max;
    int len;
    int tmp;


    len = size;  //len = 5
    while (len > 0)
    {
        i = 0;
        max = tab[0];
        tmp = 0;
        while (i < len)   //i [0-3]
        {
            if (tab[i] > max)
            {
                max = tab[i];
                tmp = i;
            }
            i++;
        }
        tab[tmp] = tab[len - 1];
        tab[len - 1] = max;
        len--;
    }
}

int main()
{
    int tab[5];
    int i;

    i = 0;
    tab[0] = 5;
    tab[1] = 2;
    tab[2] = 3;
    tab[3] = 4;
    tab[4] = 5;
    sort_int_tab(tab, 5);
    while (i < 5)
    {
        printf("tab = %d \n", tab[i]);
        i++;
    }
    return (0);
}