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