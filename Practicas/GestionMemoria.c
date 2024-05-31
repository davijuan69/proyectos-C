#include <stdio.h>
#include <stdlib.h>

int main(){
int *xp;
xp = (int *) malloc(sizeof(int));
*xp = 5;
free(xp);
printf("*xp: %d\n",*xp);
return 0;
}
