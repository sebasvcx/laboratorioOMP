# Laboratorio OpenMP - Sistemas Operativos

Este proyecto es una práctica de laboratorio para la materia **Sistemas Operativos** de la **Pontificia Universidad Javeriana**, orientada a explorar la programación paralela en C mediante el uso de **OpenMP (Open Multi-Processing)**.

## 📌 Descripción

El programa demuestra cómo:

- Configurar el número de hilos que utilizará un programa en tiempo de ejecución.
- Usar la directiva `#pragma omp parallel` para crear regiones paralelas.
- Paralelizar un bucle `for` utilizando `#pragma omp parallel for`.
- Observar el comportamiento de variables privadas dentro de regiones paralelas.

## 🛠️ Requisitos

- Sistema operativo Linux o compatible con OpenMP.
- Compilador `gcc` con soporte para OpenMP.
- OpenMP instalado (normalmente ya viene incluido con `gcc`).

## 🔧 Compilación

Para compilar el archivo:

```bash
gcc omplab_casquete.c -o ejecutable -fopenmp
