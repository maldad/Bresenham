#include <stdio.h>
main(){
    int xi, yi, xf, yf;
    /*puts("X inicial");
    scanf("%d", &xi);
    puts("Y inicial");
    scanf("%d", &yi);
    puts("X final");
    scanf("%d", &xf);
    puts("Y final");
    scanf("%d", &yf);
    printf("Punto inicial (%d, %d) Punto final (%d, %d)\n", xi, yi, xf, yf);
    */
    xi = 20;
    yi = 10;
    xf = 30;
    yf = 18;
    /*xi = 7;
    yi = 3;
    xf = 4;
    yf = 4;*/

    char matriz[xf+1][yf+1];

    //rellena la matriz con puntos;
    int i, j;
    for( i = 0; i < xf+1; i++){
        for(j = 0; j < yf+1; j++){
            matriz[i][j] = '.';
        }
    }


    //calculando DELTAS
    int deltax = xf-xi;
    int deltay = yf-yi;
    printf(" dy %d dx %d\n", deltay, deltax);
    //IF caso 1
    if(deltay >= 0 && deltax >= 0 && abs(deltay) <= abs(deltax)){
        int A = 2*deltay;
        int B = 2*deltay - 2*deltax;
        int pi = 2*deltay - deltax;
        printf("%d %d %d dy %d dx %d\n", A, B, pi, deltay, deltax);
        int xk = xi;
        int yk = yi;
        int cont = 1;
        while (cont == 1) {
            if(xk == xf && yk == yf){
                cont = 0;
            }
            if(pi > 0){
                xk++;
                yk++;

                matriz[xk][yk] = '@';
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+B;
            }//if
            else{
                xk++;
                matriz[xk][yk] = '@';
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+A;
            }//else
        }//while
    }//if caso 1

    int k, l;
    //este for va imprimir la matriz al reves
    //como si de un plano cartesiano real de tratara
    for ( k = xf; k >= 0; k-- ){
       for ( l = 0; l <= yf; l++ ){
          printf("%c ", matriz[k][l] );
       }
       printf("\n" );
   }

}//main