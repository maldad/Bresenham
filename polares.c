#include <stdio.h>
#include <math.h>

//TRANSFORMAR DE POLARES A CARTESIANAS
float redondear(float num){
    return round(num);
}//redondear

abscisa(int r, int angle){
    float cx = r*cos(angle/57.3);
    cx = redondear(cx);
    int cxx = cx;
    return cxx;
}//abscisa

ordenada(int r, int angle){
    float cy = r*sin(angle/57.3);
    cy = redondear(cy);
    int cyy = cy;
    return cyy;
}//ordenada

/*
main(){
	int r = 10;
	int angle = 288;
    printf("polar: (%d, %d°), cartesiana: (%d, %d)\n", r, angle, abscisa(r, angle), ordenada(r, angle));
}//main
*/
