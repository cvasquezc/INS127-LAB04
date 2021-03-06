//Lab 4 - Ejercicio 7 - Programa para sumar los elementos de una lista
#include <stdio.h>
#include <stdlib.h>
	typedef struct Nodo
	{
		int valor;
		struct Nodo *sgte; 
	}nodo;
	
	typedef struct Lista
	{
		nodo *ini;
		nodo *fin;
		int tam;
	}lista;
	
	lista *crearLista()
	{
		lista *newlista;
			if (newlista=(lista*)malloc(sizeof(lista))){
				newlista->ini=NULL;
				newlista->fin=NULL;
				newlista->tam=0;
			}else
			{
				printf("Error, memoria no asignada \n");
			}
	return newlista;
	free(newlista);
	}
void agregarNodo(lista *listaA,int num)
{
	nodo *newNodo;
	if(newNodo=(nodo*)malloc(sizeof(nodo))){
			newNodo->valor=num;
		if (listaA->tam==0)
		{
			listaA->fin=newNodo;
			newNodo->sgte=NULL;
		}
		newNodo->sgte=listaA->ini;
		listaA->ini=newNodo;
		listaA->tam++;
	}

}
void recorrerLista(lista *listaR)
{
	nodo *aux;
	aux=listaR->ini;
	printf("La lista contiene los siguientes elementos \n");
	while(aux!=NULL){
		printf("%d \n",aux->valor);
		aux=aux->sgte;
	}
	free(aux);
}
int sumarLista(lista *listaO,nodo *ptrO)
{
	int acum=0;
	if (ptrO!=NULL){
		acum=sumarLista(listaO,ptrO->sgte);
		acum=acum+ptrO->valor;
		return acum;
	}else
	{
		return acum;
	}
}

int main(int argc, char const *argv[])
{
	lista *listaMain;
	listaMain=crearLista();
	agregarNodo(listaMain,2);
	agregarNodo(listaMain,4);
	agregarNodo(listaMain,6);
	agregarNodo(listaMain,8);
	agregarNodo(listaMain,10);
	recorrerLista(listaMain);
	nodo *ptr=listaMain->ini;
	int suma=sumarLista(listaMain,ptr);
	printf("La suma de los elementos de la lista es: %d \n",suma);
	return 0;
}
