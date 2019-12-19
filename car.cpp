#include "Arduino.h"
#include "car.h"
car::car(int m1a, int m1b, int m2a, int m2b)
: m1_a{m1a}, m1_b{m1b}, m2_a{m2a}, m2_b{m2b}
{}
void car::_start(mode m, int b){
  _mode = m;
  _baud = b;
  if(_mode == mode::btCont || _mode == mode::accCont)
  Serial.begin(_baud);
}
void car::_run(){
  switch(_mode){
    case mode::btCont :
      btContR();
      break;
    case mode::selfCont :
      selfContR();
      break;
    case mode::accCont :
      accContR();
      break;
  }
}
void car::btContR(){
  while(!(Serial.available()));
  com = Serial.read();
  switch(com){
    case 'S' :
      stop();
      break;
    case 'F' :
      forward();
      break;
    case 'B' :
      back();
      break;
    case 'L' :
      left();
      break;
    case 'R' :
      right();
      break;
    default :
      break;
  }
  delay(100);
  stop();
}

void car::selfContR(){}
void car::accContR(){}

void car::stop(){
  digitalWrite(m1_a, LOW);
  digitalWrite(m1_b, LOW);
  digitalWrite(m2_a, LOW);
  digitalWrite(m2_b, LOW);
}
void car::forward(){
  digitalWrite(m1_a, HIGH);
  digitalWrite(m1_b, LOW);
  digitalWrite(m2_a, HIGH);
  digitalWrite(m2_b, LOW);
}
void car::back(){
  digitalWrite(m1_a, LOW);
  digitalWrite(m1_b, HIGH);
  digitalWrite(m2_a, LOW);
  digitalWrite(m2_b, HIGH);
}
void car::left(int dir){
  digitalWrite(m1_a, LOW);
  digitalWrite(m1_b, LOW);
  digitalWrite(m2_a, HIGH);
  digitalWrite(m2_b, LOW);
  if(dir){
    digitalWrite(m1_a, LOW);
    digitalWrite(m1_b, LOW);
    digitalWrite(m2_a, LOW);
    digitalWrite(m2_b, HIGH);
  }
}
void car::right(int dir){
  digitalWrite(m1_a, HIGH);
  digitalWrite(m1_b, LOW);
  digitalWrite(m2_a, LOW);
  digitalWrite(m2_b, LOW);
  if(dir){
    digitalWrite(m1_a, LOW);
    digitalWrite(m1_b, HIGH);
    digitalWrite(m2_a, LOW);
    digitalWrite(m2_b, LOW);
  }
}
// int car::dataf(int num){
//     int commaf = 0;
//     for(int a = 0;a <= 20; ++a){
//         if(commaf == (num-1)){
//             if(dataR[a] == '-'){
//                 return -(dataR[a+1]-'0');
//             }
//             return dataR[a] - '0';
//         }
//         if(dataR[a] == ','){
//             ++commaf;
//         }
//     }
// }
// bool car::isNum(int data){
//     data = data-'0';
//     int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     for(int a= 0; a<10; ++a) {
//         if(data == nums[a]){
//             return 1;
//         }
//     }
//     return 0;
// }
