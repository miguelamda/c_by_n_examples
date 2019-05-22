/* 
 * C BY 8 EXAMPLES
 * example02.c
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


// En C cada variable se define con su tipo de datos.
// Una misma variable solo puede tomar valores de su tipo de datos.
// Se dice que C es debilmente tipado porque permite conversiones 
// implicitas entre variables de diferentes tipos. Pero cuidado...
// Se podría producir "overflow" si el tipo de la variable destino
// no tiene capacidad para almacenar el dato que se le pasa.


int main()
{
	char entero8bits = 'a'; // comillas simples para caracteres ASCII
	// 1 byte
	// -2^7 <= x <= 2^7-1
	// Se suele usar para almacenar ASCII
	
	short entero16bits = 1000;
	// 2 bytes
	// -2^15 <= x <= 2^15-1 
	
	int entero = -420000; // Las variables se pueden inicializar en su definición 
	// Es el tipo natural de tamaño una "palabra" de memoria.
	// 2 bytes o 4 bytes, según la máquina.
	// -2^15 <= x <= 2^15-1 (si son 2 bytes)
	// -2^31 <= x <= 2^31-1 (si son 4 bytes)
	
	
	long entero64bits = 123456789123456789L; // Postfijo "L" o "l" para constante long
	// Dos palabras, por lo tanto puede ser 4 u 8 bytes
	// -2^31 <= x <= 2^31-1 (si son 4 bytes)
	// -2^61 <= x <= 2^61-1 (si son 4 bytes)
	
	
	// Con el prefijo unsigned, tenemos numeros positivos
	// y ganamos rango
	
	unsigned char enteroPositivo8bits = 0xAA ; // Podemos escribir un literal numerico en hexadecimal con el prefijo 0x
	unsigned short enteroPositivo16bits = 0xAABB;
	unsigned int enteroPositivo = 0xAABBCCDD; // o simplemente "unsigned"
	unsigned long enteroPositivo64bits = 0x1122334455667788;
	// Que rango tienen?
	
	// Los numeros reales se representan con el formato 
	// IEEE 754 de coma flotante. 	
	
	float realSimplePrecision = 3.1416f; // 1 palabra. Un literal real tiene es postfijo "f" o "F" para entenderlo como float  
	double realDoblePrecision = 3.14159265358979323846L; // 2 palabras. Postfijo "l" o "L" para constante double.
	
	// No hay un tipo para los booleanos, se usan valores enteros
	// en expresiones logicas, interpretando 0 como FALSO y cualquier
	// otro valor como CIERTO.
	
	// Para imprimir, la funcion printf recibe formato:
	// %d ó %i 	entero en base 10 con signo (int)
	// %u 	entero en base 10 sin signo (int)
	// %o 	entero en base 8 sin signo (int)
	// %x 	entero en base 16, letras en minúscula (int)
	// %X 	entero en base 16, letras en mayúscula (int)
	// %f 	Coma flotante decimal de precisión simple (float)
	// %lf 	Coma flotante decimal de precisión doble (double)
	// %e 	La notación científica (mantisa / exponente), minúsculas (decimal precisión simple ó doble)
	// %E 	La notación científica (mantisa / exponente), mayúsculas (decimal precisión simple ó doble)
	// %c 	caracter (char)
	// %s 	cadena de caracteres (string) 
	
	printf("enteros: %d, %d, %d, %ld\n", entero8bits, entero16bits, entero, entero64bits); // ojo a %ld para long
	
	// interpretar como ASCII
	
	printf("caracter ASCII: %c\n", entero8bits);
	
	
	printf("Enteros positivos : %u, %u, %u, %lu\n",enteroPositivo8bits,enteroPositivo16bits,enteroPositivo,enteroPositivo64bits);
	// en hexadecimal	
	printf("Enteros positivos en hexadecimal: %x, %x, %x, %lx\n",enteroPositivo8bits,enteroPositivo16bits,enteroPositivo,enteroPositivo64bits);
	
	printf("Enteros positivos en hexadecimal con mayusculas: %X, %X, %X, %lX\n",enteroPositivo8bits,enteroPositivo16bits,enteroPositivo,enteroPositivo64bits);
	printf("reales: %f %lf\n", realSimplePrecision, realDoblePrecision);
	
	// Podemos indicar cuantos digitos enteros y decimales colocar
	printf("Numero PI: %1.20lf\n",realDoblePrecision);
	
	
	printf("Esto es una cadena de texto: %s\n", "HOLA");
	
	realDoblePrecision = -1e-5; // la notacion cientifica tambien esta permitida
	
	printf("real doble precision: %lf\n",realDoblePrecision);
	
	// printf tiene muchas otras posibilidades, se recomienda mirar la documentacion
	
	// podemos usar sizeof para saber el tamaño del tipo de una variable en bytes
	printf("Tamaño de un entero: %lu\n",sizeof(entero));
	printf("Tamaño de un real de doble precision: %lu\n",sizeof(realDoblePrecision));
	
	// también sirve pasando el tipo 
	printf("Tamaño de un entero: %lu\n",sizeof(int));
	printf("Tamaño de un real de doble precision: %lu\n",sizeof(double));
	
	

	
	// Expresiones aritmetico-logicas:
	int x = 10;
	int y = 2;
	
	// cambiar de signo
	// Suma, resta, multiplicacion, division
	y = -(x+5)*y-23/(x+1);
	
	// Modulo, comparación (y con un bonus de un if-else)
	if (y%2 == 0) {
		printf("El numero %d es par\n",y);
	} else {
		printf("El numero %d es impar\n",y);
	}
	
	// Operaciones con numeros enteros devuelve numeros enteros
	// Operaciones con numeros reales devuelve numeros reales
	// Operaciones con numeros enteros y reales... que tal si programamos bien... que esto no es python...
	// pero devuelven numeros reales
	double a = 23.45;
	double b = a/x;
	printf("Division entre real y entero: %lf\n",b);
	
	// Si vamos a hacer operaciones con distintos tipos de datos, mejor usar casting
	// Mas correcto:
	double b1 = a/(double)x;
	
	printf("Division entre real y entero: %lf\n",b1);
	
	
	// Operaciones logicas (y la operacion ternaria c ? a: b)
	
	int c1 = 0;  // FALSE
	int c2 = 1;  // TRUE
	
	int c1andc2 = c1 && c2;
	
	printf("%s AND %s = %s\n", c1 ? "TRUE":"FALSE", c2 ? "TRUE":"FALSE", c1andc2 ? "TRUE":"FALSE");
	
	
	int c1orc2 = c1 || c2;
	
	printf("%s OR %s = %s\n", c1 ? "TRUE":"FALSE", c2 ? "TRUE":"FALSE", c1orc2 ? "TRUE":"FALSE");
	
	int notc1 = !c1;
	
	printf("NOT %s = %s\n", c1 ? "TRUE":"FALSE", notc1 ? "TRUE":"FALSE");
	
	
	// comparaciones
	
	// a == b
	// a > b
	// a < b
	// a >= b
	// a <= b
	
	// operaciones a nivel de bit
	
	// not logico
	int a1 = 0x00;
	
	printf("NOT LOGICO de %08X = %08X\n", a1, ~a1); 
	// La sintaxis %08X significa que se 
	// representara un numero hexadecimal con 8 ceros a la izquierda
	
	
	// and logico
	a1 = 0xFF000000;
	int a2 = 0x11223344;
	printf("AND LOGICO de %08X y %08X = %08X\n",a1,a2, a1 & a2);
	
	// or logico
		
	printf("OR LOGICO de %08X y %08X = %08X\n",a1,a2, a1 | a2);
	
	// xor logico
	a1 = 0xFF00FFFF;
	a2 = 0x00FF00FF;
	
	printf("XOR LOGICO de %08X y %08X = %08X\n",a1,a2, a1 ^ a2);	
	
	// operaciones de desplazamiento de bits

	printf("%08X desplazado 4 bits a la izquierda: %08X\n",a1, a1 << 4);
	printf("%08X desplazado 4 bits a la derecha (con signo): %08X\n",a1, a1 >> 4);
	
	unsigned a3 = 0xFFFFFFFF;
		
	printf("%08X desplazado 4 bits a la derecha (sin signo): %08X\n",a3, a3 >> 4);	
	// OJO CON LA PRECEDENCIA DE OPERADORES, TODAS LAS EXPRESIONES ARITMETICO-LOGICAS SE PUEDEN AGRUPAR
	// Mirar la documentación para conocer la precedencia, en caso de dudas, usar paréntesis
	
	return 0;
}
