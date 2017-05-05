//Lab 4 - Ejercicio 3 -  Programa para sumar los numeros dentro de un arreglo

#include <stdio.h>
#include <stdlib.h>

int *crearArreglo(int l){
	int *array;
	array=(int*)malloc(l*sizeof(int));
	return array;
}
int *agregarElementos(int *array,int largo){
	int i,num;
	for (i=0;i<largo;i++){
		printf("Ingrese el elemento %d al arreglo: ",i+1);
		scanf("%d",&num);
		array[i]=num;
	}
	return array;
}
int sumarArreglo(int *arreglo,int largo){
	int acum=0;
	if(largo!=0){
		acum=sumarArreglo(arreglo,largo-1);
		acum=acum+arreglo[largo-1];
		return acum;
	}else{
		return acum;
	}
}
int main(int argc, char const *argv[])
{
	int *arreglo;
	int largo,suma;
	printf("Ingrese cantidad de elementos del arreglo: \n");
	scanf("%d",&largo);
	arreglo=crearArreglo(largo);
	arreglo=agregarElementos(arreglo,largo);
	suma=sumarArreglo(arreglo,largo);
	printf("La suma de los elementos del arreglo da como resultado : %d",suma);
	return 0;
}