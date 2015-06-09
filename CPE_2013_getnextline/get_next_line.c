/*
** get_next_line.c for get_next_line.c in /home/lancel_e/Documents/get_next_line/get next line
** 
** Made by lancel_e
** Login   <lancel_e@epitech.net>
** 
** Started on  Fri Nov 22 17:36:43 2013 lancel_e
** Last update Wed Jun 10 01:38:15 2015 emilien lancelot
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	my_strlen(char *tab)
{
  int	nb_carac;

  if (tab[0] == '\0')
    return (0);
  nb_carac = 0;
  while (tab[nb_carac] != 0)
    nb_carac = nb_carac + 1;
  return (nb_carac);
}

char	*get_next_line(const int fd)
{
  t_var	to;

  if (fd == -1)
    return NULL;
  to.i = 0;
  to.the_line = malloc(sizeof(char*));
  if ((to.resul = read(fd, &to.my_buff, LEN)) == 0)
    return NULL;
  if (to.resul == 1)
    {
      while (((to.resul == 1 && to.my_buff !='\n')) && (to.my_buff != 0))
        {
	  to.the_line[to.i] = to.my_buff;
	  to.i = to.i + 1;
	  to.the_line = my_append_doc(to.the_line, to.my_buff);
	  to.resul = read(fd, &to.my_buff, LEN);
        }
    }
  to.the_line[to.i] = '\0';
  return to.the_line;
}

char	*my_append_doc(char *tab, char c)
{
  int	i;
  char	*temp;

  i = 0;
  temp = malloc((my_strlen(tab) + 1) * sizeof(char));
  while (tab[i])
    {
      temp[i] = tab[i];
      i = i + 1;
    }
  temp[i] = '\0';
  free(tab);
  tab = malloc((my_strlen(temp) + 2) * sizeof(char));
  i = 0;
  while (temp[i])
    {
      tab[i] = temp[i];
      i = i + 1;
    }
  tab[i] = c;
  tab[i + 1] = '\0';
  return (tab);
}

int main()
{
  char *str = NULL;

  while ((str = get_next_line(0)) != NULL)
    {
      puts(str);
      free(str);
    }
  return (0);
}
