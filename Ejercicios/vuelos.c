#include <stdio.h>
#include <string.h>

typedef struct vuelos
{
    char aerolinea[10], destino[10];
    int pasajeros;
}vuelos_t;

int vuelos_frankfurt(vuelos_t vuelos_num[], int num_v){
    int cuenta = 0;
    for(size_t i = 0; i < num_v; i++){
        if (strcmp(vuelos_num[i].destino, "frankfurt") == 0) {
            cuenta++;
        }
    }
    return cuenta;
}

int mas_pasajeros(vuelos_t vuelos_num[], int num_v){
    int max = 0; 
    int pos = 0;
    for(size_t i = 0; i < num_v; i++){
        if (vuelos_num[i].pasajeros > max){
            max = vuelos_num[i].pasajeros;
            pos = i;
        }
    }
    return pos;

}

int menos_100_pasajeros(vuelos_t vuelos_num[], int num_v){
    for(size_t i = 0; i < num_v; i++){
        if (vuelos_num[i].pasajeros < 100){
            return i;
        }
    }
    return -1;
    
}

int aereolinea_mayor_pasajeros(vuelos_t vuelos_num[], int num_v){
    int max = 0; 
    int pos = 0;
    for(size_t i = 0; i < num_v; i++){
        int cuenta = 0;
        for (size_t j = 0; j < num_v; j++)
        {
            if (strcmp(vuelos_num[i].aerolinea, vuelos_num[j].aerolinea) == 0) {
            cuenta += vuelos_num[j].pasajeros;
            
        }
        }
        if (cuenta > max) {
            pos = i;
            max = cuenta;
        }
        
    }
    return pos;
}

int main(){

    int num_v;
    printf("ingrese numero de vuelos: ");
    scanf("%d", &num_v);

    vuelos_t vuelos_num[num_v];

    for (size_t i = 0; i < num_v; i++)
    {
        printf("ingrese un vuelo");
        
        scanf("%s", vuelos_num[i].aerolinea);
        scanf("%s", vuelos_num[i].destino);
        scanf("%d", &vuelos_num[i].pasajeros);
    }

    printf("%d", vuelos_frankfurt(vuelos_num, num_v));
    int pos = mas_pasajeros(vuelos_num, num_v);
    printf("%s", vuelos_num[pos].aerolinea);
    printf("%s", vuelos_num[pos].destino);
    printf("%d", vuelos_num[pos].pasajeros);

    printf("%d", menos_100_pasajeros(vuelos_num, num_v));
    printf("%d", aereolinea_mayor_pasajeros(vuelos_num, num_v));

    return 0;
}
