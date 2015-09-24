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
    xi = 0;
    yi = 0;
    xf = 10;
    yf = 10;
    int limite = 12;

    char matriz[limite][limite];

    //rellena la matriz con puntos;
    int i, j;
    for( i = 0; i < limite; i++){
        for(j = 0; j < limite; j++){
            matriz[i][j] = '.';
        }
    }
    matriz[xi][yi] = 'S';

    //calculando DELTAS
    int deltax = xf-xi;
    int deltay = yf-yi;
    //printf("dy %d dx %d\n", deltay, deltax);
    //IF caso 1
    if(deltay >= 0 && deltax >= 0 && abs(deltay) <= abs(deltax)){
        int A = 2*deltay;
        int B = 2*deltay - 2*deltax;
        int pi = 2*deltay - deltax;
        printf("A %d B %d pk %d dy %d dx %d\n", A, B, pi, deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi;
        int yk = yi;
        int cont = 1;
        while (xk != xf || yk != yf) {
            //if(xk == xf && yk == yf){
            //    cont = 0;
            //}
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

    matriz[xf][yf] = 'E';
    printf("final (%d, %d)\n", xf, yf);
    int k, l;
    //este for va imprimir la matriz al reves
    //como si de un plano cartesiano real de tratara
    for ( k = limite-1; k >= 0; k-- ){
       for ( l = 0; l < limite; l++ ){
          printf("%c ", matriz[k][l] );
       }
       printf("\n" );
   }
   /*for ( m = xf; m >= 0; m-- ){
      for ( n = 0; n <= yf; n++ ){
         printf("%c ", matriz[m][n] );
      }
      printf("\n" );
  }*/

}//main
