// Lista Encadeada

#include <stdio.h>
#include <stdlib.h>

 struct elemento{
 int info;
 struct elemento *prox;
};

int vazia (struct elemento **inicio){
  if (*inicio == NULL){
    return 1;
  } else return 0;
}

void inserir(struct elemento **inicio, struct elemento **fim, int valor){
  struct elemento *q;
  q = (struct elemento *) malloc(sizeof(struct elemento));
  q->info = valor;
  q->prox = NULL;
  if (vazia(inicio)){
    *inicio = q;
  } else (*fim)->prox = q;
  *fim = q;
}

void remover(struct elemento **inicio){
  if (*inicio == NULL){ 										// verifica se a lista está vazia
    printf("Lista Vazia!!\n");
  } else {
        struct elemento *k;
        k = *inicio;
        *inicio = (*inicio)->prox;
        free(k);
    }
}


void imprimir(struct elemento **p){
  struct elemento *q;
  if (*p== NULL){										// verifica se a lista está vazia
    printf("Lista Vazia!!\n");
    } else {										// imprime lista
      printf("Lista:\n");
      for (q = *p ; q != NULL ; q = q->prox){
        printf("%i --> ", q->info);
        if (q->prox==NULL){
          printf ("Null\n\n");
        }
      }
    }
}

void buscar(struct elemento **p, int valor){
  struct elemento *q;
  if (*p == NULL){										// verifica se a lista está vazia
    printf("Lista Vazia!!\n");
  }	else{											// recebe o numero a ser procurado
      q = *p;
      while ((q != NULL)&&(q->info != valor)){		// procura o numero na lista
        q = q->prox;
      }
      if (q == NULL){
        printf("Numero nao encontrado na lista!\n");
      } else {
        printf("Numero encontrado na lista!!\n");
      }
    }
}

void cabeca(struct elemento **p){
  struct elemento *q;
  q = *p;
  if (q==NULL){
    printf("Lista Vazia!!\n");
  } else printf("A cabeça da lista é: %i\n", q->info  );
}

int main(){
	int n, x;
	struct elemento *inicio;
  struct elemento *fim;
  inicio = NULL;
	fim = NULL;
	do {
		printf("Lista Encadeada:\n");
		printf("1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Imprimir\n");
		printf("4 - Buscar\n");
    printf("5 - Cabeça\n");
		printf("0 - Sair\n");
		scanf (" %i", &x);
		switch(x) {
				case 1 :
						printf("Digite o numero a ser inserido ou (0) para sair: \n");
						scanf (" %i", &n);
            while (n!=0){										// insere na lista
              inserir(&inicio, &fim, n);
							scanf (" %i", &n);
						}
						break;
				case 2 :
            remover(&inicio);
						break;
				case 3 :
            imprimir(&inicio);
						break;
				case 4 :
            printf("Digite o numero a ser procurado:\n");
            scanf(" %i", &n);
            buscar(&inicio, n);
						break;
        case 5:
            cabeca(&inicio);
            break;
        case 0 :
						printf("Programa encerrado!\n");
						return 0;

				default:
						printf ("Opcao invalida!\n");
						printf("- - - - - - - -\n");
						break;
			}
	} while(x!=0);

return 0;
}
