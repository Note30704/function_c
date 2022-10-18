#include <stdio.h>
#include <stdlib.h>

#define	MAX_LIST	100

typedef	struct	a_point
{
	int	list[MAX_LIST];
	int	length;
}				ArrayList;

void	error(char	*error)
{
	fprintf(stderr, "%s\n", error);
	exit(1);
}

void	init(ArrayList	*list)
{
	list -> length = 0;
}
	
int		is_empty(ArrayList	*list)
{
	return (list -> length == 0);
}

int		is_full(ArrayList	*list)
{
	return (list -> length == MAX_LIST);
}

void	display(ArrayList	*list)
{
	int	i;

	i = 0;
	while (i < list -> length)
	{
		printf("%d\n", list -> list[i]);
		i++;
	}
}

void	add(ArrayList *list, int position, int item)
{
	int	i;
	if (!is_full(list) && (position >= 0) && (position <= list -> length))
	{
		i = list -> length - 1;
		while (i >= position)
		{
			list -> list[i + 1] = list -> list[i];
			i--;
		}
		list -> list[position] = item;
		list -> length++;
	}
}

int	delete(ArrayList *list, int position)
{
	int	i;
	int	item;

	if (position < 0 || position >= list -> length)
		error("위치 오류");

	item = list -> list[position];
	i = position;
	while (i < list -> length - 1)
	{
		list -> list[i] = list -> list[i + 1];
		i++;
	}
	list -> length--;
	return (item);
}

int	main(void)
{
	int	i;
	ArrayList	list1;
	ArrayList	*plist;

	init(&list1);
	add(&list1, 0, 10);
	add(&list1, 0, 20);
	add(&list1, 0, 30);
	display(&list1);
	delete(&list1, 2);
	delete(&list1, 1);
	display(&list1);
	
	plist = (ArrayList *)malloc(sizeof(ArrayList));
	init(plist);
	add(plist, 0, 10);
	add(plist, 0, 20);
	add(plist, 0, 30);
	display(plist);
	free(plist);

	return (0);
}
