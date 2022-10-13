int	ft_fibonacci(int n)
{
	int	i;
	int	tmp;
	int	current;
	int	last;

	if (n < 2)
		return (n);
	else
	{
		current = 1;
		last = 0;
		i = 2;
		while (i <= n)
		{
			tmp = current;
			current = current + last;
			last = tmp;
			i++;
		}
		return (current);
	}
}

