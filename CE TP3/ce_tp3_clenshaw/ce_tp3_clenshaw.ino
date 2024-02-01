#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 afficheur(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

int couleur=1; // couleur WHITE
float max=0.,min=0.;

// déclarations pour Clenshaw
#define N 9
int n=5;
float c[N]={0.,0.,0.,0.,0.,1.,0.,0.,0.}; // ici H5(x) sortira de ce code
float u[N+2]={0.};


float y[SCREEN_WIDTH]={0.};   // la fonction a tracer

float clenshaw(float x);
float calcule_y(float x1,float x2);
void max_min();

void affiche_courbe(float x1,float x2);

void setup() {
  Serial.begin(115200);
  if(!afficheur.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println(F("SSD allocation failed"));
    for(;;);
  }
  delay(2000);
  afficheur.clearDisplay();
  afficheur.setTextSize(1);
  afficheur.setTextColor(WHITE);
  afficheur.setCursor(0,10);
  afficheur.println("ECE-CLENSHAW !");
  afficheur.display();
  delay(4000);

  afficheur.clearDisplay();
  afficheur.display();


  affiche_courbe(-2.,2.);
  afficheur.display();
  delay(2000);

}

void loop() {

}


float clenshaw(float x)
{
 
 // return ;
}

float calcule_y(float x1,float x2)
{

 //   y[i]=clenshaw(x);

}

void max_min()
{

   //   max=;

   //   min=;

}

void affiche_courbe(float x1,float x2){
  int ordonnee=0;
  couleur=1;
  calcule_y(x1,x2);
  max_min();

  for(int i=0;i<SCREEN_WIDTH;i++){
    ordonnee=32+(int)(32.*(y[i]-min)/(min-max)); 
    afficheur.drawPixel(i,ordonnee,couleur);
  }

  afficheur.display();
  delay(100);
}