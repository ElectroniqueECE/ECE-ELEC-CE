double x(1.),dx(1.),eps(1.e-15);
long i(0),i_max(100);

double f(double);
double df(double x);
double d2f(double x);

void setup() {
  Serial.begin(9600);

  delay(1000); 
  do{
    Serial.print("x=");
    Serial.println(x,15);
    i++;
    // dx=;    
    x+=dx;    
    
  }while((i<i_max)&&(fabs(dx)>eps));
  Serial.print("nombre d iterations = ");
  Serial.println(i);
  Serial.println("Vérification...");
  Serial.print("f(x)=");
  Serial.println(f(x),15);
}

void loop() {
}

double f(double x)
{
  //return ;
}

double df(double x)
{
  //return ;
}


double d2f(double x)
{
  //return ;
}
