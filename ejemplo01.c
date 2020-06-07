/* 
 * C BY 8 EXAMPLES
 * example01.c: hola mundo
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
 //------------------------------------------------------------------
/*
 * C es un lenguaje de programación de propósito general 
 * desarrollado por Dennis M. Ritchie en los Laboratorios Bell
 * entre 1969 y 1972.
 * 
 * Quizás el libro de referencia por excelencia sea el manual
 * escrito por el propio creador de C:
 * 
 * C Programming Language (Prentice Hall Software)
 * Brian W. Kernighan, Dennis M. Ritchie.
 * 
 * Originalmente C fue concebido para el desarrollo de Sistemas
 * Operativos, concretamente Unix.
 * 
 * C es muy apreciado por la eficiencia del código que produce
 * y es un lenguaje muy popular para crear software de sistemas.
 * 
 * C dispone de las estructuras típicas de los lenguajes de alto
 * nivel, pero a la vez permite un control a muy bajo nivel.
 * 
 * C no es un lenguaje interpretado como Python o R. Es necesario 
 * utilizar una herramienta para compilar y enlazar los programas,
 * produciendo código máquina para el hardware objetivo.
 * 
 * Utilizaremos la herramienta gcc bajo entorno GNU/Linux 
 * en este mini-curso. Se puede compilar cada ejemplo de la 
 * siguiente forma:
 * 
 * gcc ejemploXX.c -o ejemploXX
 * 
 * Lo cual generará un ejecutable llamado ejemploXX
 * 
 * La herramienta gcc es muy completa y tiene una gran cantidad
 * de opciones que exceden el alcance de este curso, se recomienda
 * mirar la documentación:
 * 
 * https://gcc.gnu.org/ 
 */
 //------------------------------------------------------------------
 
 /* Vamos con lo básico, esto de aquí es un comentario de texto */
 
 // Esto también, pero tiene que acabar en un salto de línea
 // Si quiero empezar otra linea, tengo que poner los símbolos de nuevo
 
 // Para incluir bibliotecas se utiliza la instrucción #include
 #include <stdio.h> // stdio es la biblioteca para la entrada/salida estándar
 
 // Todo programa C tiene una función principal llamada main
 // El formato de cualquier función es
 // <tipo_de_retorno> nombre_funcion(args...)
 // {
 //   cuerpo funcion
 // }
  
 int main()
 {
	 // printf es la función para imprimir por pantalla.
	 // veremos más opciones en adelante.
	 printf("QUIERO SABER MÁS DE C!!!\n");
	 printf("Por cierto: Hola Mundo...\n");
	 // \n es el caracter especial de salto de linea.
	 return 0; 
	 /* La función main devuelve un valor entero, habitualmente
	  * se interpreta como el código de retorno del programa.
	  * Devolver 0 en el main significa que todo fue bien. */
}
 