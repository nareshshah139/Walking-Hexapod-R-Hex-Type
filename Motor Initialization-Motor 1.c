void setup()
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}
int turns =0;
int count =0;
int current_value =0;
int previous_value =0;

void loop()
{
  if(turns ==1)
  {
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  else
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    current_value = analogRead(1);
    
    if(current_value > 800)
    {
      if(count == 57)
      {
        turns++;
        count++;
      }
    else count++;
    Serial.print("TURNS:");
    Serial.println(turns);
    Serial.print("COUNT:");
    Serial.println(count);
    Serial.println(current_value);
    previous_value =current_value;
    delay(125);
    }
  }
}
    
