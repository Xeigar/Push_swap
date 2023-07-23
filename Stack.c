/**This function finds the position of the closest number of the partition
and sends it to stack_b with the least amount of move**/
void	finder_pusher(l_list **stack_a, l_list **stack_b, int partition)
{
	l_list	*temp;
	int		a;
	int		b;

	temp = *stack_a;
	a = 0;
	b = 0;
	while (temp)
	{
		if (a == 0 && temp->order <= partition)	
			a = temp->order;
		if (temp->order < partition)
			b = temp->order;
		temp = temp->next;
	}
	printf(" a = %d\n", a);
	if (a <= (list_size(*stack_a) - b))
	{
		while ((*stack_a)->order != a)
			cmd(stack_a, stack_b, "rra");
	}
	else
	{
		while ((*stack_a)->order != b)
			cmd(stack_a, stack_b, "ra");
	}
	push(stack_a, stack_b, "pb");
}

____________________________________X________________________________________

void	big_sort(l_list **stack_a, l_list **stack_b)
{
	//l_list	*temp;
	int		partition;
	int		counter;
	int		runner;

	//temp = *stack_a;
	ordering(stack_a);
	if (list_size(*stack_a) <= 100)
		partition = 4;
	else
		partition = 8;
	runner = 0;
	while (++runner < partition)
	{
		counter = -1;
		printf("%d\n", list_size(*stack_a)/ partition);
		while (++counter < ((list_size(*stack_a)/ partition) * runner))
			finder_pusher(stack_a, stack_b, list_size(*stack_a)/ partition); /*Need to
			to revise the partition variable it is not working in the finder_pusher*/
	}
}

____________________________________X________________________________________

void	big_sort(l_list **stack_a, l_list **stack_b)
{

	ordering(stack_a);
	push(stack_a, stack_b, "pb");
	push(stack_a, stack_b, "pb");
	while (list_size(*stack_a) != 3)
	{
		if ((*stack_a)->order < (*stack_b)->order)
		{
			cmd(stack_a, stack_b, "rra");
			push(stack_a, stack_b, "pb");
		}
		else
			push(stack_a, stack_b, "pb");
	}
	small_sort(stack_a, stack_b);
	printf(" -----------\ndone small sort\n -----------\n");
	while(*stack_b)
	{
		if ((*stack_a)->order > (*stack_b)->order)
		{
			push(stack_b, stack_a, "pa");
		}
		else
		{
			while ((*stack_a)->order < (*stack_b)->order && (*stack_a)->next->order > (*stack_b)->order)
				cmd(stack_a, stack_b, "rra");
			push(stack_b, stack_a, "pa");	
		}
	}
}
_____________________________________X________________________________________

/*Optimize the pushing to B part of the function by working with Max
and Min, as well as count the number of rrb and rb*/
void	b_filler(l_list	**stack_a, l_list **stack_b)
{
	
	while (list_size(*stack_a) != 3)
	{
		if ((*stack_a)->order < (*stack_b)->order)
			cmd(stack_a, stack_b, "rrb");
		else
			push(stack_a, stack_b, "pb");
		if (!(*stack_b)->next)
			push(stack_a, stack_b, "pb");
	}
}

int	last_check(l_list **stack_a, int order)
{
	l_list	*temp;

	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	printf("last stack a value = %d and order = %d\n", temp->data, temp->order);
	if (temp->order > order)
		return (1);
	return (0);
}

void	big_sort(l_list **stack_a, l_list **stack_b)
{
	ordering(stack_a);
	push(stack_a, stack_b, "pb");
	b_filler(stack_a, stack_b);
	small_sort(stack_a, stack_b);
	printf(" -----------\ndone small sort\n -----------\n");
	while(*stack_b)
	{
		
		l_list	*begin;
	begin = *stack_a;
	printf("________________________\n");
	while (begin)
	{
		printf("a = %d\n", begin->data);
		printf("a->order = %d\n", begin->order);
		begin = begin->next;
	}
	begin = *stack_b;
	while (begin)
	{
		printf("b = %d\n", begin->data);
		begin = begin->next;
	}
	printf("________________________\n");
	
		l_list	*low;
		l_list	*high;

		low = find_lowest(*stack_a);
		high = find_highest (*stack_a);
		if ((*stack_b)->order > high->order)
		{	
			while ((*stack_a) != high)
				cmd(stack_a, stack_b, "ra");
			push(stack_b, stack_a, "pa");
		}
		else if (low->order > (*stack_b)->order)
		{
			while ((*stack_a)->order != low->order)
				cmd(stack_a, stack_b, "ra");
			push(stack_b, stack_a, "pa");
		}
		else
		{
			while ((*stack_a)->order > (*stack_b)->order && last_check(stack_a, (*stack_b)->order))
				cmd(stack_a, stack_b, "ra");
			push(stack_b, stack_a, "pa");
		}
	}
	//while ((*stack_a)->order != 1)
	//	cmd(stack_a, stack_b, "rra");
}

________________________________________X____________________________________

long	ft_long_atoi(const char *nptr)
{
	long	i;
	long	neg;

	i = 0;
	neg = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg *= (-1);
		nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9'))
		return (-2147483649);
	while (*nptr)
	{
		if (!(*nptr >= '0' && *nptr <= '9'))
			return (-2147483649);
		i = i * 10 + (*nptr - 48);
		nptr++;
	}
	return (i * neg);
}

______________________________________X______________________________________

long_atoi_v1

long	ft_long_atoi(const char *nptr)
{
	long	i;
	long	neg;

	i = 0;
	neg = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg *= (-1);
		nptr++;
	}
	if (*nptr >= '0' && *nptr <= '9')
	{
		while (*nptr >= '0' && *nptr <= '9')
		{
			i = i * 10 + (*nptr - 48);
			nptr++;
		}
	}
	else
		return (-2147483649);
	return (i * neg);
}