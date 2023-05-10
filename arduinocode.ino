  
int A=9; 
int B=5;
int speed;

char input;    

void setup()
{
  Serial.begin(9600);  
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);  
}

void loop()
{
  int potentiometer = analogRead(A0);
  int potent = potentiometer/4;

   analogWrite(5, potent);
   analogWrite(9, potent);

  speed = 255;
  while(Serial.available())
  {
    input =Serial.read();
    if(input == 'F')
    {
      right();//left
    }

    else if (input== 'R')
    {
        backward();

      
    }

    else if (input== 'L')
    {
      forward();

    
    }  

    else if (input== 'G')
    {
      left();

    
    }  
 else if (input== 'S')
    {
      stop();

    
    }  

 

  }

}  

void forward()
  {
  digitalWrite(6, LOW	);
  digitalWrite(4, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void stop()
  {
  digitalWrite(6, LOW	);
  digitalWrite(4, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void backward()
  {
  digitalWrite(6, HIGH	);
  digitalWrite(4, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void right()
{
  digitalWrite(6, HIGH	);
  digitalWrite(4, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void left()
{
  digitalWrite(6, LOW	);
  digitalWrite(4, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}