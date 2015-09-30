#include <stdio.h>
int limite = 22;
char matriz[22][22];
int xk, yk;

/*
main(){
    rellena();
    linea(0, 0, 4, 4);
    linea(0, 10, 4, 10);
    linea(15, 0, 15, 10);
    imprime();
}//main
*/
rellena(){
    //rellena la matriz con puntos;
    puts("rellenando");
    int i, j;
    for( i = 0; i < limite; i++){
        for(j = 0; j < limite; j++){
            matriz[i][j] = '.';
        }
    }//for
}//rellena

ejes(){
    int i, j;
    for(i = 0; i < limite; i++){
        matriz[i][0] = '|';
    }
    for(j = 0; j < limite; j++){
        matriz[0][j] = '_';
    }
}//ejes

imprime(){
    int k, l;
    //este for va imprimir la matriz al reves
    //como si de un plano cartesiano real de tratara
    for ( k = limite-1; k >= 0; k-- ){
       for ( l = 0; l < limite; l++ ){
          printf("%c ", matriz[k][l] );
       }
       printf("\n" );
    }//for
}//imprime

colocar(int x, int y){
    if((x >= 0 && y >= 0) && (x < 22 && y < 22)){
        matriz[x][y] = '@';
        puts("colocado");
    }
}//colocar

linea(int xs, int ys, int xe, int ye){
    //int xi, yi, xf, yf;
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
    int xi = xs;
    int yi = ys;
    int xf = xe;
    int yf = ye;

    //matriz[yi][xi] = 'S';
    //matriz[yi][xi] = '@';
    colocar(yi, xi);

    //calculando DELTAS
    int deltax = xf-xi;
    int deltay = yf-yi;

    //IF para linea recta subiendo por Y
    if(deltax == 0 && deltay >= 0){
        puts("caso R1");
        printf("dy %d dx %d\n", deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi;
        int yk = yi+1;

        while(yk < yf){
            colocar(yk, xk);
            printf("punto (%d, %d)\n", xk, yk);
            yk++;
        }//while
    }//IF recta sube Y

    //IF para linea recta bajando por Y
    if(deltax == 0 && deltay < 0){
        puts("caso R2");
        printf("dy %d dx %d\n", deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi;
        int yk = yi-1;

        while(yk > yf){
            colocar(yk, xk);
            printf("punto (%d, %d)\n", xk, yk);
            yk--;
        }//while
    }//IF recta baja Y

    //IF para recta que va sobre X
    if(deltay == 0 && deltax >= 0){
        puts("caso R3");
        printf("dy %d dx %d\n", deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi+1;
        int yk = yi;

        while(xk < xf){
            colocar(yk, xk);
            printf("punto (%d, %d)\n", xk, yk);
            xk++;
        }//while
    }//if recta sobre X

    //IF para recta que regresa en X
    if(deltay == 0 && deltax < 0){
        puts("caso R4");
        printf("dy %d dx %d\n", deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi-1;
        int yk = yi;

        while(xk > xf){
            colocar(yk, xk);
            printf("punto (%d, %d)\n", xk, yk);
            xk--;
        }//while
    }//if recta regresa en X

////////////////////////////////////////////////////////////////////////////////////////
// *** terminan los 4 casos de lineas rectas, vienen los casos de lineas con pendientes *** ///
////////////////////////////////////////////////////////////////////////////////////////

    //IF caso 1, m < 45° subiendo
    if(deltay > 0 && deltax > 0 && abs(deltay) <= abs(deltax)){
        printf("CASO 1\n" );
        int A = 2*deltay;
        int B = 2*deltay - 2*deltax;
        int pi = 2*deltay - deltax;
        printf("A %d B %d pk %d dy %d dx %d\n", A, B, pi, deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi;
        int yk = yi;

        while (xk != xf || yk != yf) {
            if(pi > 0){
                xk++;
                yk++;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+B;
            }//if
            else{
                xk++;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+A;
            }//else
        }//while
    }//if caso 1

    //IF caso 2, m < 45° bajando
    if(deltay < 0 && deltax < 0 && abs(deltay) <= abs(deltax)){
        printf("CASO 2\n" );
        int A = 2*deltay;
        int B = 2*deltay - 2*deltax;
        int pi = 2*deltay - deltax;
        printf("A %d B %d pk %d dy %d dx %d\n", A, B, pi, deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi;
        int yk = yi;

        while (xk != xf || yk != yf) {
            if(pi > 0){
                xk--;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+A;
            }//if
            else{
                xk--;
                yk--;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+B;
            }//else
        }//while
    }//if caso 2

    //IF caso 3, m > 45° subiendo
    if(deltay > 0 && deltax > 0 && abs(deltay) > abs(deltax)){
        printf("CASO 3\n");
        int A = 2*deltax;
        int B = 2*deltax - 2*deltay;
        int pi = 2*deltax - deltay;
        printf("A %d B %d pk %d dy %d dx %d\n", A, B, pi, deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi;
        int yk = yi;

        while (xk != xf || yk != yf) {
            if(pi > 0){
                xk++;
                yk++;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+B;
            }//if
            else{
                yk++;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+A;
            }//else
        }//while
    }//if caso 3

    //IF caso 4, m > 45° bajando
    if(deltay < 0 && deltax < 0 && abs(deltay) > abs(deltax)){
        printf("CASO 4\n");
        int A = 2*deltax;
        int B = 2*deltax - 2*deltay;
        int pi = 2*deltax - deltay;
        printf("A %d B %d pk %d dy %d dx %d\n", A, B, pi, deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi;
        int yk = yi;

        while (xk != xf || yk != yf) {
            if(pi > 0){
                yk--;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+A;
            }//if
            else{
                xk--;
                yk--;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+B;
            }//else
        }//while
    }//if caso 4

////////////////////////////////////////////////////////////////////////////////////////////////
    //CASOS DE PENDIENTES NEGATIVAS
///////////////////////////////////////////////////////////////////////////////////////////////
    //CASO 5, m < 0, bajando en X
    if(deltay < 0 && deltax > 0 && abs(deltax) > abs(deltay)){
        printf("CASO 5\n" );
        int A = -2*deltay;
        int B = -2*deltay - 2*deltax;
        int pi = -2*deltay - deltax;
        printf("A %d B %d pk %d dy %d dx %d\n", A, B, pi, deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi;
        int yk = yi;

        while (xk != xf || yk != yf) {
            if(pi > 0){
                xk++;
                yk--;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+B;
            }//if
            else{
                xk++;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+A;
            }//else
        }//while
    }//if caso 5

    //CASO 6, m < 0, subiendo en X
    if(deltay > 0 && deltax < 0 && abs(deltax) > abs(deltay)){
        printf("CASO 6\n" );
        int A = -2*deltay;
        int B = -2*deltay - 2*deltax;
        int pi = -2*deltay - deltax;
        printf("A %d B %d pk %d dy %d dx %d\n", A, B, pi, deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi;
        int yk = yi;

        while (xk != xf || yk != yf) {
            if(pi > 0){
                xk--;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+A;
            }//if
            else{
                xk--;
                yk++;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+B;
            }//else
        }//while
    }//if caso 6

    //CASO 7, m < 0, bajando por Y
    if(deltay < 0 && deltax > 0 && abs(deltax) <= abs(deltay)){
        printf("CASO 7\n" );
        int A = -2*deltax;
        int B = -2*deltax - 2*deltay;
        int pi = -2*deltax - deltay;
        printf("A %d B %d pk %d dy %d dx %d\n", A, B, pi, deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi;
        int yk = yi;

        while (xk != xf || yk != yf) {
            if(pi > 0){
                //xk++;
                yk--;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+A;
            }//if
            else{
                xk++;
                yk--;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+B;
            }//else
        }//while
    }//if caso 7

    //CASO 8, m < 0, subiendo por Y
    if(deltay > 0 && deltax < 0 && abs(deltax) <= abs(deltay)){
        printf("CASO 8\n" );
        int A = -2*deltax;
        int B = -2*deltax - 2*deltay;
        int pi = -2*deltax - deltay;
        printf("A %d B %d pk %d dy %d dx %d\n", A, B, pi, deltay, deltax);
        printf("inicio (%d, %d)\n", xi, yi);
        int xk = xi;
        int yk = yi;

        while (xk != xf || yk != yf) {
            if(pi > 0){
                xk--;
                yk++;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+B;
            }//if
            else{
                //xk++;
                yk++;
                colocar(yk, xk);
                printf("punto (%d, %d)\n", xk, yk);
                pi = pi+A;
            }//else
        }//while
    }//if caso 8

    //AJUSTES FINALES ANTES DE IMPRIMIR LA MATRIZ YA CON LA RECTA DIBUJADA
    //matriz[yf][xf] = 'E';
    //matriz[yf][xf] = '@';
    colocar(yf, xf);
    printf("final (%d, %d)\n", xf, yf);

}//linea
