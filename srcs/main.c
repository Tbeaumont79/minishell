#include "../headers/minishell.h"

int		main(int ac, char **av)
{
	t_ministruct	st;

	init_struct(&st);
	while (!st.exit)
		shell_init(&st);
	return (0);
}
