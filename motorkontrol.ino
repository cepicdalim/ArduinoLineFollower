
// TB 6612FNG İçin aktif ediniz

void motorkontrol(int solmotorpwm, int sagmotorpwm) {  //Örnek: motorkontrol(-50,50);
  if (solmotorpwm <= 0) {
    solmotorpwm = abs(solmotorpwm);
    sag_sh = solmotorpwm;
    sol_sh = sagmotorpwm;
    digitalWrite(ENB, HIGH);
    digitalWrite(solBin1, LOW);
    analogWrite(solPwmPin, solmotorpwm);
  } else {
    digitalWrite(ENB, LOW);
    digitalWrite(solBin1, HIGH);
    analogWrite(solPwmPin, solmotorpwm);
  }

  if (sagmotorpwm <= 0) {
    sagmotorpwm = abs(sagmotorpwm);
    digitalWrite(ENA, LOW);
    digitalWrite(sagAin1, HIGH);
    analogWrite(sagPwmPin, sagmotorpwm);
  } else {
    digitalWrite(ENA, HIGH);
    digitalWrite(sagAin1, LOW);
    analogWrite(sagPwmPin, sagmotorpwm);
  }
}


// SKYLINE 5A MOTOR DRIVER İçin aktif ediniz
/*
void motorkontrol(int solmotorpwm,int sagmotorpwm){   //Örnek: motorkontrol(-50,50);

  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
if(solmotorpwm<=0){
  solmotorpwm=abs(solmotorpwm);
  analogWrite(solPwmPin,255-solmotorpwm);
  digitalWrite(solBin1,HIGH);
digitalWrite(ENB,HIGH);
}
else{
  analogWrite(solPwmPin,solmotorpwm);
  digitalWrite(solBin1,LOW);
digitalWrite(ENB,HIGH);
}

 if(sagmotorpwm<=0){
  sagmotorpwm=abs(sagmotorpwm);
  analogWrite(sagPwmPin,255-sagmotorpwm);
  digitalWrite(sagAin1,HIGH);
  digitalWrite(ENA,HIGH);
 }
 else{
  analogWrite(sagPwmPin,sagmotorpwm);
  digitalWrite(sagAin1,LOW);
  digitalWrite(ENA,HIGH);
 }

}
*/
