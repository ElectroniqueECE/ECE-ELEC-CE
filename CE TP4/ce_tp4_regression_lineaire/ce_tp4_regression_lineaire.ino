double n = 0.; //Nombre de cycles
double theta0 = 0.; 
double theta1 = 0.;
double thetaN0 = 0.0;  //theta0 N+1
double thetaN1 = 0.0; //theta1 N+1
double m  = 24.;      //Nombre de valeurs

//A modifier pour l'entrainement

double eps = 0.5;    //Objectif d'erreur
double alpha = 0.0005;    //Taux d'apprentissage

//Valeurs d'entrainements
double xi[] = {5.,5.,5.,5.,10.,10.,10.,10.,30.,30.,30.,30.,45.,45., 45.,45.,70.,70.,70.,70.,90.,90,90.,90};
double yi[] = {8.000,8.300,8.000,8.100,9.900,9.900,10.000,10.700,16.500,16.800,16.020, 16.150, 21.290, 21.620, 21.000, 20.700, 28.900, 28.200, 27.950, 27.810, 34.160,34.520,34.250,35.160};
//Yi en k RPM


//Todo Fonction de prédiction duty cycle => vitesse
double predictVitesse(...) {
  
}

//Todo Fonction de prédiction vitesse => duty cycle
double predictDuty(...){
  
}

//Todo Fonction d'hypothese linéaire
double hypRLin(...) {
  
}

void setup() {
  Serial.begin(115200);
  //Todo Entrainement + prediction

}

void learnerMLR() {
  double erreur = 0.0; 
  double resHyp = 0.0;
  double tmpSomme0 = 0.0;
  double tmpSomme1 = 0.0;
  do {
    //Todo: Descente de gradient 
    //Regression lineaire
    erreur = 0.0;


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
