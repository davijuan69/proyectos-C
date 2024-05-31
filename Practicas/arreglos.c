#include <stdio.h>

// EDADES

void imprimirEdades(int edades[], int cantidad){
     int i;

    for(i = 0; i < cantidad; i++){
        printf("ingrese una edad: ");
        scanf("%d", &edades[i]);
    }

    for(i = 0; i < cantidad; i++){
        printf("edades[%i] = %i\n", i, edades[i]);
    }

}


int main(){
    int edades[8];
    imprimirEdades(edades, 8);
   
    return 0;
}


// TEMPERATURA_HORA

/*
#include <stdio.h>
#define ELEMENTOS 24
int main() {
int temp [ELEMENTOS];
float media;
int hora;
for (hora=0; hora<ELEMENTOS ; hora++){
printf( "Temperatura de las [%d]: ", hora);
scanf( "%d", &temp [hora]);
media +=temp [hora];
}
media = media /ELEMENTOS;
printf("\nLa temperatura media es %f\n", media );
}
*/

