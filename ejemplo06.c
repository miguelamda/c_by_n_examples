/* 
 * C BY 8 EXAMPLES
 * example06.c
 * Copyright (C) 2019 Ignacio Pérez Hurtado de Mendoza
 * http://www.cs.us.es/~ignacio
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h> // para numeros aleatorios 
#include <time.h> // para inicializacion de semilla aleatoria

// CONSTANTES
#define N 5

// TIPOS
typedef struct {
	double x;
	double y;
} PUNTO;

// CABECERA DE FUNCIONES

void sumaPunto(PUNTO* p1, PUNTO* p2); 

void sumaPuntos(PUNTO* p1, PUNTO* p2, int tam);

void imprimePunto(PUNTO* a);

int main()
{
	// lo siguiente es un array de memoria estatica, es decir, la dimension
	// del array se define en tiempo de compilacion y debe ser establecida
	// a priori por el programador, en este caso usamos la constante N
	// que tiene un valor 5. Recordad que las constantes en C tambien se
	// definen en tiempo de compilacion (no son variables).
	// De hecho, las constantes definidas con #define no son mas que
	// constantes simbolicas que se pasan al compilador.
	int arrayInt[N];  
	
	// es totalmente equivalente a escribir
	// int arrayInt[5];
	
	// para acceder a cada elemento del array se puede usar el operador []
	// El indice de un array comienza en 0
	
	
	for (int i=0; i<N; i++) {
		printf("Introduzca el valor de  arrayInt[%d]: ",i);
		scanf("%d",&arrayInt[i]);
	}
	
	// escribir arrayInt[i] devuelve el valor del elemento en la posicion i-esima
	// del array (comenzando en 0). Se puede tratar como una variable y obtener
	// su direccion de memoria con &
	
	int suma=0;
	for (int i=0;i<N;i++) {
		suma+=arrayInt[i];
	}
	
	double media = (double)suma / (double)N; // atentos al casting
	
	printf("La media es: %lf\n",media);
 	
	// La memoria esta alineada, es decir:
	// la direccion de array[0] es D0
	// la direccion de array[1] es D0 + sizeof(int)
	// la direccion de array[2] es D0 + 2*sizeof(int)
	// etc
	
	for (int i=0;i<N;i++) {
		printf("El valor de arrayInt[%d] es %d y su direccion es %p\n",i,arrayInt[i],&arrayInt[i]);
	}
	printf("\n");
	short arrayShort[N] = {1,2,3,4,5}; // tambien podemos definir un array de esta forma
	
	for (int i=0;i<N;i++) {
		printf("El valor de arrayShort[%d] es %d y su direccion es %p\n",i,arrayShort[i],&arrayShort[i]);
	}	
	
	// como la memoria esta alineada, podemos usar punteros para acceder a un array, para ello tomamos un puntero al inicio del array
	
	// int *pt = &arrayInt[0];
	
	// que se puede escribir directamente asi:
	
	int *pt = arrayInt;
	
	// ya que los arrays y los punteros para C son lo mismo
	
	printf("pt apunta al inicio del arrayInt en la direccion %p, el primer elemento del array es: %d\n",pt, *pt);
	
	// los operadores + y - se pueden usar con punteros, sin embargo no se realizara el incremento (o decremento) a nivel de bytes
	// sino a nivel del tamaño del tipo de dato contenido en el array
	
	pt += 2;
	
	// ahora pt apunta a arrayInt[2] (pero la direccion de memoria ha sido incrementada 8 bytes)
	// recordad que los indices comienzan en 0, asi que sera el tercer elemento
	printf("Ahora pt apunta al tercer elemento del arrayInt en la direccion %p, el valor es: %d\n",pt,*pt);
	
	// Podemos definir un array de estructuras
	
	PUNTO p1[N];
	
	PUNTO p2[N];
	
	// Vamos a usar numeros aleatorios, para ello inicializamos la semilla aleatoria segun el reloj de la CPU
	srand(time(NULL));
	
	for (int i=0;i<N;i++) {
		p1[i].x =  rand() % 16; // rand() obtiene un numero aleatorio entero en [0,RAND_MAX]. 
		//RAND_MAX depende del compilador, pero se garantiza que al menos vale 32767 
		p1[i].y =  rand() % 16;
		p2[i].x =  rand() % 16;
		p2[i].y =  rand() % 16;
		imprimePunto(&p1[i]);
		printf(" ");
		imprimePunto(&p2[i]);
		printf("\n");
	}
	
	// Vamos a pasar los dos arrays a una funcion para que los sume
	sumaPuntos(p1,p2,N);
	printf("\n");
	for (int i=0;i<N;i++) {
		imprimePunto(p1+i); // otra manera de generar punteros a los valores de un array
		printf("\n");
	}
	
	
	return 0;
}

// suma un punto con otro: p1+=p2;
void sumaPunto(PUNTO* p1, PUNTO* p2) {
	p1->x += p2->x;
	p1->y += p2->y;
}

// suma todos los puntos de dos arrays de puntos de tamaño tam
void sumaPuntos(PUNTO* p1, PUNTO* p2, int tam) {
	for (int i=0;i<tam;i++) {
		sumaPunto(p1+i, p2+i);
	}
	
	// tambien podria escribirse asi:
	//for (int i=0;i<tam;i++) {
	//	sumaPunto(&p1[i], &p2[i]);
	//}
		
}

void imprimePunto(PUNTO* a) {
	printf("(%lf,%lf)",a->x,a->y);
}
