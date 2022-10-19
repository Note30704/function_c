#include <stdio.h>
#include <stdlib.h>

typedef int	element;

typedef	struct	L_point
{
	element			data;
	struct	L_point	*link;
}				LinkList;

void	error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void	insert(LinkList **phead, LinkList *p, LinkList *new_node)
{
	if (*phead == NULL)
	{
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL)
	{
		new_node->link = *phead;
		*phead = new_node;
	}
	else
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

void	delete(LinkList **phead, LinkList *p, LinkList *select)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = select->link;
	free(select);
}

void	display(LinkList *head)
{
	LinkList	*p = head;

	while (p != NULL)
	{
		printf("%d -> ", p->data);
		p = p->link;
	}
	printf("\n");
}

LinkList	*create(element data, LinkList *link)
{
	LinkList	*new_node;

	new_node = (LinkList *)malloc(sizeof(LinkList));

	if (new_node == NULL)
		error("메모리 할당 에러");
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}

LinkList	*search(LinkList *head, int find)
{
	LinkList	*p;

	p = head;
	while (p != NULL)
	{
		if (p->data == find)
			return (p);
		p = p->link;
	}
	return (p);
}

LinkList	*reverse(LinkList *head)
{
	LinkList	*p;
	LinkList	*q;
	LinkList	*r;

	p = head;
	q = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return (q);
}

int	main(void)
{
	LinkList	*p;
	LinkList	*list1 = NULL;
	LinkList	*list2 = NULL;

	insert(&list1, NULL, create(10, NULL));
	insert(&list1, NULL, create(20, NULL));
	insert(&list1, NULL, create(30, NULL));
	display(list1);

	insert(&list1, list1 - 2, create(50, NULL));	//리스트, 넣을자리, target
	display(list1);

	delete(&list1, NULL, list1);
	display(list1);

	insert(&list2, NULL, create(60, NULL));
	insert(&list2, NULL, create(70, NULL));
	insert(&list2, NULL, create(80, NULL));

	display(list2);

	list2 = reverse(list2);
	display(list2);

	p = search(list1, 50);
	printf("ans = %d", p->data);
	free(list1);
	free(list2);
	return (0);
}
