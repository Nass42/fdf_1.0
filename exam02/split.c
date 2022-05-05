#include <stdio.h>
#include <stdlib.h>
#define WORDS 1000
#define WORD 1000


#include <stdio.h>
#include <stdlib.h>
#define WORDS 10
#define WORD 10


int ft_isspace(char c, char cd)
{
        if (c == cd)
                return (1);
        return (0);
}

char *ft_word(char *str, char c)
{
        int i;
        char *word;

        i = 0;
        word = (char *)malloc(sizeof(char) * (WORD + 1));
        if (!word)
                return (0);
        while (str[i] && !ft_isspace(str[i], c) && str[i] != '\0')
        {
                word[i] = str[i];
                i++;
        }
        word[i] = '\0';
        return (word);
}



char    **ft_split(char *str, char c)
{
        int count;
        int i;
        char **words;

        //count = ft_count(str);
        i = 0;
        if(!str)
          return NULL;
        words = (char **)malloc(sizeof(char *)* (WORDS + 1));
        if (!words)
                return (NULL);
        while(*str == c)
                str++;
        i = 0;
        while (*str)
        {
                words[i] = ft_word(str, c);
                while(*str && !ft_isspace(*str, c))
                        str++;
                while(*str && ft_isspace(*str, c))
                        str++;
                i++;

        }




        words[i] = NULL;
        return(words);
}

int main()
{
  char *str = "hello    i      am";
  char **s;
  int i = 0;
  char c = ' ';
  s= ft_split(str, c);
//      ft_split(av[1]);
  while (s[i])
        printf("******%s***** \n", s[i++]);
}

