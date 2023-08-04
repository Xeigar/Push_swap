//This function has a problem sorting, it puts a bigger bar above a smaller one
void	middle_chase(l_list **stack_a, l_list **stack_b)
{
	l_list	*temp;
	l_list	*comp;
	l_list	*last;
	int		i;

	temp = *stack_a;
	i = 0;
	last = get_last(*stack_a);
	if ((*stack_a)->order > (*stack_b)->order && last->order < (*stack_b)->order)
		return;
	while (temp->next->next && !((temp->order < (*stack_b)->order)
		&& (temp->next->order > (*stack_b)->order)))
	{
		temp = temp->next;
		i++;	
	}
	comp = temp->next;
	while ((*stack_a) != comp)
	{
		if (i  <= list_size(*stack_a) / 2)
		 	cmd(stack_a, stack_b, "ra");
		else
			cmd(stack_a, stack_b, "rra");
	}
}

void	chaser(l_list **stack_a, l_list **stack_b, l_list *comp)
{
	l_list	*temp;
	int		i;

 	temp = *stack_a;
	i = 0;
	while (temp != comp)
	{
		temp = temp->next;
		i++;
	}
	while ((*stack_a) != comp)
	{
		if (i <= list_size(*stack_a) / 2)
			cmd(stack_a, stack_b, "ra");
		else
			cmd(stack_a, stack_b, "rra");
	}
}

void	case_select(l_list **stack_a, l_list **stack_b)
{
	l_list	*low;
	l_list	*high;

	low = find_lowest(*stack_a);
	high = find_highest (*stack_a);
	if ((*stack_b)->order > high->order)
	{	
		//printf("Choice 1\n");
		chaser(stack_a, stack_b, low);
		push(stack_b, stack_a, "pa");
	}
	else if (low->order > (*stack_b)->order)
	{
		//printf("Choice 2\n");
		chaser(stack_a, stack_b, low);
		push(stack_b, stack_a, "pa");
	}
	else
	{
		//printf("Choice 3\n");
		middle_chase(stack_a, stack_b);
		push(stack_b, stack_a, "pa");
	}
}


____________________________________________XXX______________________________

l_list	*calculator(l_list *stack_a, l_list *stack_b)
{
	int		position;
	int		place;
	l_list	*temp;
	l_list	*a;
	l_list	*cheapest;
	
	temp = stack_b;
	cheapest = NULL;
	position = 0;
	while(temp)
	{
		a = stack_a;
		place = 0;
		while (a->next->next && !((a->order < temp->order)
			&& (a->next->order > temp->order)))
		{
			place++;
			a = a->next;
		}
		if (position  <= list_size(stack_b) / 2 && place >= list_size(stack_a) + position)
			temp->price = position + (list_size(stack_a) - place);
		else if (position  > list_size(stack_b) / 2 && place < list_size(stack_a) + position)
			temp->price = place + (list_size(stack_a) - position);
		else if (position  > list_size(stack_b) && position >= place)
			temp->price = position;
		else
			temp->price = place;
		if (!cheapest || temp->price < cheapest->price)
			cheapest = temp;
		temp = temp->next;
		position++;
	}
	return (cheapest);
}


