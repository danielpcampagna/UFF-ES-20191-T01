#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char entrada[121];
char linha[121] ;
char tipo[3];
float  base, bmaior, bmenor, altura, lado, lado1, lado2, raio;
int main(){



//labrir arquivo



FILE* fp;

//  printf ("Digite o nome do arquivo de entrada. \n");
// scanf("%120s", entrada);
fp=fopen("arquivo.txt", "r");

if (fp==NULL) {
        printf("Nao foi possivel abrir o arquivo de entrada: %s \n", entrada);
    exit (1);}

while (fgets(linha, 121, fp)) {
int pai ,id;
char cb1, cb2, c1, c2, c3;
float v1, v2, v3;
char str[120];

int n = sscanf(linha, "%d  %c %d %c %c %c %c %f %f  %f %s ",&id, &cb1, &pai, &cb2, &tipo[0], &tipo[1], &tipo[2], &v1, &v2, &v3, str );

if (n<8 || n> 10) {
    printf("Os dados no arquivo nao estao no formato especificado.\n");
    exit (2);
}
  if (id<=pai) {
    printf("O arquivo tem inconsistencias!! Nao pode inserir elementos sem pai.\n" );
    exit (3);
  }



  printf("%d %d  %d%c %f  ", n, pai, id, cb1, v1 );
  printf("%s \n", tipo);





if (tipo=="QUA"){
    lado=v1 ;
}

if (tipo=="TRI") {
    base=v1;
    altura=v2;
}

if (tipo=="RET") {
    lado1=v1;
    lado2=v2;
}
if (tipo=="TRA") {
    bmaior=v1;
    bmenor=v2;
    altura=v3;
}
if (tipo=="CIR") {
    raio=v1;
}

}
/*
    TAG* inserir_arv_gen(TAG *t, char* tipo, id, pai,  void *figura) {
        if
    TAG* result = ;
    return result;
}
*/

return 0;

}




