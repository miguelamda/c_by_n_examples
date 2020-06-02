/* 
 * C++ BY 8 EXAMPLES
 * example04.c: estructura de un fichero C, y cabeceras (.h)
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

// Los programas en C suelen tener la siguiente estructura:

////////////////////// COMIENZO CABECERA
// BIBLIOTECAS
// incluir todas las bibliotecas necesarias

// CONSTANTES
// definir todas las constantes

// TIPOS
// definicion de tipos propios y estructuras

// CABECERA DE FUNCIONES
// Se incluye la cabecera de las funciones a utilizar, de esa forma se podrán
// usar en cualquier parte del programa. Si no, solo se pueden usar las funciones
// que se hayan definido arriba en el fichero.
////////////////////// FIN CABECERA

// VARIABLES GLOBALES

// FUNCION MAIN

// RESTO DE FUNCIONES

// Para exportar funciones, tipos abstractos de datos, etc, se hace uso de cabeceras.
// La cabecera se suele escribir en ficheros con extension .h y el codigo de las
// funciones en ficheros con extension .c
// En este mini-curso, por sencillez, vamos a escribir todo en los ficheros .c
// lo cual tambien es posible, pero vamos a respetar la estructura anterior.

////////////////////// COMIENZO CABECERA

// BIBLIOTECAS
#include <stdio.h>
#include <math.h>

// CONSTANTES
#define PI 3.14159265358979323846L

// TIPOS
typedef int ENTERO;

typedef struct {
	double x;
	double y;
} PUNTO;

// CABECERA DE FUNCIONES
double distanciaEuclidea(PUNTO a, PUNTO b);
PUNTO puntoMedio(PUNTO a,PUNTO b);
void imprimePunto(PUNTO a);

// VARIABLES GLOBALES
PUNTO CERO = {0.0,0.0};

////////////////////// FIN CABECERA


// FUNCION MAIN
int main()
{
	PUNTO u;
	u.x = 10.4;
	u.y = -23.4;
	
	PUNTO v;
	
	v.x = 0;
	v.y = 6.4;
	printf("Punto u: ");
	imprimePunto(u);
	printf("\n");
	printf("Punto v: ");
	imprimePunto(v);
	printf("\n");
	printf("Distancia entre u y v: %lf\n",distanciaEuclidea(u,v));
	PUNTO w = puntoMedio(u,v);
	
	printf("Punto medio entre u y v: ");
	imprimePunto(w);
	
	printf("\n");
	return 0;
}

// RESTO DE FUNCIONES (quedaron pendientes de definir...)
double distanciaEuclidea(PUNTO a, PUNTO b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

PUNTO puntoMedio(PUNTO a, PUNTO b)
{
	PUNTO pm;
	pm.x = (a.x + b.x) * 0.5;  // Tip: multiplicar es mas eficiente que dividir
	pm.y = (a.y + b.y) * 0.5;
	return pm;
}

void imprimePunto(PUNTO a) 
{
	printf("(%lf,%lf)",a.x,a.y);
}
