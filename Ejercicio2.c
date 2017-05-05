// Lab 4 - Ejercicio 2 - Programa para multiplicar dos numeros ocupando sumas

#include <stdio.h>

int multiplicarConSuma(int a, int b){
		int product=0;
		if (a>0){
			product=multiplicarConSuma(a-1,b);
			product=product+b;
		return product;
	}else
	{
		return product;
	}
}
int main(int argc, char const *argv[])
{
	int numA,numB,producto;
	printf("Ingrese un numero: \n");
	scanf("%d",&numA);
	printf("Ingrese un segundo numero: \n");
	scanf("%d",&numB);
	producto = multiplicarConSuma(numA,numB);
	printf("El producto de los numeros %d y %d es = %d \n",numA,numB,producto);
	return 0;
}