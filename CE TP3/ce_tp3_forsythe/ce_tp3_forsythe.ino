#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 afficheur(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

int couleur=1;
float max=0.,min=0.;

// déclarations pour Clenshaw
#define N 9
int n=9; 

float c[N]={0.};
float u[N+2]={0.};

// datas pour Forsythe
#define NDATA 9
int ndata=9;
float xi[NDATA]={-2.,-1.5,-1.,-0.5,0.,0.3,0.6,1.2,1.7};
float yi[NDATA]={0.0183,0.1054,0.3678,0.7788,1.,0.9139,0.6976,0.2369,0.0555};
float wi[NDATA]={1.,1.,1.,1.,1.,1.,1.,1.,1.};

float y[SCREEN_WIDTH]={0.};   // la fonction a tracer

float clenshaw(float x);
float calcule_y(float x1,float x2);
void max_min();

void affiche_datas();
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
  afficheur.println("ECE-FORSYTHE !");
  afficheur.display();
  delay(4000);

  afficheur.clearDisplay();
  afficheur.display();

 // affiche_courbe(-2.,2.);
  affiche_datas();

  afficheur.display();
  delay(2000);

}

void loop() {

}


float clenshaw(float x)
{
  

}

float calcule_y(float x1,float x2)
{
  
}

void max_min()
{
 
}

void affiche_datas()
{
  // a enlever ensuite
  min=0.;
  max=1.5;
  // au dessus
  int abscisse=0;
  int ordonnee=0;
  couleur=1;

  for(int i=0;i<n;i++){
    float deltax=xi[N-1]-xi[0];
    abscisse=(int)(128*(xi[i]-xi[0])/deltax);
    ordonnee=32+(int)(32.*(yi[i]-min)/(min-max)); 
    afficheur.fillCircle(abscisse,ordonnee,2,couleur);
  }

  afficheur.display();
  delay(100);
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