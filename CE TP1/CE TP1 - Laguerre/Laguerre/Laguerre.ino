double x(1000.),dx(1.),eps(1.e-14);
long i(0),i_max(100);
unsigned long temps1(0.),temps2(0.),deltatemps(0.);

double f(double);
double df(double);
double d2f(double);
double signe(double x);

void setup() {
  Serial.begin(9600);

  delay(1000); 
  temps1=micros();
  do{
    Serial.print("x=");
    Serial.println(x,14);
    i++;
    dx=-2.*f(x)/(df(x)+signe(df(x))*sqrt(df(x)*df(x)-2.*f(x)*d2f(x)));    
    x+=dx; 
    
  }while((i<i_max)&&(fabs(dx)>eps));  //
  temps2=micros();
  deltatemps=temps2-temps1;
  Serial.print("f(x) = ");
  Serial.println(f(x),14);
  Serial.print("nombre d iterations = ");
  Serial.println(i-1);
  Serial.print("Dt (ms)= ");
  Serial.println(deltatemps);

}

void loop() {
}

double f(double x)
{
  return x*x-x-1.;
}


double df(double x)
{
  return 2.*x-1.;
}


double d2f(double x)
{
  return 2.;
}

double signe(double x)
{
  if(x<0)
    return -1.;
    else
    return 1.;
}