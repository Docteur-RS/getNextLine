#ifndef MY_H_
#define MY_H_

#define LEN  1

typedef struct s_var
{
  int	i;
  char	*the_line;
  char	my_buff;
  int   resul;
}t_var;

char* get_next_line(const int fd);
char *my_append_doc(char *tab, char c);
int my_strlen(char *tab);

#endif
