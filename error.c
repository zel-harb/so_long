/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:35:34 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/09 02:27:42 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int 	ft_strchr_int( char **s, char c,int size)
{
	int	ds;
	int		i;
    int     j;

	
	i = 0;
    ds =0;
    j = 0;
	while (i < size)
	{
        j=0;
        while(j < ft_strlen(s[i]))
        {
		    if (s[i][j] == c)
			    ds++;
            j++;
        }
		i++;
	}
	return (ds);
}
int count_line(int fd)
{
    int count_line;
    char *line;

    line=get_next_line(fd);
    while(line)
    {
        count_line++;
        line=get_next_line(fd);
    }
    return count_line;
}

int check_ber(char *argv,int argc)
{
    int i;
    
    i = ft_strlen(argv);
    char *s=".ber";
    if(i  <= 4)
        return 0;
    int j =0;
    i =i -4;
    while(argv[i])
    {
        if(argv[i]!= s[j])
            return 0;
        i++;
        j++;
    }
    return 1; 
}
int check_first_last(char *line)
{
    int i = 0;
    
    while (i < ft_strlen(line))
    {
        if (line[i] != '1')
            return 0;
        i++;
    }
    return 1;
}
int check_mid(char *line)
{
    int i;

    i=0;
    if(line [i] != '1')
        return 0;
    if(line[ft_strlen(line)-1]!= '1')
        return 0;
    return 1;
    
}
int check_error(t_data *read)
{ 
    int i;
    int count;

    i = 0;
    
    count =ft_strlen(read->str[0]);
    if(check_first_last(read->str[0])==0 || check_first_last(read->str[(read->count)-1])==0)
        return 0;
    i++;
    while(read->str[i] && i < read->count)
    {
        if(check_mid(read->str[i]) == 0)
            return 0;
        if(count != ft_strlen(read->str[i]))
            return 0;
            i++;
    }
    return 1;
}
int check_arg(t_data *read)
{
   char tab[4];
   
   tab[0]='P';
   tab[1]='E';
   tab[2]='C';
   tab[3]='0';
    if(ft_strchr_int(read->str,tab[0],read->count)!=1 || !ft_strchr_int(read->str,tab[1],read->count))
        return 0;
    if(!ft_strchr_int(read->str,tab[2],read->count)|| !ft_strchr_int(read->str,tab[3],read->count))
        return 0;
    return 1;
}
// int food_fill()
// {
    
// }

int check_map(t_data *read)
{
    if(check_error(read)== 0)
      return 0;
    if(check_arg(read)==0)
        return 0; 
    return 1;
}
void full_str(t_data **read_m,int fd)
{
    char *line;
    int k;
    
    k = 0;
    line = get_next_line(fd);
    if (line != NULL) {
       (*read_m)->str = ft_split(line, '\n');
       (*read_m)->count = count_words(line, '\n');
       (*read_m)->len = ft_strlen((*read_m)->str[0]);
        free(line);
    }
    
}
