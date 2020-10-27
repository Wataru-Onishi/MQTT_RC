
const int MA1 = 10;
const int MA2 = 11;
const int MB1 = 12;
const int MB2 = 13;

int com = 0;

void setup() {

  Serial.begin(9600);
  
  pinMode(MA1,OUTPUT);
  pinMode(MA2,OUTPUT);
  pinMode(MB1,OUTPUT);  
  pinMode(MB2,OUTPUT);  

}

void loop() {
    while(true){

      if(Serial.available() > 0){
        com = Serial.read();
        Serial.println(com);
      }
      if(com == 'w'){
        motor_forward();
        delay(1000);
      }  
      else if(com =='d'){
        motor_righit();
        delay(1000);
      }
      else if(com =='a'){
        motor_left();
        delay(1000);
      }
      else if(com =='s'){
        motor_stop();
        delay(1000);
      }
      else if(com =='b'){
        motor_back();
        delay(1000);
        }
      else if(com =='f'){
        break;
      }
  }
}

void motor_forward(){
      digitalWrite(MA1,HIGH);
      digitalWrite(MA2,LOW);
      digitalWrite(MB1,HIGH);
      digitalWrite(MB2,LOW);
}

void motor_back(){
      digitalWrite(MA1,LOW);
      digitalWrite(MA2,HIGH);
      digitalWrite(MB1,LOW);
      digitalWrite(MB2,HIGH);   
      Serial.println("back");   
}

void motor_stop(){
      digitalWrite(MA1,LOW);
      digitalWrite(MA2,LOW);
      digitalWrite(MB1,LOW);
      digitalWrite(MB2,LOW);  
      Serial.println("motor stop");
}

void motor_righit(){
      digitalWrite(MA1,HIGH);
      digitalWrite(MA2,LOW);
      digitalWrite(MB1,LOW);
      digitalWrite(MB2,LOW);  
      Serial.println("righit"); 
}

void motor_left(){
      digitalWrite(MA1,LOW);
      digitalWrite(MA2,LOW);
      digitalWrite(MB1,HIGH);
      digitalWrite(MB2,LOW);
      Serial.println("left");
}
