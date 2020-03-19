#include "../headers/minishell.h"
#include "../Libft/libft.h"

void	init_exit(t_struct *st)
{
	st->exit = 0;
}

int		isok(t_struct *st, char *str)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	i = ft_strlen(st->s) - 1;
	if (i == len)
		return (0);
	if (i > len && (st->s[len + 1] != '\n' || st->s[len + 1] != ' ' || st->s[len + 1] != '\0'))
		return (1);
	else
		return (0);
}

int		ft_error(char *s)
{
	ft_putstr("zsh: command not found: ");
	ft_putstr(s);
	return (-1);
}

int		ft_dispatcher(t_struct *st)
{
	static char commande[7][7] = {{"cd"}, {"echo"}, {"pwd"}, {"export"}, {"unset"}, {"env"}, {"exit"}};
	static int (*fct[7])(t_struct *st) = {ft_cd, ft_echo, ft_pwd, ft_export, ft_unset, ft_env, ft_exit}; // fonction a cree par la suite
	int i;

	i = 0;
	while (i < 7)
	{
		if (!(ft_strcmp(st->s, commande[i])))
		{
			if (!(isok(st, commande[i])))
				return ((fct[i])(st));
			else
				return (ft_error(st->s));
		}
		else
			i++;
	}
	return (ft_error(st->s));
}

int		main(void)
{
	t_struct	st;
	int			ret;
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];

	ret = 1;
	tmp = NULL;
	init_exit(&st);
	shell_init();
	while (!(st.exit))
	{
		while ((ret = (read(0, buf, BUFFER_SIZE))) > 0 && !(st.exit))
		{
			buf[ret] = '\0';
			if (!(st.s = ft_strdup(buf)))
				return (-1);
			ft_dispatcher(&st);
			free(st.s);
			shell_init();
			if (ft_strchr(st.s, '\n'))
				break ;
		}
	}
	return (0);
}
