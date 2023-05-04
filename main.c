#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 6

//Cargo la matriz con letras aleatorias sin repetir
void cargarMatriz(char matriz[][TAM],int t);

//Muestro la matriz
void mostrarMatriz(char matriz[][TAM],int t);

//Muestro solamente las vocales de la matriz
void mostrarMatrizVocales(char matriz[][TAM],int t);

//Muestro la diagonal de la matriz
void mostrarMatrizDiagonal(char matriz[][TAM],int t);

//Guardo la matriz original en un archivo
void guardarMatrizEnArchivo(char matriz[][TAM],int t);

int main()
{

    int tam2 = 6;
    char mat[tam2][TAM];

    cargarMatriz(mat,tam2);
    mostrarMatriz(mat,tam2);
    mostrarMatrizVocales(mat,tam2);
    mostrarMatrizDiagonal(mat,tam2);
    guardarMatrizEnArchivo(mat,tam2);

    return 0;
}
void cargarMatriz(char matriz[][TAM],int t){

    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                     'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int numLetras = 52;
    srand(time(NULL));

    for(int i=0; i<TAM; i++){
        for(int j=0; j<6; j++){
            int indice = rand()%numLetras;
            matriz[i][j]=letras[indice];
            letras[indice]= letras[numLetras-1];
            numLetras = numLetras -1;
        }
    }

};
void mostrarMatriz(char matriz[][TAM],int t){

    for(int i=0; i<TAM; i++){
        for(int j=0; j<6; j++){
            printf("/ %c / ",matriz[i][j]);
        }
        printf("\n");
    }

};

void mostrarMatrizVocales(char matriz[][TAM],int t){

    printf("\n--Las vocales de la matriz--\n");

    for(int i=0; i<TAM; i++){
        for(int j=0; j<6; j++){

            if(matriz[i][j]== 'a' || matriz[i][j] == 'e' || matriz[i][j] == 'i' || matriz[i][j] == 'o' || matriz[i][j] == 'u' ||
               matriz[i][j]== 'A' || matriz[i][j] == 'E' || matriz[i][j] == 'I' || matriz[i][j] == 'O' || matriz[i][j] == 'U' ){
                    printf(" / %c /", matriz[i][j]);
            }else{
                printf(" / # /");
            }

        }
        printf("\n");
    }

};

void mostrarMatrizDiagonal(char matriz[][TAM],int t){

    printf("\n--La diagonal de la matriz--\n");

    for(int i=0; i<TAM; i++){
        for(int j=0; j<6; j++){
            if( i == j){
                printf("/ %c /",matriz[i][j]);
            }else{
                printf("/ # /");
            }
        }
        printf("\n");
    }

};
void guardarMatrizEnArchivo(char matriz[][TAM],int t){

    FILE * archivo;
    archivo = fopen("matriz.txt","w");

    for(int i=0; i<TAM; i++){

        for(int j=0; j<6; j++){

            fprintf(archivo, "/ %c /",matriz[i][j]);
        }
        fprintf(archivo,"\n");
    }
    fclose(archivo);

};



