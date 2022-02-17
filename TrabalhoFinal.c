#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
  int i, j, NAval, NAluno;
  float somaAl[j], somaAv[j], somaDP[j], notas[j], mediaAl[j], mediaAv[j], desvio[j];
  float *nota;

  printf("Digite a quantidade de avaliacoes: ");
  scanf("%d", &NAval);
  printf("Digite a quantidade de alunos: ");
  scanf("%d", &NAluno);

  nota=(float*)malloc(4*sizeof(float));

  if(nota==NULL){
    printf("Error: Memoria insuficiente! \n");
    exit(1);
  }

  for(i=0; i<NAval; i++){
    printf("\n----- Avaliacao %d -----\n", i+1);
    for(j=0; j<NAluno; j++){
      printf("Nota do aluno [%d]: ", j+1);
      scanf("%f", &nota[j], &nota[i]);
      somaAl[j] = somaAl[j] + nota[j];
      somaAv[i] = somaAv[i] + nota[i];
    }
  }

  printf("\nResultado Final\n");
  printf("Medias arredondadas, para cima, dos alunos: \n");
  for(j=0; j<NAluno; j++){
    mediaAl[j] = somaAl[j]/NAval;
    printf("Aluno [%d]-> %.2f\n", j+1, ceil(mediaAl[j]));
    }

  printf("\nMedia e desvio padrao(populacional) das avaliacoes: \n");
  for(i=0; i<NAval; i++){
    mediaAv[i] = somaAv[i]/NAluno;
    desvio[i] = desvio[i] + pow(notas[i]-mediaAv[i],2);
    printf("Desvio padrao da avaliacao [%d]: %.2f\n", i+1, sqrt(desvio[i])/NAluno);
  }
  free(nota);
  return 0;
}
