
long tiempo =0;
int boton=4;
int estadobom=LOW;
int A=12;
int B=11;

//bomba
int a=2;
int c=13;

//puerta electrica
int b=3;
int x=7;
int d=9;
int estado1=LOW;
int state=HIGH;
int estado=LOW;
//aire acondicionado
int aire=8;
void setup() {
  // put your setup code here, to run once:
  pinMode (A, OUTPUT);
  pinMode (B, OUTPUT);
  pinMode (aire, OUTPUT);

  pinMode (a, INPUT_PULLUP);
  digitalWrite(a, HIGH);
  attachInterrupt(digitalPinToInterrupt(a),bomba,HIGH);
  pinMode (c, OUTPUT);
  pinMode (x, OUTPUT);

  digitalWrite(b, HIGH);
  attachInterrupt(digitalPinToInterrupt(b),puerta,CHANGE);
  pinMode (b, INPUT_PULLUP);
  pinMode (d, OUTPUT);


  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(aire, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  delay(7000);
 
  
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  delay(6000);
  
  digitalWrite(A, LOW);
  delay(4000);

  digitalWrite(aire, LOW);
  delay(2000);
  digitalWrite(aire, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  delay(6000);

  Serial.print("termino el dia   ");

}

void bomba(){
   if (millis()>(tiempo+500)){
      digitalWrite(c ,estadobom);
      estadobom = !estadobom;
      Serial.print("CAMBIO DE ESTADO DE LA BOMBA   ");
    }
  tiempo=millis();
}

void puerta(){
  if (millis()>(tiempo+500)){
    digitalWrite(d,estado1); 
    digitalWrite(x,estado);
  
  if(state){
    estado1=!estado1;
    estado=LOW;
    Serial.print(" cerro la puerta   ");
  }else{
    estado=!estado;
    estado1=LOW;
    Serial.print(" abrio la puerta   ");
  }
  state=!state;
  
  //digitalWrite(d ,estadobom);
  //estadobom = !estadobom;
  //Serial.print("abrio o cerro la puerta");
  tiempo=millis();
}
}
