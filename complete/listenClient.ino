void listenClient() {
  
  WiFiClient client = server.available();
  if(!client) {
    return;
  }  
  //Serial.println("Somebody is connected");
  String req = client.readString();
  int w = req.indexOf("wifi");
  int p = req.indexOf("&ghost");
  String cut = req.substring(w,p);
  int cat = cut.indexOf("&");
  int pas = cut.indexOf("pass");
  String wiifii = cut.substring(5,cat);
  String passwd = cut.substring(pas+5).c_str();
  char buf_wifi[wiifii.length()+1];
  char buf_passwd[passwd.length()+1];
  wiifii.toCharArray(buf_wifi,wiifii.length()+1);
  passwd.toCharArray(buf_passwd,passwd.length()+1);
  if(buf_wifi) {    
    if(p != -1) {
    WiFi.begin(buf_wifi,buf_passwd);
    while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
     }
    }
  }
  
  //respond the html
  String s ="HTTP/1.1 200 OK\r\n";
  s +="Content-Type: text/html\r\n\r\n";
  s +="<!DOCTYPE HTML>\r\n";

  s += "<html>";
  s += "<style>.green{color:green}span {width:300px}.smt{background-color:blue;color:white}.shape{font-size:1.3em;width:200px;height:50px;border-radius:10px;}</style>";
  s += "<h2 class='green'>Choose WiFi and Enter password!</h2>";
  s += "<h3> Robot car ip : ";
  s += WiFi.localIP().toString().c_str();
  s += ":";
  s += localUdpPort;
  s += "</h3>";
  for (int i = 0; i < n; ++i) {
    
    s += "<form action='http://www.example.com' method='post'>";
    s += "<input type='text' name='wifi' class='pswd shape' value='";
    s += WiFi.SSID(i);
    s += "'>";
    s += "<input type='text' name='pass' class='pswd shape' placeholder='password'>";
    s += "<input type='hidden' name='ghost'>";
    s += "<input type='submit' class='smt shape'>"; 
    
    s += "</form>";
  }
  
  s += "</html>";
  client.flush();
  client.print(s);
  delay(1);
  //Serial.println("Client disconnected");
}

