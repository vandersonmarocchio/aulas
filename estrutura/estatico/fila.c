#include <stdio.h>
#define tam 2

typedef struct fila{
  int info[tam];
  int inicio;
  int fim;
}fila;

void init (fila *s){
  s->inicio = -1;
  s->fim = -1;
}

int vazia(fila *s){
  if (s->fim == s->inicio){
    return 1;
  } else return 0;
}

int cheia(fila *s){
  if ((s->inicio == -1) && (s->fim == tam)){
    return 1;
  } else return 0;
}

void desloca(fila *s){
   int desloca;
   desloca = s->inicio + 1;
   for (int i = s->inicio + 1; i <= s->fim; i++){
     s->info[i - desloca] = s->info[i];
   }
   s->inicio = -1;
   s->fim = s->fim - desloca;
}

void insere(fila *s, int x){
  if (!cheia(s)){
    if (s->fim == tam){
        desloca(s);
    }
    s->fim = s->fim + 1;
    s->info[s->fim] = x;
    printf("Numero inserido!!\n");
    printf("\n\ninicio:%d\n", s->inicio );
    printf("fim:%d\n\n\n  ", s->fim );
  } else printf("Fila cheia!!\n");
}

void remover(fila *s){
  int x;
  if (!vazia(s)){
    s->inicio = s->inicio + 1;
    x = s->info[s->inicio];
    printf("Numero %d removido!! ", x);
    if (vazia(s)){
      init(s);
    }
  } else printf("\n\nFila Vazia!!\n\n");
}

void exibir(fila *s){
  if (!vazia(s)){
    printf("\n\n\tFila\n");
    printf("Inicio:");
    for (int i = s->inicio +1 ; i<=s->fim; i++){
      if (i == s->fim){
        printf("Fim:" );
      }
      printf("\t%d\n", s->info[i]);
    }
    printf("\n\n");
  } else printf("\n\nFila Vazia!!\n\n");
}

int main(){
	int n, x;
	fila q;
  init(&q);
	do {
		printf("Fila estatica:\n");
		printf("1 - Inserir\n");
		printf("2 - remover\n");
		printf("3 - Imprimir\n");
		printf("0 - Sair\n");
		scanf (" %i", &x);
		switch(x) {
				case 1 :
						printf("Digite o numero a ser inserido:\n");
						scanf (" %i", &n);
            insere(&q, n);
						break;
				case 2 :
            remover(&q);
						break;
				case 3 :
            exibir(&q);
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
