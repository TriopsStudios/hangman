/******************************************************************************
Ahorcado. Alejandro Martínez Manzano - 2024 - alemartinezman@gmail.com
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define W 10
#define H 10

char tableroUno[H][W];
char *palabraElegida;
char *palabraACompletar;
char *listaPalabras[5] = {"hola", "adios", "bienvenido","feo","increible"};
char letraElegida;
int index_;
void dibujarTableroUno(int errores);
void iniciarTablero();
int elegirPalabra();
void Inicializar();
int main()
{
    
    int error = 0;
    int indiceaux;
    bool letraEsEncontrada = false;
    bool loop = true;
    Inicializar();
    while(loop==true){
        letraEsEncontrada = false;
        scanf(" %c", &letraElegida);
        for(int i=0; i<strlen(palabraElegida);i++){
            if(*(palabraElegida+i) == letraElegida && *(palabraACompletar+i)=='_'){
               indiceaux=i;
                index_=i;
                letraEsEncontrada = true;
                *(palabraACompletar+i) = letraElegida;
                
                break;
            }
            
        }
        if(letraEsEncontrada!= true){
            error++;
            
        }
        system("clear");
      
        dibujarTableroUno(error);
        if(strcmp(palabraACompletar, palabraElegida) == 0){
            printf("Has ganado\n");
            loop = false;
        }
        if(error==3){
            printf("El sujeto ha sido ahorcado\n");
            loop = false;
        }
       
    }
    free(palabraElegida);
    free(palabraACompletar);
}

int elegirPalabra(){
     // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Seleccionar un índice aleatorio entre 0 y 4
    int indiceAleatorio = rand() % 5;
    
    palabraElegida = malloc((strlen(listaPalabras[indiceAleatorio])+1) * sizeof(char));
    palabraACompletar = malloc((strlen(listaPalabras[indiceAleatorio])+1) * sizeof(char));
    if(palabraElegida == NULL){
        printf("Error al asignar memoria\n");
        return 1;
    }
    if(palabraACompletar == NULL){
        printf("Error al asignar memoria\n");
        return 1;
    }
    
    
    // Copiar el string en la memoria asignada
    strcpy(palabraElegida, listaPalabras[indiceAleatorio]);
    for(int i=0; i<strlen(palabraElegida);i++){
        *(palabraACompletar+i) ='_';
    }
    //printf("%s\n", palabraElegida);
    return 0;
}


void iniciarTablero(){
    for(int i=0;i<W;i++){
           for(int e=0;e<H;e++){
               tableroUno[i][e] = ' ';
           }
       }
       
       
    
}
void dibujarTableroUno(int errores){
    switch(errores){
        case 0:
       for(int i=0;i<W;i++){
           for(int e=0;e<H;e++){
               tableroUno[i][e] = ' ';
           }
       }
        break;
        case 1:
        tableroUno[1][W/2] = 'O';
        break;
        case 2:
        tableroUno[1][W/2] = 'O';
        tableroUno[2][W/2] = 'I';
        break;
        case 3:
        tableroUno[1][W/2] = 'O';
        tableroUno[2][W/2] = 'I';
        tableroUno[3][W/2] = '-';
        break;
    }
    
    //DibujarElTablero
   
    // for(int n = 0; n<strlen(palabraElegida); n++){
      //  tableroUno[8][n*2] = '_';
    //}
    for(int i =0;i<strlen(palabraElegida);i++){
        tableroUno[8][i*2] = *(palabraACompletar +i);
    }
   // 
    for(int a = 0; a<H; a++){
        for(int b = 0; b<W;b++){
            printf("%c", tableroUno[a][b]);
        }
         printf("\n");
    }
    
   
    
}

void Inicializar(){
    int error = 0;
   error = elegirPalabra();
   if(error == 1){
       printf("Fallo al alojar memoria para palabra\n");
   }
    iniciarTablero();
     for(int i =0;i<strlen(palabraElegida);i++){
        tableroUno[8][i*2] = *(palabraACompletar +i);
    }
   // 
    for(int a = 0; a<H; a++){
        for(int b = 0; b<W;b++){
            printf("%c", tableroUno[a][b]);
        }
         printf("\n");
    }
    //dibujarTableroUno(0);

}
