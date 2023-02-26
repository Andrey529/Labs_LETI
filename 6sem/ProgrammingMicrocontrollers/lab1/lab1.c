void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  //attachInterrupt(2, stateMove, CHANGE);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, INPUT);
}
 
int state = LOW;
int stateMove(){
  state = !state;
  return state;
}
 
// the loop function runs over and over again forever
void loop() {
 
  if(digitalRead(2)){
    stateMove();
    delay(200);
  }
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