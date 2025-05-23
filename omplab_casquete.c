/***********************************************
* Autor: Sebastián Vargas Casquete
* Materia: Sistemas Operativos
* Tema: Uso de OpenMP (Open Multi-Processing)
* 	Pontificia Universidad Javeriana
* Descripción:
*   Este programa demuestra el uso básico de OpenMP
*   para ejecutar tareas en paralelo. Se configuran
*   un número específico de hilos mediante el argumento
*   de entrada, y se usa una región paralela para imprimir
*   información sobre los hilos y ejecutar un bucle en paralelo.
*
*   El objetivo es evidenciar cómo OpenMP maneja múltiples hilos
*   y cómo se puede paralelizar un bucle con "#pragma omp parallel for".
*
* Compilación:
*   gcc omplab_casquete.c -o ejecutable -fopenmp
*
* Ejecución:
*   ./ejecutable <NumHilos>
*
* Ejemplo:
*   ./ejecutable 4
*
* Observaciones:
*   - Se espera que `a = 50` y `b = 1049` al final del bucle.
*   - El uso de `private(a, i)` crea una copia local para cada hilo,
*     esto puede alterar el resultado esperado de `b`.
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000

// Función que valida argumentos y obtiene número de hilos
int obtener_numero_hilos(int argc, char *argv[]) {
    if (argc < 2) {
        printf("entrada por consola \n $./ejecutable NumHilos");
        exit(0);
    }
    return atoi(argv[1]);
}

// Configurar OpenMP con la cantidad deseada de hilos
void configurar_hilos(int hilos) {
    omp_set_num_threads(hilos);
}

// Función que imprime la configuración de hilos
void imprimir_info_hilos(int maxHilos) {
#pragma omp parallel
    printf("MaxHilos %d \t Equipo de hilos impuesto= %d \n", maxHilos, omp_get_num_threads());
}

// Ejecutar el bucle paralelo
void ejecutar_bucle_parallel(int *b) {
    int i;
	int a = 50;
#pragma omp parallel for private(a, i)
    for (i = 0; i < N; i++) {
        *b = a + i;
    }
}

int main(int argc, char *argv[]) {
    int hilos = obtener_numero_hilos(argc, argv);
    int maxHilos = omp_get_max_threads();
    int b = 0;
    int a = 50;

    configurar_hilos(hilos);
    imprimir_info_hilos(maxHilos);
    ejecutar_bucle_parallel(&b);

    printf("El valor de a = %d \t b = %d (se espera que a=50, b=1049)\n", a, b);

    return 0;
}

/*************** conclusiones ***************
* 1. El uso de OpenMP permite paralelizar de forma sencilla
*    tareas que se repiten en bucles, aprovechando múltiples
*    núcleos del procesador para mejorar el rendimiento.
*
* 2. La directiva `#pragma omp parallel for` permite ejecutar
*    iteraciones de un bucle en diferentes hilos simultáneamente.
*
* 3. Es importante tener cuidado con las variables compartidas
*    entre hilos. El uso incorrecto puede generar resultados
*    inconsistentes o condiciones de carrera.
* 4. OpenMP es una herramienta útil para introducir paralelismo
*    en programas C/C++ sin necesidad de modificar demasiado
*    el código secuencial original.
********************************************/
