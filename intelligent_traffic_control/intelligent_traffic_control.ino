//This project is developed to solved the trffic problem in real world
//Most of the people have suffer to reach at exact time due to traffic jam
//the traffic rules used is work on one similar function 
//but in our project it works on two phase ie peak value and not a peak value
//it fetch system time and comapare to work

//it is develop under the guidance of Mrs.Prema C 
//team memeber are  Alvira Ansari Gaurav Arya & Faiyaz Ahmed
//version 1.0
//for visualization we use python language to view the activity happening at traffic

#include<stdio.h>           //include standard header file
char val;  //variable to store the receive data
String voice;                //to store voice we use variable voice
int firstSide[]={2,3,4};    //connected with arduino pin 
int secondSide[]={5,6,7};
int thirdSide[]={8,9,10};
int fourthSide[]={11,12,13};
int sensor_1=A0;                     //attach IR sensor at pin A0 to received data 
int sensor_2=A1;
int sensor_3=A3;
int sensor_4=A4;
int sensor_5=A5;
int sensor_6=A6;
//int sensor_7=3;   we can use pin 3 of orange led for sensor input and orange led combine with another line same led     
//int sensor_8=4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                        //communication with serial port and arduino
  for(int i=0;i<3;i++){
      pinMode(firstSide[i],OUTPUT);         //send output to arduino 
      pinMode(secondSide[i],OUTPUT);
      pinMode(thirdSide[i],OUTPUT);
      pinMode(fourthSide[i],OUTPUT);
  }
  pinMode(sensor_1,INPUT);                 //received input from sensor
  pinMode(sensor_2,INPUT);
  pinMode(sensor_3,INPUT);
  pinMode(sensor_4,INPUT);
  pinMode(sensor_5,INPUT);
  pinMode(sensor_6,INPUT);
  Serial.println("Wel-Come to Intelligent traffic light signal");    //print the message at the screen 

}

void loop() {
 // int No_peak_hour();
  // put your main code here, to run repeatedly:
  /*int ldrval=analogRead(ldr);       street light
  int senval=digitalRead(sensor);
  if(ldr==0)
  {
    if(senval==LOW){
      digitalWrite(led,HIGH);
    }else{
      digitalWrite(led,LOW);
    }
  }*/
  int sensor1_val,sensor2_val,sensor3_val,sensor4_val,sensor5_val,sensor6_val,sensor7_val,sensor8_val;
  sensor1_val=digitalRead(sensor_1);
  sensor2_val=digitalRead(sensor_2);
  sensor3_val=digitalRead(sensor_3);
  sensor4_val=digitalRead(sensor_4);
  sensor5_val=digitalRead(sensor_5);
  sensor6_val=digitalRead(sensor_6);
  
   /* Serial.println("sensor 3 reading is &&_____&&&&&&____");
  Serial.println(sensor3_val);
    Serial.println("sensor 4 reading is ");
  Serial.println(sensor4_val);
    Serial.println("sensor 5 reading is .000000000");
  Serial.println(sensor5_val);
    Serial.println("sensor 1 reading is !!!!!!!!!!!!!");
  Serial.println(sensor6_val);*/                                   //ITS OPEN ONE LANE IN EACH TIME IF THE SENSOR ARE ACTIVATED

  if(sensor1_val==LOW){                                //this line of code for first line (sensor)
    //Serial.println(1);
    //Serial.println(sensor1_val);
    if(sensor2_val==LOW){
    Serial.print(1);
    //Serial.println(sensor2_val);
      digitalWrite(firstSide[0],HIGH);
      digitalWrite(firstSide[1],LOW);
      digitalWrite(secondSide[1],HIGH);
      digitalWrite(thirdSide[1],HIGH);
      digitalWrite(fourthSide[1],HIGH);
      delay(12000);
      digitalWrite(firstSide[0],LOW);
      for(int i=0;i<10;i++){
        digitalWrite(firstSide[2],HIGH);
        delay(200);
        digitalWrite(firstSide[2],LOW);
        delay(200);
      }
      digitalWrite(secondSide[1],LOW);
      digitalWrite(thirdSide[1],LOW);
      digitalWrite(fourthSide[1],LOW);
    }
  }
  if(sensor3_val==HIGH){                              //this line of code for 2nd lane (sensor)
    if(sensor4_val==HIGH){
      Serial.println(2);
      digitalWrite(firstSide[1],HIGH);
      digitalWrite(secondSide[1],LOW);
      digitalWrite(secondSide[0],HIGH);
      digitalWrite(thirdSide[1],HIGH);
      digitalWrite(fourthSide[1],HIGH);
      delay(12000);
      digitalWrite(secondSide[0],LOW);
      for(int i=0;i<10;i++){
        digitalWrite(secondSide[2],HIGH);
        delay(200);
        digitalWrite(secondSide[2],LOW);
        delay(200);
      }
      digitalWrite(firstSide[1],LOW);
      digitalWrite(thirdSide[1],LOW);
      digitalWrite(fourthSide[1],LOW);
      
    }
  }
  if(sensor5_val==LOW){                      //this line of code for 3rd lane (sensor)
    if(sensor6_val==LOW){
      Serial.println(3);
      digitalWrite(firstSide[1],HIGH);
      digitalWrite(secondSide[1],HIGH);
      digitalWrite(thirdSide[1],LOW);
      digitalWrite(thirdSide[0],HIGH);
      digitalWrite(fourthSide[1],HIGH);
      delay(12000);
      digitalWrite(thirdSide[0],LOW);
      for(int j=0;j<10;j++){
        digitalWrite(thirdSide[2],HIGH);
        delay(200);
        digitalWrite(thirdSide[2],LOW);
        delay(200);
      }
      digitalWrite(firstSide[1],LOW);
      digitalWrite(secondSide[1],LOW);
      digitalWrite(fourthSide[1],LOW);
    }
  }
 if(sensor7_val==LOW){     //this line of code for 4th lane (sensor)
    if(sensor8_val==LOW){
      Serial.println(4);
      digitalWrite(firstSide[1],HIGH);
      digitalWrite(secondSide[1],HIGH);
      digitalWrite(thirdSide[1],HIGH);
      digitalWrite(fourthSide[1],LOW);
      digitalWrite(fourthSide[0],HIGH);
      delay(12000);
      digitalWrite(fourthSide[0],LOW);
      for(int k=0;k<10;k++){
        digitalWrite(fourthSide[2],HIGH);
        delay(200);
        digitalWrite(fourthSide[2],LOW);
        delay(200);
      }
      digitalWrite(firstSide[1],LOW);
      digitalWrite(secondSide[1],LOW);
      digitalWrite(thirdSide[1],LOW);
    }
  }   //close of start if


//this is used to communicate with bluetooth and arduino
if(Serial.available()){//CONNECT WITH BLUETOOTH IF AVAILABLE
  val=Serial.read();
  voice=voice+val;
  if(voice=="red")
  {
    digitalWrite(firstSide[0],HIGH);
              digitalWrite(firstSide[1],LOW);
              digitalWrite(secondSide[1],HIGH);
              digitalWrite(thirdSide[1],HIGH);
              digitalWrite(fourthSide[1],HIGH);
              delay(9000);
              digitalWrite(firstSide[0],LOW);
              for(int i=0;i<10;i++){
                digitalWrite(firstSide[2],HIGH);
                delay(200);
                digitalWrite(firstSide[2],LOW);
                delay(200);
              }
              digitalWrite(firstSide[1],HIGH);
  }
  else if(voice=="green"){
    digitalWrite(firstSide[1],HIGH);
              digitalWrite(secondSide[0],HIGH);
              digitalWrite(secondSide[1],LOW);
              digitalWrite(thirdSide[1],HIGH);
              digitalWrite(fourthSide[1],HIGH);
              delay(9000);
              digitalWrite(secondSide[0],LOW);
              for(int i=0;i<10;i++){
                digitalWrite(secondSide[2],HIGH);
                delay(200);
                digitalWrite(secondSide[2],LOW);
                delay(200);
              }
              digitalWrite(secondSide[1],HIGH);
    
  }else if(voice=="yellow"){
    digitalWrite(firstSide[1],HIGH);
              digitalWrite(secondSide[1],HIGH);
              digitalWrite(thirdSide[0],HIGH);
              digitalWrite(thirdSide[1],LOW);
              digitalWrite(fourthSide[1],HIGH);
              delay(9000);
              digitalWrite(thirdSide[0],LOW);
              for(int i=0;i<10;i++){
                digitalWrite(thirdSide[2],HIGH);
                delay(200);
                digitalWrite(thirdSide[2],LOW);
                delay(200);
              }
              digitalWrite(thirdSide[1],HIGH);
    
  }else if(voice=="blue")
  {
    digitalWrite(firstSide[1],HIGH);
              digitalWrite(secondSide[1],HIGH);
              digitalWrite(thirdSide[1],HIGH);
              digitalWrite(fourthSide[0],HIGH);
              digitalWrite(fourthSide[1],LOW);
              delay(9000);                            //it's delay the arduino in that line ie 9 sec
              digitalWrite(fourthSide[0],LOW);
              for(int j=0;j<10;j++){
                digitalWrite(fourthSide[2],HIGH);
                delay(200);
                digitalWrite(fourthSide[2],LOW);
                delay(200);
              }
              digitalWrite(fourthSide[1],HIGH);
  }
  else{
    digitalWrite(firstSide[1],LOW);
    digitalWrite(secondSide[1],LOW);
    digitalWrite(thirdSide[1],LOW);
    digitalWrite(fourthSide[1],LOW);
  }
  Serial.println("The character signal received from Intelligent traffic control app is");     //control with an app made with mitappinventor
  //the app having button ABCD if we click on each letter thn line will activate
  Serial.println(val);
  switch(val){
    case 'A':                                                       //ACTIVATE FIRST LANE
              digitalWrite(firstSide[0],HIGH);
              digitalWrite(firstSide[1],LOW);
              digitalWrite(secondSide[1],HIGH);
              digitalWrite(thirdSide[1],HIGH);
              digitalWrite(fourthSide[1],HIGH);
              delay(9000);
              digitalWrite(firstSide[0],LOW);
              for(int i=0;i<10;i++){
                digitalWrite(firstSide[2],HIGH);
                delay(200);
                digitalWrite(firstSide[2],LOW);
                delay(200);
              }
              digitalWrite(firstSide[1],HIGH);
              break;
    case 'B':                                                       //ACTIVATE SECOND LANE
              digitalWrite(firstSide[1],HIGH);
              digitalWrite(secondSide[0],HIGH);
              digitalWrite(secondSide[1],LOW);
              digitalWrite(thirdSide[1],HIGH);
              digitalWrite(fourthSide[1],HIGH);
              delay(9000);
              digitalWrite(secondSide[0],LOW);
              for(int i=0;i<10;i++){
                digitalWrite(secondSide[2],HIGH);
                delay(200);
                digitalWrite(secondSide[2],LOW);
                delay(200);
              }
              digitalWrite(secondSide[1],HIGH);
              break;
    case 'C':                                                       //ACTIVATE THIRD LANE
              digitalWrite(firstSide[1],HIGH);
              digitalWrite(secondSide[1],HIGH);
              digitalWrite(thirdSide[0],HIGH);
              digitalWrite(thirdSide[1],LOW);
              digitalWrite(fourthSide[1],HIGH);
              delay(9000);
              digitalWrite(thirdSide[0],LOW);
              for(int i=0;i<10;i++){
                digitalWrite(thirdSide[2],HIGH);
                delay(200);
                digitalWrite(thirdSide[2],LOW);
                delay(200);
              }
              digitalWrite(thirdSide[1],HIGH);
              break;
    case 'D':                                                         //ACTIVATE FOURTH LANE
              digitalWrite(firstSide[1],HIGH);
              digitalWrite(secondSide[1],HIGH);
              digitalWrite(thirdSide[1],HIGH);
              digitalWrite(fourthSide[0],HIGH);
              digitalWrite(fourthSide[1],LOW);
              delay(9000);                            //it's delay the arduino in that line ie 9 sec
              digitalWrite(fourthSide[0],LOW);
              for(int j=0;j<10;j++){
                digitalWrite(fourthSide[2],HIGH);
                delay(200);
                digitalWrite(fourthSide[2],LOW);
                delay(200);
              }
              digitalWrite(fourthSide[1],HIGH);
              break;
    default:
    digitalWrite(firstSide[1],LOW);
    digitalWrite(secondSide[1],LOW);
    digitalWrite(thirdSide[1],LOW);
    digitalWrite(fourthSide[1],LOW);
    break;//this function exit from switch statement
  }
 }
}


  //The below line of code is used to open two side lane at a time according to sensor density
  digitalWrite(firstSide[1],LOW);
    digitalWrite(secondSide[1],LOW);
    digitalWrite(firstSide[0],HIGH);   //line 1 gren on
    digitalWrite(secondSide[0],HIGH);  //line 2 gren on
    digitalWrite(thirdSide[1],HIGH);   //line 3 red  on
    digitalWrite(fourthSide[1],HIGH);  //line 4 red  on
      delay(1900);
      for(int j=0;j<7;j++){
        digitalWrite(firstSide[0],LOW);   //line 1 gren off
        digitalWrite(secondSide[0],LOW);  //line 2  gren off
        digitalWrite(firstSide[2],HIGH);   //line 1 orange on
        digitalWrite(secondSide[2],HIGH);  //line 2 orange on
        delay(200);
        digitalWrite(firstSide[2],LOW);      //line 1 orange off
        digitalWrite(secondSide[2],LOW);     //line 2 orange off
        delay(200);
      }
      digitalWrite(thirdSide[1],LOW);        //line 3 red off
      digitalWrite(fourthSide[1],LOW);       //line 4 red off
      digitalWrite(thirdSide[0],HIGH);        //line 3 gren on
      digitalWrite(fourthSide[0],HIGH);       //line 4 gren on
      digitalWrite(firstSide[1],HIGH);        // line 1 red on 
      digitalWrite(secondSide[1],HIGH);         //line 2 red on
      delay(1900);
      for(int j=0;j<7;j++){
        digitalWrite(thirdSide[0],LOW);
        digitalWrite(fourthSide[0],LOW);
        digitalWrite(thirdSide[2],HIGH);
        digitalWrite(fourthSide[2],HIGH);
        delay(200);
        digitalWrite(thirdSide[2],LOW);
        digitalWrite(fourthSide[2],LOW);
        delay(200);
      }
} //closing of void loop

   /*  //this is starting of normal function each lane rotate after certain time
     //we can check it
      digitalWrite(firstSide[0],HIGH);
      digitalWrite(firstSide[1],LOW);
      digitalWrite(secondSide[1],HIGH);
      digitalWrite(thirdSide[1],HIGH);
      digitalWrite(fourthSide[1],HIGH);
      delay(9000);
      digitalWrite(firstSide[0],LOW);
      for(int i=0;i<5;i++){
         digitalWrite(firstSide[2],HIGH);
         delay(200);
         digitalWrite(firstSide[2],LOW);
         delay(200);
         }
      digitalWrite(firstSide[1],HIGH);
  
 digitalWrite(firstSide[0],LOW);
 digitalWrite(secondSide[0],HIGH);
 digitalWrite(secondSide[1],LOW);
 digitalWrite(thirdSide[1],HIGH);
 digitalWrite(fourthSide[1],HIGH);
 delay(9000);
 digitalWrite(secondSide[0],LOW);
 for(int j=0;j<5;j++){
  digitalWrite(secondSide[2],HIGH);
  delay(200);
  digitalWrite(secondSide[2],LOW);
  delay(200);
 }
 digitalWrite(secondSide[1],HIGH);

 digitalWrite(secondSide[0],LOW);
 digitalWrite(firstSide[1],HIGH);
 digitalWrite(thirdSide[1],LOW);
 digitalWrite(thirdSide[0],HIGH);
 digitalWrite(fourthSide[1],HIGH);
 delay(9000);
 digitalWrite(thirdSide[0],LOW);
 for(int i=0;i<5;i++){
  digitalWrite(thirdSide[2],HIGH);
  delay(200);
  digitalWrite(thirdSide[2],LOW);
  delay(200);
 }
 digitalWrite(thirdSide[1],HIGH);

 digitalWrite(thirdSide[0],LOW);
 digitalWrite(firstSide[1],HIGH);
 digitalWrite(secondSide[1],HIGH);
 digitalWrite(fourthSide[1],LOW);
 digitalWrite(fourthSide[0],HIGH);
 delay(9000);
 digitalWrite(fourthSide[0],LOW);
 for(int j=0;j<5;j++){
  digitalWrite(fourthSide[2],HIGH);
  delay(200);
  digitalWrite(fourthSide[2],LOW);
  delay(200);
 }
 digitalWrite(fourthSide[1],HIGH);

}
*/
//close of void loop function




/*  int sensor1_val,sensor2_val,sensor3_val,sensor4_val,sensor5_val,sensor6_val,sensor7_val,sensor8_val;
  int lane1=analogRead(sensor1_val)+analogRead(sensor2_val);
  int lane2=analogRead(sensor3_val)+analogRead(sensor4_val);
  int lane3=analogRead(sensor5_val)+analogRead(sensor6_val);
  int lane4=analogRead(sensor7_val)+analogRead(sensor8_val);
  if((lane1>=lane3 or lane1>lane4)and(lane2>=lane3 or lane2>=lane4)){
  if((sensor1_val==LOW)or(sensor3_val==LOW)){     //this logic is used to open the two side of way t one time by compring the sum of sensor value
    if((sensor2_val==LOW)or sensor4_val==LOW)){
      digitalWrite(firstSide[0],HIGH);            //enable 1st lane green
      digitalWrite(secondSide[0],HIGH);           //enable 2nd lane green
      digitalWrite(firstSide[1],LOW);             //disable 1st lane red
      digitalWrite(secondSide[1],LOW);            //disable 2nd lane red
      digitalWrite(thirdSide[1],HIGH);            //enable 3rd lane red
      digitalWrite(fourthSide[1],HIGH);           //enable 4th lane red
      delay(9000);                                  //active until 9 sec
      digitalWrite(firstSide[1],LOW);
      digitalWrite(secondSide[1],LOW);
      for(int j=0;j<10;j++){                      //blink 10 times   
        digitalWrite(firstSide[0],LOW);   //line 1 gren off
        digitalWrite(secondSide[0],LOW);  //line 2  gren off
        digitalWrite(firstSide[2],HIGH);   //line 1 orange on
        digitalWrite(secondSide[2],HIGH);  //line 2 orange on
        delay(200);
        digitalWrite(firstSide[2],LOW);      //line 1 orange off
        digitalWrite(secondSide[2],LOW);     //line 2 orange off
        delay(200);
      } //                                     //for end
  }
  else{                                    //end of inner if
    digitalWrite(thirdSide[1],LOW);
    digitalWrite(fourthSide[1],LOW);
    digitalWrite(thirdSide[0],HIGH);
    digitalWrite(fourthSide[0],HIGH);
    digitalWrite(firstSide[1],HIGH);
    digitalWrite(secondSide[1],HIGH);
    delay(19000);
    digitalWrite(thirdSide[1],LOW);
    digitalWrite(fourthSide[1],LOW);
    for(int k=0;k<10;k++){
    digitalWrite(thirdSide[0],LOW);
    digitalWrite(fourthSide[0],LOW);
    digitalWrite(thirdSide[2],HIGH);
    digitalWrite(fourthSide[2],HIGH);
    delay(200);
    digitalWrite(thirdSide[2],LOW);
    digitalWrite(fourthSide[2],LOW);
    delay(200);
  }   //for loop close
 }   //else close
}   //2nd innner if close
 else{
    digitalWrite(thirdSide[1],LOW);
    digitalWrite(fourthSide[1],LOW);
    digitalWrite(thirdSide[0],HIGH);
    digitalWrite(fourthSide[0],HIGH);
    digitalWrite(firstSide[1],HIGH);
    digitalWrite(secondSide[1],HIGH);
    delay(19000);
    digitalWrite(thirdSide[1],LOW);
    digitalWrite(fourthSide[1],LOW);
    for(int k=0;k<10;k++){
    digitalWrite(thirdSide[0],LOW);
    digitalWrite(fourthSide[0],LOW);
    digitalWrite(thirdSide[2],HIGH);
    digitalWrite(fourthSide[2],HIGH);
    delay(200);
    digitalWrite(thirdSide[2],LOW);
    digitalWrite(fourthSide[2],LOW);
    delay(200);
    } //for loop close
  }//else close
} //comapring outer if loop
  else{
    digitalWrite(thirdSide[1],LOW);
    digitalWrite(fourthSide[1],LOW);
    digitalWrite(thirdSide[0],HIGH);
    digitalWrite(fourthSide[0],HIGH);
    digitalWrite(firstSide[1],HIGH);
    digitalWrite(secondSide[1],HIGH);
    delay(19000);
    digitalWrite(thirdSide[1],LOW);
    digitalWrite(fourthSide[1],LOW);
    for(int k=0;k<10;k++){
    digitalWrite(thirdSide[0],LOW);
    digitalWrite(fourthSide[0],LOW);
    digitalWrite(thirdSide[2],HIGH);
    digitalWrite(fourthSide[2],HIGH);
    delay(200);
    digitalWrite(thirdSide[2],LOW);
    digitalWrite(fourthSide[2],LOW);
    delay(200);
    }  //for loop close
  }    //else close
*/
