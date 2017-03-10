/*******************************************
L298N MOTOR DRIVER SET UP
/*******************************************/


//motor A Right
 int const EN_A       = 15;   //D8 pwm
 int const IN1        = 4;    //D2
 int const IN2        = 5;    //D1
 //motor B left
 int const EN_B       = 12;   //D6 pwm
 int const IN3        = 13;   //D7
 int const IN4        = 14;   //D5
 char command;
 int velocity = 1023;

/*============ END MOTOR SETUP ============*/
#include <ESP8266WiFi.h>
#include <DNSServer.h>
WiFiServer server(80);
//add
#include <WiFiUdp.h>
WiFiUDP udp;
unsigned int localUdpPort = 4210;       //local port listen on
char incomingPacket[255];               //buffer for incoming packer
char replyPacket[] = "Hi there! got the hacker alinthit";

const byte DNS_PORT = 53;
DNSServer dnsServer;
int n;
void scanNet();
void setup() {
  WiFi.mode(WIFI_AP_STA); 
  WiFi.softAP("ROBOT");
  IPAddress HTTP_IP = WiFi.softAPIP();
  
  scanNet();
 
  dnsServer.setTTL(300);
  dnsServer.setErrorReplyCode(DNSReplyCode::ServerFailure);
  dnsServer.start(DNS_PORT, "www.example.com", HTTP_IP);
  server.begin();
  Serial.begin(115200);
  Serial.print("Server ip is ");
  Serial.println(HTTP_IP);
  //add
  initHardWare();
  udp.begin(localUdpPort);
}

void loop() {
  dnsServer.processNextRequest();
  listenClient();
  //add
  udpMain();
}






