#include <stdio.h>
#include <string.h>

int devolveString(char *linha, char *termo, int tam){
    int i = 0;
    int k = 0;
    char string[1000];
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
    for (i = 0; i < 1000; i++)
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
    char header[1000];
    char linha[1000];
    char title[] = "<title>";
    char description[] = "<description>";
    char link[] = "<link>";

    fp = fopen("taguatinga.xml", "r");

    if (fp != NULL)
    {
        while (fgets(header, sizeof(header), fp))
        {
            if(devolveString(header, title, strlen(header))){
                break;
            }
        }
        while (fgets(header, sizeof(header), fp))
        {
            if(devolveString(header, description, strlen(header))){
                break;
            }
        }
        while (fgets(header, sizeof(header), fp))
        {
            if(devolveString(header, link, strlen(header))){
                break;
            }
        }
        while (fgets(linha, sizeof(linha), fp))
        {
            devolveString(linha, description,strlen(linha));
        }
    }
    

    return 0;
}