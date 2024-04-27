#include <stdio.h>
#include <string.h>

void sass(char *colour)
{
    char buf[100];
    strcpy(buf, colour);
    printf("So your favourite colour is %s? How dull!\n", buf);
}

int main(int argc, char *argv[])
{
   sass(argv[1]);
   return 0;
}