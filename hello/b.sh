#!bin/bash

cc get_next_line.c get_next_line_utils.c main.c ft_draw.c ft_mlx_putstr.c ft_color.c ft_bresenham.c ft_read_color.c ft_split.c ft_rotate.c ft_init.c ft_keys.c ft_read_file.c -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit
