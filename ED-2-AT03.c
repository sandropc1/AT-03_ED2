#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct{

char code[4];
char nome[31];
char sexo[2];
char idade[3];
char especialidade[31];
char telefone[15];
}Professor;


void preencheTemp(FILE *arq1,FILE *arq2){//le o art de entrada e salva no temporario
rewind(arq1);
int tamanho,top;
Professor professor;
char verifica[200];
char teste;

fscanf(arq1,"size=%d top=%d",&tamanho,&top);
fprintf(arq2,"size=%d top=%d\n",tamanho,top);
fgets(verifica,200,arq1);

  while(teste != EOF){
    fscanf(arq1,"%[^|,]|%[^|,]|%[^|,]|%[^|,]|%[^|,]|%[^|,]",&professor.code,&professor.nome,&professor.sexo,&professor.idade,&professor.especialidade,&professor.telefone);
    teste = fgetc(arq1);
    if(teste != EOF){
    fprintf(arq2,"%s|%s|%s|%s|%s|%s\n",&professor.code,&professor.nome,&professor.sexo,&professor.idade,&professor.especialidade,&professor.telefone);

  }
    fgets(verifica,200,arq1);
  }
}

void indicaDelete(FILE *arq1,char key[]){//le o art de entrada e salva no temporario
rewind(arq1);
int counter = 1;
Professor professor;
Professor professoraux;
int tamanho,top;
int ret;
char verifica[200];
char teste;

fscanf(arq1,"size=%d top=%d",&tamanho,&top);
fgets(verifica,200,arq1);


printf("\nKey: %s\n",key);
  while(teste != EOF){
    fscanf(arq1,"%[^|,]|%[^|,]|%[^|,]|%[^|,]|%[^|,]|%[^|\n,]",&professor.code,&professor.nome,&professor.sexo,&professor.idade,&professor.especialidade,&professor.telefone);
    ret = strcmp(key,professor.code);
    teste = fgetc(arq1);

  if(teste != EOF && ret == 0){
    top = counter;
    char aux = top+'0';
    
    professor.code[0] = '*';
    professor.code[1] = top;//verificar isso aqui dps
    professor.code[2] = '|';

    rewind(arq1);
    for(int i= 1; i<counter;i++){//percorre o arquivo até a linha que deve ser substituida
      fscanf(arq1,"%[^|,]|%[^|,]|%[^|,]|%[^|,]|%[^|,]|%[^|\n,]",&professoraux.code,&professoraux.nome,&professoraux.sexo,&professoraux.idade,&professoraux.especialidade,&professoraux.telefone);

      }
      printf("%s|%s|%s|%s|%s|%s\n",&professor.code,&professor.nome,&professor.sexo,&professor.idade,&professor.especialidade,&professor.telefone);//printf
      fprintf(arq1,"%s|%s|%s|%s|%s|%s\n",&professor.code,&professor.nome,&professor.sexo,&professor.idade,&professor.especialidade,&professor.telefone);//substitui a linha
    }
    counter++;
  }
  fseek( arq1, 0, SEEK_SET );
  fprintf(arq1,"size=%d top=%d ",tamanho,top);
  printf("linha: %d top:%d\n",counter,top);

}


int main(int argc, const char * argv[]){

  FILE *arq_entrada = fopen("input1.txt","r");
  FILE *arq_saida = fopen("saida.txt","w+");
  FILE *arq_operations = fopen("operations1.txt","r");
  FILE *arq_saida_temp = fopen("saida_temp.txt","w+");

int tamanho,top;

char verificador;
char verifica[200];
Professor professor;

fscanf(arq_entrada,"size=%d top=%d",&tamanho,&top);

preencheTemp(arq_entrada,arq_saida_temp);

verificador = fgetc(arq_operations);

while(verificador != EOF){

if(verificador == 'd'){
  char aux[5];//cria um auxiliar pra colocar o codigo do registro a ser excluido
  fscanf(arq_operations,"%s",aux);

  indicaDelete(arq_saida_temp,aux);


}
/*
  if(verificador == 'i'){
    printf("\nOperação de adicao i\n");
  fscanf(arq_operations," %[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]",&professor.code,&professor.nome,&professor.sexo,&professor.idade,&professor.especialidade,&professor.telefone);

  fprintf(arq_saida_temp,"%s|%s|%s|%s|%s|%s\n",&professor.code,&professor.nome,&professor.sexo,&professor.idade,&professor.especialidade,&professor.telefone);
  }
*/
  fgets(verifica,200,arq_operations);
  verificador = fgetc(arq_operations);
}

return 0;
}
