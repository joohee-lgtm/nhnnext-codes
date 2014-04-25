int val;
int LED = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

}

void loop()
{
  val = analogRead(A5);
  Serial.println(val);
  if (val > 30){
    digitalWrite(LED,HIGH);
    delay(10);
    digitalWrite(LED,LOW);
  }
  delay(300);
}

