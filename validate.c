#include "so_long.h"

int main(void)
{
	int fd = open("map.ber", O_RDONLY);
	t_total_data *total_data;
	total_data = malloc(sizeof(t_total_data));
	total_data->map_data = malloc(sizeof(t_map_data));
	set_map_str(fd, total_data);
	printf("\n%d\n", is_square(total_data->map_data));
	return (0);	
}



bool	is_square(t_map_data *map_data)
{	
	int index;
	int	line_len;
	int current;
	
	index = 0;
	line_len = 0;
	current = 0;
	
	while (map_data->map_str[line_len] != '\n' && map_data->map_str[line_len] != '\0')
		line_len++;
	index = line_len + 1;
	while (map_data->map_str[index] != '\0')
	{
		current = index;
		while (map_data->map_str[current] != '\n' && map_data->map_str[current] != '\0')
			current++;
		if (current - index != line_len)
			return (false);
		index += line_len;
		if (map_data->map_str[index] == '\n')
			index++;
	}
	return (true);
}




void	*set_map_str(int fd, t_total_data *total_data)
{
	int	read_return;
	char buf[5];
	total_data->map_data->map_str = malloc(sizeof(char) * 1);
	if (total_data->map_data->map_str == NULL)
		return (NULL);
	total_data->map_data->map_str[0] = '\0';
	while (1)
	{
		read_return = read(fd, buf, 5);
		buf[read_return] = '\0';
		total_data->map_data->map_str = join_s(total_data->map_data->map_str, buf);
		if (read_return < 5)
			break;
	}
	// free(buf);
	printf("%s\n", total_data->map_data->map_str);
	return (NULL);
}




// bool	is_wall(t_map_data *map_data)
// {
// 	int index;
// 	int	line_len;
// 	index = 0;
// 	line_len = 0;
// 	while (map_data->map_str[line_len++] != '\n')
// 		;
// 	while (index < line_len)
// 	{
// 		if (map_data->map_str[index] != '1')
// 			return (false);
// 		index++;
// 	}
// 	while (map_data->map_str[index] != '\0')
// 	{
// 		if (map_data->map_str[index] != '1' || map_data->map_str[index + line_len] != '1')
// 			return (false);
// 		index += line_len;
// 	}
// 	index -= line_len;
// 	while (map_data->map_str[index] != '\0')
// 	{
// 		if (map_data->map_str[index] != '1')
// 			return (false);
// 		index++;
// 	}
// 	return (true);
// }




// int	is_proper_char(char *map_str)
// {
// 	int index;
// 	int	count_c;
// 	index = 0;
// 	count_c = 0;
// 	while (map_str[index] != '\0')
// 	{
// 		if (map_str[index] == c)
// 			count_c++;
// 		index++;
// 	}
// 	return (count_c);
// }

