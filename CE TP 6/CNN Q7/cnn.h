#include <Arduino.h>
#define POOL_SIZE 2 // max-pooling size
#define DATA_SIZE 28 // on consisdère une image de 28x28 ( donc carré )
#define KERNEL_SIZE 3
#define LAYER 2

const float kernel1[KERNEL_SIZE][KERNEL_SIZE] = {{-0.125, -0.125, -0.125}, 
                                                 {0.125, 1, -0.125}, 
                                                 {-0.125, -0.125, -0.125}};
// Première Couche 
void maxPooling(const float poolinput[DATA_SIZE][DATA_SIZE], float pool[DATA_SIZE/POOL_SIZE][DATA_SIZE/POOL_SIZE] );

void Convolution2D(const float input[DATA_SIZE][DATA_SIZE], const float kernel[KERNEL_SIZE][KERNEL_SIZE], float output[DATA_SIZE][DATA_SIZE]);

// Seconde Couche 
void Convolution2D_2(const float input[DATA_SIZE/POOL_SIZE][DATA_SIZE/POOL_SIZE], const float kernel[KERNEL_SIZE][KERNEL_SIZE], float output[DATA_SIZE/POOL_SIZE][DATA_SIZE/POOL_SIZE]);

void maxPooling_2(const float input[DATA_SIZE/POOL_SIZE][DATA_SIZE/POOL_SIZE], const float kernel[KERNEL_SIZE][KERNEL_SIZE], float pool[DATA_SIZE/(POOL_SIZE*LAYER)][DATA_SIZE/(POOL_SIZE*LAYER)] );

void flatten2vector(float input[DATA_SIZE/(POOL_SIZE*LAYER)][DATA_SIZE/(POOL_SIZE*LAYER)], float output[(DATA_SIZE/(POOL_SIZE*LAYER)) * (DATA_SIZE/(POOL_SIZE*LAYER))]);


// Fonction qui sera appelé dans le setup de votre code arduino 
// input : image de 28x28 pixels
// output : vector à 1 dimension qui sera envoyé au réseau de neurones
// Le calcule doit donc être fait pour toute les images de la base de donnée avant de les FeedForward dans le réseau de neurones ( cf Architecture du TP)
void cnn(const float input[DATA_SIZE][DATA_SIZE], float output[(DATA_SIZE/(POOL_SIZE*LAYER)) * (DATA_SIZE/(POOL_SIZE*LAYER))]);

void testPrint(float output[(DATA_SIZE/(POOL_SIZE*LAYER)) * (DATA_SIZE/(POOL_SIZE*LAYER))]);
