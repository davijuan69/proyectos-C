#include <stdio.h>
#include <stdlib.h> 
/*abecedario*/

char *abecedario(int n){
char *auxp,*restp, i;
restp = auxp = (char*)malloc(sizeof(char)  * (n+1));

for(i=0;i<n;i++){
   *auxp++='A'+i;
    *(auxp)='\0'; 
}

if(n > 26){
    return NULL;
}

return restp;

free(auxp);
free(restp);
}

int main(){
    printf(abecedario(26));
    return 0;
}