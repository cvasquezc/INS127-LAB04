//Lab 4 - Ejercicio 9 - Programa para indicar si las listas ingresadas son iguales

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Nodo{
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
bool sonIguales(lista *listaA, lista *listaB,nodo *auxA,nodo *auxB){
	if (auxA!=NULL){
		if(sonIguales(listaA,listaB,auxA->sgte,auxB->sgte)){
			if (auxA->valor==auxB->valor){
				return true;
			}else{
				return false;
			}
		}		
	}
}
int main(int argc, char const *argv[]){
	lista *listaMainA,*listaMainB;
	int num,i,valor;
	listaMainA=crearLista();
	listaMainB=crearLista();
	
	printf("Cuantos elementos desea agregar a cada lista: \n");
	scanf("%d",&num);
	for (i=0;i<num;i++){
		printf("Ingrese el elemento %d a la lista 1: \n",i+1);
		scanf("%d",&valor);
		agregarNodo(listaMainA,valor);
	}
	for (i=0;i<num;i++){
		printf("Ingrese el elemento %d a la lista 2: \n",i+1);
		scanf("%d",&valor);
		agregarNodo(listaMainB,valor);
	}
	nodo *ptrA=listaMainA->ini;
	nodo *ptrB=listaMainB->ini;
	if (sonIguales(listaMainA,listaMainB,ptrA,ptrB)){
		printf("Verdadero \n");
	}else{
		printf("Falso \n");
	}
	return 0;
}