#include <stdlib.h>
#include <stdio.h>
#include "../includes/minilibx-linux/mlx.h"
#include "../includes/fract_ol.h"

int	key_hook()
{
	printf("Hello from key_hook!\n");
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return(1);

	data.win = mlx_new_window(data.mlx, WIN_HEIGHT, WIN_WIDTH, "Window");
	if (data.win == NULL)
    {
        mlx_destroy_display(data.mlx);
        free(data.mlx);
        return (1);
    }

	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);

    mlx_destroy_display(data.mlx);
    free(data.mlx);
	return (0);
}