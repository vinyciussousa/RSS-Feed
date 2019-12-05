#include <stdio.h>
#include <string.h>

int devolveString(char *linha, char *termo, int tam){
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
                    char ch3 = linha[j+2];
                    if (ch != '<' && ch2 != '/' && ch3 != termo[1])
                    {
                        string[t] = linha[j];
                        t++;
                    }
                    if (ch == '<' && ch2 == '/' && ch3 == termo[1])
                    {
                        string[t] = '\0';
                        t = 0;
                        printf("%s\n", string);
                        return 1;
                    }
                }
            } 
        } else
        {
            k = 0;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    FILE *fp;
    char linha[100];
    char title[] = "<title>";
    char description[] = "<description>";
    char link[] = "<link>";

    fp = fopen("taguatinga.xml", "r");

    if (fp != NULL)
    {
        while (fgets(linha, sizeof(linha), fp))
        {
            if(devolveString(linha, title, strlen(linha))){
                break;
            }
        }
        while (fgets(linha, sizeof(linha), fp))
        {
            if(devolveString(linha, description, strlen(linha))){
                break;
            }
        }
        while (fgets(linha, sizeof(linha), fp))
        {
            if(devolveString(linha, link, strlen(linha))){
                break;
            }
        }
        while (fgets(linha, sizeof(linha), fp))
        {
            int a = devolveString(linha, title, strlen(linha));
            int b = devolveString(linha, description, strlen(linha));
            int c = devolveString(linha, link, strlen(linha));
        }
    }
    

    return 0;
}