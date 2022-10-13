double	ft_pow(double x, int n)
{
	if (n == 0)
		return (1);
	else if (n & 1)		//n % 2 == 1 (홀수);
		return (x * ft_pow(x * x, (n - 1) / 2));
	else
		return (ft_pow(x * x, n / 2));
}


//n이 홀수 인 경우 (n - 1)로 인해 x를 한 번 더 곱해준다.
