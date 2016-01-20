/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:39:07 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/16 16:47:42 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/param.h>
# include <string.h>
# include <termios.h>
# include "Libft/libft.h"

typedef	struct			s_env
{
	char				**path;
	char				**arg;
	char				**bkp;
	char				*home;
	char				*oldpwd;
}						t_env;

void					handle_signal(int signo);
char					*ft_check_path(t_env *env, char *line);
void					ft_prompt(t_env *env, char **envp);
void					ft_putchar_color_fd(char *color, char c, int fd);
void					ft_putstr_color_fd(char *color, char *str, int fd);
void					ft_putendl_color_fd(char *color, char *str, int fd);
char					*ft_strtri(char const *s);
char					*ft_my_join(char const *s1, char const *s2);
char					**ft_strsplit(char const *s, char c);
int						get_next_line(int const fd, char **line);
char					*ft_mallocat(char const *s1, char const *s2);
char					*ft_write_stock(char **line, char *src);
int						ft_isprint(int c);
int						ft_check_build(char *line, t_env *env);
int						ft_strcmp(const char *s1, const char *s2);
void					ft_get_env(t_env *env, char **envp);
char					*ft_strdup(const char *s);
int						ft_tablen(char **tab);
void					ft_error(char *line);
int						ft_env(t_env *env, char **cmd);
void					ft_cd(char *line, t_env *env);
char					*ft_get_line_env(t_env *env, char *key);
int						ft_replace_line_env(t_env *env, char *key,
							char *newpath);
char					*ft_strsub(char const *s, unsigned int start,
							size_t len);
int						ft_check_cd(char *line, t_env *env);
void					ft_cd_minus(t_env *env, char *line);
void					ft_cd_home(t_env *env);
void					ft_cd_tilde(t_env *env, char **cdtab);
int						ft_exit(char *s);
char					*ft_delete_tilde(char **cdtab);
int						ft_setenv(char *line, t_env *env);
int						ft_check_line_env(t_env *env, char *key);
void					ft_add_line(t_env *env, char *key, char *arg);
void					ft_delete_line(t_env *env, char *key);
int						ft_unsetenv(char *line, t_env *env);
void					ft_resize_tab(t_env *env);
char					*ft_tolowerstr(char *str);
void					ft_error_setenv(int n);
void					ft_error_cd(char *line, int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_cd_bis(char *tmp, char **cdtab);
void					ft_error_cd_bis(char *line, int n);
char					*ft_epur_str(char *src);
void					ft_cd_slash(t_env *env, char *arg);

#endif
