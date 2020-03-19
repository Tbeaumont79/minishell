#include "../headers/minishell.h"
#include "../Libft/libft.h"

void	init_exit(t_struct *st)
{
	st->exit = 0;
}

int		ft_error(char *s)
{
	ft_putstr("zsh: command not found: ");
	ft_putstr(s);
	return (-1);
}

int		get_opt(t_struct *st)
{
	int i;
	int size;
	int tmp;

	i = 0;
	size = 0;
	while (st->s[i])
	{
		if (st->s[i] == '-')
			break ;
		i++;
	}
	if (!st->s[i])
		return (0);
	i++;
	tmp = i;
	while (ft_isalpha(st->s[i]))
	{
		size++;
		i++;
		if (st->s[i] == ' ')
			break ;
	}
	if (!(st->datas[opt] = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	tmp--;
	size = 0;
	while (++tmp < i)
		st->datas[opt][size++] = st->s[tmp];
	st->datas[opt][size] = '\0';
	return (0);
}

int		get_path(t_struct *st)
{
	if (!st->datas[comand][0])
		return (-1);
	
}

int		ft_dispatcher(t_struct *st)
{
	static char commande[7][7] = {{"cd"}, {"echo"}, {"pwd"}, {"export"}, {"unset"}, {"env"}, {"exit"}};
	static int (*fct[7])(t_struct *st) = {ft_cd, ft_echo, ft_pwd, ft_export, ft_unset, ft_env, ft_exit}; // fonction a cree par la suite
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < 7)
	{
		while (st->s[j])
		{
			st->datas[comand] = ft_strstr(st->s, commande[i]) ? ft_strdup(commande[i]) : "";
			if ((get_opt(st)) == -1)
				return (-1);
			
			j++;		
		}
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
	if (!(st.datas = (char **)malloc(sizeof(char *) * enum_size)))
		return (-1);
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
