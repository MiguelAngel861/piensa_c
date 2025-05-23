En el arreglo tridimensional LLU se almacenan las lluvias mensuales registradas
en milímetros, en las 24 provincias de Argentina, durante los últimos 10 años.
Escribe un programa en C que permita resolver lo siguiente:
a) La provincia que tuvo el mayor registro de precipitación pluvial durante
los últimos 10 años.
b) La provincia que tuvo el menor registro de lluvias en el último año.
c) El mes que tuvo el mayor registro de lluvias en la provincia 18 en el
quinto año.
Nota: En todos los casos se debe escribir además el registro de lluvias
correspondiente.
Dato: LLU[24][12][10] (arreglo tridimensional de tipo real que almacena las
lluvias mensuales en las 24 provincias durante los últimos 10 años).

#include <stdio.h>
/* Lluvias.
El programa, al recibir como dato un arreglo tridimensional que contiene
➥información sobre lluvias, genera información estadística. */
const int PRO = 24;
const int MES = 12;
const int AÑO = 10;
void Lectura(float [PRO][MES][AÑO], int, int, int);
void Funcion1(float [PRO][MES][AÑO], int, int, int);
void Funcion2(float [PRO][MES][AÑO], int, int, int); /* Prototipos de funciones. */
void Funcion3(float [PRO][MES][AÑO], int, int, int);
void main(void)
{
float LLU[PRO][MES][AÑO];
Lectura(LLU, PRO, MES, AÑO);
Funcion1(LLU, PRO, MES, AÑO);
Funcion2(LLU, PRO, MES, AÑO);
Funcion3(LLU, 18, MES, 5);
}
void Lectur (float A[][MES][AÑO], int F, int C, int P)
/* Esta función se utiliza para leer un arreglo tridimensional de tipo real de
➥F filas, C columnas y P planos de profundidad. */
{
int K, I, J;
for (K=0; K<P; K++)
for (I=0; I<F; I++)
for (J=0; J<C; J++)
{
printf(”Año: %d\tProvincia: %d\tMes: %d”, K+1, I+1, J+1);
scanf(”%f”, &A[I][J][K]);
}
}
void Funcion1(float A[][MES][AÑO],int F, int C, int P)
/* Esta función se utiliza para localizar la provincia que tuvo el mayor registro
➥de precipitación pluvial en los últimos 10 años. Escribe además el registro
➥correspondiente. */
{
        int I, K, J, EMAY = -1;
        float ELLU = -1.0, SUM;
        for (I=0; I<F; I++)
        {
        SUM = 0.0;
        for (K=0; K<P; K++)
        for (J=0; J<C; J++)
        SUM += A[I][J][K];
        SUM /= P * C;
        if (SUM > ELLU)
        {
        ELLU = SUM;
        EMAY = I;
        }
        }
        printf(”\n\nProvincia con mayor registro de lluvias: %d”, EMAY+1);
        printf(”\nRegistro: %.2f”, ELLU);
        }
        void Funcion2(float A[][MES][AÑO],int F, int C, int P)
        /* Esta función se utiliza para localizar la provincia que tuvo el menor registro
        ➥de lluvias en el último año. Escribe además el registro correspondiente. */
        {
        int I, J, EMEN;
        float ELLU = 1000, SUM;
        for (I=0; I<F; I++)
        {
        SUM = 0;
        for (J=0; J<C; J++)
        SUM += A[I][J][P-1];
        SUM /= C;
        if (SUM < ELLU)
        {
        ELLU = SUM;
        EMEN = I;
        }
        }
        printf(”\n\nProvincia con menor registro anual de lluvias en el último año: %d”,
        EMEN+1);
        printf(”\nRegistro anual: %.2f”, ELLU);
        }
        void Funcion3(float A[][MES][AÑO],int F, int C, int P)
        /* Esta función se utiliza para localizar el mes con mayor registro de lluvias en
        ➥la provincia 18 en el quinto año. Escribe además el registro correspondiente. */
        {
        int J, EMES = -1;
        float ELLU = -1.0;
        or (J=0; J<C; J++)
        {
        if (A[F-1][J][P-1] > ELLU)
        {
        ELLU = A[F-1][J][P-1];
        EMES = J;
        }
        }
        printf(”\n\nMes: %d Lluvias: %.2f”, EMES+1, ELLU);
        }