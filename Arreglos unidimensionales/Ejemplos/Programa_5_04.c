/* Producto de vectores.
El programa calcula el producto de dos vectores y almacena el resultado
➥en otro arreglo unidimensional. */

#include <stdio.h>

const int MAX = 10; /* Se define una constante para el tamaño de los arreglos. */
/* Prototipos de funciones. */
void Lectura(int VEC[], int T);
void Imprime(int VEC[], int T); 
void Producto(int *X, int *Y, int *Z, int T);  /* Observa que en los parámetros, para indicar que lo que se recibe es un arreglo, se puede escribir VEC[] o *VEC. */

int main(void)
{
        int VE1[MAX], VE2[MAX], VE3[MAX]; /* Se declaran tres arreglos de tipo entero de 10 elementos. */
        
        Lectura(VE1, MAX); /* Se llama a la función Lectura. Observa que el paso del arreglo a la funciónes por referencia. Sólo se debe incluir el nombre del arreglo. */
        Lectura(VE2, MAX);
        Producto(VE1, VE2, VE3, MAX); /* Se llama a la función Producto. Se pasan los nombres de los tres arreglos. */

        printf("\nProducto de los Vectores");

        Imprime(VE3, MAX);
        
        return 0;
}

/* La función Lectura se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */
void Lectura(int VEC[], int T)
{
        int I;

        printf("\n");

        for (I = 0; I < T; I++) {
                printf("Ingrese el elemento %d: ", I+1);
                scanf("%d", &VEC[I]);
        }
}

/* La función Imprime se utiliza para imprimir un arreglo unidimensional de T elementos de tipo entero. */
void Imprime(int VEC[], int T) 
{
        int I;

        for (I = 0; I < T; I++) {
                printf("\nVEC[%d]: %d", I+1, VEC[I]);
        }
}

/* Esta función se utiliza para calcular el producto de dos arreglos unidimensionales de T elementos de tipo entero. */
void Producto(int *X, int *Y, int *Z, int T)
{
        int I;
        
        for (I = 0; I < T; I++) {
                Z[I] = X[I] * Y[I];
        }
}