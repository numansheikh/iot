#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

String ssid_ST="********";
String key_ST="********";

WiFiUDP UDP;
#define PORT_UDP 786

IPAddress ipBroadCast(192, 168, 1, 255);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Hello");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid_ST.c_str(), key_ST.c_str());
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }     
  Serial.print("ST:");
  Serial.println(WiFi.localIP());

  UDP.begin(PORT_UDP);
  delay(1000);
}

#define BUFFER_SIZE 64
char s_buf[BUFFER_SIZE];
int s_buf_i=0;

void remoteSend(){ 
  if (Serial.available()){
    if (s_buf_i<BUFFER_SIZE)
      s_buf[s_buf_i]=Serial.read();
    else
      s_buf[s_buf_i]=0;
    if (s_buf[s_buf_i]==0 || s_buf[s_buf_i]==10 || s_buf[s_buf_i]==13){
      s_buf[s_buf_i]=0;
      UDP.beginPacket(ipBroadCast, PORT_UDP);
      UDP.write(s_buf,s_buf_i);
      UDP.endPacket();
      Serial.println("Sent "+String(s_buf));
      s_buf_i=-1;
    }
    s_buf_i++;
    
  }
}

void remoteRecieve(){
  char buf[BUFFER_SIZE];
  int packetSize = UDP.parsePacket();
  if (packetSize){// receive incoming UDP packets
    Serial.print("Recieved ");
    int len = UDP.read(buf, BUFFER_SIZE);
    if (len > 0)
      buf[len] = 0;
    Serial.write(buf,len);
    Serial.println();
  }
}

void loop(){
  remoteSend();
  remoteRecieve();
}
