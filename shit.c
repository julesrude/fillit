#include "libft.h"

int	rec_factorial(int num)
{
	if(num == 1)
		return(1);
	return(num * rec_factorial(num - 1));
}

int	main()
{
	ft_putnbr(rec_factorial(5));
	return(0);
}
