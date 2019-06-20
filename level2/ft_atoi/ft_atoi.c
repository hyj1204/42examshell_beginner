int ft_atoi(const char *str)
{
	int i;
	int num;
	int flag;

	i = 0;
	num = 0;
	flag = 1;
	if (str[0] == '-')
	{
		flag = -1;
		i++;
	}
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return flag * num;
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	return flag * num;
}