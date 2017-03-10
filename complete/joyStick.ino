char Joystick(int RJX,int LJY) {
  if     ( LJY> 25 && RJX>-25 && RJX<25 ) { command = 'F'; }
  else if( LJY<-25 && RJX>-25 && RJX<25 ) { command = 'B'; }
  else if( RJX<-25 && LJY> 25 ) { command = 'L'; }
  else if( RJX> 25 && LJY> 25 ) { command = 'R'; }
  else if( RJX<-25 && LJY<-25 ) { command = 'l'; } //backward left(reverse right wheel)
  else if( RJX> 25 && LJY<-25 ) { command = 'r'; } //backward right(reverse left wheel)
  else { command = 'S'; }
  return command;
}
