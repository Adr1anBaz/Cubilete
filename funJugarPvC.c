#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void cargando(void);
void teclearAlgo(void);//Esta función es auxiliar, nos permite teclear diferentes cosas para que se haga menos
void convertirMano(int arreglo[5], char arreglo2[5]); //La función permite traducir los números que salen en el cubilete
//Hago que primero sea un arreglo de números, y después lo transformo a letras, como las caras de los dados
int deseasCambiarManoP( void ); //Pregunta si se desea cambiar de mano
void cargando(void); //Simula una pantalla de "Cargando" como las de los videojuegos
int obtenerPrimerJugador( void );//Esta función nos permite obtener el primer jugador que va a jugar
void obtenerMano(int arreglo[5]); //Llena el arreglo y retorna el valor de mano para cualquier jugador
void cambiarMano(int arreglo[5]); //Permite cambiar los valores de una mano de los dados
void mensajePrimeraRonda ( void ); //Sólo manda un mensaje que indica que es la primera ronda
void mensajeSegundaRonda ( void );//Sólo manda un mensaje que indica que es la primera ronda
void mensajeTercerRonda ( void );//Sólo manda un mensaje que indica que es la primera ronda
void obtenerManoRonda ( int arreglo[5], char arreglo2[5]); //Esta función es importante, tanto obtener la mano, como cambiar dados
void seleccionarGanadorPvC(int manoJugador1, int manoJugador2); //Selecciona el ganador
int calcularPuntosMano( int arreglo[5]); //Calcula los puntos que se tienen por mano para hacer la comparación

extern void jugarPvC ( void )
{
    char arreglo2[5];
    arreglo2[0]='0';
    arreglo2[1]='0';
    arreglo2[2]='0';
    arreglo2[3]='0';
    arreglo2[4]='0';
    int mano1[5], mano2[5], r1=0, aux1=0, r2=0, aux2=0;
    printf("\nVas a jugar contra mí\n");
    mensajePrimeraRonda();
    printf("\nTú vas a tirar primero\n");
    teclearAlgo();
    cargando();
    obtenerManoRonda(mano1, arreglo2);
    r1= calcularPuntosMano(mano1);
    aux1 = aux1 + r1;
    printf("\nLLEVAS %d PUNTOS ", aux1);
    ////////////////////////////////////////////////////////
    printf("\nVeamos qué dados obtengo yo...\n");
    cargando();
    obtenerMano(mano2);
    convertirMano(mano2, arreglo2);
    r2= calcularPuntosMano(mano2);
    aux2 = aux2 + r2;
    printf("\nLLEVO %d PUNTOS ", aux2);
//RONDA 2
    mensajeSegundaRonda();
    printf("\nEs tu turno, jugador 1\n");
    teclearAlgo();
    cargando();//Cargando
    obtenerManoRonda(mano1 , arreglo2);
    r1= calcularPuntosMano(mano1);
    aux1 = aux1 + r1;
    printf("\nLLEVAS %d PUNTOS ", aux1);
///////////////////////////////////////////
    printf("Veamos qué me sale\n");
    cargando();
    obtenerMano(mano2);
    convertirMano(mano2, arreglo2);
    r2= calcularPuntosMano(mano2);
    aux2 = aux2 + r2;
    printf("\nLLEVO %d PUNTOS ", aux2);

//RONDA 3
    printf("\n¿Estás liste para la ronda final?\n");
    mensajeTercerRonda();
    printf("\nHaz los honores de tirar, jugador 1\n");
    teclearAlgo();
    cargando();//Cargando
    obtenerManoRonda(mano1, arreglo2);
    r1= calcularPuntosMano(mano1);
    aux1 = aux1 + r1;
    printf("\nLLEVAS %d PUNTOS", aux1);
    //TURNO DE LA COMPUTADORA
    printf("\nLo mejor para el final, mis dados son:\n");
    cargando();
    obtenerMano(mano2);
    convertirMano(mano2, arreglo2);
    r2= calcularPuntosMano(mano2);
    aux2 = aux2 + r2;
    printf("\nLLEVO %d PUNTOS ", aux2);
    seleccionarGanadorPvC(aux1, aux2);
    printf("Gracias por haber jugado mi juego :,)\n");
}
/**
 * @brief Este procedimiento permite saber si el jugador ganó contra la computadora
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param void.
 * @return void.
 */
void seleccionarGanadorPvC(int manoJugador1, int manoJugador2)
{
    int resultado;
    if(manoJugador1 > manoJugador2)
    {
        printf("\n¡Eres el ganador de este juego de cubilete!\n");
    }
    if(manoJugador2 > manoJugador1)
    {
        printf("\n¡Te gané!\n");
    }
    if(manoJugador1 == manoJugador2)
    {
        printf("\n¡Hemos empatado, padrino!\n");
        printf("\nFelicidades\n");
    }
}