/**
 * @file Principal.c
 * @brief Este programa tiene como propósito dar la opción de jugar cubilete o dos personas o a una persona
 * @date 14/oct/2022
 * @author Adrián Bazaldua
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Esas dos funciones se ocupan para sacar números random.
La usaremos para el PvP y PvC*/

void saludar(void); // Este procedimiento sólamente manda un saludo al usuario
void imprimirInstrucciones(void); //Esta función imprime las instrucciones
int jugarDeNuevo(void); // Esta función permite que se juegue las veces que el usuario quiera
void jugarPvP ( void ); //La función que permite jugar en PVP
void jugarPvC ( void ); //La función que permite jugar contra la computadora

int main(int argc, char **argv)
{
    int bucle = 1, ganador = 1, jugarNuevo = 0;
    do
    {
        system("clear");
        char opcion; // "opcion" te permite elegir si se quiere jugar un PvP o un PvC
        saludar();
        imprimirInstrucciones();
        scanf(" %c", &opcion);
        switch (opcion)
        {
        case 'P':
        case 'p':
        {
            printf("Has elegido jugar un PvP\n");
            jugarPvP();
            bucle = jugarDeNuevo();
        }
        break;
        case 'C':
        case 'c':
        {
            printf("Has elegido jugar contra mí\n");
            jugarPvC();
            bucle = jugarDeNuevo();
        }
        break;
        default:
        {
            printf("Por favor selecciona una opción válida.\n");
            bucle = 1;
        }
        break;
        }
    } while (bucle == 1);
    return 0;
}
/**************************************************/


/*
Cubilete valores
De menor a mayor: 
A=1
K=2
Q=3
J=10
Negra=9
*/

/**
 * @brief Esta función permite repetir el juego si así se desea
 * @author Adrián Bazaldua
 * @date 14/oct/2022
 * @param void.
 * @return bucle, es una variable entera, que en el código principal me permite repetir mis juegos
 */
int jugarDeNuevo(void)
{
    char opcionJugarNuevo, bucle = 0, bucle2 = 1;
    do
    {
        printf("\n¿Deseas jugar de nuevo?\n");
        printf("\nEscribe una (S) si es un sí, y una (N) si es un no\n");
        scanf(" %c", &opcionJugarNuevo);
        switch (opcionJugarNuevo)
        {
        case 'S':
        case 's':
        {
            bucle = 1;
            bucle2 = 0;
        }
        break;
        case 'N':
        case 'n':
        {
            bucle = 0;
            bucle2 = 0;
        }
        break;
        default:
        {
            printf("Por favor selecciona una opción válida");
            bucle2 = 1;
        }
        break;
        }
    } while (bucle2 == 1);
    return bucle;
}
/**
 * @brief Este procedimiento sólo manda un mensaje de bienvenida
 * @author Adrián Bazaldua
 * @date 14/oct/2022
 * @param void.
 * @return void.
 */
void saludar(void)
{
    printf("\nHola, mi nombre es Adrián :)\n");
    printf("\nEste programa te permitirá jugar el juego de Cubilete\n");
    return;
}
/**
 * @brief Este procedimiento le pide al usuario que ingrese si quiere jugar un PvP o un PvC
 * @author Adrián Bazaldua
 * @date 14/oct/2022
 * @param void.
 * @return void.
 */
void imprimirInstrucciones(void)
{
    printf("\nPara empezar, necesitas elegir si deseas jugar contra mi o si deseas jugar contra otra persona.\n");
    printf("\nNota: Sólo se puede jugar contra otro jugador, este programa no admite más de dos personas jugando :)\n");
    printf("\nPor favor escribe una (P) si deseas jugar contra otra persona\n");
    printf("\nPor favor escribe una (C) si deseas jugar contra mí\n");
    return;
}