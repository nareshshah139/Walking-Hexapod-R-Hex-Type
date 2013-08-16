int speed_req = 6;
int PWM_val[6] = {191,191,191,191,191,191};
volatile long count = 0;
float Kp = 0.2;
float Kd = 0.8;
float Kp2 = 0.4;
float Kd2 = 0.8;
unsigned short int i;
int temp = 0;
unsigned short int previous[6] = {0,0,0,0,0,0};
short int count_whitetoblack[6] = {0,0,0,0,0,0};
short int count_blacktowhite[6] = {0,0,0,0,0,0};
boolean flag[6] = {0,0,0,0,0,0};
int steps = 0;
short int motor_speed_actual[6] = {0,0,0,0,0,0};
short int motor_speed_req[6] = {0,0,0,0,0,0};
float time[6] = {0,0,0,0,0,0};
float last_time[6] = {0,0,0,0,0,0};


void setup()
{
  Serial.begin(9600);
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
}

void loop()
{
  int number = 7;
  int steps = 0;
  
  // Starting conditions for motors first round
  digitalWrite(2,LOW);
  digitalWrite(7,LOW);
  digitalWrite(12,LOW);
  analogWrite(3,PWM_val[0]);
  analogWrite(6,PWM_val[2]);
  analogWrite(13,PWM_val[5]);
  
  while(millis()< 112000)
  {
    //Sensor measurements for all motors
      if(analogRead(0) > 800 && temp == 0)
      {
        count_whitetoblack[0]++;
      }
      count_blacktowhite[0] = count_whitetoblack[0] - 1;
      //Serial.println(count_whitetoblack[0]);
      if(analogRead(1) > 800 &&  temp == 1)
      {
        count_whitetoblack[1]++;
      }
      count_blacktowhite[1] = count_whitetoblack[1] - 1;
      //Serial.println(count_whitetoblack[1]);
      if(analogRead(2) > 800 && temp == 0)
      {
        count_whitetoblack[2]++;
      }
      count_blacktowhite[2] = count_whitetoblack[2] - 1;
      //Serial.println(count_whitetoblack[2]);
      if(analogRead(3) > 800 && temp == 1)
      {
        count_whitetoblack[3]++;
      }
      count_blacktowhite[3] = count_whitetoblack[3] - 1;
      //Serial.println(count_whitetoblack[3]);
      if(analogRead(4) > 800 && temp == 1)
      {
        count_whitetoblack[4]++;
      }
      count_blacktowhite[4] = count_whitetoblack[4] - 1;
      //Serial.println(count_whitetoblack[4]);
      if(analogRead(5) > 800 && temp == 0)
      {
        count_whitetoblack[5]++;
      }
      count_blacktowhite[5] = count_whitetoblack[5] - 1;
      //Serial.println(count_whitetoblack[5]);
      delay(150);
    
    //for motor 0
    //************************************
    if(count_blacktowhite[0] == 56)
    {
      flag[0] =1;
      time[0] = millis();
      motor_speed_actual[0] = (60*1000)/(time[0]-last_time[0]);
      count_blacktowhite[0] =-1;
    //  Serial.println("I have reached the end of motor 0");
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      count_whitetoblack[0] = 0;
      PWM_val[0] = UpdatePid(PWM_val[0], speed_req, motor_speed_actual[0]);
      
      temp = 1;
    }
  
    //************************************
    //For motor 1
    //************************************
    if(count_blacktowhite[1] == 56)
    {
      flag[1] =1;
      time[1] = millis();
      motor_speed_actual[1] = (60*1000)/(time[1]-last_time[1]);
      count_blacktowhite[1] =-1;
          //  Serial.println("I have reached the end of motor 1");

      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      count_whitetoblack[1] = 0;
      Serial.println(PWM_val[1]);
      PWM_val[1] = UpdatePid2(PWM_val[1], speed_req, motor_speed_actual[1]);
      Serial.println(PWM_val[1]);     
      temp = 0;  
  }
    
    //*************************************
    //For motor 2
    //*************************************
    if(count_blacktowhite[2] == 56)
    {
      flag[2] =1;
      time[2] = millis();
      motor_speed_actual[2] = (60*1000)/(time[2]-last_time[2]);
      count_blacktowhite[2] =-1;
           // Serial.println("I have reached the end of motor 2");

      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      count_whitetoblack[2] = 0;
      PWM_val[2] = UpdatePid(PWM_val[2], speed_req, motor_speed_actual[2]);
      temp = 1; 
    
  }
    //**************************************
    //For motor 3
    //**************************************
    if(count_blacktowhite[3] == 56)
    {
      flag[3] =1;
      time[3] = millis();
      motor_speed_actual[3] = (60*1000)/(time[3]-last_time[3]);
      count_blacktowhite[3] =-1;
      Serial.println("I have reached the end of motor 3");

      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      count_whitetoblack[3] = 0;
      PWM_val[3] = UpdatePid2(PWM_val[3], speed_req, motor_speed_actual[3]);
      temp = 0;
    }

    //***************************************
    //For motor 4
    //***************************************
    if(count_blacktowhite[4] == 56)
    {
      flag[4] =1;
      time[4] = millis();
      motor_speed_actual[4] = (60*1000)/(time[4]-last_time[4]);
      count_blacktowhite[4] =-1;
           // Serial.println("I have reached the end of motor 4");

      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      count_whitetoblack[4] = 0;    
      PWM_val[4] = UpdatePid2(PWM_val[4], speed_req, motor_speed_actual[4]);
      temp = 0;
    }
    
    //***************************************
    //For motor 5
    //***************************************
    if(count_blacktowhite[5] == 56)
    {
      flag[5] =1;
      time[5] = millis();
      motor_speed_actual[5] = (60*1000)/(time[5]-last_time[5]);
      count_blacktowhite[5] =-1;
            //Serial.println("I have reached the end of motor 5");

      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
      count_whitetoblack[5] = 0;  
      PWM_val[5] = UpdatePid(PWM_val[5], speed_req, motor_speed_actual[5]); 
      temp =1;
    }
    
    //***************************************
    //Starting conditions for motors 1,3,4
    //***************************************
    if(flag[0]==1 && flag[2]==1 && flag[5] ==1)
    {
      analogWrite(4,PWM_val[1]);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(5,LOW);
      analogWrite(8,PWM_val[3]);
      analogWrite(11,PWM_val[4]);      
      flag[0] = 0;
      flag[2] = 0;
      flag[5] = 0;
      last_time[1] = millis();
      last_time[3] = millis();
      last_time[4] = millis();
    }
    //*****************************************
    //Stopping conditions for all the motors after the total number of steps have been completed
    //*****************************************
    if(flag[1] == 1 && flag[3] == 1 && flag[4] == 1)
    {
      if(steps == number)
      {
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        digitalWrite(7,HIGH);
        digitalWrite(8,HIGH);
        digitalWrite(9,HIGH);
        digitalWrite(10,HIGH);
        digitalWrite(11,HIGH);
        digitalWrite(12,HIGH);
        digitalWrite(13,HIGH);
        Serial.println("Did I even reach here?");
      }
      else
      //Starting conditions for motors 0,2,5 (2nd round)
      {
        digitalWrite(2,LOW);
        digitalWrite(7,LOW);
        digitalWrite(12,LOW);
        analogWrite(3,PWM_val[0]);
        analogWrite(6,PWM_val[2]);
        analogWrite(13,PWM_val[5]);
        flag[1] = 0;
        flag[3] = 0;
        flag[4] = 0;
        last_time[0] = millis();
        last_time[2] = millis();
        last_time[5] = millis();       
        steps++;
        Serial.println(steps);
      }
    }
  }
}

int UpdatePid(int command, int targetValue, int currentValue)
{
  float pidTerm = 0;
  int error = 0;
  static int last_error = 0;
  error = abs(targetValue) - abs(currentValue);
  pidTerm = (Kp*error) + (Kd*(error - last_error));
  last_error = error;
  return constrain(command + int(pidTerm), 0 , 255);
  Serial.println("Hi, I came here and saw PID control at work");
}

int UpdatePid2(int command, int targetValue, int currentValue)
{
  float pidTerm = 0;
  int error = 0;
  static int last_error = 0;
  error = abs(targetValue) - abs(currentValue);
  pidTerm = (Kp2*error) + (Kd2*(error - last_error));
  last_error = error;
  return constrain(command + int(pidTerm), 0 , 255);
  Serial.println("Hi, I came here and saw PID control at work");
}
