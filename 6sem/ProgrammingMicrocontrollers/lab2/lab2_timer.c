void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(0, swap, CHANGE);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, INPUT);
}
 
void swap(){
  if (digitalRead(2))
  {
    stateMove();
  }
}
 
int state = LOW;
int stateMove(){
  state = !state;
  return state;
}
 
// the loop function runs over and over again forever
void loop() {
  if (state == LOW) {
    digitalWrite(4,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
  } else if(state == HIGH) {
    digitalWrite(4,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
 
}