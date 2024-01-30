#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 afficheur(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

int couleur=0;
#define N 7
#define M 7
#define NB 49          // nb de neurones = N*M
#define NBMOTIFS 7

int n=7,m=7;
int nb=n*m;
int nbmotifs=7;  

int motifs[NBMOTIFS][N][M]={
{ // T
{1,1,1,1,1,1,1},
{1,1,1,1,1,1,1},
{0,0,0,1,1,0,0},
{0,0,0,1,1,0,0},
{0,0,0,1,1,0,0},
{0,0,0,1,1,0,0},
{0,0,0,1,1,0,0}
},

{ // I
{1,1,1,1,1,1,1},
{1,1,1,1,1,1,1},
{0,0,0,1,1,0,0},
{0,0,0,1,1,0,0},
{0,0,0,1,1,0,0},
{1,1,1,1,1,1,1},
{1,1,1,1,1,1,1}
},

{ // C
{1,1,1,1,1,1,1},
{1,1,1,1,1,1,1},
{1,1,0,0,0,0,0},
{1,1,0,0,0,0,0},
{1,1,0,0,0,0,0},
{1,1,1,1,1,1,1},
{1,1,1,1,1,1,1}
},

{ // O
{1,1,1,1,1,1,1},
{1,1,1,1,1,1,1},
{1,1,0,0,0,1,1},
{1,1,0,0,0,1,1},
{1,1,0,0,0,1,1},
{1,1,1,1,1,1,1},
{1,1,1,1,1,1,1}
},

{ // E
{1,1,1,1,1,1,1},
{1,1,1,1,1,1,1},
{1,1,0,0,0,0,0},
{1,1,1,1,1,1,1},
{1,1,0,0,0,0,0},
{1,1,1,1,1,1,1},
{1,1,1,1,1,1,1}
},

{ // H
{1,1,0,0,0,1,1},
{1,1,0,0,0,1,1},
{1,1,0,0,0,1,1},
{1,1,1,1,1,1,1},
{1,1,1,1,1,1,1},
{1,1,0,0,0,1,1},
{1,1,0,0,0,1,1}
},

{  // B
{1,1,1,1,1,1,0},
{1,1,1,1,1,1,1},
{1,1,0,0,0,1,1},
{1,1,1,1,1,1,0},
{1,1,0,0,0,1,1},
{1,1,1,1,1,1,1},
{1,1,1,1,1,1,0},
}
};

float T[NB][NB]={{0.}};   // les poids synapitiques entre neurones 

int neurone[N][M]={{0}};   // le réseau de neurone en mémoire

void affiche_reseau();
void copie_reseau(int num);
void reseau_ajoute_bruit();

void apprentissage();
int conversion(int x);
void convergence();

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
  afficheur.println("ECE-HOPFIELD model !");
  afficheur.display();
  delay(2000);

  afficheur.clearDisplay();
  afficheur.display();
  for(int i=0;i<nbmotifs;i++)
  {
    copie_reseau(i);
    affiche_reseau();

  delay(500);
  afficheur.clearDisplay();
  afficheur.display();
    
  }
  apprentissage(); // on lance l apprentissage des motifs !

}

void loop() {
  afficheur.clearDisplay();
  afficheur.display();

  copie_reseau(0); 
  reseau_ajoute_bruit();
  affiche_reseau();
  delay(2000);
  // convergence
  convergence();
  afficheur.clearDisplay();
  afficheur.display();

  affiche_reseau();
  afficheur.display();
  delay(2000);


}


void affiche_reseau(){

  for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
  couleur=neurone[i][j];
  afficheur.fillRoundRect(40+j*9,i*9,8,8,2,couleur); //neurone[i][j] 
  }
   }

 afficheur.display();
   delay(100);
}
void reseau_ajoute_bruit(){
  float seuil=0.8; // le modifier pour voir !
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      neurone[i][j]=(random(100)/100.>seuil) ? 1 : neurone[i][j];// on ajoute des 1 aleatoires
      neurone[i][j]=(random(100)/100.>seuil) ? 0 : neurone[i][j];  // idem avec des 0
  }
  }
  
}

void copie_reseau(int num)
{
  for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
      neurone[i][j]=motifs[num][i][j]; 
   }}

}

void apprentissage()
{
  // nb : nbre de neurones
  // nbmotifs : nbre de motifs
  float sum=0.;
  int neurone1dim[NBMOTIFS][NB]={{0}};
  for(int num_motif=0;num_motif<nbmotifs;num_motif++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        neurone1dim[num_motif][i*n+j]=motifs[num_motif][i][j];    
      }
    }  
  }

  // on calcule les T now
  for(int in=0;in<nb;in++)
  {
    for(int jn=in+1;jn<nb;jn++)
    {
  sum=0.;
  for(int num_motif=0;num_motif<nbmotifs;num_motif++)
  {
    sum+=(float)conversion(neurone1dim[num_motif][in])*(float)conversion(neurone1dim[num_motif][jn]);
  }
  T[in][jn]=sum/((float)nbmotifs);
  T[jn][in]=T[in][jn];
  }
  }

  for(int in=0;in<nb;in++)
  {
    T[in][in]=0.;
  }
}


int conversion(int x)
{
  return 2*x-1;
}


void convergence()
{
  int i_h=0,j_h=0;
  int neurone1dim[NB]={0};
  int c=5;
  float I=0.;
  for(int t=0;t<nb*c;t++)
  {
    i_h=random(n);
    j_h=random(m);
    
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        neurone1dim[i*n+j]=neurone[i][j];    
      }
    }  
    
    I=0.;
    for(int j=0;j<nb;j++)
    {
        I+=T[i_h*n+j_h][j]*(float)conversion(neurone1dim[j]);
    }
    neurone[i_h][j_h]=(I>0.) ? 1 : 0;
  }
  
}