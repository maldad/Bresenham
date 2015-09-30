#include <stdio.h>
#include "polares.c"
#include "bresenham_v2.c"
//#include "brecaso1.c"
//TODO
//[x] - calcular coordenadas cartesianas llamando a polares.c
//[x] - guardar esas coordenadas en 2 arreglos, uno para X, otro para Y
//[x] - recorrer esos arreglos y mandar a llamar a funcion linea en bresenham.c

//distancia al punto
int r, angle;
//angulo respecto a X
//coordenadas a calcular
int equis, ye;
int abscisas[10];
int ordenadas[10];
int lados;

calcula_cartesianas(int radio, int l){
    angle = 360/l;
    lados = l;
    int avance = 0;
    printf("lados: %d angulo: %d\n", lados, angle);
    int i;
    for(i = 0; i < lados; i++){
        abscisas[i] = abscisa(radio, avance);
        ordenadas[i] = ordenada(radio, avance);
        avance += angle;
    }//for
}//calcula_cartesianas

grafica_lados(){
    rellena();
    ejes();
    int i;
    int xs, ys, xe, ye;
    for(i = 0; i < lados-1; i++){
        xs = abscisas[i];
        ys = ordenadas[i];
        xe = abscisas[i+1];
        ye = ordenadas[i+1];

        linea(xs, ys, xe, ye);
    }//for
    //imprimiendo el lado final
    //que requiere el punto final y el inicial...
    xs = abscisas[lados-1];
    ys = ordenadas[lados-1];
    xe = abscisas[0];
    ye = ordenadas[0];
    linea(xs, ys, xe, ye);
    imprime();
}//grafica_lados

main(){
    //radio, lados
    int r, l;
    puts("radio...");
    scanf("%d", &r);
    puts("lados...");
    scanf("%d", &l);
    calcula_cartesianas(r, l);
    int i;
    for(i = 0; i < 10; i++){
        printf("cartesiana %d: (%d, %d)\n", i, abscisas[i], ordenadas[i]);
    }
    grafica_lados();
}//main
