//Lab 4 - Ejercicio 8 - Programa para listar los elementos de una lista
#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo
{
	int valor;
	struct Nodo *sgte; 
}nodo;

typedef struct Lista{
	nodo *ini;
	nodo *fin;
	int tam;
}lista;

lista *crearLista(){
	lista *newlista;
	if (newlista=(lista*)malloc(sizeof(lista))){
		newlista->ini=NULL;
		newlista->fin=NULL;
		newlista->tam=0;
	}else{
		printf("Error, memoria no asignada \n");
	}
	return newlista;
	free(newlista);
}
void agregarNodo(lista *listaA,int num){
	nodo *newNodo;
	if(newNodo=(nodo*)malloc(sizeof(nodo))){
		newNodo->valor=num;
		if (listaA->tam==0){
			listaA->fin=newNodo;
			newNodo->sgte=NULL;
		}
		newNodo->sgte=listaA->ini;
		listaA->ini=newNodo;
		listaA->tam++;
	}

}
void listarLista(lista *listaO,nodo *ptrO){
	if(ptrO==listaO->ini){
		printf("Los elementos de la lista son \n");
	}
	if (ptrO!=NULL){
		printf("%d \n",ptrO->valor);
		listarLista(listaO,ptrO->sgte);
	}
}
int main(int argc, char const *argv[])
{
	lista *listaMain;
	listaMain=crearLista();
	agregarNodo(listaMain,1);
	agregarNodo(listaMain,2);
	agregarNodo(listaMain,3);
	agregarNodo(listaMain,4);
	agregarNodo(listaMain,5);
	nodo *ptr=listaMain->ini;
	listarLista(listaMain,ptr);
	return 0;
}