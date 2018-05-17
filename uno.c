
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* En esta parte tenemos las funciones que nos daran los 2 numeros al azar 
 * entre 1 al 100
 */
int numero_azar_a(){
	int na;
	na = (rand() %100)+1;
	return na;
}
int numero_azar_b(){
	int nb;
	nb=(rand() %100)+1;
	return nb;
}

/*Aqui en el void, tenemos todo el procedimiento en el cual nos solicita una letra A o B
 *Llamamos a nuestras funciones de arriba, la cual nos entrega 2 numeros al azar.
 * mas Abajo nos muestra estos numeros y nos compara respecto a la letra que hayamos elegido
 * esto nos entregara si hemos ganado o hemos perdido
 * junto con esto se nos ira sumando un contador para las victorias y otro para las derrotas
 * finalizando este void, nos preguntara si queremos apostar nuevamente, si no queremos solo precionamos la tecla n y se cerrara el programa.
 */
void 
Game_apuesta (){
	int x, y;
	int i=0, j=0;
	char letra;
	char tecla='S';

	while (tecla=='S'){
		printf("Apuestas por A o por B \n");
		scanf (" %c", &letra);
		
		x= numero_azar_a();
		y= numero_azar_b();
		
	printf("el numero A saca un: %d \n", x);
	printf("el numero B saca un: %d \n", y);
	
		if(letra=='A' && x>y){
			printf("HAS GANADO!!!  \n");
			i++;
		}
		if (letra=='B' && y>x){
			printf("HAS GANADO!!! \n");
			i++;
		}
		if (letra=='A' && y>x){
			printf("HAS PERDIDO!!! \n");
			j++;
		}
		if (letra=='B' && x>y){
			printf("HAS PERDIDO!!! \n");
			j++;
		}
		printf("llevas un total de : %d partidas ganadas \n", i);
		printf("y un total de : %d partidas perdidas \n", j);	
		
		printf("Quieres apostar otra vez? (S/N) \n");	
		scanf(" %c", &tecla);
		if (tecla=='N' || tecla=='n'){
			break;
		}
	}
}

/* Aqui solamente le damos la bienvenida al usuario y llamamos la funcion void el cual nos trae todo el procedimiento
 * le agregamos el parametro srand(time(NULL)) para que los 2 numeros generados en nuestra funcion principal no se repitan
 * y terminamos con un return 0
 */
int main (){
	srand(time(NULL));
	printf("bienvenido al programa de apuestas \n");
	Game_apuesta ();
	return 0;
}
