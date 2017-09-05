// Lista Encadeada

#include <stdio.h>
#include <stdlib.h>

 struct elemento{
 int info;
 struct elemento *prox;
};

void inserir(struct elemento **p, int valor){
  struct elemento *q;
  q = (struct elemento *) malloc(sizeof(struct elemento));
  q->info = valor;
  q->prox = *p;
  *p = q;
}

void remover(struct elemento **p, int valor ){
  struct elemento *q;
  if (*p== NULL){ 										// verifica se a lista está vazia
    printf("Lista Vazia!!\n");
    } else {
      q = *p;
      while ((q != NULL)&&(q->info != valor)){		// procura o numero na lista
        q = q->prox;
      }
      if (q == NULL){
        printf("Numero nao encontrado na lista!\n");
      } else {
        q = *p;
        if (valor == q->info){							//verifica se é o primeiro da lista (caso problemático)
          *p = q->prox;
          q = *p;
        } else {									// Caso geral
          while ((q!= NULL)&&(valor!= q->prox->info)){
            q = q->prox;
          }
          struct elemento *k;
          k = q->prox;
          q->prox = k->prox;
          free(k);
        }
        printf("O numero %i foi removido!!\n", valor);
      }
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
	struct elemento *p;
	p = NULL;
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
              inserir(&p, n);
							scanf (" %i", &n);
						}
						break;
				case 2 :
            printf("Digite o numero a ser removido:\n");
            scanf (" %i", &n);
            remover(&p, n);
						break;
				case 3 :
            imprimir(&p);
						break;
				case 4 :
            printf("Digite o numero a ser procurado:\n");
            scanf(" %i", &n);
            buscar(&p, n);
						break;
        case 5:
            cabeca(&p);
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
