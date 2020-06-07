/* 
 * C BY 8 EXAMPLES
 * example06.c: arrays estáticos, números aleatorios y aritmética de punteros
 * 
 * Copyright (C) 2019 Ignacio Pérez Hurtado de Mendoza
 * http://www.cs.us.es/~ignacio
 * Copyright (C) 2020 Miguel Ángel Martínez del Amor
 * http://www.cs.us.es/~mdelamor
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
#include <stdlib.h> // para números aleatorios 
#include <time.h> // para inicialización de semilla aleatoria

// CONSTANTES
#define N 5

// TIPOS
typedef struct {
	double x;
	double y;
} PUNTO;

int main()
{
	// Lo siguiente es un array de memoria estática, es decir, la dimensión
	// del array se define en tiempo de compilación y debe ser establecida
	// a priori por el programador. En este caso usamos la constante N
	// que tiene un valor 5. Recuerda que las constantes en C también se
	// definen en tiempo de compilación (no son variables).
	// De hecho, las constantes definidas con #define no son más que
	// constantes simbólicas que se pasan al compilador.
	
	int arrayInt[N];  
	
	// es totalmente equivalente a escribir
	// int arrayInt[5];
	
	// El acceso a cada elemento del array se puede hacer con el operador []
	// El índice de un array comienza en 0
	
	for (int i=0; i<N; i++) { 
		printf("Introduzca el valor de  arrayInt[%d]: ",i);
		scanf("%d",&arrayInt[i]);
	}

	// Fíjate que en el bucle for anterior, hemos definido la variable i dentro del 
	// bucle. Esto es posible desde C++, y también ya en C. Esta variable solo existe
	// dentro del bucle for, pero no fuera.
	
	// Escribir arrayInt[i] devuelve el valor del elemento en la posición i-ésima
	// del array (comenzando en 0). 
	
	int suma=0;
	for (int i=0;i<N;i++) {
		suma+=arrayInt[i];
	}
	
	double media = (double)suma / (double)N; // atento al casting (cambio de tipo)
	
	printf("La media es: %lf\n",media);
 	
	// El acceso a una posición en un array se puede tratar como una variable, y se puede obtener
	// su dirección de memoria con &

	// Recuerda, la memoria está alineada, es decir:
	// la dirección de array[0] es D0
	// la dirección de array[1] es D0 + sizeof(int)
	// la dirección de array[2] es D0 + 2*sizeof(int)
	// etc
	
	// verás que hemos simplificado el acceso a puntero: "&arrayInt[i]" equivale a "arrayInt + i"
	for (int i=0;i<N;i++)
		printf("El valor de arrayInt[%d] es %d y su direccion es %p\n",i,arrayInt[i],arrayInt + i);
	printf("\n");

	// Por cierto, una cadena de texto es un array de char (es decir, char *). El final de una cadena
	// se marca con el carácter especial '\0', que nunca se imprime. Esto equivale a usar comillas, lo 
	// cual genera un array automáticamente dentro del ámbito de la función.
	char cadena[N] = {'h','o','l','a','\0'}; 
	char *cadena2 = "que tal?";
	
	printf("La cadena es: %s, %s\n",cadena,cadena2);
		
	// Podemos definir un array de estructuras
	
	PUNTO p1[N];
	
	// Vamos a usar números aleatorios, para ello inicializamos la semilla aleatoria según el reloj de la CPU
	srand(time(NULL));
	
	for (int i=0;i<N;i++) {
		p1[i].x =  rand() % 16; // rand() obtiene un numero aleatorio entero en [0,RAND_MAX]. 
								//RAND_MAX depende del compilador, pero se garantiza que al menos vale 32767 
		p1[i].y =  rand() % 16;
		printf("p1.x=%d; p2.y=%d\n",p1[i].x,p1[i].y);
	}
	
	return 0;
}
