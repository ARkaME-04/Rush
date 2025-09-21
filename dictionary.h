#ifndef DICTIONARY_H
# define DICTIONARY_H

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;
//parcourir le dico
t_dict	*parse_dict(char *filename);
//recherche
char	*dict_lookup(ft_dict *dict, char *key);
void	free_dict(t_dict *dict);
void	dict_error(void);
// utility
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
int		ft_putstr(char *str);
void	dict_error(void);
char	*read_dict_file(char *filename);

#endif
