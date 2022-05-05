void	bres_frag(t_fdf **data)
{
	double	bres[10];
	int		n[3];
	t_bres	*lol;
	
	(*data)->dx = fabs((*data)->x2 - (*data)->x1);
	(*data)->dy = fabs((*data)->y2 - (*data)->y1);
	(*data)->s1 = get_sign((*data)->x2 - (*data)->x1);
	(*data)->s2 = get_sign((*data)->y2 - (*data)->y1);
	(*data)->swap = 0;
	(*data)->x = (*data)->x1;
	(*data)->y = (*data)->y1;
	if (bres[1] > bres[0])
	{
		bres[5] = bres[0];
		bres[0] = bres[1];
		bres[1] = bres[5];
		bres[4] = 1;
	}
	bres[6] = 2 * bres[1] - bres[0];
	n[2] = 0;
	(*data)->dx = bres[0];
	(*data)->dy = bres[1];
	(*data)->s1 = bres[2];
	(*data)->s2 = bres[3];
	(*data)->swap = bres[4];
	(*data)->x = (*data)->x1;
	(*data)->y = (*data)->y1;
	(*data)->D = bres[6];
	(*data)->i = n[2];
	(*data)->x = n[0];
	(*data)->y = n[1];
	bres_frog(data);
	// while (n[2] < bres[0])
	// {
	// 	mlx_pixel_put((*data)->mlx_ptr, (*data)->win_ptr, n[0], n[1], (*data)->color);
	// 	while (bres[6] >= 0)
	// 	{
	// 		bres[6] = bres[6] - 2 * bres[0];
	// 		if (bres[4])
	// 			n[0] += bres[2];
	// 		else
	// 			n[1] += bres[3];
	// 	}
	// 	bres[6] = bres[6] + 2 * bres[1];
	// 	if (bres[4])
	// 		n[1] += bres[3];
	// 	else
	// 		n[0] += bres[2];
	// 	n[2]++;
	// }
}