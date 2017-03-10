
  int getLeftY(char *str1) {
    String str3(str1);
    int found = str3.indexOf("leftTouchPadY");
    String stringX =str3.substring(found+15,found+18); 
    int last = stringX.indexOf(",");
    stringX = stringX.substring(0,last);
    //const char* charX = stringX.c_str();
    //int intX = atoi(charX);
    return atoi(stringX.c_str());
    
  }
  int getRightX(char *str1) {
    String str2(str1);
    int found = str2.indexOf("rightTouchPadX");
    String stringX =str2.substring(found+16,found+19); 
    int last = stringX.indexOf(",");
    stringX = stringX.substring(0,last);
    //const char* charX = stringX.c_str();
    //int intX = atoi(charX);
    return atoi(stringX.c_str());
    
  }
  int getVelocity(char *str) {
    String str4(str);
    int found = str4.indexOf("btn4");
    String btn4 = str4.substring(found+6,found+7);
    const char* char_btn4 = btn4.c_str();
    int int4 = atoi(char_btn4);
    if(int4 == 1) {
      velocity = 700;
    }
    else { 
      velocity = 1023;
    }
    return velocity;
  }
  

