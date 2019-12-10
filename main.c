#include <stdio.h>
#include <string.h>

int devolveString(char *linha, char *termo, FILE *fp2, int *e_header)
{

    int i = 0;
    int k = 0;
    char string[10000];
    if (linha[0] == '\t')
    {
        while (linha[k] == '\t')
            k++;
        for (i = 0; i < strlen(linha); ++i)
        {
            linha[i] = linha[i + k];
        }
    }
    i = 0;
    k = 0;
    for (i = 0; i < 1000; i++)
    {
        if (linha[i] == termo[k])
        {
            k++;
            if (k == strlen(termo))
            {
                char c = termo[1];
                int t = 0;
                for (int j = k; j < strlen(linha); j++)
                {
                    char ch = linha[j];
                    char ch2 = linha[j + 1];
                    char ch3 = linha[j + 2];
                
                    if (ch == '<' && ch2 == '/' && ch3 == termo[1])
                    {
                        string[t] = '\0';
                        t = 0;
                        if (c == 't' && *e_header == 0)
                        {
                            fprintf(fp2, "<html>\n<head>\n<title>%s</title>\n</head>\n<body>\n", string);
                            *e_header += 1;
                        }
                        if (c == 't' && *e_header == 1)
                        {
                            fprintf(fp2, "<h1>%s</h1>\n", string);
                            *e_header += 1;
                        }
                        else if (c == 't' && *e_header > 1)
                        {
                            fprintf(fp2, "<h2>%s</h2>\n", string);
                        }
                        if (c == 'l')
                        {
                            fprintf(fp2, "<br>\n<a href=\"%s\"> %s </a></br>\n", string, string);
                        }
                        if (c == 'p')
                        {
                            fprintf(fp2, "\n<p>%s</p>\n\n<hr>\n", string);
                        }

                        printf("%s\n", string);

                        return 1;
                    }
                    else
                    {
                        string[t] = linha[j];
                        t++;
                    }
                }
            }
        }
        else
        {
            k = 0;
        }
    }

    return 0;
}

int devolveStringDesc(char *linha, char *termo, FILE *fp2)
{

    int i = 0;
    int k = 0;
    char string[10000];
    if (linha[0] == '\t')
    {
        while (linha[k] == '\t')
            k++;
        for (i = 0; i < strlen(linha); ++i)
        {
            linha[i] = linha[i + k];
        }
    }
    i = 0;
    k = 0;
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
                    char ch2 = linha[j + 1];
                    char ch3 = linha[j + 2];
                        
                    if (ch == '<' && ch2 == '/' && ch3 == 'd')
                    {
                        string[t] = '\0';
                        t = 0;
                        printf("%s\n", string);
                        fprintf(fp2, "<p>%s</p>\n", string);
                        return 1;
                    }
                    else
                    {
                        string[t] = linha[j];
                        t++;
                    }
                    
                }

                printf("%s\n", string);
                fprintf(fp2, "<p>%s</p>\n", string);
            }
        }
        else
        {
            k = 0;
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    FILE *fp;
    char linha[10000];
    char title[] = "<title>";
    char description[] = "<description>";
    char link[] = "<link>";
    char pubDate[] = "<pubDate>";

    fp = fopen("taguatinga.xml", "r");
    FILE *fp2;
    fp2 = fopen("pf.html", "w");

    int e_header = 0;
    if (fp != NULL)
    {
        while (fgets(linha, sizeof(linha), fp))
        {
            devolveString(linha, title, fp2, &e_header);
            devolveStringDesc(linha, description, fp2);
            devolveString(linha, link, fp2, &e_header);
            break;
        }
        while (fgets(linha, sizeof(linha), fp))
        {
            devolveString(linha, title, fp2, &e_header);
            devolveStringDesc(linha, description, fp2);
            devolveString(linha, link, fp2, &e_header);
            devolveString(linha, pubDate, fp2, &e_header);
        }
    }
    fclose(fp);
    fclose(fp2);
    fp2 = fopen("pf.html", "a");
    fprintf(fp2, "</body>\n</html>\n");
    fclose(fp2);

    return 0;
}