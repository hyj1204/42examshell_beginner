#include <unistd.h>

void putchar(char c) {
  write(1, &c, 1);
}

char alpha_mirror(char *str)
{
  int go;
  int i;

  go = 0;
  i = 0;
  while (str[i] != '\0')
  {
    if(str[i] >= 'A' && str[i] <= 'M')
    {
      go = str[i] - 65;
      putchar(90 - go);
    }
    else if (str[i] >= 'N' && str[i] <= 'Z')
    {
      go = 90 - str[i];
      putchar(65 + go);
    }
    else if(str[i] >= 'a' && str[i] <= 'm')
    {
      go = str[i] - 97;
      putchar(122 - go);
    }
    else if (str[i] >= 'n' && str[i] <= 'z')
    {
      go = 122 - str[i];
      putchar(97 + go);
    }
    else
    {
      putchar(str[i]);
    }
    i++;
  }
  putchar('\n');
  return(*str);
}

int main(int ac, char **av)
{
  if (ac == 2)
  {
    alpha_mirror(av[1]);
  }
  else
  {
    putchar('\n');
  }
}
