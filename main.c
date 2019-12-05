#include <stdio.h>
#include <string.h>

void devolveString(char *linha, char *termo, int tam){
    int i = 0;
    int k = 0;
    char string[100];
    if (linha[0] == '\t')
    {
        while(linha[k] == '\t')
            k++;
        for (i = 0; i < strlen(linha); ++i)
        {
            linha[i] = linha[i+k];
        }
    }
    i=0;
    k=0;
    for (i = 0; i < 100; i++)
    {
        if (linha[i] == termo[k])
        {
            k++;
            if (k == strlen(termo))
            {
                int t = 0;
                for (int j = k; j < strlen(linha); j++)
                {
                    char ch = linha[j];
                    char ch2 = linha[j+1];
                    if (ch != '<' && ch2 != '/')
                    {
                        string[t] = linha[j];
                        t++;
                    }
                    if (ch == '<' && ch2 == '/')
                    {
                        string[t] = '\0';
                        t = 0;
                        break;
                    }
                }
                printf("%s\n", string);
            } 
        } else
        {
            k = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    FILE *fp;
    char linha[100];
    char title[] = "<title>";
    char description[] = "<description>";
    char link[] = "<link>";
    char titulo[100];

    fp = fopen("taguatinga.xml", "r");

    if (fp != NULL)
    {
        while (fgets(linha, sizeof(linha), fp))
        {
            devolveString(linha, title, strlen(linha));
        }
    }
    

    return 0;
}