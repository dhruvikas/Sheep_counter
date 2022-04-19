int tr1 = 4, ech1 = 3; // trigger and echo pin - 1
int tr2 = 9, ech2 = 8; // trigger and echo pin - 2

int c = 0; // counter 

void setup()
{
  pinMode(tr1, OUTPUT);
  pinMode(tr2, OUTPUT);
  pinMode(ech1, INPUT);
  pinMode(ech2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  float ur1, ur2;
  float dit1, dit2;
  float gate = 150;
  
  //to clear out the trigger pins
  digitalWrite(tr1, LOW);
  delayMicroseconds(2);
  digitalWrite(tr2, LOW);
  delayMicroseconds(2); 
  
  // entering sheep
  digitalWrite(tr1, HIGH);
  delayMicroseconds(10);
  digitalWrite(tr1, LOW);  
  ur1 = pulseIn(ech1, HIGH);  
  dit1 = 0.034*(ur1/2);
  
  // exiting sheep
  digitalWrite(tr2, HIGH);
  delayMicroseconds(10);
  digitalWrite(tr2, LOW);  
  ur2 = pulseIn(ech2, HIGH);  
  dit2 = 0.034*(ur2/2);
  
  if(dit1<gate)
  {
    c++;
    delay(700); //assuming this as the avg time it takes for a sheep to pass the gate 
  }
  
  if(dit2<gate)
  {
    if(c>0){
      c--;
      delay(700);
    }  	
  }
  
  Serial.print("\nNumber of Sheeps Inside = ");
  Serial.println(c);
  delay(500);
}