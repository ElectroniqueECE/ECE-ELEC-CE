// TP 9 - MFCC / FFT 
// FFT + Affichage OLED ( à compléter )


#include <Arduino.h>
#include <arduinoFFT.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// ==================  FFT  ==================

// Définition des paramètres FFT

// vecteur de données

// TODO 

// #define BUFFER_SIZE 
// #define SAMPLING_FREQ
// #define FFT_SIZE

double vReal[BUFFER_SIZE];
double vImag[BUFFER_SIZE];



// ==================  OLED ==================

// Définition des Paramètres OLED 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET-1// (-1 partage le pin de reset Arduino)
#define OLED_ADDR 0x3C


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,&Wire, OLED_RESET);


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

}

void setup() {
  Serial.begin(9600);
  setupOLED();
  setupADC();

}

int barLength(double d) {
  float fy;
  int y;
  fy = 10.0 * (log10(d) + 1.1) ;
  y = fy;
  y = constrain(y, 0, 56+30)- 30;
  return y;
}

void showSpectrum() {

  int maxValue = 0;
  int peak_freq = 0;
  int displayFFTvalue[FFT_SIZE];
  for(int i = 0; i < FFT_SIZE; i++) {
    if(vReal[i] > maxValue) {
      maxValue = vReal[i];
      // peak_freq = TODO
    }

  }
  for(int i = 0; i < FFT_SIZE; i++) displayFFTvalue[i] = barLength(vReal[i]);



  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("PEAK :");
  display.print(peak_freq);
  for(int i = 0; i < FFT_SIZE; i++) {
    display.drawLine(i, 64, i,64 - displayFFTvalue[i], WHITE);
  }

}

void loop() {


  fillBuffer();
  ArduinoFFT<double> FFT = ArduinoFFT<double>(vReal, vImag, BUFFER_SIZE, SAMPLING_FREQ); /* Create FFT object */
  FFT.dcRemoval();
  FFT.windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);               /* Weigh data */
  FFT.compute(vReal, vImag, BUFFER_SIZE, FFT_FORWARD);            /* Compute FFT */
  FFT.complexToMagnitude(vReal, vImag, BUFFER_SIZE);              /* Compute magnitudes */           

    //Display clear
    display.clearDisplay();
    showSpectrum();
    //showOthers();
    display.display();

}