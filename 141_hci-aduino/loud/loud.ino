int val;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  val = analogRead(A5);
  Serial.println(val);
  delay(100);
}

