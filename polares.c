#include <stdio.h>
#include <math.h>
//#include "brecaso1.c"
//TRANSFORMAR DE POLARES A CARTESIANAS
redondear(int num){
    return round(num);
}//redondear
char matriz[2][2];
rellena(){
    int i, j;
    for( i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            matriz[i][j] = 'X';
        }
    }//for
}
imprimeLaMadre(){
    int a, b;
    for( a = 0; a < 2; a++){
        for(b = 0; b < 2; b++){
            printf("%c\n", matriz[a][b]);
        }
    }//for
}
main(){

rellena();
imprimeLaMadre();


    /*
    //distancia al punto
    int r = 10;
    //angulo respecto a X
    int angle = 144;

    int cx = r*cos(angle/57.3);
    int cy = r*sin(angle/57.3);
    cx = redondear(cx);
    cy = redondear(cy);

    printf("polar: (%d, %d°), cartesiana: (%d, %d)\n", r, angle, cx, cy);
    linea(0, 0, 4, 4);
    */
}//main
