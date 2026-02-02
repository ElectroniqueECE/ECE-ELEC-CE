// TP 9  - MFCC - //
// A complété

#include <Arduino.h>
#include <arduinoMFCC.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// ==================  MFCC ================== // 

// TODO

// #define MFCC_SIZE 
// #define DCT_MFCC_SIZE 

// #define FRAME_SIZE  
// #define FREQ_ECH 


// Déclaration de l'objet MFCC
arduinoMFCC mymfcc(MFCC_SIZE,DCT_MFCC_SIZE, FRAME_SIZE, FREQ_ECH);


// vecteur de données
float frame[FRAME_SIZE];
// vecteur de coefficient finaux ( pre-DCT)
float mfcc[MFCC_SIZE];

// vecteur de coefficient finaux ( post-DCT)
float dct_mfcc[MFCC_SIZE];


// ==================  OLED ================== // 

// Définition des Paramètres OLED 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET-1// (-1 partage le pin de reset Arduino)
#define OLED_ADDR 0x3C

#define DENSITY 5
#define NUM_FRAME_DISP 10
#define FRAME_DISP_SIZE int(SCREEN_WIDTH / NUM_FRAME_DISP)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,&Wire, OLED_RESET);

int currentXInit = 0; 


// Initialisation de l'écran OLED
void setupOLED() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 allocation failed, check screen adress, or connection"));
    while(1) {}
  }
  
}

// Initialisation de l'ADC
void setupADC() {

  // TODO

}

// Fonction de remplissage du buffer
void fillBuffer() {

  // TODO 


// Affichage du gradian en fonction de l'intensité du coefficiant passé en paramètre
void displayGradian(int x1, int y1, int width, int height, int density) {

  for(int y=y1 ; y < y1 + height; y++) { 
    int densityCounter = 0;
    int offset = (y%2 ? density/2 : 0); // offset pour décaler les lignes impaires 
    for (int x = x1 + offset; x < x1 + width + offset; x++) {
      densityCounter = (densityCounter+1)%density;  
      if(densityCounter == 0) display.drawPixel(x, y, 1);
      else display.drawPixel(x, y, 0);
    }
  }
}

// Affichage des coefficients MFCC
void displayCoeff(int coeff_size) {
    
  int maxVal = 450;
  int minVal = 260;

  //Serial.println(maxVal); fonctions de debug si besoin
  //Serial.println(minVal);
  
  int size = int( SCREEN_HEIGHT/coeff_size )+1; // taille de chaque barre en fonction du nombre de canaux

  for(int i=0; i < coeff_size; i++) displayGradian(currentXInit, size*i, FRAME_DISP_SIZE,size, map((int)(mfcc[coeff_size - 1 - i]*100),minVal, maxVal, 6, 1));
   
  currentXInit += FRAME_DISP_SIZE; // incrémentation de la position de départ de la prochaine frame
  
  if(currentXInit > SCREEN_WIDTH) { // Retour à la position initiale si on dépasse la largeur de l'écran
    currentXInit = 0;
    display.clearDisplay();
    
  }
  display.display(); // Affichage de la frame
  
}


void setup() {
  Serial.begin(9600);
  setupOLED();
  setupADC();
  
  currentXInit = 0;

  // TODO
  
}

void loop() {
 // TODO

}