
#include <Servo.h>


//Potentimeters
const int pot1 = A0; 
const int pot2 = A1; 
const int pot3 = A2;

const int LED = 2;

//2 buttons for memory
const int btn1 = 12; 
const int btn2 = 13;
const int btn3 = 8;

//init button values
int btn1Value = 0; 
int btn2Value = 0;
int btn3Value = 0;

int temp=0;
//define servos 
Servo serv1;
Servo serv2;
Servo serv3;

//Potentimeter values
int pot1Ang;
int pot2Ang;
int pot3Ang;
int pot1Val; 
int pot2Val;
int pot3Val;


int serv1Pos[] = {1,1,1,1,1};
int serv2Pos[] = {1,1,1,1,1};
int serv3Pos[] = {1,1,1,1,1};

void setup() {
 
  //set servos
  serv1.attach(6); 
  serv2.attach(7);
  serv3.attach(9);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(LED, OUTPUT);



  Serial.begin(9600);
}

void loop() {

  pot1Val = analogRead(pot1);
  pot1Ang = map(pot1Val, 0, 1023, 0, 179); 
  pot2Val = analogRead(pot2); 
  pot2Ang = map(pot2Val, 0, 1023, 0, 179);
  pot3Val = analogRead(pot3);
  pot3Ang = map(pot3Val, 0, 1023, 0, 179);
    serv1.write(pot1Ang);
  serv2.write(pot2Ang);
  serv3.write(pot3Ang);

          if(digitalRead(btn3) == HIGH){
    btn3Value= 1;
      pot1Val = 0;
  pot1Ang = map(pot1Val, 0, 1023, 0, 179); 
  pot2Val = 0;
  pot2Ang = map(pot2Val, 0, 1023, 0, 179);
  pot3Val = 0;
  pot3Ang = map(pot3Val, 0, 1023, 0, 179);
  
  //move servos as angles
  serv1.write(pot1Ang);
  serv2.write(pot2Ang);
  serv3.write(pot3Ang);
   btn3Value =0;
      }

  
  if(digitalRead(btn1) == HIGH and ( btn3Value == 0) ){

  //move servos as angles

   if(btn1Value> 0 ){
    btn1Value++;}
    
    switch(btn1Value){
      case 0:
     btn1Value++; 
      digitalWrite(LED, HIGH); 
      case 1:
      
        serv1Pos[0] = pot1Ang;
        serv2Pos[0] = pot2Ang;
        serv3Pos[0] = pot3Ang;
        
        Serial.println("first position saved");
        break;
      case 2:
         serv1Pos[1] = pot1Ang;
         serv2Pos[1] = pot2Ang;
         serv3Pos[1] = pot3Ang;

         Serial.println("second position saved");
         break;
      case 3:
         serv1Pos[2] = pot1Ang;
         serv2Pos[2] = pot2Ang;
         serv3Pos[2] = pot3Ang;
  
         Serial.println("third position saved");
         break;
       case 4:
         serv1Pos[3] = pot1Ang;
         serv2Pos[3] = pot2Ang;
         serv3Pos[3] = pot3Ang;

         Serial.println("forth position saved");
         break;
       case 5:
         serv1Pos[4] = pot1Ang;
         serv2Pos[4] = pot2Ang;
         serv3Pos[4] = pot3Ang;

         Serial.println("5th position saved...");
          digitalWrite(LED, LOW);
         break;

    }
            
  }

  if(digitalRead(btn2) == HIGH){ 
    btn2Value = 1;   
  }
  
  if(btn2Value > 0){
    for(int i = 0; i < 5; i++){
        serv1.write(serv1Pos[i]);
        serv2.write(serv2Pos[i]);
        serv3.write(serv3Pos[i]);
        delay(1050);
      }
  }
  delay(300);
} 
