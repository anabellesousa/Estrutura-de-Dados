#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct Node {
    double  value;
    struct Node *next;
};


void Add (struct Node** node, double value)
     
     if(!(*node)){
        *node = (struct Node*) malloc (sizeof(struct Node));
         (*node)->value = value;
         (*node)->next = NULL;
       
     }
     else{
        struct Node* aux = *node;
        while ( aux->next ){
            aux = aux->next;
        }
        
        aux->next = ( struct Node* ) malloc ( sizeof( struct Node ) );
        aux->next->value = value;
        aux->next->next = NULL;
      }
}

int Tamanho (struct Node** node){   
    int i = 0;
    struct Node* aux = *node;
    while ( aux ){
        i++;
        aux = aux->next;
    }
    return i;

    
}

void PrintList(struct Node** node){  
    struct Node* aux = *node;
        
        while ( aux ){
            printf("%f\n", aux->value);
            aux = aux->next;
        }
        
}

void Uniao(struct Node** n1, struct Node** n2){
    struct Node* aux = *n1;
        while ( aux->next ){
            aux = aux->next;
        }
        aux->next = *n2;
    
}
void Add2 (struct Node** node, double value1, double value2){
    Add(node, value1);
    Add(node, value2);
}

bool Find (struct Node** node, double value){
    struct Node* aux = *node;
    while ( aux ){
        if(aux->value == value){
            return true;
        } 
        aux = aux->next;
        
    }
    return false;
   
}

void Remove (struct Node** node, double value){
    struct Node* aux = *node;
    struct Node* aux2 = NULL;
    
    while ( aux && aux->value != value){
       aux2 = aux;
       aux = aux->next;
    }

    if(aux){
        if(aux2 == NULL){
            aux2 = *node;
            *node = aux->next;
            free(aux2);
            
        }else{
            aux2->next = aux->next;
             free(aux);     
        }
       
    }else{
        printf("Elemento a ser removido não foi encontrado\n");
    }
       
}

bool TestaVazio(struct Node** node){
    if(!(*node)){
        return true;
    }else{
        return false;
    }
}

int main(void){

    struct Node* n1 = NULL;
    struct Node* n2 = NULL;
    struct Node* n3 = NULL;
    
    
     Add(&n1, 55.65);


    Add(&n1, 85.10);
    printf("Lista 1:\n");
    PrintList(&n1);
    printf("Tamanho da lista 1: %d\n", Tamanho(&n1));

    
    
    n2 = (struct Node*) malloc (sizeof(struct Node));
    n2->value = 1.00;



    Add(&n2, 3.10);
    Add(&n2, 4.10);
     printf("Lista 2:\n");
    PrintList(&n2);
    printf("Tamanho da lista 2: %d\n", Tamanho(&n2));

    printf("Unindo lista 2 a lista 1:\n");
    Uniao(&n1, &n2);
    PrintList(&n1);

    printf("Adicionando dois novos valores:\n");
    Add2(&n1, 29.00, 08.00);
    PrintList(&n1);

    printf("A lista 1 tem o número 10.00?: %s\n", Find(&n1, 10.00) ? "True" : "False" );
    printf("Eliminando o ultimo elemento, o primeiro, e um do meio(3.1)\n");
     Remove(&n1, 08.00);
     Remove(&n1, 55.65);
     Remove(&n1, 3.10);
    PrintList(&n1);
    printf("Lista 2 esta vaiza?: %s\n", TestaVazio(&n2) ? "True" : "False");
    printf("Lista 3 esta vaiza?: %s\n", TestaVazio(&n3) ? "True" : "False");


    return 0;
}
