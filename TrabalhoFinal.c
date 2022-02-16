#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
  int i, j, N1, N2;
  float somaAl[j], somaAv[j], somaDP[j], notas[j], mediaAl[j], mediaAv[j], desvio[j];

  printf("Digite a quantidade de avaliacoes: ");
  scanf("%d", &N1);
  printf("Digite a quantidade de alunos: ");
  scanf("%d", &N2);

  for(i=0; i<N1; i++){
    printf("\n----- Avaliacao %d -----\n", i+1);
    for(j=0; j<N2; j++){
      printf("Nota do aluno [%d]: ", j+1);
      scanf("%f", &notas[j]);
      somaAl[j] = somaAl[j] + notas[j];
      somaAv[i] = somaAv[i] + notas[j];
    }
  }

  printf("\nResultado Final\n");
  printf("Medias arredondadas, para cima, dos alunos: \n");
  for(j=0; j<N2; j++){
    mediaAl[j] = somaAl[j]/N1;
    printf("Aluno [%d]-> %.2f\n", j+1, ceil(mediaAl[j]));
    }

  printf("\nMedia e desvio padrao(populacional) das avaliacoes: \n");
  for(j=0; j<N1; j++){
    mediaAv[j] = somaAv[j]/N2;
    desvio[j] = desvio[j] + pow(notas[j]-mediaAv[j],2);
    printf("Desvio padrao da avaliacao [%d]: %.2f\n", j+1, sqrt(desvio[j])/N2);
  }
}
