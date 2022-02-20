#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
  int i, j, avaliacoes, alunos, somaAv[i], somaAl[j];
  float soma, mediaDP, desvio, sigma;
  float* media;
  float** nota;

  printf("Digite a quantidade de avaliacoes: ");
  scanf("%d", &avaliacoes);
  printf("Digite a quantidade de alunos: ");
  scanf("%d", &alunos);

  nota=malloc(alunos*sizeof(float*));

  for (i=0; i<alunos; i++)
    nota[i] = malloc (avaliacoes*sizeof(float)) ;

  for(i=0; i<avaliacoes; i++){
    printf("\n----- Avaliacao %d -----\n", i+1);
    for(j=0; j<alunos; j++){
      printf("Nota do aluno [%d]: ", j+1);
      scanf("%f", &nota[j][i]);
      if(nota[j][i]>10 || nota[j][i]<0){
        printf("\n\nERROR: VALOR DE NOTA INVALIDO!\n\n");
        exit(1);
      }
    }
  }
  printf("\n\n --- Notas imputadas ---");
  for(i=0; i<avaliacoes; i++){
    for(j=0; j<alunos; j++){
        printf("\n ----- Avaliacao [%d] -----\nNota do aluno [%d]: %.2f", i+1, j+1, nota[j][i]);
    }
    printf("\n");
  }
  printf("\n\n --- Resultado Final --- \n");
  printf(">Medias arredondadas para cima<");
  media=malloc(alunos*sizeof(float));

  for(i=0; i<alunos; i++){
    soma=0.0;
    for(j=0; j<avaliacoes; j++){
      soma += nota[i][j];
      media[i]=soma/avaliacoes;
    }
    printf("\nMedia do aluno [%d]: %.2f", i+1, ceil(media[i]));
  }

  printf("\n\n");
  printf("\n>Media e desvio padrao(Populacional) das avaliacoes<  \n");
  for(j=0; j<avaliacoes; j++){
    soma=0.0;
    for(i=0; i<alunos; i++){
      soma+=nota[i][j];
    }
    media[j]=soma/alunos;
    sigma=0;
    for(i=0; i<alunos; i++){
      sigma += pow(nota[i][j]-media[j],2);
    }
    desvio=sqrt(sigma/alunos);
    printf("\nAvaliacao [%d]->   Media: %.2f", j+1, media[j]);
    printf("\tDesvio padrao: %.2f\n", desvio);
  }
  printf("\n");
  free(nota);
}
