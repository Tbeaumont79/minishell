#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# define BUFFER_SIZE 42

typedef struct			s_struct
{
	int					exit;
	char				*s;
}						t_struct;

void	shell_init(void);
void	ft_cd(t_struct *st);
void	ft_echo(t_struct *st);
void	ft_exit(t_struct *st);
void	ft_pwd(t_struct *st);
void	ft_unset(t_struct *st);
void	ft_env(t_struct *st);
void	ft_export(t_struct *st);


#endif
