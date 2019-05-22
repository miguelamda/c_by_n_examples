/* 
 * C BY 8 EXAMPLES
 * example03.c
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


#include <stdio.h>
#include <math.h> 
// para funciones matematicas. Debemos compilar con la opcion -lm
// por ejemplo:
// gcc ejemplo03.c -o ejemplo03 -lm


// Podemos renombrar tipos con typedef
// sintaxis:
// typedef <tipo_antiguo> <tipo_nuevo>

// El tipo antiguo se puede seguir usando y se crea el tipo nuevo
// como un alias del antiguo.

typedef int ENTERO;


// Podemos definir variables globales, aunque ya sabemos que no es nada
// recomendable...

ENTERO variableGlobal = 42;


// podemos definir funciones
// sintaxis:
// tipo_devuelto nombre_funcion(argumento1, ..., argumentoN)
// {
//	... codigo...
// }

ENTERO suma(ENTERO a, ENTERO b)
{
	ENTERO s = a + b;
	return s;
}

// Podemos definir estructuras, que son agrupaciones de datos

typedef struct
{
	double x;
	double y;
} PUNTO;

// Si una funcion no devuelve nada, su tipo es void
void imprimePunto(PUNTO a) 
{
	printf("(%lf,%lf)",a.x,a.y);
}

double distanciaEuclidea(PUNTO a, PUNTO b)
{
	double d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	// sqrt(x) devuelve la raiz cuadrada de x
	// para acceder a un campo de una estructura usamos el operador .
	return d;
}

// La recursividad es posible, aunque no recomendable si lo que buscamos es eficiencia

unsigned factorialRec(unsigned n)
{
	if (n==0) {
		return 1;
	} else {
		return n*factorialRec(n-1); 
	}
}

// Mejor un esquema iterativo, vamos a ver el la sintaxis de while
// while (condicion)
// {
//   cuerpo
// }

unsigned factorialIt1(unsigned n)
{
	unsigned factorial = 1;
	while(n>0) {
		factorial *= n; // Equivalente a    factorial = factorial * n;
		n--;  // Equivalente a   n = n-1;
	}
	return factorial;
}

// Ahora con bucle for
// for (inicializacion; condicion; incremento) 
// {
//   cuerpo
// }

// Equivale a:
// inicializacion
// while(condicion)
// {
//   cuerpo
//   incremento
// }

unsigned factorialIt2(unsigned n)
{
	unsigned factorial = 1;
	for (unsigned i = 2; i<=n; i++) {
		factorial *= i;
	}
	return factorial;
}


int esPar(int x) {
	printf("entra en la funcion esPar(x)\n");
	return x%2 == 0;
}

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
	
	double d = distanciaEuclidea(u,v);
	printf("Distancia entre u y v: %lf\n",d);
	
	unsigned x = 6;
	
	printf("El factorial de %d es %d\n",x,factorialRec(x));
	printf("El factorial de %d es %d\n",x,factorialIt1(x));
	printf("El factorial de %d es %d\n",x,factorialIt2(x));
	
	// Los operadores && y || tienen evaluacion perezosa
	
	int a = 24;
	
	if (a>20 || esPar(a)) {
		printf("el numero %d es mayor de 20 o par\n",a);
	}
	
	if (esPar(a) || a>20) {
		printf("el numero %d es mayor de 20 y par\n",a);
	}	
	
	if (a<20 && esPar(x)) {
		printf("El numero %d es menor de 20 y par\n",a);
	} else {
		printf("El numero %d no es menor de 20 y par\n",a);
	}
	
	if (esPar(x) && a<20) {
		printf("El numero %d es menor de 20 y par\n",a);
	} else {
		printf("El numero %d no es menor de 20 y par\n",a);
	}
	
	

	
	
	return 0;
}
