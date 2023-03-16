#include<stdio.h>
#include <stdlib.h>
#include<limits.h>

struct nodo {
    int data;
    struct nodo* sig ;
};

struct cola {
    struct  nodo  *primero, *ultimo;
};

struct  nodo *crearNodo (int  data){
    struct nodo * nuevo =  (struct nodo*) malloc( sizeof (struct  nodo ));

    nuevo->data = data;
    nuevo->sig  = NULL;
    return nuevo;
};

struct cola  * crearCola(){
    struct cola * c = (struct cola*)  malloc (sizeof (struct cola));
    c ->primero = c->ultimo=NULL;
    return  c;
};

void  enQueue ( int data, struct cola** c ){

    struct nodo* nuevo =  crearNodo(data);
    if((*c )->primero == NULL){
        (*c )->primero = (*c )->ultimo = nuevo;
    return;
    };

    //si la cola no esta vacia
    (*c )->ultimo->sig = nuevo;
    (*c) ->ultimo= nuevo;
}


int  deQueue( struct cola ** c){
     if( (*c )->primero==NULL  )  return INT_MIN;

     //que ocurrre si la cola no esta vacia
     struct nodo *eliminado = (*c)->primero ;
      int data = eliminado->data;

      //eliminamos el nodo de la cola
      (*c) ->primero = eliminado->sig;

      if((*c)->primero==NULL){
        (*c)->ultimo = NULL;
      }

      free(eliminado);

      return data;
}

void mostrar ( struct cola ** c){
    if ( (*c )->primero==NULL) return ;

    //si no esta vacia
    printf("Primero %d \n  Ultimo : %d \n", (*c )->primero->data, (*c )->ultimo->data );


    struct nodo* actual  = (*c )->primero;

    while(actual){
        printf ("%d,  ", actual->data);
        actual = actual ->sig;
    }

    printf ("\n----------\n ");


}


int main (){
	int numero;
	printf ("Bienvenido al juego de bingo, ya se empezaran a sacar los numeros\n");
	printf ("Escoja los numeros que deseara jugar: (El primero tiene que ser un numero del 1 al 15, el siguiente del 16 al 30, luego 31 a 45,luego 46 a 60 y por ultimo del 61 al 75. Asi sucesivamente hasta crear 5 filas\n");
	
	int matriz[5][5],i,j,a,b,r,d,flag;
	
	for (i=0;i<5;i++){
		for (j=0;j<5;j++)
		{
			printf("numero:",i,j);
			scanf ("%d",&matriz[i][j]);
		}}
		
	printf ("B       I       N       G       O\n");
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			printf ("%d\t",matriz[i][j]);
		}
			printf ("\n");	
	}

	
    struct cola  * c = crearCola();
    
    enQueue(2, &c);
    enQueue(23, &c);
    enQueue(62, &c);
    enQueue(41, &c);

    mostrar( &c);

    for( int i = 0; i < 5 ; i++){
        printf("Eliminado %d \n", deQueue(&c));
        mostrar(&c);
    };

    return 0;
};
