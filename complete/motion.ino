
void start_engine(int v){   //CASE F
  analogWrite(EN_A, v);
  analogWrite(EN_B, v);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void back_engine(int v){   //CASE B
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EN_A, v);
  analogWrite(EN_B, v);
}
void front_left(int v){        //CASE L
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);//FF
  analogWrite(EN_A, v);
  analogWrite(EN_B, v);//FF

}
void front_right(int v){       //CASE R
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);//FF
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN_A, v);//FF
  analogWrite(EN_B, v);
  
}
void back_left(int v) {        //CASE l
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN_A, v);
  analogWrite(EN_B, v);//FF
}
void back_right(int v){        //CASE R
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EN_A, v);//FF
  analogWrite(EN_B, v);
}


void stop_engine() {      //CASE S
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(EN_A, 0);
  analogWrite(EN_B, 0);
}

