#include "../headers/minishell.h"
#include "../Libft/libft.h"

int ft_error(char *s)
{
	ft_putstr(s);
	return (-1);
}

int		ft_dispatcher(t_struct *st)
{
	static char commande[7][7] = {{"cd"}, {"echo"}, {"pwd"}, {"export"}, {"unset"}, {"env"}, {"exit"}};
	static int *(fct[7])(t_struct *st) = {ft_cd, ft_echo, ft_pwd, ft_export, ft_unset, ft_env, ft_exit}; // fonction a cree par la suite
	int i;
	int size;

	i = 0;
	size = ft_strlen(commande);
	while (i < size)
	{
		if (ft_strstr(st->s, commande[i]))
			break ;
		i++;
	}
	if (i > 0)
		return ((fct[i])(st));
	else
		return (ft_error("invalid command !"));
	return (0);
}

int		main(void)
{
	t_struct	st;
	int ret;
	char *tmp;
	char buf[BUFFER_SIZE + 1];

	ret = 1;
	tmp = NULL;
	shell_init();
	while ((ret = (read(0, buf, BUFFER_SIZE))) > 0)
	{
		buf[ret] = '\0';
		shell_init();
		if (!(st.s = ft_strdup(buf)))
			return (-1);
	}
	ft_putstr(st.s);
	free(st.s);
	return (0);
}