/*
Siguiendo el prototipo: float relacionPI(int array[], int size), calcule la
división entre las suma de los valores pares y la suma de los valores
impares.
*/

float relacionPI(int array[], int size) {
    int sumaPares = 0;
    int sumaImpares = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            sumaPares += array[i];
        } else {
            sumaImpares += array[i];
        }
    }
    if (sumaImpares == 0) {
        return 0.0f;
    }

    return (float)sumaPares / sumaImpares;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(array) / sizeof(array[0]);
    float resultado = relacionPI(array, size);
    printf("resultado: %.2f\n", resultado);
    return 0;
}