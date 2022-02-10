#include "push_swap.h"

int main(int argc, char **argv)
{
	t_vault *vault;
	int *arr;
	int *indexes;

	arr = (int *) malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (0);
	if (validator(argc, argv, arr) == 0) {
		ft_putendl_fd("Error", 2);
		return (0);
	}
	is_sorted(argc, arr);
	indexes = parse(argc, arr, &vault);
	print_data(vault, "");
	//TODO	sort(vault);
	sort(vault, indexes);
	print_data(vault, "");
	free(indexes);
	free(arr);
	free(vault);
	return (0);
}