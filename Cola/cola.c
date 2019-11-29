#include "cola.h"

void inicializacion(struct ColaId *cola){
     cola->inicio = NULL;
     cola->fin = NULL;
     cola->tamano = 0;
}

int ins_cola_vacia(struct ColaId *cola, int dato){
if(cola->tamano == 0){
      struct ElementoCola *nuevo_elemento;
      if((nuevo_elemento=(struct ElementoCola *)malloc(sizeof(struct ElementoCola)))==NULL)
         return -1;
      nuevo_elemento->dato = dato;
      nuevo_elemento->siguiente = cola->fin;
      cola->inicio = nuevo_elemento;
      cola->fin = nuevo_elemento;
      cola->tamano++;
      return 0;

    }
    else
    printf("La cola esta vacia\n");

}

int ins_cola(struct ColaId *cola, int dato){
struct ElementoCola *nuevo_elemento;
    if((nuevo_elemento = (struct ElementoCola *)malloc(sizeof(struct ElementoCola))) == NULL)
      return -1;
    nuevo_elemento->dato = dato;
    nuevo_elemento->siguiente = NULL;
    cola->fin->siguiente = nuevo_elemento;
    cola->fin = nuevo_elemento;
    cola->tamano++;
    return 0;
}

void visualizar(struct ColaId *cola){
     struct ElementoCola *actual;
     actual = cola->inicio;
     while(actual!=NULL){
          printf("%d ",actual->dato);
          actual = actual->siguiente;
     }
     printf("\n");
}

int eliminar(struct ColaId *cola){
      struct ElementoCola *sup_elemento, *actual, *aux;
    if(cola->tamano == 0)
    return -1;
    sup_elemento=cola->inicio;
    cola->inicio = cola->inicio->siguiente;
    if(cola->inicio==NULL)
    cola->fin=NULL;
     free(sup_elemento);
     cola->tamano--;
     return 0;
}


