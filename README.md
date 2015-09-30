Algoritmo de Bresenham
para el dibujado de lineas implementado en C,

30/sep/2015
Ahora el archivo principal es poligono.c,
desde ahi se mandan a llamar polares.c y;
segun se comente o descomente en los #include de poligono,
se usará brecaso1.c, o bresenham_v2.c

USOS:
* brecaso1.c -> si sólo se desean graficar partes positivas
* bresenham_v2 -> si se desea graficar positivas y negativas

TODO:
* [x] - casos con pendientes negativas
* [x] - pruebas con coordenadas negativas
* [ ] - íngreso de datos desde el teclado
