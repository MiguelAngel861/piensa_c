#include <stdio.h>

/* Búsqueda binaria. */
const int MAX = 100;

void lectura(int *, int); /* Prototipos de funciones. */
int binaria(int *, int, int);

void main(void)
{
        int res, ele, tam, vec[MAX];

        do {
                printf("Ingrese el tamaño del arreglo: ");
                scanf("%d", &tam);
        } while (tam > MAX || tam < 1);
        /* Se verifica que el tamaño del arreglo sea correcto. */

        lectura(vec, tam);

        printf("\nIngrese el elemento a buscar: ");
        scanf("%d", &ele);

        res = binaria(vec, tam, ele); /* Se llama a la función que busca en el arreglo. */

        if (res)
                /* Si res tiene un valor verdadero —diferente de 0—, se escribe la
                 * posición en la que se encontró el elemento. */
                printf("\nEl elemento se encuentra en la posición: %d", res);
        else
                printf("\nEl elemento no se encuentra en el arreglo");
}

void lectura(int a[], int t)
{
        /* La función lectura se utiliza para leer un arreglo unidimensional de t
         * elementos de tipo entero. */
        int i;

        for (i = 0; i < t; i++) {
                printf("Ingrese el elemento %d: ", i + 1);
                scanf("%d", &a[i]);
        }
}

int binaria(int a[], int t, int e)
{
        /* Esta función se utiliza para realizar una búsqueda binaria del
         * elemento e en el arreglo unidimensional a de t elementos. Si se
         * encuentra el elemento, la función regresa la posición correspondiente.
         * En caso contrario, regresa 0. */
        int izq = 0, cen, der = t - 1, ban = 0;

        while ((izq <= der) && (!ban)) {
                cen = (izq + der) / 2;
                if (e == a[cen])
                        ban = cen + 1; /* Ajuste para devolver la posición basada en 1 */
                else if (e > a[cen])
                        izq = cen + 1;
                else
                        der = cen - 1;
        }

        return ban;
}