int PIN_UE = A0;
int PIN_UD = A1;

long UE(0), UD(0), UR(0);
double ue(0.), ud(0.), ur(0.), id(0.);

void setup() {
  pinMode(PIN_UE, INPUT);
  pinMode(PIN_UD, INPUT);
  Serial.begin(9600);
}
void loop() {
  UE = analogRead(PIN_UE);
  ue = (double)(UE * 3.3 / 1024.);

  UD = analogRead(PIN_UD);
  ud = (double)(UD * 3.3 / 1024.);

  ur = ue - ud;
  id = ur;  // en mA car R0=1k

  if (Serial.available()) {
    Serial.print("Ue=");
    Serial.println(ue);
    Serial.print("Id(micro-A)=");
    Serial.println(id * 1000.);
    Serial.print("Ud=");
    Serial.println(ud);
    delay(3000);
  }
}