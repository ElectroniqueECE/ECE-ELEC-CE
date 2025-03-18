#include <Arduino.h>
#define POOL_SIZE 2 // max-pooling size
#define DATA_ROW 28
#define DATA_COL 28
#define KERNEL_SIZE 3
#define LAYER 1

const float kernel1[KERNEL_SIZE][KERNEL_SIZE] = {{0, 0.1, 0}, 
                                                 {0.1, 0.8, 0.1}, 
                                                 {0, 0.1, 0}};

void maxPooling(const float poolinput[DATA_ROW][DATA_COL], float pool[DATA_ROW/POOL_SIZE][DATA_COL/POOL_SIZE] );

void Convolution2D(const float input[DATA_ROW][DATA_COL], const float kernel[KERNEL_SIZE][KERNEL_SIZE], float output[DATA_ROW][DATA_COL]);

void Convolution2D_2(const float input[DATA_ROW/POOL_SIZE][DATA_COL/POOL_SIZE], const float kernel[KERNEL_SIZE][KERNEL_SIZE], float output[DATA_ROW/POOL_SIZE][DATA_COL/POOL_SIZE]);

void maxPooling_2(const float input[DATA_ROW/POOL_SIZE][DATA_COL/POOL_SIZE], const float kernel[KERNEL_SIZE][KERNEL_SIZE], float pool[DATA_ROW/(POOL_SIZE*LAYER)][DATA_COL/(POOL_SIZE*LAYER)] );

void flatten2vector(float input[DATA_ROW/(POOL_SIZE*LAYER)][DATA_COL/(POOL_SIZE*LAYER)], float output[(DATA_ROW/(POOL_SIZE*LAYER)) * (DATA_COL/(POOL_SIZE*LAYER))]);



void cnn(const float input[DATA_ROW][DATA_COL], float output[(DATA_ROW/(POOL_SIZE*LAYER)) * (DATA_COL/(POOL_SIZE*LAYER))]);

void testPrint(float output[(DATA_ROW/(POOL_SIZE*LAYER)) * (DATA_COL/(POOL_SIZE*LAYER))]);
