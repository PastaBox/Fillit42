/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:28:27 by fciprian          #+#    #+#             */
/*   Updated: 2016/11/30 14:51:44 by fciprian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define TETRIMINOS_MAX_HEIGHT (4 + 1)
# define TETRIMINOS_MAX_WIDTH 4
# define TETRIMINOS_MAX_LENGHT (TETRIMINOS_MAX_HEIGHT * TETRIMINOS_MAX_WIDTH)
# define TETRIMINOS_MAX 26

# define BUFFER_SIZE (TETRIMINOS_MAX * TETRIMINOS_MAX_LENGHT + 1)

# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_point
{
	int				*tab_x;
	int				*tab_y;
	int				posy;
	int				posx;
	char			**map;
}					t_point;

typedef struct		s_tetris
{
	t_point			tab;
	int				alpha;
	char			**str;
	struct s_tetris	*next;
}					t_tetris;

t_tetris			*ft_solver(char *buffer, int tetriminos);
t_tetris			*ft_create(t_tetris *list, int a, char *buffer, int start);

void				ft_set_message_errors(char *message);
void				ft_gestion(int file_descriptor);
void				ft_print_mapping(char **map);
void				ft_gestion(int file_descriptor);
void				ft_check_length(int length);
void				ft_check_empty_separator(char *buffer);

char				**ft_alloc(char *buffer, int start);
char				**ft_mapping(int tetraminos);
char				**ft_recur_map(t_tetris *list, int tetraminos);
char				**ft_reset_map(t_tetris *list, int y, int x, char **map);
char				**ft_place_piece(t_tetris *list, int y, int x, char **map);

int					ft_valid_map(char *buffer);
int					ft_check_contact(char *s);
int					ft_check_chars(char *buffer);
int					ft_resolution(t_tetris *list, char **map, int size);
int					ft_valid_map(char *buffer);
int					ft_check_valid(t_tetris *list, int y, int x, char **map);
int					ft_tetris_norme(int tetris);
int					*ft_check_block_x(t_tetris *list);
int					*ft_check_block_y(t_tetris *list);
int					ft_resolution(t_tetris *list, char **map, int size);
int					ft_valid_map(char *buffer);
int					ft_char(int tetraminos);
int					*ft_malloc_tab(int *tab);
int					ft_check_pattern(char *str);
int					ft_reader(int file_descriptor, char *buffer);
int					ft_check_empty_map(char *buffer);
int					ft_return_contact(char *s, int i, int contact, int tetris);

#endif
