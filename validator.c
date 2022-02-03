#include "push_swap.h"
#include <stdio.h>

//TODO 32 linebreaks insted 24
//TODO norminette

int validator(int argc, char **argv, int array[])
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i + 1]) > 2147483647
			|| ft_atoi(argv[i + 1]) < (-2147483648) || ft_strlen(argv[i + 1]) > 11)
			return (0);
        j = 1;
        if (!ft_isdigit(argv[i + 1][0]) && argv[i + 1][0] == '-')
        {
            if (!ft_isdigit(argv[i + 1][1]))
                return (0);
            j = 2;
        }
        while (argv[i + 1][j]) {
            if (!ft_isdigit(argv[i + 1][j++]))
                return (0);
		}
		array[i] = ft_atoi(argv[i + 1]);
		ft_putnbr_fd(array[i], 1); 			//trace
		j = i - 1;
		while (j >= 0)
		{
			if (array[i] == array[j--])
				return (0);
		}
		i++;
	}
	return (1);
}