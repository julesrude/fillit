int		place_tetra(t_tetromino *tetra, char **current_map, int size)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = tetra->x;
	y = tetra->y;
	i = 0;
	j = 0;
	if (x <= size - tetra->height + 1 && y <= size - tetra->width + 1)
	{
		while (i < tetra->height)
		{
			while(j < tetra->width)
			{
				printf(COLOR_YELLOW "trying to place it to x:%d y:%d\n" COLOR_RESET, tetra->x, tetra->y); // ВИВОД!
				
					printf(COLOR_RED "%c\nmap coord: x %d y %d\ntetra coord: x %d y %d\n" COLOR_RESET, current_map[2][2], x + i, y + j, i, j);
					
					show_map();
					printf(COLOR_GREEN "-------------%c\n" COLOR_RESET, current_map[x + i][y + j]);
				if(COMBINE(tetra->figure[i][j], current_map[x + i][y + j]) != '0')
					{
						current_map[x + i][y + j] = COMBINE(tetra->figure[i][j], current_map[x + i][y + j]); //змогло поставити навіть дві - і всьо, поїхали. а треба зупиняти, якщо не всі
						printf(COLOR_MAGENTA "if\n" COLOR_RESET);
					}
				else 
				{
					
					printf(COLOR_MAGENTA "else\n" COLOR_RESET);
					tetra->y = y + 1;
					place_tetra(tetra, map->field, size);
					return(0);
				}
				j++;
			}
		j = 0;
		i++;
		}
	}
	else if(x < size - tetra->height + 1 && y >= size - tetra->width + 1)
	{
		printf(COLOR_CYAN "changing the x. x:%d, y:%d\n" COLOR_RESET, tetra->x, tetra->y); // ВИВОД!
		show_map();
		tetra->y = 0;
		tetra->x = x + 1;
		place_tetra(tetra, map->field, size);
		return (0);
	}
	else
		return (0);
	//ft_arrfree((void **)map->field, map->size);
	if(i == tetra->height || j == tetra->width)
		map->field = current_map;
	return (1);
}
