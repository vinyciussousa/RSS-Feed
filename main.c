#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    char linha[100];

    fp = fopen("news.xml", "r");

    if (fp != NULL)
    {
        while (fgets(linha, sizeof(linha), fp))
        {
            
        }
    }
    

    return 0;
}

