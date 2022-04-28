int Gatillo_1 = 22;
int eco_1 = 23;
int Gatillo_2 = 24;
int eco_2 = 25;
int buzzer = 3;
int duracion_1;
int distancia_1;
int duracion_2;
int distancia_2;
int paso = 50;
int nivel;
int motor = 52;

void setup() {
  pinMode(Gatillo_1,OUTPUT);
  pinMode(eco_1,INPUT);
  pinMode(Gatillo_2,OUTPUT);
  pinMode(eco_2,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(motor,OUTPUT);
}

void loop() {
  digitalWrite(Gatillo_1,HIGH);
  delay(10);
  digitalWrite(Gatillo_1,LOW);
  duracion_1 = pulseIn(eco_1,HIGH);
  distancia_1 = duracion_1/58.2;
  
  digitalWrite(Gatillo_2,HIGH);
  delay(10);
  digitalWrite(Gatillo_2,LOW);
  duracion_2 = pulseIn(eco_2,HIGH);
  distancia_2 = duracion_2/58.2;
  if (distancia_2 > 11){
    digitalWrite(motor,HIGH);
  }
  else{
    digitalWrite(motor,LOW);
  }
  if(distancia_1 <= paso*4 && distancia_1 > paso*3 ){
    nivel = 50;
  }
  else if(distancia_1 <= paso*3 && distancia_1 > paso*2 ){
    nivel = 100;
  }
  else if(distancia_1 <= paso*1 && distancia_1 > 0 ){
    nivel = 255;
  }
  else{
    nivel = 0;  
  }
  analogWrite(buzzer,nivel);
}
