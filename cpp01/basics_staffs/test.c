#include <stdio.h>
#include <stdlib.h>


int main()
{
    char *h = malloc(12);
    h = "helllo world";
    printf ("%c\n", *h);
}