
#include <Servo.h>

Servo thumbservo;
Servo indexservo;
Servo middleservo;
Servo ringservo;
Servo pinkyservo;





void setup() {
  Serial.begin(9600);
  thumbservo.attach(3);
  indexservo.attach(5);
  middleservo.attach(6);
  ringservo.attach(9);
  pinkyservo.attach(10);

  


  thumbservo.write(180);
  indexservo.write(180);
  middleservo.write(180);
  ringservo.write(180);
  pinkyservo.write(180);
  
}
int arr[5] = {0,0,0,0,0};
String s ;
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    s="";
    s = Serial.readStringUntil('\n');

    // Split the readString by a pre-defined delimiter in a simple way. ' '(percentage) is defined as the delimiter in this project.
    int delimiter, delimiter_1, delimiter_2, delimiter_3, delimiter_4, delimiter_5;
    delimiter = 0;
    delimiter_1 = s.indexOf(" ", delimiter + 1);
    delimiter_2 = s.indexOf(" ", delimiter_1 +1);
    delimiter_3 = s.indexOf(" ", delimiter_2 +1);
    delimiter_4 = s.indexOf(" ", delimiter_3 +1);
    delimiter_5 = s.indexOf(" ", delimiter_4 +1);
    
    // Define variables to be executed on the code later by collecting information from the readString as substrings.
    String first = s.substring(delimiter , delimiter_1);
    String second = s.substring(delimiter_1 + 1, delimiter_2);
    String third = s.substring(delimiter_2 + 1, delimiter_3);
    String forth = s.substring(delimiter_3 + 1, delimiter_4);
    String fifth = s.substring(delimiter_4 + 1, delimiter_5);
    arr[0] = first.toInt();
    arr[1] = second.toInt();
    arr[2] = third.toInt();
    arr[3] = forth.toInt();
    arr[4] = fifth.toInt();
    for(int i = 0 ; i < 5 ; i++ )
    {
      arr[i] = (180-arr[i]*1.8); 
    }
    thumbservo.write(arr[0]); 
    indexservo.write(arr[1]); 
    middleservo.write(arr[2]); 
    ringservo.write(arr[3]); 
    pinkyservo.write(arr[4]); 
  }
}
