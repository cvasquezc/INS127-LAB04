//Lab 4 - Ejercicio 11 - Programa para eliminar un elemento de la lista
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
		printf("\nError, memoria no asignada");
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
	printf("La lista contiene los siguientes elementos: \n");
	while(aux!=NULL){
		printf("%d \n",aux->valor);
		aux=aux->sgte;
	}
	free(aux);
}
void EliminarX(lista *listaO,int x,nodo *ptrO){
	nodo *aux;
	if(x==ptrO->valor && listaO->ini==ptrO){  
		aux=ptrO;                             
		listaO->ini=aux->sgte;
		aux->sgte=NULL;
		listaO->tam--;
		free(aux);
	}else if (ptrO->sgte!=NULL){
		EliminarX(listaO,x,ptrO->sgte); 
		if(x==ptrO->sgte->valor){
			aux=ptrO->sgte;
			ptrO->sgte=ptrO->sgte->sgte;
			aux->sgte=NULL;
			listaO->tam--;
			free(aux);
		}
	}
}


int main(int argc, char const *argv[])
{
	lista *listaMain;
	int num;
	listaMain=crearLista();
	agregarNodo(listaMain,1);
	agregarNodo(listaMain,2);
	agregarNodo(listaMain,3);
	agregarNodo(listaMain,5);
	agregarNodo(listaMain,7);
	recorrerLista(listaMain);
	printf(" Ingrese una numero para eliminarlo: \n");
	scanf("%d",&num);
	nodo *ptr=listaMain->ini;
	EliminarX(listaMain,num,ptr);
	recorrerLista(listaMain);
	return 0;
}