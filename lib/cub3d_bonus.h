/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mablatie <mablatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:34:06 by vanitas           #+#    #+#             */
/*   Updated: 2024/01/29 14:09:42 by mablatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <X11/Xlib.h>
# include <stdbool.h>
# include <time.h>
# include <sys/time.h>

# define ERR_MLX_IMG "Could not create mlx image"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"

# define ERR_TEX_MISSING "Missing texture(s)"
# define ERR_COLOR_MISSING "Missing color(s)"

# define ERR_MALLOC "Allocation error"

# define ROTSPEED 0.01

# ifndef BONUS
#  define BONUS 0
# endif

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
	DOOR = 4,
	DOOR_OPEN0 = 5,
	DOOR_OPEN1 = 6,
	DOOR_OPEN2 = 7,
	DOOR_OPEN3 = 8,
	BARREL0 = 9,
	BARREL1 = 10,
	BARREL2 = 11,
	BARREL3 = 12,
	BARREL4 = 13,
	BARREL5 = 14,
	BARREL6 = 15,
	FLOOR = 16,
	CEILING = 17,
	ARROW = 18,
	SASL = 19,
	SASR = 20,
};

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_info
{
	char			**map;
	char			**mapcopy;
	char			**island;
	int				island_x;
	int				island_y;
	int				index;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	double			step;
	char			*floor;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	double			pos;
	unsigned char	r_floor;
	unsigned char	g_floor;
	unsigned char	b_floor;
	char			*ciel;
	unsigned char	r_ciel;
	unsigned char	g_ciel;
	unsigned char	b_ciel;
	int				map_w;
	int				map_h;
	int				x;
	int				y;
}			t_info;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_ray;

typedef struct s_stats
{
	float	ms;
	float	stamina;
	char	sprint;
	int		hp;
	int		max_hp;
	int		dmg;
	int		as;
	bool	is_player;
}			t_stats;

typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_calcul
{
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		enemy_screen_x;
	int		enemy_height;
	int		draw_starty;
	int		draw_endy;
	int		enemy_width;
	int		draw_startx;
	int		draw_endx;
	int		v_move_screen;
}			t_calcul;

typedef struct s_motion
{
	t_img	ter_walk[6];
	t_img	ter_attack;
	t_img	dino_walk[5];
	t_img	dino_roar[6];
	t_img	dino_attack[11];
	t_img	shiplr[4];
}	t_motion;

typedef struct s_sprite
{
	t_img		*motion;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			steptick;
	time_t		steptime;
	float		width_scale;
	float		height_scale;
	bool		attacking;
	float		range;
	bool		in_range;
	time_t		last_move;
	double		distance;
	char		c;
	bool		see_player;
	int			incr;
	t_stats		stats;
	t_calcul	cl;
	int			fly;
}	t_sprite;

typedef struct s_player
{
	char			dir;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
	t_img			face[6];
	t_img			gun[5];
	t_img			reload[11];
	t_img			hud;
	t_img			bullets;
	t_img			death;
	t_img			obj1;
	int				is_firing;
	bool			can_damage;
	int				orient;
	t_sprite		*aiming_at;
	unsigned char	punched;
	unsigned char	hited;
	unsigned char	nb_bullets;
	bool			reloading;
	unsigned char	teleporting;
	unsigned char	chipset;
	t_stats			stats;
}			t_player;

typedef struct s_anim
{
	int			pos_x;
	int			pos_y;
	int			cube_pos_x;
	int			cube_pos_y;
	int			exc_pos_x;
	int			exc_pos_y;

	t_img		walkr[10];
	t_img		idler[10];
	t_img		push[10];
	t_img		runl[6];
	t_img		dead[10];

	t_img		exc;
	t_img		jumpl;
	t_img		bg;
	t_img		cube;
	t_img		blank;
	t_img		start;
	t_img		settings;
	t_img		exit;
	int			step;
	bool		alloced;
}			t_anim;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	char			**config;
	t_img			textures2[21];
	int				**texture_pixels;
	int				height;
	int				width;
	int				done;
	t_info			i;
	t_ray			ray;
	t_player		player;
	t_anim			anim;
	char			lockcursor;
	bool			game_launched;
	t_vector		mouse;
	t_vector		stars[200];
	t_img			mars;
	t_img			moon;
	t_img			earth;
	t_sprite		*enemies;
	t_motion		all_enemies_anim;
	double			*wall_dist;
	float			test;
	int				nb_enemies;
	t_sprite		ship[100];
	t_sprite		chipset;
	t_sprite		greenherb;
	t_img			puce;
	t_img			heal;
	t_img			tmp;
	time_t			t0;
	int				time_limit;
	t_img			time_out[10];
	unsigned char	win;
	t_img			win_screen;
	bool			door;
	t_img			load;
}				t_data;
// faudrait changer wall_dist parce qu'on peut pas changer de resolution avec

typedef struct s_norm
{
	int	tex_y;
	int	color;
	int	tex_x;
}				t_norm;

typedef struct s_order
{
	int	i;
	int	j;
	int	count;
}				t_order;

typedef struct s_floor
{
	int				p;
	float			ray_dirx0;
	float			ray_diry0;
	float			ray_dirx1;
	float			ray_diry1;
	float			pos_z;
	float			row_distance;
	float			floor_stepx;
	float			floor_stepy;
	float			floor_x;
	float			floor_y;
	int				cell_x;
	int				cell_y;
	int				tx;
	int				ty;
	int				floor_texture;
	int				ceiling_texture;
	unsigned long	color;
}				t_floor;

typedef struct s_texnorm
{
	int		y;
	int		color;
	bool	trp;
}			t_texnorm;

/*Init*/
void		init_struct(t_data *data);
void		init_data(t_data *data);
void		init_textures(t_data *data);
void		init_ray(t_ray *ray);
void		init_mlx(t_data *data);
void		init_img_clean(t_img *img);
void		init_texture_img(t_data *data, t_img *image, char *path);
void		init_img(t_data *data, t_img *image, int width, int height);
void		init_texture_pixels(t_data *data);
void		init_player_direction(t_data *data);
void		set_image_pixel(t_img *image, int x, int y, int color);
void		init_img_nullifier(t_data *data);
void		init_chipset(t_data *data);
void		init_heal(t_data *data);
void		loading(t_data *data, t_img *load, int percent);
void		set_anim(t_data *data, t_anim *intro);
void		set_anim_2(t_data *data, t_anim *intro, int size);
void		set_anim_3(t_data *data, t_anim *intro, int size);
void		set_anim_4(t_data *data, t_anim *intro, int size);
void		set_anim_5(t_data *data, t_anim *intro, int size);
void		set_anim_6(t_data *data, t_anim *intro, int size);
void		init_cat_stats(t_data *data);
void		init_fight(t_data *data);

/*Parsing*/
void		get_info(t_data *data, char *path);
void		get_texture2(t_data *data, char *cpy);
void		check_extension(t_data *data, char *path);
char		*str_full_space(t_data *data, char *to_cpy, int size);
void		ft_safe_trim(t_data *data, char **str, char *charset);
char		*ft_safe_dup(t_data *data, char *todup);
char		*ft_safe_dup_init(t_data *data, char *todup);
char		*ft_safe_join(t_data *data, char *str1, char *str2, int option);
void		print_var(t_data *data);
int			only_blank(char *str);
void		parse_map(t_data *data);
char		last_occur(char *str);
char		first_occur(char *str);
void		island(t_data *data);
int			longest_str(char *str);
void		parse_info(t_data *data);

/*Render*/
int			raycasting(t_player *player, t_data *data);
void		render_images(t_data *data);
int			render(t_data *data);
int			check_put_textures(t_info *i);
void		user_interface(t_data *data, t_img *img);
void		put_face(t_data *data, t_img *img);
void		print_life(t_data *data, t_img *img);
void		print_stamina(t_data *data, t_img *img);
void		draw_circle(int center_x, int center_y, t_img *img);
void		minimap(t_data *data, t_img *image);
void		weapon(t_data *data, t_img *img);
void		reload(t_data *data, t_img *img);
void		crosshair(t_data *data, t_img *img);
void		spark(t_data *data, t_img *img);
void		bullets(t_data *data, t_img *img);
void		hit_react(t_data *data, t_img *img);
void		chipset(t_data *data, t_img *img);
void		objective(t_data *data, t_img *img);
void		load_screen(t_data *data);
int			fall2(t_data *data, int jump_x, int jump_y);
void		init_raycasting_info(t_data *data, int x, t_ray *ray,
				t_player *player);
void		set_dda(t_ray *ray, t_player *player);
void		calculate_line_height(t_ray *ray, t_data *data, t_player *player);
void		perform_dda(t_data *data, t_ray *ray);
int			open_door(t_data *data, char *a);
int			close_door(t_data *data, char *a);
int			explosion(char *a);
void		update_enemies(t_data *data, t_sprite *enemy);
void		map_restore(t_data *data);
void		player_detection(t_data *data, t_sprite *enemy, int x, int y);
void		update_animation(t_data *data, t_sprite *enemy);
void		attack(t_data *data, t_sprite *enemy);
void		roar(t_sprite *enemy);
void		chase_player(t_data *data, t_sprite *enemy);
double		calculate_sprite_distance(t_data *data, double sprite_x,
				double sprite_y);
t_sprite	*order_enemy(t_data *data, t_sprite *enemies, int nb_enemies);
void		screen_shake(t_data *data);
void		update_ship(t_data *data, t_sprite *ship);
void		update_ship_render(t_data *data, t_sprite *enemy);
void		add_ship_in_texture(t_data *data, t_sprite *enemy);
void		update_enemies_render(t_data *data, t_sprite *enemy);
void		add_enemies_in_texture(t_data *data, t_sprite *enemy);
void		floorcasting(t_data *data);
void		update_item(t_data *data, t_sprite *item);
void		set_frame_image_pixel(t_data *data, t_img *image, int x, int y);
void		draw_stars(t_data *data, t_img *img);
void		portal(t_data *data);
void		refresh(t_data *data, int i, int a);

/*Inputs*/
int			move_player(t_data *data);
int			validate_move(t_data *data, double new_x, double new_y);
int			rotate_player(t_data *data, double rotdir);
void		update_texture_pixels(t_data *data, t_ray *ray, int x);
void		listen_for_input(t_data *data);
void		mouse_rotate(t_data *data);
void		validate_enemies_move(t_data *data, t_sprite *enemy,
				double new_x, double new_y);
int			is_valid_enemy_pos(t_data *data, double dir_x, double dir_y,
				t_sprite *enemy);
int			is_valid_pos_wall_collision(t_data *data, double x, double y);
int			is_valid_pos_in_map(t_data *data, double x, double y);
int			key_release_handler(int key, t_data *data);
void		handle_mouse_bis_2(t_data *data);
void		key_press_handler_bis_2(int key, t_data *data);

/*Exit*/
void		clean_anim(t_data *data);
void		clean_exit(t_data *data, int code);
int			err_msg(char *str);
int			quit_cub3d(t_data *data);
void		end(t_data *data);
void		end_norm(t_data *data);
void		free_textures(t_info *i);

/*Utils*/
int			pos_neg(void);
int			ft_abs(int nbr);
int			isdigitstr(char *str);
void		datalog(t_data *data);
void		free_tab(void **tab);
void		put_img_to_img(t_img *dst, t_img *src, int x, int y);
void		put_img_to_img_scaled(t_img *dst, t_img *src);
int			get_pixel_img(t_img *img, int x, int y);
void		change_color(t_img *img, int color_to_change,
				int new_color, int old);
t_img		new_img(t_data *data, int width, int height, char *path);
void		new_img_norm_2(t_data *data, t_img *to_feet,
				char *path, t_img *new);
void		reverse_put_img_to_img(t_img *dst, t_img *src, int x, int y);
time_t		get_time(void);
t_img		new_img_xpm(t_data *data, char *path);
void		the_put_img(t_img *dst, t_img *src, int x, int y);
void		put_img_to_img_scaled(t_img *dst, t_img *src);
void		protect_textures(t_data *data);

/*Norm*/
void		clean_norm(t_data *data, int i);
void		clean_norm_2(t_data *data);
void		init_time_s_out(t_data *data);
void		init_term_2(t_sprite *new);
void		init_dino_2(t_sprite *new);
void		init_ship_2(t_sprite *new);
void		init_chipset_2(t_data *data);
void		init_heal_2(t_data *data);
void		init_motion_2(t_data *data, t_motion *motion, t_img *load);
void		init_motion_3(t_data *data, t_motion *motion, t_img *load);
void		init_player_img_2(t_data *data, t_player *player, t_img *load);
void		init_walls_2(t_data *data, t_img *load);
void		init_shipyard(t_data *data);
void		init_player_2(t_player *player);
void		order_enemy_norm(t_sprite *enemies, t_sprite *new,
				int nb_enemies, t_order *norm);
void		add_ship_in_texture_norm(t_data *data, t_sprite *enemy,
				int y, t_norm *norm);
void		update_ship_render_norm(t_data *data, t_sprite *enemy);
void		afficher_image_avion_norm(t_sprite *ship, float angle);
void		update_item_norm(t_sprite *item);
void		update_enemies_render_norm(t_data *data, t_sprite *enemy);
void		add_enemies_in_texture_norm(t_data *data, t_sprite *enemy,
				int y, t_norm *norm);
void		update_animation_norm(t_sprite *enemy);
void		update_animation_norm_2(t_data *data, t_sprite *enemy);
void		second_norm(t_data *data, t_img *chrono, int time, t_img *img_nb);
void		weapon_norm(t_data *data, int *i, int *incr);
void		bounce_norm(t_data *data, int v_y, int *i, int *j);
void		perform_dda_norm(t_data *data, t_ray *ray);
void		floorcasting_norm(t_data *data, t_floor *floor, int y);
void		floorcasting_norm_2(t_data *data, t_floor *floor, int y, int x);
void		render_frame_norm(t_data *data, t_img *image);
void		refresh_norm(t_data *data);
void		menu_norm(t_data *data, int *i);
void		get_texture_index_norm(t_data *data, t_ray *ray, int ok);
void		update_texture_pixels_norm(t_data *data, int x, t_texnorm *norm);
t_sprite	init_term(t_data *data, int i, int j);
t_sprite	init_dino(t_data *data, int i, int j);
t_sprite	init_ship(t_data *data);

/*character_stat*/
bool		update_health_point(t_data *data, t_stats *stats, int delta);
void		upgrade_stamina(t_data *data);
void		fire(t_data *data);
void		time_s_out(t_data *data);

#endif