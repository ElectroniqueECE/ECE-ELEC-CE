double n = 0.; //Nombre de cycles
double theta0 = 0.; 
double theta1 = 0.;
double thetaN0 = 0.0;  //theta0 N+1
double thetaN1 = 0.0; //theta1 N+1
double m  = 24.;      //Nombre de valeurs

//A modifier pour l'entrainement

double eps = 100000.;    //Objectif d'erreur
double alpha = 0.0005;    //Taux d'apprentissage

//Valeurs d'entrainements
double xi[] = {5.,5.,5.,5.,10.,10.,10.,10.,30.,30.,30.,30.,45.,45., 45.,45.,70.,70.,70.,70.,90.,90,90.,90};
double yi[] = {8000.,8300.,8000.,8100.,9900.,9900.,10000.,10700.,16500.,16800.,16020., 16150., 21290., 21620., 21000., 20700., 28900., 28200., 27950., 27810., 34160.,34520.,34250.,35160.};


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


    Serial.print("Erreur Cumulee: ");
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
