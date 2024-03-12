/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:35:34 by zel-harb          #+#    #+#             */
/*   Updated: 2024/03/11 17:04:34 by zel-harb         ###   ########.fr       */
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
int check_error(t_img *read)
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
int check_arg(t_img *read)
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

int check_map(t_img *read)
{
    if(check_error(read)== 0)
    {
         write(2,"Error\n",6);
        return 0;
    }
    if(check_arg(read)==0)
    {
        write(2,"Error\n",6);
        return 0; 
    }
    return 1;
}

