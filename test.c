#include <stdlib.h>
#include <std
int main(void)
{
    char *line = NULL;
    size_t len;
    size_t read;

    while ((read = getline(&line, &len, stdin)))
    {
            
        printf("%s\n", line);

    }
        

    free(line);
    return (0);
}