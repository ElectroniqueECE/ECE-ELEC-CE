double x(1000.),dx(1.),eps(1.e-15);
long i(0),i_max(100),p(1);

double f(double);
double df(double x);

void setup() {
  Serial.begin(9600);

  delay(1000); 
  do{
    Serial.print("x=");
    Serial.println(x,15);
    i++;
    dx=-f(x)/df(x);    
    x+=dx;    
    
  }while((i<i_max)&&(fabs(dx)>eps));
  Serial.print("nombre d iterations = ");
  Serial.println(i);

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

