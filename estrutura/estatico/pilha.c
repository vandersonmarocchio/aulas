#include<stdio.h>
#define tam 10

typedef struct spilha{
    int itens[tam];
    int topo;
}pilha;

void init (pilha*s){
     s->topo=-1;
}

int vazia(pilha*s){
     if(s->topo==-1)
     {
         return 1;
     }
     return 0;
}

void exibir(pilha*s){
  int i,aux;
  if(vazia(s))
  {
    printf("\nERRO-PILHA VAZIA\n");
  }
  else{

    printf("\n\n\tPilha:\n");
    for (i = 0; i<=s->topo; i++){
      if (i==s->topo){
        printf("Cabeça:");
      }
      printf("\t %d \n" , s->itens[i]);
    }
    printf("\n\n");
  }
}

int cheia(pilha*s){
     if(s->topo==tam)
     {
         return 1;
     }
     return 0;
}

void empilhar (pilha*s,int x){
     if(cheia(s))
     {
         printf("\nERRO-Lista ja esta cheia\n");
     }
     else
     {
         s->topo = s->topo + 1;
         s->itens[s->topo] = x;
         printf("\nELEMENTO INSERIDO COM SUCESSO\n");
     }
     exibir(s);
}

int desempilhar(pilha*s){
    int aux;
    if(vazia(s))
    {
         printf("\nERRO-PILHA vazia\n");
         return -1;
    }
    else
    {
         aux=s->itens[s->topo];
         s->topo=s->topo-1;
         exibir(s);
         return aux;
    }
    printf("ELEMENTO REMOVIDO COM SUCESSO\n");
}

int cabeca(pilha*s){
    if(vazia(s))
    {
         printf("\nERRO -PILHA VAZIA\n");
         return -1;
    }
    return s->itens[s->topo];
}




int main(){
    pilha p;
    int aux, a,x;
    init(&p);
    do{
         do{
              printf("Pilha Estatica:\n");
              printf("1 - Inserir\n");
              printf("2 - Remover\n");
              printf("3 - Ver topo na Pilha\n");
              printf("4 - Exibir elementos\n");
              printf("0 - Sair\n");
              scanf("%d",&a);
              printf("\n\n");
         } while(a<1||a>5);
         switch(a)
         {
              case 1:
              {
                   printf("Qual o valor deseja inserir na PILHA ?\n");
                   scanf(" %d",&x);
                   empilhar(&p,x);
                   break;
              }
              case 2:
              {
                   aux=desempilhar(&p);
                   if(aux!=-1)
                   {
                        printf("\nVoce acabou de remover o elemento %d da PILHA\n",aux);
                   }
                   break;
              }
              case 3:
              {
                   aux=cabeca(&p);
                   if(aux!=-1)
                   {
                        printf("O elemento que esta no topo da pilha e %d \n",aux);
                   }
                   break;
              }
              case 4:
              {
                   exibir(&p);
                   break;
              }
              case 0:
              {
                   printf("\nPrograma Encerrado!!\n");
                   return 0;
              }
         }
    }while(a!=5);
}
