/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:51:06 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 20:41:20 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("[argc is not 2]\n");
		return (1);
	}
	if (!validate_ext(argv[1]))
	{
		ft_printf("[not proper file ext]\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("[file don't exist]\n");
		return (1);
	}
	so_long(fd);
	close(fd);
	return (0);
}

void	so_long(int fd)
{
	t_t	*t;

	t = malloc(sizeof(t_t));
	if (t == NULL)
		return ;
	t->wd = malloc(sizeof(t_wd));
	if (t->wd == NULL)
		return ;
	t->md = malloc(sizeof(t_md));
	if (t->md == NULL)
		return ;
	t->md->row_size = 0;
	t->md->col_size = 0;
	set_str(fd, t->md);
	init_wd(t);
	if (deal_map(t))
		key_hook(t);
	mlx_loop(t->wd->mp);
	end_game(t);
}

int	deal_map(t_t	*t)
{
	t_c	person;

	if (!validate_map(t->md))
	{
		mlx_loop_end(t->wd->mp);
		return (0);
	}
	set_c_map(t->md);
	set_v_map(t->md);
	person = get_cor(t->md, P);
	t->md->possible = is_possible(t->md, person);
	if (!t->md->possible)
	{
		ft_printf("[impossible map]\n");
		mlx_loop_end(t->wd->mp);
		return (0);
	}
	init_tiles(t);
	return (1);
}

void	init_wd(t_t *t)
{
	t->wd->title = "so_long";
	t->wd->size_x = t->md->col_size * 20;
	t->wd->size_y = t->md->row_size * 20;
	t->wd->mp = mlx_init();
	t->wd->wp = mlx_new_window(\
	t->wd->mp, t->wd->size_x, t->wd->size_y, t->wd->title);
	return ;
}

int	validate_ext(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (*str == '\0')
		return (0);
	if (str[len - 1] != 'r' || str[len - 2] != 'e' \
	|| str[len - 3] != 'b' || str[len - 4] != '.')
		return (0);
	return (1);
}
