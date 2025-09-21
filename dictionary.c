/* Mettez le header 42 pls*/

#include <fcntl.h>//open
#include <unistd.h>//close & read
#include <stdlib.h>//malloc &free
#include "dictionary.h"

/*error message*/
void	dict_error(void)
{
	write(1, "Dict Error\n", 11);
}

/*Ignore les espaces en debut de chaine*/
static char	*skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

/*Copie la partie nombre avant (:)*/
static char	*copy_number(char *line)
{
	int		len;
	int		i;
	int		*res;

	len = 0;
	while (line[len] && line[len] != ':')
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && line[i] != ':')
	{
		res[i] = line[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*Copie la partie lettre appele "valeur" apres (:)*/
static char	*copy_value(char *line)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (!line[i])
		return (NULL);
	i++;
	line = skip_spaces(&(line[i]));
	j = 0;
	while (line[j] && line[j] != '\n')
		j++;
	res = (char *)malloc(sizeof(char) * (j + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < j)
	{
		res[i] = line[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*Transforme une ligne, ex: "123 : cent.." en entree du dico*/
static t_dict	split_pair(char *line)
{
	t_dict	entry;

	entry.key = copy_number(line);
	entry.value = copy_value(line);
	if (!entry.key || !entry.value)
	{
		free(entry.key);
		free(entry.value);
		entry.key = NULL;
		entry.value = NULL;
	}
	return (entry);
}

/*Parser le dico et return tableau + taille*/
t_dict	*parse_dict(char *filename, int *size)
{
	int		i;
	char	*content;
	char	**lines;
	t_dict	*dict;

	content = read_dict_file(filename);
	if (!content)
		return (NULL);
	i = 0;
	while (lines[i])
		i++;
	*size = i;
	dict = (t_dict *)malloc(sizeof(t_dict) * i);
	if (!dict)
		return (NULL);
	i = 0;
	while (lines[i])
	{
		dict[i] = split_pair(lines[i]);
		if (!dict[i].key || !dict[i].value)
		{
			dict_error();
			free_split(lines);
			free(dict);
			return (NULL);
		}
		i++;
	}
	free_split(lines);
	return (dict);
}

/*recherche cle dans le dico et retourne valeur 
 * (en gros cherche chiffre et return sa version en lettre)*/
char	*dict_lookup(t_dict *dict, int size, char *key)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (NULL);
}
/*NB: key = chiffre, value = lettre*/
