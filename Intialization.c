int motors[6] = {2,4,6,8,10,12};
int transition_count[6] = {};

void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

int turns = 0;
int count = 0;
int current_value = 0;
int previous_value = 0;

void loop()
{
  for(int i = 0;i<6;i++)
  {
    if(turns == 1 && i!=1)
    {
      digitalWrite(motors[i],HIGH);
      digitalWrite(motors[i] + 1,HIGH);
      Serial.println("Reached Here");
    }
    else
    {
      if(i==1)
      {
        if(turns==1)
        {
          digitalWrite(4,LOW);
        }
        else
        {
          digitalWrite(4,HIGH);
          digitalWrite(5,LOW);
          
          current_value = analogRead(i);
          if(current_value > 800)
          {
            if(count == transition_count[i])
            {
              turns++;
              count++;
            }
          delay(125);  
          }
          
        }
      }
      if(i!=1)
      {
        digitalWrite(motors[i],HIGH);
        digitalWrite(motors[i]+1,LOW);
        
        current_value = analogRead(i);
        if(current_value == transition_count[i])
        {
          if(count == transition_count[i])
          {
            turns++;
            count++;
          }
        }
      }
    }
  }
}
