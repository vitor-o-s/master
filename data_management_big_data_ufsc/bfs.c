#include<stdlib.h>
#include<stdio.h>

#define MAX 100

typedef struct Queue {
  int items[MAX];
  int front;
  int rear;
} Queue;

typedef struct Edge{
  int value;
  struct Edge* next;
}edge;

typedef struct Node{
  int value;
  struct edge* edge_next;
  struct Node* next;
}node;

typedef struct list{
  node* head;
  int n_vertex;
}List;

void initQueue(Queue* q) {
  q->front = -1;
  q->rear = -1;
}

int isEmpty(Queue* q) {
  if (q->rear == -1) return 1;
  return 0;
}

void enqueue(Queue* q, int value) {
  if (q->rear == MAX - 1) return; // Queue is full
  if (q->front == -1) {
    q->front = 0;
  }
  q->rear++;
  q->items[q->rear] = value;
}

int dequeue(Queue* q) {
  if (isEmpty(q)) return -1; // Queue is empty

  int item = q->items[q->front];
  q->front++;
  if (q->front > q->rear) {
    q->front = q->rear = -1;
  }
  return item;
}


void inicializa(List* l){
  l->head = NULL;
}

node * create_node(int value){
  node *new;
  new = (node *) malloc (sizeof(node));
  if(new == NULL) return NULL;
  new->value = value;
  new->edge_next = NULL;
  new->next = NULL;
  return new;
}

edge * create_edge(int value){
  edge *new;
  new = (edge *) malloc (sizeof(edge));
  if(new == NULL) return NULL;
  new->value = value;
  new->next = NULL;
  return new;
}

int isvoid(List*l){
  //Verifica se lista está vazia para fins de add
  //Retorna 0 se vazia e 1 se contem elementos
  if (l->head == NULL) return 0;
  return 1;
}

int procurarVertice(List *l, int value){
  //Retorna 1 caso ja exista o valor do nó
  //E 0 caso não seja encontrado
  node* aux;
  aux = l->head;
  while(aux!=NULL){
    if(aux->value == value) return 1;
    aux = aux->next;
  }
  if(aux == NULL) return 0;
  return 1;

}

void addV(List *l, int value){
  //add no fim da lista
  node* new = create_node(value);
  if(l->head==NULL){
    l->head = new;
    return;
  }
  node* aux = l->head;

  while(aux->next!=NULL){
    //não permite criação de valores repetidos
    if(aux->value == value) return;
    aux = aux->next;
  }
  if(aux->value == value) return;
  aux->next = new;
  return;
}

int removerV(List *l, int value){

  node * aux = l->head;
  //remove cabeça
  if(aux->value == value){
    l->head = l->head->next;
    free(aux);
    return 1;
  }

  while(aux->next!=NULL  && aux->next->value!= value){
    aux = aux->next;
  }

  //remove resto
  node *erase;
  erase = aux->next;
  aux->next = erase->next;
  free(erase);
  return 1;

}

void w_removeE(List *l, int V, int E){

  node* aux;
  aux = l->head;
  while(aux->value!=V){
    aux = aux->next;
  }
  edge* edge_aux = aux->edge_next;

  if(edge_aux->value == E){
    edge* erase = edge_aux;
    aux->edge_next = edge_aux->next;
    free(erase);
    return;
  }

  while(edge_aux->next!=NULL && edge_aux->next->value!=E){
    edge_aux = edge_aux->next;
  }
  if (edge_aux->next != NULL && edge_aux->next->value == E) {
    edge* erase = edge_aux->next;
    edge_aux->next = erase->next;
    free(erase);
  }
}

int removerE(List *l, int v1, int v2){
  if(procurarVertice(l,v1)==1 && procurarVertice(l,v2)==1){
    w_removeE(l,v1,v2);
    w_removeE(l,v2,v1);
  }
}

void imprimirGrafo(List *l){
  node * aux = l->head;
  while(aux!=NULL){
    //Imprime o Vertice
    printf(" %d: ",aux->value);
    //Imprime lista de arestas
    edge* edge_aux;
    edge_aux = aux->edge_next;
    while (edge_aux!=NULL) {
      printf(" %d",edge_aux->value);
      edge_aux = edge_aux->next;
    }
    aux = aux->next;
    printf("\n");
  }
}

void w_add(List *l, int V, int A){
  node* aux = l->head;
  edge* new = create_edge(A);
  //Busca vertice
  while(aux->value!=V){
    aux = aux->next;
  }
  //Add ini
  if(aux->edge_next == NULL){
    aux->edge_next = new;
    return;
  }
  //Add fim
  edge* edge_aux = aux->edge_next;

  while(edge_aux->next!=NULL){
    edge_aux = edge_aux->next;
  }
  edge_aux->next = new;
  return;
}

void addA(List *l, int v1, int v2){
  //Função chama wrapper
  if(procurarVertice(l,v1)==1 && procurarVertice(l,v2)==1){
    w_add(l,v1,v2);
    w_add(l,v2,v1);
  }
}

int liberar_lista(List* l) {
    node* aux;
    while (isvoid(l) != 0) {
        aux = l->head;
        edge* edge_aux = aux->edge_next;
        while (edge_aux != NULL) {
            edge* temp_edge = edge_aux;
            edge_aux = edge_aux->next;
            free(temp_edge);
        }
        l->head = l->head->next;
        free(aux);
    }
    free(l);
    return 1;
}

void bfs(List* graph, int startVertex, int endVertex) {
  int visited[MAX] = {0};
  int parent[MAX];
  for (int i = 0; i < MAX; i++) {
    parent[i] = -1;
  }
  Queue q;
  initQueue(&q);

  visited[startVertex] = 1;
  enqueue(&q, startVertex);

  while (!isEmpty(&q)) {
    int currentVertex = dequeue(&q);
    node* temp = graph->head;
    
    // Find the node corresponding to currentVertex
    while (temp != NULL && temp->value != currentVertex) {
      temp = temp->next;
    }

    if (temp != NULL) {
      edge* tempEdge = temp->edge_next;

      while (tempEdge) {
        int adjVertex = tempEdge->value;

        if (!visited[adjVertex]) {
          parent[adjVertex] = currentVertex;
          visited[adjVertex] = 1;
          enqueue(&q, adjVertex);

          if (adjVertex == endVertex) {
            // Found the endVertex, reconstruct path
            int path[MAX];
            int pathLength = 0;
            for (int v = endVertex; v != -1; v = parent[v]) {
              path[pathLength++] = v;
            }
            printf("Path: ");
            for (int i = pathLength - 1; i >= 0; i--) {
              printf("%d ", path[i]);
              if (i > 0) printf("-> ");
            }
            printf("\n");
            return;
          }
        }
        tempEdge = tempEdge->next;
      }
    }
  }
  printf("No path found.\n");
}


int main(void){

  List *L = (List*) malloc (sizeof(List));
  inicializa(L);
  for(int i = 1; i<=10; i++){
    addV(L, i);
  }
  addA(L,1,2);
  addA(L,1,4);
  addA(L,1,5);
  addA(L,1,6);
  addA(L,1,8);
  addA(L,1,10);
  addA(L,2,3);
  addA(L,2,4);
  addA(L,2,9);
  addA(L,2,10);
  addA(L,3,4);
  addA(L,3,5);
  addA(L,4,5);
  addA(L,5,6);
  addA(L,6,7);
  addA(L,6,8);
  addA(L,7,8);
  addA(L,7,9);
  addA(L,8,9);
  addA(L,8,10);
  addA(L,9,10);
  imprimirGrafo(L);
  bfs(L, 1, 3);
  //removerE(L,1,2);
  //imprimirGrafo(L);
  //removerE(L,2,3);
  //imprimirGrafo(L);
  //removerE(L,1,3);
  //imprimirGrafo(L);
  //free(L);

  return 0;
}
