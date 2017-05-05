//Lab 4 -  Ejercicio 1
//Programa para calcular el factorial de un numero

#include <stdio.h>

int calcularFactorial(int n){
	int fact=1;
	if(n>0){
		fact=calcularFactorial(n-1);
		fact=fact*n;
		return fact;
	}else{
		return fact;
	}
}
int main(int argc, char const *argv[])
{
	int num,factorial;
	printf("Ingrese un numero : \n");
	scanf("%d",&num);
	factorial=calcularFactorial(num);
	printf("El factorial de %d es: %d",num,factorial);
	return 0;
}