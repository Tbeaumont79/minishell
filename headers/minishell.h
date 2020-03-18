#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 42

typedef struct			s_struct
{
	int					exit;
	char				*s;
}						t_struct;

void	shell_init(void);


#endif