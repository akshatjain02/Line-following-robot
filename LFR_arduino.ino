int Left_p=3;         //Positive terminal of left motor connected to 3rd digital PWM
int Left_n=5;         //Negative terminal of left motor connected to 5th digital PWM
int Right_p=6;        //Positive terminal of right motor connected to 6th digital PWM
int Right_n=9;        //Negative terminal of right motor connected to 9th digital PWM


void setup()
{
  pinMode(Left_p,OUTPUT);         
  pinMode(Left_n,OUTPUT);
  pinMode(Right_p,OUTPUT);
  pinMode(Right_n,OUTPUT);

  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
}


void loop()
{
  int ex_right=analogRead(A0);
  int right=analogRead(A1);
  int centre=analogRead(A2);    //IR LED Array has 5 bulbs for receiving. Reading their values through the Analog PWM
  int left=analogRead(A3);
  int ex_left=analogRead(A4);

  if(ex_left<700 && ex_right<700 && centre>700)             //black=1000, white=400, average=700
  {
    go_straight();                                          //Movement of robot based on light received by IR LED array bulbs
  }
  if(ex_left<700 && ex_right<700 && centre<700)
  {
    STOP();
  }
  if(ex_left>700 && ex_right<700)
  {
    turn_left();
  }
  if(ex_left<700 && ex_right>700)
  {
    turn_right();
  }
}


void go_straight()
{
  digitalWrite(Left_p,HIGH);           //Assigning value of potenial to the positive and negative terminals of motors.
  digitalWrite(Left_n,LOW);            //to incorporate movement by wheels.
  digitalWrite(Right_p,HIGH);
  digitalWrite(Right_n,LOW);
}
void STOP()
{
  digitalWrite(Left_p,LOW);
  digitalWrite(Left_n,LOW);
  digitalWrite(Right_p,LOW);
  digitalWrite(Right_n,LOW);
}

void turn_left()
{
  digitalWrite(Left_p,HIGH);
  digitalWrite(Left_n,LOW);
  digitalWrite(Right_p,LOW);
  digitalWrite(Right_n,LOW);
}

void turn_right()
{
  digitalWrite(Left_p,LOW);
  digitalWrite(Left_n,LOW);
  digitalWrite(Right_p,HIGH);
  digitalWrite(Right_n,LOW);
}
