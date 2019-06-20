#include <unistd.h> 
#include <stdio.h>

 unsigned char reverse_bits(unsigned char octet)
{
	unsigned char result = 0;
	unsigned int  len = 8;

	while (len > 0)
	{
		result = (result << 1) | (octet & 1); //从0开始，获得每一次最后位置的值（octet & 1），并上之前向前移一位的值（result << 1）。
        octet = octet >> 1;//原来的数向后移一位，以便下次获得后面一位的值
		len--;
	}
	return (result);
}


void	print_bits(unsigned char octet)
{
	int i = 128;
    int len = 8;
	while (len-- > 0)
	{
		if ((octet & i) == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		i = i >> 1;
	}
}

int	main(void)
{
	unsigned char c;
	unsigned char reverse;
	c = '&';
    printf("char & int %%d = %d\n", c);
	print_bits(c);
	printf("\n");
    reverse = reverse_bits(c);
	print_bits(reverse);

	return (0);
}