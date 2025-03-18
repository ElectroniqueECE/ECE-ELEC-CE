double x(1.),dx(1.),eps(1.e-15);
long i(0),i_max(100),p(1);

double f(double x);
double df(double x);
double d2f(double x);

void setup() {
  Serial.begin(9600);

  delay(1000); 
  do{
    Serial.print("x=");
    Serial.println(x,15);
    i++;
    dx=-df(x)/d2f(x);    
    x+=dx;    
    
  }while((i<i_max)&&(fabs(dx)>eps));
  Serial.print("nombre d iterations = ");
  Serial.println(i);

}

void loop() {
}

double f(double x)
{
  return -1.6*pow(x,6)-3.*pow(x,4)+10.*x;
}

double df(double x)
{
  return -9.6*pow(x,5)-12.*pow(x,3)+10.;
}

double d2f(double x)
{
  return -48.*pow(x,4)-36.*pow(x,2);
}


