//
//  listaDinamica.h
//  Listas Dinamicas
//
//  Created by Arturo Tamayo Gonzalez on 21/10/16.
//  Copyright © 2016 Arturo Tamayo Gonzalez. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct MiNodo{
    int dato;
    struct MiNodo* siguiente;
};
typedef struct MiNodo Nodo;


struct MiLista{
    Nodo* cabeza;
};
typedef struct MiLista Lista;


//Crear Lista
Lista lista_crearLista (){
    Lista l;
    l.cabeza = malloc(sizeof(Nodo));
    l.cabeza= NULL;
    return l;
}

//Crear Nodo
Nodo lista_crearNodo(int dato){
    Nodo n;
    n.dato = dato;
    n.siguiente = malloc(sizeof(Nodo));
    n.siguiente= NULL;
    return n;
}

//Agregar
void lista_agregar(Lista* l, Nodo* n){
    if(l->cabeza == NULL)
        l->cabeza = n;
    else{
        Nodo* aux = l->cabeza;
        while(aux->siguiente != NULL)
        {
        aux = aux->siguiente;
        }
        aux->siguiente = n;
    }
}

//Imprimir
void lista_imprimir(Lista l){
    Nodo* aux = l.cabeza;
    printf("Datos en la lista\n");
    while(aux!= NULL){
        printf("%d\n", aux->dato);
        aux = aux->siguiente;
    }
}
//Borrar desde posicion
void lista_borrar(Lista* l, int p){
    int i;
    Nodo* aux;
    Nodo* aux2;
    aux = l->cabeza;
    for (i=0; i<p-1 && aux !=NULL; i++) {
        aux = aux->siguiente;
    }
    aux2 = aux->siguiente;
    if(aux2 != NULL){
    aux->siguiente = aux2->siguiente;
    }
    else{
        aux->siguiente = NULL;
    }
    free(aux2);
}

//Borrar toda la lista
void lista_borrarTODO(Lista* l){
    Nodo* aux= l->cabeza;
    while(aux!=NULL) {
        l->cabeza = aux->siguiente;
        free (aux);
        aux = l->cabeza;
    }
}

//Insertar
void lista_insertar(Lista* l, Nodo* n, int p){
    int i;
    Nodo* aux = l->cabeza;
    if(p==0){
        n->siguiente = aux;
        l->cabeza =n;
    }
    else {
    for (i=0; i<p-1; i++) {
        aux = aux->siguiente;
    }
    if(aux->siguiente != NULL){
        n->siguiente = aux->siguiente;
    }
    aux->siguiente = n;
    }
}
//Reemplazar
void lista_Reemplazar(Lista* l, Nodo* nuevodato, int dato){
    Nodo* aux =l->cabeza;
    while(aux!=NULL && aux->dato == dato){
        aux->dato = nuevodato->dato;
        aux = aux->siguiente;
    }
    }

//Mostrar el Siguiente
int lista_siguiente1(Lista l, int dato){
    Nodo* aux = l.cabeza;
    while(aux!=NULL && aux->dato == dato){
        aux = aux->siguiente;
        printf("El dato siguiente es %d\n", aux->dato);
        return aux->dato;
    }
    return -1;
}

//Mostrar el anterior
int lista_anterior(Lista l, int dato){
    Nodo* aux = l.cabeza;
    while(aux->siguiente && aux->siguiente->dato <= dato){
        printf("El dato anterior es: %d\n", aux->dato);
        aux = aux->siguiente;
    }
    return -1;
}
//Buscar el dato en la posicion dada dentro de una lista
Nodo lista_buscarNodo(Lista l, int p){
    int i;
    Nodo* aux = l.cabeza;
    for (i=0; i<p && aux!=NULL; i++){
        aux = aux->siguiente;
    }
    printf("EL dato encontrado es: %d\n", aux->dato);
    return *aux;
}
//Buscar posicion
int lista_buscarPosicion(Lista l, int dato){
    int i;
    Nodo* aux = l.cabeza;
    for(i=0; aux!=NULL && aux->dato !=dato; i++){
        aux = aux->siguiente;
    }
    printf("La posicion de tu dato es : %d\n",i);
    return (aux != NULL) ? i : -1;
    
    //caso verdadero : caso falso
    
}
//Mostrar el primer elemento de la lista
int lista_MostrarPrimero(Lista l){
    Nodo* aux = l.cabeza;
    printf("El primer elemento de la lista es: %d\n", aux->dato);
    return aux->dato;
}

//Crear una nueva lista con los elementos de L1 y L2
Lista lista_merge(Lista l1, Lista l2){
    Lista nueva;
    Nodo* nuevo;
    
    nueva = lista_crearLista();
    
    Nodo* aux = l1.cabeza;
    while (aux->siguiente !=NULL) {
        nuevo = malloc(sizeof(Nodo));
        *nuevo = lista_crearNodo(aux->dato);
        lista_agregar(&nueva ,nuevo);
        aux = aux->siguiente;
    }
    aux = l2.cabeza;
    while (aux->siguiente != NULL) {
        nuevo = malloc(sizeof(Nodo));
        *nuevo= lista_crearNodo(aux->dato);
        lista_agregar(&nueva, nuevo);
        aux= aux->siguiente;
    }
    return nueva;
}

//Extraer pares de una lista
Lista lista_extraerPares(Lista l) {
    Lista nueva;
    Nodo* nuevo;
    nueva = lista_crearLista();
    
    Nodo* aux = l.cabeza;
    while (aux != NULL) {
        if (aux->dato % 2 == 0) {
            nuevo = malloc(sizeof(Nodo));
            *nuevo = lista_crearNodo(aux->dato);
            lista_agregar(&nueva, nuevo);
        }
        aux = aux->siguiente;
    }
    lista_imprimir(nueva);
    return nueva;
}

















   

