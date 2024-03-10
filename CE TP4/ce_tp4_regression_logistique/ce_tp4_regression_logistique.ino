float n = 0.;  //Nombre de cycles
float theta0 = 0.; 
float theta1 = 0.;
float thetaN0 = 0.0; //theta0 N+1
float thetaN1 = 0.0; //theta1 N+1
float m  = 10.;      //Nombre de valeurs

//A modifier l'entrainement

float eps = 0.0005;    //Objectif d'erreur
float alpha = 0.00001; //Taux d'apprentissage


//Valeurs d'entrainements
float xi[] = {-255, 70, -128,-60, -50, 80, 30, 128, 200, -80};
float yi[] = {0,1,0,0,0,1,1,1,1,0};


//Todo fonction de prediction
float predict(...) {
  
}

//Todo fonction hypothese logistique binaire
float hypRLogBin(...) {
  
}

void setup() {
  Serial.begin(115200);
  //Todo Entrainement + prediction

}

void learnerMLRLog() {
  float erreur = 0.0; 
  float resLog = 0.0;
  float tmpSomme0 = 0.0;
  float tmpSomme1 = 0.0;
  do {
    //Todo: Descente de gradient 
    //Regression logistique



    Serial.print("Erreur: ");
    Serial.println(erreur,6);
  } while (eps<erreur);
  Serial.print("Theta0: ");
  Serial.println(theta0,6);
  Serial.print("Theta1: ");
  Serial.println(theta1,6);
  Serial.print("Nombre de cycles: ");
  Serial.println(n);
}

//Rien dans la loop
void loop() {}
