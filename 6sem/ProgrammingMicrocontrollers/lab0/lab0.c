// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(4, OUTPUT);
}
 
 
void fastBlink(){
  digitalWrite(4,HIGH);
  delay(200);
  digitalWrite(4,LOW);
  delay(100);
}
 
void slowBlink()
{
  digitalWrite(4,HIGH);
  delay(500);
  digitalWrite(4,LOW);
  delay(100);
}
 
void word1 (){
  fastBlink();
  slowBlink();
  fastBlink();
  fastBlink();
  delay(2000);
}
 
void word2(){
  fastBlink();
  delay(2000);
}
 
void word3(){
  slowBlink();
  delay(2000);
}
 
void word4(){
  fastBlink();
  fastBlink();
  delay(2000);
}
 
// the loop function runs over and over again forever
void loop() { 
 word1();
 word2();
 word3();
 word4(); 
}