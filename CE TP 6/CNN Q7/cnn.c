#include "cnn.h"

void maxPooling(const float pool_in[DATA_SIZE][DATA_SIZE], float pool_out[DATA_SIZE/POOL_SIZE][DATA_SIZE/POOL_SIZE] )
{
 // à compléter                                                                                                                                                             
}

void Convolution2D(const float input[DATA_SIZE][DATA_SIZE], const float kernel[KERNEL_SIZE][KERNEL_SIZE], float output[DATA_SIZE][DATA_SIZE])
{
    // à compléter ( attention au padding !)
}

void maxPooling_2(const float pool_in[(DATA_SIZE/POOL_SIZE)][(DATA_SIZE/POOL_SIZE)], float pool_out[(DATA_SIZE/POOL_SIZE)/POOL_SIZE][(DATA_SIZE/POOL_SIZE)/POOL_SIZE] )
{
  // // à compléter ( même code que Convolution2D, mais en adaptant les dimensions des tableaux ! )
}

void Convolution2D_2(const float input[((DATA_SIZE/POOL_SIZE)/POOL_SIZE)][(DATA_SIZE/POOL_SIZE)], const float kernel[KERNEL_SIZE][KERNEL_SIZE], float output[(DATA_SIZE/POOL_SIZE)][(DATA_SIZE/POOL_SIZE)])
{
    // à compléter ( même code que Convolution2D, mais en adaptant les dimensions des tableaux ! Attention au padding !)
}




void flatten2vector(float input[DATA_SIZE/(POOL_SIZE*LAYER)][DATA_SIZE/(POOL_SIZE*LAYER)], float output[(DATA_SIZE/(POOL_SIZE*LAYER)) * (DATA_SIZE/(POOL_SIZE*LAYER))]) 
{
  // à compléter
}

void cnn(const float input[DATA_SIZE][DATA_SIZE], float output[(DATA_SIZE/(POOL_SIZE*LAYER)) * (DATA_SIZE/(POOL_SIZE*LAYER))])
{
    float conv1[DATA_SIZE][DATA_SIZE];
    Convolution2D(input, kernel1, conv1);
    float pool1[DATA_SIZE/POOL_SIZE][DATA_SIZE/POOL_SIZE];
    maxPooling(conv1, pool1);
    float conv2[(DATA_SIZE/POOL_SIZE)][(DATA_SIZE/POOL_SIZE)];
    Convolution2D_2(pool1, kernel1, conv2);
    float pool2[(DATA_SIZE/POOL_SIZE)/POOL_SIZE][(DATA_SIZE/POOL_SIZE)/POOL_SIZE];
    maxPooling_2(conv2, pool2);

    flatten2vector(pool2, output);
    //testPrint(output); // fonction pour afficher le vecteur de sortie
  
}



void testPrint(float output[(DATA_SIZE/(POOL_SIZE*LAYER)) * (DATA_SIZE/(POOL_SIZE*LAYER))])
{
    for(int i = 0; i < (DATA_SIZE/(POOL_SIZE*LAYER)) * (DATA_SIZE/(POOL_SIZE*LAYER)); i++) {
        Serial.print(output[i]);
        Serial.print(" ");
    }
    Serial.println();
}
