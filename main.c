//
//  main.c
//  Listas Dinamicas
//
//  Created by Arturo Tamayo Gonzalez on 21/10/16.
//  Copyright © 2016 Arturo Tamayo Gonzalez. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
#include"listaDinamica.h"
#define SALIR 13

void mostrarMenu();
int seleccionarOpcion();
void ejecutarOpcion(Lista* miLista, int opcion);


int main(){
    Lista Milista;
    int opcion;
    
    Milista = lista_crearLista();
    do{
        mostrarMenu();
        opcion = seleccionarOpcion();
        ejecutarOpcion(&Milista, opcion);
    }
    while (opcion != SALIR);
}
void mostrarMenu(){
    printf("---Lista Dinamica---\n");
    printf("1.- Agregar dato\n");
    printf("2.- Imprimir lista\n");
    printf("3.- Insertar dato\n");
    printf("4.- Borrar dato\n");
    printf("5.- Borrar lista\n");
    printf("6.- Buscar dato\n");
    printf("7.- Buscar la posicion de un dato\n");
    printf("8.- Reemplazar dato\n");
    printf("9.- Siguiente dato\n");
    printf("10.- Dato anterior\n");
    printf("11.- Primer dato de la lista\n");
    printf("12.- Extraer pares de la lista\n");
    printf("%d .-SALIR\n", SALIR);
}

int seleccionarOpcion(){
    int opcion;
    printf("\tOpcion: ");
    scanf("%d", &opcion);
    getchar();
    
    return opcion;
}
void ejecutarOpcion (Lista* miLista, int opcion){
    Nodo* n;
    Nodo* m;
    //Lista l;
    int posicion;
    int datonuevo,dato;
    //l= lista_crearLista();
    
    switch (opcion) {
        case 1:
            n = malloc(sizeof(Nodo));
            printf("Dato a agregar: ");
            scanf("%d", &dato);
            *n = lista_crearNodo(dato);
            lista_agregar(miLista, n);
            break;
        case 2:
            lista_imprimir(* miLista);
            break;
        case 3:
            n = malloc(sizeof(Nodo));
            printf("Dato a insertar:  ");
            scanf("%d", &dato);
            *n = lista_crearNodo(dato);
            printf("Posicion en la que desea insertar el dato:  ");
            scanf("%d", &posicion);
            lista_insertar(miLista, n, posicion);
            break;
        case 4:
            printf("Posicion del dato que desea eliminar:  ");
            scanf("%d", &posicion);
            lista_borrar(miLista, posicion);
            break;
        case 5:
            lista_borrarTODO(miLista);
            break;
        case 6:
            printf("Posicion del dato que desea buscar: ");
            scanf("%d", &posicion);
            lista_buscarNodo(*miLista, posicion);
            break;
        case 7:
            n=malloc(sizeof(Nodo));
            printf("Dato que desea buscar:  ");
            scanf("%d", &dato);
            *n = lista_crearNodo(dato);
            lista_buscarPosicion(*miLista, dato);
            break;
        case 8:
            m=malloc(sizeof(Nodo));
            printf("Dato que deseas reemplazar: ");
            scanf("%d", &dato);
            printf("Dato nuevo: ");
            scanf("%d", &datonuevo);
            *m=lista_crearNodo(datonuevo);
            lista_Reemplazar(miLista, m, dato);
            break;
        case 9:
            printf("Dato del que quisieras saber el siguiente:  ");
            scanf("%d", &dato);
            lista_siguiente1(*miLista, dato);
            break;
        case 10:
            printf("Dato del que quisieras saber el anterior:  ");
            scanf("%d", &dato);
            lista_anterior(*miLista, dato);
            break;
        case 11:
            lista_MostrarPrimero(*miLista);
            break;
        case 12:
            lista_extraerPares(*miLista);
            break;
        case 13:
            break;
    }
}
 




