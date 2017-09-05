#include <stdio.h>
#include <stdlib.h>

struct pilha{
    int info;
    struct pilha *prox;
};

void Inicializar(struct pilha **topo){
   *topo = NULL;
}

int Vazia(struct pilha **topo){
   if(*topo == NULL)
      return 1;
   else
      return 0;
}

void Empilhar(struct pilha **topo, int elemento){
    struct pilha *novo;
    novo = (struct pilha *)malloc(sizeof(struct pilha));
    novo->info = elemento;
    novo->prox = *topo;
    *topo = novo;
}

int Desempilhar(struct pilha **topo){
   int result;
   struct pilha *auxiliar;
   if(Vazia(topo)){
        printf("\n Pilha Vazia! \n");
        exit(1);
   }
   else {
        result = (*topo)->info;
        auxiliar = *topo;
        *topo = (*topo)->prox;
        free(auxiliar);
        return result;
   }
}

void Exibir(struct pilha *topo){
    int i = 0;
    struct pilha *pilha;
    printf("\n\n\tPilha:\n\n");
    if (Vazia(&topo)){
        printf ("A Pilha esta vazia!\n");
    }
    else  {
        pilha = topo;
        printf("Topo:");
        while(pilha != NULL){
            printf("\t%i\n", pilha->info);
            pilha = pilha->prox;
            if (pilha == NULL){
              printf("\tnull\n\n");
            }
        }
    }

}

void Menu(){
    printf("Pilha dinamica: \n");
    printf("1 - Empilhar \n");
    printf("2 - Desempilhar \n");
    printf("0 - Sair \n");
}

int main(){
    struct pilha *topo;
    Inicializar(&topo);
    int opcao;
    int info;

    Menu();
    scanf("%i", &opcao);

    while (opcao != 0){

        switch (opcao){
            case 1:
                printf( "Digite um info: ");
                scanf("\n%i", &info);

                Empilhar(&topo, info);
                Exibir(topo);
                Menu();
                break;
            case 2:
                Desempilhar(&topo);
                Exibir(topo);
                Menu();
                break;

            case 0 :
                printf("Programa encerrado\n");
                return 0;
            default:
                printf( "Escolha invalida.\n\n");
                Menu();
                break;
        }
        scanf("%i", &opcao);
    }
  return 0;
}
