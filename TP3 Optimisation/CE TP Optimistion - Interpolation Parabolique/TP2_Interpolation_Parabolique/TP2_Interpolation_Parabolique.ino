double x0(0.0),x1(1.0),x2(2.0),x3(0.0);
long i(0),i_max(50);
double eps(1.e-15),dx(1.0);

double f(double);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  delay(5000); // le temps de se placer dans la console série !
  do{
    i++;
    x3=(f(x0)*(x1*x1-x2*x2)+f(x1)*(x2*x2-x0*x0)+f(x2)*(x0*x0-x1*x1))/(2.*f(x0)*(x1-x2)+2.*f(x1)*(x2-x0)+2.*f(x2)*(x0-x1));
    dx=x2-x3;
    x0=x1;
    x1=x2;
    x2=x3;
    Serial.println(x3,19);
  }while((i<i_max)&&(fabs(dx)>eps));
}

void loop() {
  // put your main code here, to run repeatedly:

}

double f(double x)
{
  return -1.6*pow(x,6)-3.*pow(x,4)+10.*x;
}
