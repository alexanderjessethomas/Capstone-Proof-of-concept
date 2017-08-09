 int pwmMotor1 = 5;
int pinOneMotor1 = 7;
int pinTwoMotor1 = 6;

int pwmMotor2 = 10; 
int pinOneMotor2 = 9;
int pinTwoMotor2 = 8; 

void setup(){
  pinMode(pwmMotor1, OUTPUT);
  pinMode(pinOneMotor1, OUTPUT);
  pinMode(pinTwoMotor1, OUTPUT);
  
  pinMode(pwmMotor2, OUTPUT);
  pinMode(pinOneMotor2, OUTPUT);
  pinMode(pinTwoMotor2, OUTPUT);
  
  Serial.begin(9600);
  
}

void forward(){
  //Going Forward different speeds 
  digitalWrite(pinOneMotor1, HIGH);
  digitalWrite(pinTwoMotor1, LOW);
  analogWrite(pwmMotor1, 255);
 
  digitalWrite(pinOneMotor2, HIGH);
  digitalWrite(pinTwoMotor2, LOW);
  analogWrite(pwmMotor2, 255);
  
  delay(6000);//run for six seconds 
  
  //make motors go slower to show ability to change speed 
  digitalWrite(pinOneMotor1, HIGH);
  digitalWrite(pinTwoMotor1, LOW);
  analogWrite(pwmMotor1, 100);
 
  digitalWrite(pinOneMotor2, HIGH);
  digitalWrite(pinTwoMotor2, LOW);
  analogWrite(pwmMotor2, 100);
  
  delay(6000);//run for six secodns 
  
  //end motors going forward 
  
  //stop motors for two seconds 
  digitalWrite(pinOneMotor1, LOW);
  digitalWrite(pinTwoMotor1, LOW);
  
  digitalWrite(pinOneMotor2, LOW);
  digitalWrite(pinTwoMotor2, LOW);
  
  delay(2000); // stop motors for two seconds 
  
}

void backward(){
  //Going backwards using different speeds 
  digitalWrite(pinOneMotor1, LOW);
  digitalWrite(pinTwoMotor1, HIGH);
  analogWrite(pwmMotor1, 255);
 
  digitalWrite(pinOneMotor2, LOW);
  digitalWrite(pinTwoMotor2, HIGH);
  analogWrite(pwmMotor2, 255);
 
  delay(6000);//run for six seconds 
  
  //change speed to go slower 
  digitalWrite(pinOneMotor1, LOW);
  digitalWrite(pinTwoMotor1, HIGH);
  analogWrite(pwmMotor1, 100);
 
  digitalWrite(pinOneMotor2, LOW);
  digitalWrite(pinTwoMotor2, HIGH);
  analogWrite(pwmMotor2, 100);
 
  delay(6000);//run for six seconds 

  //stop motors for two seconds 
  digitalWrite(pinOneMotor1, HIGH);
  digitalWrite(pinTwoMotor1, HIGH);
  
  digitalWrite(pinOneMotor2, HIGH);
  digitalWrite(pinTwoMotor2, HIGH);
  
  delay(2000); // stop motors for two seconds 
  
}

void gradualAccelerationMaxSpeed(){
  //enable motor 1
  digitalWrite(pinOneMotor1, HIGH);
  digitalWrite(pinTwoMotor1, LOW);
  //enable motor2
  digitalWrite(pinOneMotor2, HIGH);
  digitalWrite(pinTwoMotor2, LOW);
  //run make both motors accelerate 
  for(int i = 0; i <= 255; i++){
    analogWrite(pwmMotor1, i);
    analogWrite(pwmMotor2, i);
    
    delay(20);
  }
  
}

void gradualDeclerationFromMaxSpeed(){
  //enable motor 1
  digitalWrite(pinOneMotor1, HIGH);
  digitalWrite(pinTwoMotor1, LOW);
  //enable motor2
  digitalWrite(pinOneMotor2, HIGH);
  digitalWrite(pinTwoMotor2, LOW);
 
  for(int i = 255; i >= 0; i--){
   analogWrite(pwmMotor1, i);
   analogWrite(pwmMotor2, i);
    
   delay(20);
  }
  
}

void loop(){
  //forward();
  if(Serial.available()){
    switch(Serial.read()){
      //forward movement case 
      case 'f':
        forward();
        delay(1000); //give enough time to run
        break;
        
      //backward movement case
      case 'b':
        backward();
        delay(1000); //give enough time to run 
        break;
      
      //acceleration case
      case 'a':
        gradualAccelerationMaxSpeed();
        delay(1000); //give enough time to run  
        break;
      
      case 'd':
        gradualAccelerationMaxSpeed();
        delay(1000); //give enough time to run 
        break; 
      
      //default case
      default: 
        Serial.write("Hello World");
        break;
    }//end switch
  }//end if 
   
}
