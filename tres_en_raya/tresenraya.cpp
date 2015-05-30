#include <stdio.h>
#include <stdlib.h>


char tablero[3][3];
char jugadorActual = 'X';


//MOSTRAR TABLERO DE INICIO
void inicializar(){
    for(int x=0; x<3; x++){
	for(int y=0; y<3; y++){
	    tablero[x][y] = '_';
	}
    }
}


//HACER COMPROBACIONES PARA VER SI HAY UN GANADOR
bool ganador(){

    //HORIZONTAL
    char jugadorEncontrado = tablero[0][0];
    for(int x=0; x<3; x++){
	for(int y=0; y<3; y++){
	    if(tablero[x][y] == '_'){
		break; break;
	    }
	    if(jugadorEncontrado != tablero[x][y]){
		break; break;
	    }
	    jugadorEncontrado = tablero[x][y];
	    if(y==2){
		printf("¡HA GANADO %c!\n", jugadorEncontrado);
		return true;
	    }
	}
    }


    //VERTICAL
    jugadorEncontrado = tablero[0][0];
    for(int x=0; x<3; x++){
	for(int y=0; y<3; y++){
	    if(tablero[y][x] == '_'){
		break; break;
	    }
	    if(jugadorEncontrado != tablero[y][x]){
		break; break;
	    }
	    jugadorEncontrado = tablero[y][x];
	    if(y==2){
		printf("¡HA GANADO %c!\n", jugadorEncontrado);
		return true;
	    }
	}
    }


    //DIAGONAL DE IZQUIERDA A DERECHA
    jugadorEncontrado = tablero[0][0];
    for(int x=0 ; x<3; x++){
	if(tablero[x][x] == '_'){
	    break; 
	}
	if(jugadorEncontrado != tablero[x][x]){
	    break;                                               
	}
	jugadorEncontrado = tablero[x][x];
	if(x==2){
	    printf("¡HA GANADO %c!\n", jugadorEncontrado);
	    return true;                          
	}                 
    }


    //DIAGONAL DE DERECHA A IZQUIERDA
    jugadorEncontrado = tablero[0][2];
    for(int x=2 ; x>=0; x--){
	if(tablero[2-x][x] == '_'){
	    break; 
	}
	if(jugadorEncontrado != tablero[2-x][x]){
	    break;                                               
	}
	jugadorEncontrado = tablero[2-x][x];
	if(x==0){
	    printf("¡HA GANADO %c!\n", jugadorEncontrado);
	    return true;                          
	}                 
    }
    return false;
}


//COMPROBAR SI HAY TABLAS
bool tablas(){
    for(int x=0; x<3; x++){
	for(int y=0; y<3; y++){
	    if(tablero[x][y] == '_'){
		return false;
	    }
	}
    }
    printf("TABLAS\n");
    return true;
}


//MOSTRAR TABLERO DESPUÉS DE HACER UN MOVIMIENTO
void desplegarTablero(){
    for(int x=0; x<3; x++){
	for(int y=0; y<3; y++){
	    printf("%c\t", tablero[x][y]);
	}
	printf("\n");
    }
}


//********************
//DESARROLLO DEL JUEGO
//********************

int main (int argc, char *argv[]) {

    //EMPEZAR LA PARTIDA
    inicializar();

    //MIENTRAS NO HAYA GANADOR Y NO HAYA EMPATE
    while(!ganador() && !tablas()){
	system("clear");
	printf("TRES EN RAYA\n"
		"============\n");
	printf("\nEn este juego debemos alinear tres X o 0 de forma horizontal, vertical o diagonal para ganar la partida.\n");
	printf("Tanto filas como columnas están numeradas en 0, 1 y 2.\n\n");
	desplegarTablero();
	int fila=0;
	int columna=0;
	printf("\nEn qué fila quiere jugar %c: ", jugadorActual);
	scanf("%d", &fila);    
	printf("En qué columna quiere jugar %c: ", jugadorActual);
	scanf("%d", &columna);

	//SI LA CASILLA YA ESTÁ OCUPADA POR OTRA FICHA
	if(tablero[fila][columna] != '_'){
	    printf("Casilla ocupada\n");                                 
	}else{
	    tablero[fila][columna] = jugadorActual;
	    if(jugadorActual == 'X'){
		jugadorActual  = 'O';                     
	    }else{
		jugadorActual = 'X';         
	    }
	}
	system("clear");
	printf("TRES EN RAYA\n"
		"============\n");
	printf("\nEn este juego debemos alinear tres X o 0 de forma horizontal, vertical o diagonal para ganar la partida.\n");
	printf("Tanto filas como columnas están numeradas en 0, 1 y 2.\n\n");
	desplegarTablero();
	printf("\n");
    }
    printf("\n");

    return EXIT_SUCCESS;
}
