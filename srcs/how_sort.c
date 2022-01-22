/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:57:15 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/21 23:58:32 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_10(t_stack *stack_a, t_stack *stack_b)
	b_num = stack_b->numbers;	
	while (3 < stack_a->numbers && !issorted(stack_a, STD))
	{
		min_pos = get_min_max(stack_a, MAX);
		min_pos = get_min_max(stack_a, MIN);
		half = stack_a->numbers / 2;
		if (min_pos <= half)
		{
void	sort_10(t_stack *stack_a, t_stack *stack_b)
		else
			while (min_pos++ <= stack_a->numbers)
				rra_rrb(stack_a, "rra");
		if (!issorted(stack_a, REV))
		if (!issorted(stack_a, STD))
			pa_pb(stack_a, stack_b, 'b');
	}
	sort_3(stack_a);
	while (b_num < stack_b->numbers)
	while (0 < stack_b->numbers)
		pa_pb(stack_b, stack_a, 'a');
}

void	sort_3_r(t_stack *stack_a)
	}
}

void	sort_10_r(t_stack *stack_b, t_stack *stack_a)
{
	int m_pos;
	int half;
	int b_num;

	b_num = stack_b->numbers;
	while (3 < stack_b->numbers && !issorted(stack_b, REV))
	{
		m_pos = get_min_max(stack_a, MAX);
		half = stack_a->numbers / 2;
		m_pos = get_min_max(stack_b, MAX);
		half = stack_b->numbers / 2;
		if (m_pos <= half)
		{
			while (1 < m_pos--)
				ra_rb(stack_a, "rb");
				ra_rb(stack_b, "rb");
		}
		else
			while (m_pos++ <= stack_a->numbers)
				rra_rrb(stack_a, "rrb");
			while (m_pos++ <= stack_b->numbers)
				rra_rrb(stack_b, "rrb");
		if (!issorted(stack_a, REV))
			pa_pb(stack_a, stack_b, 'a');
			pa_pb(stack_b, stack_a, 'a');
	}
	sort_3_r(stack_a);
	sort_3_r(stack_b);
	while (b_num < stack_b->numbers)
		pa_pb(stack_b, stack_a, 'b');
		pa_pb(stack_a, stack_b, 'b');
}

void	sort_b_r(t_stack *stack_b, t_stack *stack_a, bool fchunk)
void	smart_pb(t_stack *stack_a, t_stack *stack_b)
{
		t_node	*last;

		last = stack_b->bottom;
		while(stack_a->top->index < stack_b->top->index)
		{
			ra_rb(stack_b, "rb");
			stack_b->rb_count++;
		}
		if (stack_a->top->index > stack_b->top->index)
		{
			while (stack_a->top->index > stack_b->bottom->index && stack_b->bottom->index != 0)
			{
				rra_rrb(stack_b, "rrb");
				stack_b->rb_count--;
			}
			pa_pb(stack_a, stack_b, 'b');
		}
		while (stack_a->seg == stack_b->numbers && !issorted(stack_b, REV))			// push rb_count back, when seg == numbers
		{
			rra_rrb(stack_b, "rrb");
			stack_b->rb_count--;
		}
}

void	sort_b_r(t_stack *stack_a, t_stack *stack_b)
{
	int	rb_count;
	int half;

	half = stack_b->numbers / 2;
	rb_count = 0;
	if(fchunk == true)
	if(stack_a->c_chunk == 1)
	{
		pa_pb(stack_a, stack_b, 'b');
		sort_10_r(stack_b, stack_a);
	}
	while (fchunk == false)
	if (stack_a->c_chunk > 1)
	{
		if (stack_a->top->index > stack_b->top->index)
		pa_pb(stack_a, stack_b, 'b');
		smart_pb(stack_a, stack_b);
	}
}

void	sort_b(t_stack *stack_a, t_stack *stack_b)
{
	int	max_pos;
	int	rb_count;

	rb_count = 0;
	while (0 < stack_b->numbers && !issorted(stack_b, REV))
	{
		max_pos = get_min_max(stack_b, MAX);
		while(max_pos > 2)
		{
			ra_rb(stack_b, "rb");
			rb_count++;
			max_pos--;
		}
		if (max_pos == 2)
			sa_sb(stack_b, "sb");
		if (!issorted(stack_a, REV))
			pa_pb(stack_b, stack_a, 'a');
		while (0 < rb_count--)
			rra_rrb(stack_b, "rrb");
	}
	while (0 < stack_b->numbers)
		pa_pb(stack_b, stack_a, 'a');
}
//void	sort_b(t_stack *stack_a, t_stack *stack_b)
//{
//	int	max_pos;
//	int	rb_count;
//	
//	rb_count = 0;
//	while (0 < stack_b->numbers && !issorted(stack_b, REV))
//	{
//		max_pos = get_min_max(stack_b, MAX);
//		while(max_pos > 2)
//		{
//			ra_rb(stack_b, "rb");
//			rb_count++;
//			max_pos--;
//		}
//		if (max_pos == 2)
//			sa_sb(stack_b, "sb");
//		if (!issorted(stack_a, REV))
//			pa_pb(stack_b, stack_a, 'a');
//		while (0 < rb_count--)
//			rra_rrb(stack_b, "rrb");
//	}
//	while (0 < stack_b->numbers)
//		pa_pb(stack_b, stack_a, 'a');
//}

void	seg_a(t_stack *stack_a, t_stack *stack_b, int key, int seg, bool fchunk)
void	seg_a(t_stack *stack_a, t_stack *stack_b)
{
	int		t_pos;
	int		half;

	while ((stack_b->numbers < seg) && 1 < key)   //pust t_pos and half and seg into t_struct stack
	stack_a->c_chunk += 1;
	while (stack_b->numbers < stack_a->seg && stack_a->c_chunk < stack_a->chunks)    //put, key, t_pos and half and seg into t_struct stack  
	{
		t_pos = get_target(stack_a, seg);
		t_pos = get_target(stack_a, stack_a->seg);
		half = stack_a->numbers / 2;
		if (t_pos <= half && 0 < t_pos)
		{
void	seg_a(t_stack *stack_a, t_stack *stack_b, int key, int seg, bool fchunk)
				rra_rrb(stack_a, "rra");
				t_pos++;
			}
		sort_b_r(stack_b, stack_a, fchunk);		//if sort_b_r = true --> first chunk if sort_b_r = false --> other chunks
		sort_b_r(stack_a, stack_b);	//if sort_b_r = true --> first chunk if sort_b_r = false --> other chunks
	}
	if (stack_b->numbers == seg && 2 < key)
	if (stack_b->numbers == stack_a->seg && stack_a->c_chunk < stack_a->chunks)
	{
		seg = (stack_a->numbers + stack_b->numbers) / key;
		seg_a(stack_a, stack_b, --key, seg, false);
		stack_a->seg += (stack_a->numbers + stack_b->numbers) / stack_a->chunks;
		seg_a(stack_a, stack_b);
	}
}

t_stack	sort_100(t_stack *stack_a, t_stack *stack_b)
{
	int	seg;
	int key;

	key = 0;
	index_a(stack_a);
	if (stack_a->numbers < 60)
		key = 4;
	else if (stack_a->numbers < 500)
		key = 11;
	seg = stack_a->numbers / key;
	seg_a(stack_a, stack_b, key, seg, true);
	if (stack_a->numbers <= 60)
		stack_a->chunks = 4;
	else if (stack_a->numbers <= 100)	// 8 = 814 Operations // 9 = 815 Ops 
		stack_a->chunks = 8;
	else if (stack_a->numbers <= 500) 
		stack_a->chunks = 16; // 14 = 7968 // 15 = 7863 // 16 = 7854 // 17 = 7920 // 18 = 8013 // 19 = 8040 // 20 = 8030
	stack_a->seg = stack_a->numbers / stack_a->chunks;
	seg_a(stack_a, stack_b);
	sort_10(stack_a, stack_b);
	//sort_b(stack_a, stack_b);
	return (*stack_b);
}

// IDEAS SET NEW  VAR IN STRUCT STACK->AB = A OR B THEN CHANGE ALL FUNCTIONS TO REVERSE AND NORMAL IN 1

t_stack	how_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!issorted(stack_a, STD) && stack_a->numbers > 1)
	if (!issorted(stack_a, STD) && stack_a->numbers > 0)
	{ 
		if (stack_a->numbers <= 3)
			sort_3(stack_a);