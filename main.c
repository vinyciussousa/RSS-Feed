#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    char linha[1000];
    char title[] = "<title>";
    char fechar[] = "</";
    char titulo[1000];

    fp = fopen("news.xml", "r");

    if (fp != NULL)
    {
        while (fgets(linha, sizeof(linha), fp))
        {
            int i = 0;
            int k = 0;
            for (i = 0; i < 100; i++)
            {
                if (linha[i] == title[k])
                {
                    k++;
                    if (k == strlen(title))
                    {
                        int t = 0;
                        for (int j = k; j < strlen(linha); j++)
                        {
                            char ch = linha[j];
                            char ch2 = linha[j+1];
                            if (ch != '<' && ch2 != '/')
                            {
                                titulo[t] = linha[j];
                            }
                            if (ch == '<' && ch2 == '/')
                            {
                                titulo[t] = '\0';
                                break;
                            }
                            t++;
                        }
                        printf("%s\n", titulo);
                    } 
                } else
                {
                    k = 0;
                }
            }   
        }
    }
    

    return 0;
}