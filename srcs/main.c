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
	while (i < ft_strlen(st->s))
	{
		if (st->s[i] == '-')
			break ;
		i++;
	}
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

int		ft_skip_space(char *s, int i)
{
	printf("avant i : %d\n", i);
	while (s[i])
	{
		if (s[i] != ' ')
			break ;
		i++;
	}
	printf("apres i : %d\n", i);	
	return (i);
}

int		ft_check_and_get_path(t_struct *st)
{
	int i;
	int j;
	int size;
	int tmp;
	
	j = 0;
	size = 0;
	i = 0;
	printf("in check path\n");
	i = ft_skip_space(st->s, i);
	printf("1\n");
	while (st->s[i++] == st->datas[comand][j++])
		;
	printf("2\n");
	i = ft_skip_space(st->s, i);
	j = 0;
	i += st->s[i] == '-' ? 1 : 0;
	printf("bonjour -> %s\n", st->datas[opt]);
	printf("%c\n", st->datas[opt][j]);
	if (st->datas[opt][j] != '\0')
	{
		while (st->s[i++] == st->datas[opt][j++])
			;
	}
	printf("3\n");
	i = ft_skip_space(st->s, i);
	tmp = i;
	printf("%c\n", st->s[i]);
	while (ft_isalpha(st->s[i]))
	{
		size++;
		i++;
	}
	printf("4\n");
	if (!(st->datas[path] = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	size = 0;
	printf("%d\n", size++);
	while (tmp < i)
	{
		st->datas[path][size] = st->s[tmp];
		printf("st->datas[path][size] -> %c et st->s[tmp] -> %c\n", st->datas[path][size], st->s[tmp]);
		size++;
		tmp++;
	}
	printf("st->datas[path][size] -> %s\n", st->datas[path]);
	st->datas[path][size] = '\0';
	return (0);
}

int		get_command(t_struct *st)
{
	static char commande[7][7] = {{"cd"}, {"echo"}, {"pwd"}, {"export"}, {"unset"}, {"env"}, {"exit"}};
	int i;

	i = 0;
	while (i < 7)
	{
		if (ft_strstr(st->s, commande[i]))
			st->datas[comand] = ft_strdup(commande[i]);
		i++;
	}
	return (i == 7 && st->datas[comand][0] == '\0' ? -1 : 0);
}

int		ft_parse(t_struct *st)
{
	if ((get_command(st)) == -1)
		return (ft_error("cannot get command"));
	printf("2 et %s\n", st->datas[comand]);
	if ((get_opt(st)) == -1)
		return (-1);
	ft_check_and_get_path(st);
	printf("4 et %s\n", st->datas[path]);
	return (0);
}

int		ft_dispatcher(t_struct *st)
{

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
			if (ft_parse(&st) == -1)
				return ft_error("invalid command");
			//ft_dispatcher(&st);
			free(st.s);
			shell_init();
			if (ft_strchr(st.s, '\n'))
				break ;
		}
	}
	return (0);
}
