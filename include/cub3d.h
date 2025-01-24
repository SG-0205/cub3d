/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:22:08 by armeyer           #+#    #+#             */
/*   Updated: 2025/01/24 13:51:56 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
// Include des macros d'erreur
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD_W_Z 119
# define BACK_S_S 115
# define RIGHT_D_D 100
# define LEFT_A_Q 97
# define BUFFER_SIZE 4096

// Constantes pour les tailles de fenetres, ratio ~ 16/9
# define WIN_X 1800
# define WIN_Y 800

typedef struct s_texture
{
	int			texdir;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
}				t_texture;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		movespeed;
	double		rotspeed;
	int			x;
	int			texture;
	int			texx;
}				t_ray;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	int			*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
	int			left;
	int			right;
	int			forward;
	int			back;
	int			rotate_left;
	int			rotate_right;
	int			width;
	int			height;
	void		*img2;
	int			*addr2;
}				t_data;

typedef struct s_gm
{
	int			rx;
	int			ry;
	int			i;
	int			f;
	int			c;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			nblines;
	int			sizeline;
	char		**map;
	char		**gnl_buff_link;
	char		**gnl_internal_link;
	char		**strjoin_link;
	char		starting_pos;
	int			dx;
	int			dy;
	int			ierror;
	int			ierror2;
	int			ierror3;
	int			screenx;
	int			screeny;
	int			erreur;
	int			multiple_player;
	int			empty_line;
	int			insidemap;
	int			count;
	int			count2;
	int			nb_v_lines;
	int			sum;
	int			wrongcharmap;
	t_data		texture[5];
	t_data		data;
	t_ray		ray;
	t_texture	t;
}				t_gm;

int				ft_cub(char *str, t_gm *gm);
void			ft_parsing(char *file, t_gm *gm);
void			ft_parsing_2(char *file, t_gm *gm);
int				ft_parsing_map(char *file, t_gm *gm);
int				ft_strlen2(char *str);
int				ft_charinstr(char *str, char c);
int				ft_wall_util(char *str);
int				ft_starting_pos(char c, t_gm *gm, int i, int j);
void			ft_color_res(char **str, t_gm *gm);
int				ft_atoi2(const char *str, t_gm *gm);
void			ft_texture(char *str, t_gm *gm);
int				ft_path_texture(char *str, char **texture, t_gm *gm, int j);
void			ft_init_game(t_gm *gm);
int				ft_wall(t_gm *gm);
int				ft_is_map(char *str, t_gm *gm);
void			ft_map(char *str, t_gm *gm);
int				ft_copy_map(char *str, t_gm *gm);
void			ft_init_sprite(t_gm *gm);
int				ft_raycasting(t_gm *gm);
int				ft_mlx(t_gm *gm);
int				ft_key_press(int keycode, t_gm *gm);
int				ft_key_release(int keycode, t_gm *gm);
int				ft_color_column(t_gm *gm);
void			ft_draw_texture(t_gm *gm, int x, int y);
void			ft_initialisation2(t_gm *gm);
void			ft_initialisation3(t_gm *gm);
void			ft_init_texture(t_gm *gm);
void			ft_init_sprite2(t_gm *gm, int i, int j, int v);
void			ft_stepsidedist(t_gm *gm);
void			ft_incrementray(t_gm *gm);
void			ft_drawstartend(t_gm *gm);
void			ft_swap(t_gm *gm);
void			parsing_routine_map(t_gm *gm, int *ret, int *fd, char *str);
void			parsing_routine(int *ret, char *str, int *fd, t_gm *gm);
int				ft_check(char *str);
int				switch_buff(char *temp, char **line, char **buff);
int				ft_copy(char **line, char **buff, t_gm *gm);
void			ft_forward_back(t_gm *gm);
void			ft_left_right(t_gm *gm);
void			ft_rotate_right_left(t_gm *gm);
void			ft_error(t_gm *gm, char *str);
int				ft_exit(t_gm *gm);
void			ft_verify_errors(t_gm *gm);
void			ft_init_game_2(t_gm *gm);
int				get_next_line(int fd, char **line, t_gm *gm);
int				ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_subbuff(char *buff, int start, int len, t_gm *gm);
void			ft_init_direction(t_gm *gm);
void			ft_init_game_3(t_gm *gm);
void			ft_rotate_left(t_gm *gm, double olddirx);
void			ft_atoi2_check(const char *str, t_gm *gm);
int				ft_empty_line(char *str);
void			launch_mlx_hook(t_gm *gm);
int				get_next_line_line_saver(char **line, char *buff, int ret);
int				ft_cub(char *str, t_gm *gm);
void			ft_parsing(char *file, t_gm *gm);
void			ft_parsing_2(char *file, t_gm *gm);
int				ft_parsing_map(char *file, t_gm *gm);
int				ft_strlen2(char *str);
int				ft_charinstr(char *str, char c);
int				ft_wall_util(char *str);
int				ft_starting_pos(char c, t_gm *gm, int i, int j);
void			ft_color_res(char **str, t_gm *gm);
int				ft_atoi2(const char *str, t_gm *gm);
void			ft_texture(char *str, t_gm *gm);
int				ft_path_texture(char *str, char **texture, t_gm *gm, int j);
void			ft_init_game(t_gm *gm);
int				ft_wall(t_gm *gm);
int				ft_is_map(char *str, t_gm *gm);
void			ft_map(char *str, t_gm *gm);
int				ft_copy_map(char *str, t_gm *gm);
void			ft_init_sprite(t_gm *gm);
int				ft_raycasting(t_gm *gm);
int				ft_mlx(t_gm *gm);
int				ft_key_press(int keycode, t_gm *gm);
int				ft_key_release(int keycode, t_gm *gm);
int				ft_color_column(t_gm *gm);
void			ft_draw_texture(t_gm *gm, int x, int y);
void			ft_initialisation2(t_gm *gm);
void			ft_initialisation3(t_gm *gm);
void			ft_init_texture(t_gm *gm);
void			ft_init_sprite2(t_gm *gm, int i, int j, int v);
void			ft_stepsidedist(t_gm *gm);
void			ft_incrementray(t_gm *gm);
void			ft_drawstartend(t_gm *gm);
void			ft_swap(t_gm *gm);
void			ft_forward_back(t_gm *gm);
void			ft_left_right(t_gm *gm);
void			ft_rotate_right_left(t_gm *gm);
void			ft_error(t_gm *gm, char *str);
int				ft_exit(t_gm *gm);
void			ft_verify_errors(t_gm *gm);
void			ft_init_game_2(t_gm *gm);
int				get_next_line(int fd, char **line, t_gm *gm);
int				ft_strlen(char *str);
char			*ft_substr2(char const *s, unsigned int start, size_t len);
char			*ft_strjoin2(char *s1, char *s2);
char			*ft_subbuff(char *buff, int start, int len, t_gm *gm);
void			ft_init_direction(t_gm *gm);
void			ft_init_game_3(t_gm *gm);
void			ft_rotate_left(t_gm *gm, double olddirx);
void			ft_atoi2_check(const char *str, t_gm *gm);
int				ft_empty_line(char *str);
void			launch_mlx_hook(t_gm *gm);
int				get_next_line_line_saver(char **line, char *buff, int ret);
int				prepare_buff(char **buff);
int				handle_existing_buff(char **line, char **buff, t_gm *gm);
int				read_and_process(int fd, char **line, char **buff, t_gm *gm);
void			map_closure_check(t_gm *gm, char *file);
void			check_last_data(t_gm *gm, char *file);
char			*ft_strdup(char *str);

#endif
