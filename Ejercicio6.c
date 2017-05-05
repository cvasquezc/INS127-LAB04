//Lab 6 -  Ejercicio 6 - Programa para calcular la ocurrencia de una variable en una lista
#include <stdio.h>
#include <stdlib.h>
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
void recorrerLista(lista *listaR){
	nodo *aux;
	aux=listaR->ini;
	printf("La lista contiene los siguientes elementos \n");
	while(aux!=NULL){
		printf("\n%d",aux->valor);
		aux=aux->sgte;
	}
	free(aux);
}
int calcularOcurrencia(lista *listaO,int x,nodo *ptrO){
	int acum=0;
	if (ptrO!=NULL){
		acum=calcularOcurrencia(listaO,x,ptrO->sgte);
		if(x==ptrO->valor){
			acum++;
		}
		return acum;
	}else{
		return acum;
	}
}

int main(int argc, char const *argv[])
{
	lista *listaMain;
	int num;
	listaMain=crearLista();
	agregarNodo(listaMain,1);
	agregarNodo(listaMain,1);
	agregarNodo(listaMain,1);
	agregarNodo(listaMain,2);
	agregarNodo(listaMain,2);
	agregarNodo(listaMain,3);
	agregarNodo(listaMain,3);
	agregarNodo(listaMain,3);
	recorrerLista(listaMain);
	printf(" Ingresar  numero para calcular cuantas veces se repite en la lista: ");
	scanf("%d",&num);
	nodo *ptr=listaMain->ini;
	int cantidad=calcularOcurrencia(listaMain,num,ptr);
	printf("La cantidad de veces que se repite la variable %d es de: %d \n",num,cantidad);
	return 0;
}
