
void menual_car() {
   switch(command) {
      /*case 'S':
        stop_engine();//Serial.println("stop");
        break;*/
      case 'F':
        start_engine(velocity);//Serial.println("forward");
        break;
      case 'B':
        back_engine(velocity);//Serial.println("backward");
        break;
      case 'L':
        front_left(velocity);//Serial.println("left");
        break;
      case 'R':
        front_right(velocity);//Serial.println("right");
        break;
      case 'l':
        back_left(velocity);//Serial.println("back_left");
        break;
      case 'r':
        back_right(velocity);//Serial.println("back_right");
        break;
      default:               
        { stop_engine(); }
      
    }
}

