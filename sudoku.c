#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  
  
  for (int i = 0; i < 9; i++){
    int fila_valida[10] = {0,0,0,0,0,0,0,0,0,0};
    for (int j = 0; j < 9; j++){
      if (fila_valida[n->sudo[i][j]]){
        return 0;
      }
      if ( fila_valida[n->sudo[i][j]] == 0 && n->sudo[i][j] != 0){
        fila_valida[n->sudo[i][j]] = 1;
      }
    }
    
  }

  for (int z = 0; z < 9; z++){
    int columnas_validas[10] = {0,0,0,0,0,0,0,0,0,0};

    for (int y = 0; y < 9; y++){
      if (columnas_validas[n->sudo[z][y]] != 0){
        return 0;
      }
      if (columnas_validas[n->sudo[z][y]] == 0 && n->sudo[z][y] != 0){
        columnas_validas[n->sudo[z][y]] = 1;
      }
    }
  }

  
  
  
  
  for (int x = 0; x < 9; x++){
    int subMatriz[10] = {0,0,0,0,0,0,0,0,0,0};
    int k = s, p;
    for(p=0;p<9;p++){
        int i=3*(k/3) + (p/3) ;
        int j=3*(k%3) + (p%3) ;

      if (subMatriz[n->sudo[i][j]] != 0){
        return 0;
      }
      if (subMatriz[n->sudo[i][j]] == 0 && n->sudo[i][j]){
        subMatriz[n->sudo[i][j]] = 1;
      }
    }
  }
  
  return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  int i, j, k;

  for (i = 0; i < 9; i++){
    for (j = 0; j < 9; j++){

      if (n->sudo[i][j] == 0){
        for ( k = 1; k < 10; k++){
          n->sudo[i][j] = k;
          if(is_valid(n)){
            Node* adj = copy(n);
            pushBack(list, adj);
          }
        }
        n->sudo[i][j] = 0;
        return list;
      }
    }
  }
  return list;
}


int is_final(Node* n){
  for (int i = 0; i < 9; i++){
    for (int  j = 0; j < 9; j++){
      if (n->sudo[i][j] == 0){
        return 0;
      }
    }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/
