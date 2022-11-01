//Declaramos las funciones que vamos a usar
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//Declaración de prototipos de la función
extern void cargando(void);
extern void teclearAlgo(void);//Esta función es auxiliar, nos permite teclear diferentes cosas para que se haga menos
//monótono el jugar
extern void convertirMano(int arreglo[5], char arreglo2[5]);
extern int deseasCambiarManoP( void ); //Pregunta si se desea cambiar de mano
extern void cargando(void); //Simula una pantalla de "Cargando" como las de los videojuegos
extern int obtenerPrimerJugador( void );//Esta función nos permite obtener el primer jugador que va a jugar
extern void obtenerMano(int arreglo[5]); //Llena el arreglo y retorna el valor de mano para cualquier jugador
extern void cambiarMano(int arreglo[5]); //Permite cambiar los valores de una mano de los dados
extern void mensajePrimeraRonda ( void );//Sólo manda un mensaje que indica que es la primera ronda
extern void mensajeSegundaRonda ( void );//Sólo manda un mensaje que indica que es la primera ronda
extern void mensajeTercerRonda ( void );//Sólo manda un mensaje que indica que es la primera ronda
extern void obtenerManoRonda ( int arreglo[5], char arreglo2[5]); //Esta función es importante, tanto obtener la mano, como cambiar dados
extern void seleccionarGanador(int manoJugador1, int manoJugador2); //Selecciona el ganador
extern int calcularPuntosMano( int arreglo[5]);//Calcula los puntos que se tienen por mano para hacer la comparación
extern void jugarPvP( void ) 
{
    char arreglo2[5];
    arreglo2[0]='0';
    arreglo2[1]='0';
    arreglo2[2]='0';
    arreglo2[3]='0';
    arreglo2[4]='0';
    int r1=0, r2=0, aux1 = 0, aux2= 0;
    int mano1[5], mano2[5];
    int ganador=0, opcion=0, cambio=0;
    printf("Bienvenido, en esta ocasión vas a jugar contra otro jugador\n");
    printf("Ahora que se han presentado, es momento de elegir quién tirará primero los dados");
    //sleep(1);
    printf("Esto lo haremos dando un número, quien tenga el número mayor, empezará\n");
    //INTRODUCIR FUNCIÓN QUE HACE EL LOADING
    ganador = obtenerPrimerJugador();
    switch(ganador)
    {
        case 1 : 
        {
            //El jugador 1 empieza;
            mensajePrimeraRonda();
            printf("\nVas a tirar tu primero, jugador 1.\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano1, arreglo2);
            r1= calcularPuntosMano(mano1);
            aux1 = aux1 + r1;
            printf("\nLLEVAS %d PUNTOS", aux1);
            //CONTINUA EL JUGADOR 2
            printf("\n Es turno del jugador 2.\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano2, arreglo2);
            r2= calcularPuntosMano(mano2);
            aux2 = aux2 + r2;
            printf("\nLLEVAS %d PUNTOS", aux2);
//EMPIEZA LA SEGUNDA RONDA
            mensajeSegundaRonda();
            printf("\nEs tu turno, jugador 1\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano1 , arreglo2);
            r1= calcularPuntosMano(mano1);
            aux1 = aux1 + r1;
            printf("\nLLEVAS %d PUNTOS", aux1);
            //CONTINUA EL JUGADOR 2
            printf("\nEs hora de que juegue el jugador 2\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano2, arreglo2);
            r2= calcularPuntosMano(mano2);
            aux2 = aux2 + r2;
            printf("\nLLEVAS %d PUNTOS", aux2);
            printf("\n¿Están listos para la ronda final?\n");
//EMPIEZA LA TERCER RONDA
            mensajeTercerRonda();
            printf("\nHaz los honores de tirar, jugador 1\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano1, arreglo2);
            r1= calcularPuntosMano(mano1);
            aux1 = aux1 + r1;
            printf("\nLLEVAS %d PUNTOS", aux1);
            //CONTINUA EL JUGADOR 2
            printf("\nFinalmente...jugador 2, realiza el último tiro\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano2, arreglo2);
            r2= calcularPuntosMano(mano2);
            aux2 = aux2 + r2;
            printf("\nLLEVAS %d PUNTOS", aux2);
            //Selecciona el ganador del juego
            seleccionarGanador(aux1, aux2);
            printf("Gracias por haber jugado mi juego :,)");
        }break;
        //EL JUGADOR DOS EMPIEZA EL JUEGO
        case 2:
        {
            mensajePrimeraRonda();
            printf("\nVas a tirar tu primero, jugador 2.\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano2, arreglo2);
            r2= calcularPuntosMano(mano2);
            aux2 = aux2 + r2;
            printf("\nLLEVAS %d PUNTOS", aux2);
            //TURNO DEL JUGADOR 1
            printf("\n Es turno del jugador 1.\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano1, arreglo2);
            r1= calcularPuntosMano(mano1);
            aux1 = aux1 + r1;
            printf("\nLLEVAS %d PUNTOS", aux1);
//RONDA 2
            mensajeSegundaRonda();
            printf("\nEs tu turno, jugador 2\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano2 , arreglo2);
            r2= calcularPuntosMano(mano2);
            aux2 = aux2 + r2;
            printf("\nLLEVAS %d PUNTOS", aux2);
            //CONTINUA EL JUGADOR 1
            printf("\nEs hora de que juegue el jugador 1\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano1, arreglo2);
            r1= calcularPuntosMano(mano1);
            aux1 = aux1 + r1;
            printf("\nLLEVAS %d PUNTOS", aux1);
            printf("\n¿Están listos para la ronda final?\n");
//RONDA 3
            mensajeTercerRonda();
            printf("\nHaz los honores de tirar, jugador 2\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano2, arreglo2);
            r2= calcularPuntosMano(mano2);
            aux2 = aux2 + r2;
            printf("\nLLEVAS %d PUNTOS", aux2);
            //TURNO JUGADOR 1
            printf("\nFinalmente...jugador 1, realiza el último tiro\n");
            teclearAlgo();
            cargando();//Cargando
            obtenerManoRonda(mano1, arreglo2);
            r1= calcularPuntosMano(mano1);
            aux1 = aux1 + r1;
            printf("\nLLEVAS %d PUNTOS", aux1);
            //Selecciona el ganador si el jugador 2, empieza la partida
            seleccionarGanador(aux1, aux2);
            printf("Gracias por haber jugado mi juego :,)");
        }break;
        default:
        {
            //Nadie empieza xd;
            printf(".");
        }break;
    }
}
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
 * @brief Este procedimiento permite transforar los valores que están en la mano de enteros, a otro arreglo que es tipo char
 * De esta forma, se muestra en pantalla las caras de los dados y no números
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param arreglo[5], int.
 * @param arreglo2[5], char.
 * @return void.
 */
void convertirMano(int arreglo[5], char arreglo2[5])
{
    int i,k;
    for ( i = 0; i <= 4; i++)
    {
        if(arreglo[i]==6)
        {
            arreglo2[i]='A';
        }
        if(arreglo[i]==5)
        {
            arreglo2[i]='K';
        }
        if(arreglo[i]==4)
        {
            arreglo2[i]='Q';
        }
        if(arreglo[i]==3)
        {
            arreglo2[i]='J';
        }
        if(arreglo[i]==2)
        {
            arreglo2[i]='D';
        }
        if(arreglo[i]==1)
        {
            arreglo2[i]='N';
        }
    }
    for(k = 0; k<=4; k++)
    {
        printf("%c ", arreglo2[k]);
    }
}
/**
 * @brief Este procedimiento permite saber si el jugador 1 ganó o si el jugador 2 ganó
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param manoJugador1, tipo entero.
 * @param manoJugador2, tipo entero. 
 * @return void.
 */
void seleccionarGanador(int manoJugador1, int manoJugador2)
{
    int resultado;
    if(manoJugador1 > manoJugador2)
    {
        printf("\n¡El jugador 1 es el ganador de este juego de cubilete!\n");
    }
    if(manoJugador2 > manoJugador1)
    {
        printf("\n¡El jugador 2 es el ganador de este juego de cubilete!\n");
    }
    if(manoJugador1 == manoJugador2)
    {
        printf("\n¡Ha pasado lo más inesperado, hay un empate!\n");
        printf("\nFelicidades a ustedes\n");
    }
}
/**
 * @brief Este procedimiento permite obtener la mano como tal, preguntar si se desea cambiar y sacar el valor total para hacer
 * la comparación
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param arreglo[5].
 * @param arreglo2[5], char.
 * @return void.
 */
void obtenerManoRonda ( int arreglo[5], char arreglo2[5] )
{
    int cantidadCambios = 0, cambio, auxiliarCantidadCambios=0, valorMaximoVeces = 3, puntosMano=0;
    obtenerMano(arreglo);
    printf("\n");
    convertirMano(arreglo, arreglo2);
    do
    {
        printf("\n¿Deseas cambiar de mano? Este procedimiento sólo se puede hacer hasta 3 veces\n");
        printf("\nEscribe una 's' para Sí, y una 'n' para No\n");
        cambio = deseasCambiarManoP();
        
        if(cambio == 1)
        {
            cantidadCambios = cantidadCambios +1;
            auxiliarCantidadCambios = auxiliarCantidadCambios + 1;
            printf("Llevas %d cambios, te quedan %d cambios disponibles\n", cantidadCambios, (3-cantidadCambios));
            cambiarMano(arreglo);
            printf("\n");
            convertirMano(arreglo, arreglo2);

        }
        else
        {
            printf("\nHiciste %d cambios\n", cantidadCambios);
            break;
        }
    }while(cantidadCambios < 3);
    puntosMano = calcularPuntosMano(arreglo);
    return;
}
/**
 * @brief Este procedimiento permite saber los puntos que hay en una mano
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param arreglo[5], int.
 * @return void.
 */
int calcularPuntosMano( int arreglo[5])
{
    int resultado = 0, i;
    for(i = 0; i <= 4; i++)
    {
        resultado = resultado + arreglo[i];
    }
    return resultado;
}
//ESTA FUNCIÓN PERMITE CAMBIAR LOS DADOS DE UN JUGADOR
/**
 * @brief Este procedimiento pregunta cuántos dados se desea cambiar, qué posiciones y los cambia por ceros
 * Luego revisa cuáles son cero para volvernos a llenar y dar la impresión de que se volvieron a tirar la mano
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param arreglo[5], int, es un arreglo.
 * @return void.
 */
void cambiarMano(int arreglo[5])
{
    int auxiliar=1;
    int howManyChangesDoYouWant, positionYouWantToChange;
    int i, j, k, y;
    printf("\n¿Cuántos dados quieres cambiar?\n");
    scanf(" %d", &howManyChangesDoYouWant);

    for (i = 1; i<= howManyChangesDoYouWant; i++)
    {
        printf("\n¿Qué posición deseas cambiar? ");
        scanf(" %d", &positionYouWantToChange); //Esto me permite saber qué posiciones deseo cambiar

        arreglo[positionYouWantToChange-1] = 0;
    }
    printf("\n");
    printf("\nTu nueva mano es la siguiente: ");
    for (k = 0; k <=4; k++)
    {
        if(arreglo[k]==0)
        {
            arreglo[k] = rand() % 6 +1;
        }
        //printf("%d ", arreglo[k]);
    }
    return;
}
//ESTA FUNCIÓN PERMITE OBTENER LOS DADOS DE UN JUGADOR
/**
 * @brief Este procedimiento permite tirar los dados la primera vez
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param arreglo[5], tipo int.
 * @return void.
 */
void obtenerMano(int arreglo[5])
{
   int i, j;
    for(i = 0; i <= 4; i++)
    {
        arreglo[i] = rand() % 6 +1;
        //printf("%d ", arreglo[i]);
    }
    return;
}
//ESTA FUNCIÓN PREGUNTA AL USUARIO SI DESEA CAMBIAR LA MANO CON LA QUE ESTÁ JUGANDO
/**
 * @brief Este procedimiento permite evaluar si el usuario desea cambiar de mano o no
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param void.
 * @return void.
 */
int deseasCambiarManoP( void )
{
    char opcion;
    int opcion2=0, resultado;
    do{
    scanf(" %c", &opcion);
    if((opcion=='s') || (opcion == 'n'))
    {
        opcion2=1;
        if((opcion == 's') || (opcion== 'S'))
        {
            resultado = 1;
        }
        if((opcion == 'n') || (opcion=='N'))
        {
            resultado = 2;
        }
    }
    else{
        printf("\nPor favor selecciona una opción válida \n");
        opcion2 = 0;
    }
    }while(opcion2 == 0);
    return resultado;
}
//Esta función saca dos números random y los asigna a los jugadores, con base a ello, sabemos quien empezará el juego
/**
 * @brief Este procedimiento permite evaluar si el usuario desea cambiar de mano o no
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param void.
 * @return void.
 */
int obtenerPrimerJugador( void )
{
    int jugador1, jugador2, opcion=1, ganador=0;
    do
    {
        jugador1 = rand() % 11;
        srand(time(NULL));
        jugador2 = rand() % 11;
        printf("El jugador 1 obtuvo: %d\n", jugador1);
        printf("El jugador 2 obtuvo: %d\n", jugador2);
        if(jugador1>jugador2)
        {
            printf("Por lo tanto, el jugador 1 va a empezar con el juego\n");
            opcion = 2;
            ganador=1;
        }
        if(jugador2>jugador1)
        {
            printf("Por lo tanto, el jugador 2 va a empezar con el juego\n");
            opcion = 2;
            ganador=2;
        }
        if(jugador1==jugador2)
        {
            printf("Hubo un empate, hay que hacerlo de nuevo\n");
            opcion= 1;
        }
    }while( opcion == 1);
    return ganador;
}

//Esta función permite teclear cualquier cosa para hacer que el jugador piense que el juego es más dinámico
/**
 * @brief Este procedimiento permite teclear algo random, para el código no sea tan monótono
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param void.
 * @return void.
 */
void teclearAlgo( void )
{
    char algo;
    printf("Presiona cualquier tecla para continuar\n");
    scanf(" %c", &algo);
    return;
}
/**
 * @brief Este procedimiento permite imprimir un mensaje para más estética
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param void.
 * @return void.
 */
void mensajePrimeraRonda ( void )
{
    printf("\n***************************************************************************************\n");
    printf("\nPRIMERA RONDA\n");
    printf("\n***************************************************************************************\n");

}
/**
 * @brief Este procedimiento permite imprimir un mensaje para más estética
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param void.
 * @return void.
 */
void mensajeSegundaRonda ( void )
{
    printf("\n***************************************************************************************\n");
    printf("\nSEGUNDA RONDA\n");
    printf("\n***************************************************************************************\n");   
}
/**
 * @brief Este procedimiento permite imprimir un mensaje para más estética
 * @author Adrián Bazaldua
 * @date 30/oct/2022
 * @param void.
 * @return void.
 */
void mensajeTercerRonda ( void )
{
    printf("\n***************************************************************************************\n");
    printf("\nTERCER RONDA\n");
    printf("\n***************************************************************************************\n");
}
/**
 * @brief Este procedimiento permite imprimir un mensaje para más estética. Obtenido de internet
 * @author anónimo
 * @date 30/oct/2022
 * @param void.
 * @return void.
 */
void cargando(void)
{
        for ( int loop = 0; loop < 1; ++loop) {
        for ( int each = 0; each < 4; ++each) {
            printf ( "\rCargando%.*s   \b\b\b", each, "...");
            fflush ( stdout);//force printing as no newline in output
            sleep ( 1);
        }
    }
    printf ( "\n");
}