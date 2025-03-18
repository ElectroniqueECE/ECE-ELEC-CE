#include "cnn.h"

void maxPooling(const float pool_in[DATA_ROW][DATA_COL], float pool_out[DATA_ROW/POOL_SIZE][DATA_COL/POOL_SIZE] )
{
  for(int i = 0; i < DATA_ROW/POOL_SIZE; i++) {
    for(int j = 0; j < DATA_ROW/POOL_SIZE; j++) {
      float maxVal = -INFINITY;
      for(int k = 0; k < POOL_SIZE; k++) {
        for(int l = 0; l < POOL_SIZE; l++) {
          maxVal = max(maxVal, pool_in[i*POOL_SIZE + k][j*POOL_SIZE + l]);
        }
      }
      pool_out[i][j] = maxVal;
    }
  }
}

void Convolution2D(const float input[DATA_ROW][DATA_COL], const float kernel[KERNEL_SIZE][KERNEL_SIZE], float output[DATA_ROW][DATA_COL])
{
    float paddedInput[DATA_ROW+KERNEL_SIZE-1][DATA_COL+KERNEL_SIZE-1];
    for(int i = 0; i < DATA_ROW+KERNEL_SIZE-1; i++) {
        for(int j = 0; j < DATA_COL+KERNEL_SIZE-1; j++) {
            if(i < KERNEL_SIZE/2 || i >= DATA_ROW+KERNEL_SIZE/2 || j < KERNEL_SIZE/2 || j >= DATA_COL+KERNEL_SIZE/2) {
                paddedInput[i][j] = 0;
            } else {
                paddedInput[i][j] = input[i-KERNEL_SIZE/2][j-KERNEL_SIZE/2];
            }
        }
    }

    for(int i = 0; i < DATA_ROW; i++) {
        for(int j = 0; j < DATA_COL; j++) {
            float sum = 0;
            for(int k = 0; k < KERNEL_SIZE; k++) {
                for(int l = 0; l < KERNEL_SIZE; l++) {
                    sum += paddedInput[i+k][j+l] * kernel[k][l];
                }
            }
            output[i][j] = sum;
        }
    }
}

void maxPooling_2(const float pool_in[(DATA_ROW/POOL_SIZE)][(DATA_COL/POOL_SIZE)], float pool_out[(DATA_ROW/POOL_SIZE)/POOL_SIZE][(DATA_COL/POOL_SIZE)/POOL_SIZE] )
{
  for(int i = 0; i < (DATA_ROW/POOL_SIZE)/POOL_SIZE; i++) {
    for(int j = 0; j < (DATA_COL/POOL_SIZE)/POOL_SIZE; j++) {
      float maxVal = -INFINITY;
      for(int k = 0; k < POOL_SIZE; k++) {
        for(int l = 0; l < POOL_SIZE; l++) {
          maxVal = max(maxVal, pool_in[i*POOL_SIZE + k][j*POOL_SIZE + l]);
        }
      }
      pool_out[i][j] = maxVal;
    }
  }
}

void Convolution2D_2(const float input[((DATA_ROW/POOL_SIZE)/POOL_SIZE)][(DATA_COL/POOL_SIZE)], const float kernel[KERNEL_SIZE][KERNEL_SIZE], float output[(DATA_ROW/POOL_SIZE)][(DATA_COL/POOL_SIZE)])
{
    float paddedInput[(DATA_ROW/POOL_SIZE)+KERNEL_SIZE-1][(DATA_COL/POOL_SIZE)+KERNEL_SIZE-1];
    for(int i = 0; i < (DATA_ROW/POOL_SIZE)+KERNEL_SIZE-1; i++) {
        for(int j = 0; j < (DATA_COL/POOL_SIZE)+KERNEL_SIZE-1; j++) {
            if(i < KERNEL_SIZE/2 || i >= (DATA_ROW/POOL_SIZE)+KERNEL_SIZE/2 || j < KERNEL_SIZE/2 || j >= (DATA_COL/POOL_SIZE)+KERNEL_SIZE/2) {
                paddedInput[i][j] = 0;
            } else {
                paddedInput[i][j] = input[i-KERNEL_SIZE/2][j-KERNEL_SIZE/2];
            }
        }
    }

    for(int i = 0; i < (DATA_ROW/POOL_SIZE); i++) {
        for(int j = 0; j < (DATA_COL/POOL_SIZE); j++) {
            float sum = 0;
            for(int k = 0; k < KERNEL_SIZE; k++) {
                for(int l = 0; l < KERNEL_SIZE; l++) {
                    sum += paddedInput[i+k][j+l] * kernel[k][l];
                }
            }
            output[i][j] = sum;
        }
    }
}




void flatten2vector(float input[DATA_ROW/(POOL_SIZE*LAYER)][DATA_COL/(POOL_SIZE*LAYER)], float output[(DATA_ROW/(POOL_SIZE*LAYER)) * (DATA_COL/(POOL_SIZE*LAYER))]) 
{
  int idx = 0;
  for(int i = 0; i < DATA_ROW/(POOL_SIZE*LAYER); i++) {
    for(int j = 0; j < DATA_COL/(POOL_SIZE*LAYER); j++) {
      
      output[idx] = input[i][j];
      idx++;
      
    }
  }
}

void cnn(const float input[DATA_ROW][DATA_COL], float output[(DATA_ROW/(POOL_SIZE*LAYER)) * (DATA_COL/(POOL_SIZE*LAYER))])
{
    float conv1[DATA_ROW][DATA_COL];
    Convolution2D(input, kernel1, conv1);
    float pool1[DATA_ROW/POOL_SIZE][DATA_COL/POOL_SIZE];
    maxPooling(conv1, pool1);
    // float conv2[(DATA_ROW/POOL_SIZE)][(DATA_COL/POOL_SIZE)];
    // Convolution2D_2(pool1, kernel1, conv2);
    // float pool2[(DATA_ROW/POOL_SIZE)/POOL_SIZE][(DATA_COL/POOL_SIZE)/POOL_SIZE];
    // maxPooling_2(conv2, pool2);

    flatten2vector(pool1, output);
    //testPrint(output);
  
}



void testPrint(float output[(DATA_ROW/(POOL_SIZE*LAYER)) * (DATA_COL/(POOL_SIZE*LAYER))])
{
    for(int i = 0; i < (DATA_ROW/(POOL_SIZE*LAYER)) * (DATA_COL/(POOL_SIZE*LAYER)); i++) {
        Serial.print(output[i]);
        Serial.print(" ");
    }
    Serial.println();
}
