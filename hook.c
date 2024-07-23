#include "so_long.h"


key_hook(t_win_data *win_data)
{
	void	*param_ptr;
	param_ptr = NULL;
	// 원본
	// int mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
	// param의 역할을 전혀 모르겠음
	mlx_key_hook(win_data->win_ptr, &move_person, param_ptr);
}

// int move_person(int key, void *param)
int move_person(int key)
{
	// t_win_data *win_data;

	// win_data = (t_win_data *)param;
	if (key == KEY_W || key == KEY_UP)
	{
			// move up
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
			// move down
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
			// move left
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
			// move right
	}
	return (0);
}

// mouse_hook(int button,int x,int y,void *param);