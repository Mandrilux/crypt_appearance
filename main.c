/*
** main.c for in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 10:48:51 2016
** Last update Thu Jun  9 10:33:21 2016 
*/

#include "data.h"

int		main(void)
{
  t_data	data;
  int		nb_space;
  int		*tmp;
  int		i = -1;
  t_list *l_a = NULL;

  printf("Entrez une chaine\n");
  if ((data.str_ori  = get_next_line(0)) == NULL)
    {
      printf("[-] Error when read string\n");
      return (EXIT_FAILURE);
    }
  resolv(&data);
  if (create_occ_nb(&data) == -1)
    {
      printf("[-] Error when count char\n");
      return (EXIT_FAILURE);
    }
  if ((nb_space = count_char(data.str_ori, ' ')) > 0)
    {
      if ((tmp = malloc(sizeof(int) * (strlen(data.occ_str) + 1))) == NULL)
	{
	  printf("[-] Error memory\n");
	  return (EXIT_FAILURE);
 	}
      while (++i < (int)strlen(data.occ_str))
	tmp[i] = data.occ_num[i];
      tmp[i] = nb_space;
      free(data.occ_num);
      data.occ_num = tmp;
      data.occ_str = my_strmcat(data.occ_str, my_strdup(" "));
    }
  i = -1;
  while (data.occ_str[++i] != '\0')
    add_first(&l_a, data.occ_num[i], data.occ_str[i]);
  sort(&l_a, strlen(data.occ_str));
  show_list_c(l_a);
  if ((ceasar(l_a, data.str_ori)) == -1)
    printf("[-] Error when resolving by ceasar\n");
  free_list(&l_a);
  return (EXIT_SUCCESS);
}

int	create_occ_nb(t_data *data)
{
  int	len;
  int	i = -1;

  len = strlen(data->occ_str);
  if ((data->occ_num = malloc(sizeof(int) * len)) == NULL)
    return (-1);
  if (data->occ_str == NULL)
    return (-1);
  while (data->occ_str[++i] != '\0')
    data->occ_num[i] = count_char(data->str_ori, data->occ_str[i]);
  return (1);
}
