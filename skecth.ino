#include <Servo.h>

#define BLYNK_TEMPLATE_ID "TMPLy4alRxRW"
#define BLYNK_DEVICE_NAME "Smart Jemuran"
#define BLYNK_AUTH_TOKEN "RG29eCWPiNe3xi2JliwRORVHxEvVaYJ9"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

int ldr, hujan;
Servo jemuran_1;

bool status = false;
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();

  if(pinValue ==1 ){
    status = true;
    Serial.println("Jemuran Buka");
  }
 else{
   status = false;
 }
}

void setup()
{
  Serial.begin(115200);
 jemuran_1.attach(25);
  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  Blynk.run();
  ldr = map(analogRead(34),0,4096, 100,0);
  hujan = map(analogRead(35), 0, 4096, 0, 100);
  
  if (status == true){
    jemuran_1.write(0);
    Serial.println("Jemuran Buka");
  }else{

  if(ldr < 30 || hujan > 40){
    jemuran_1.write(180);
    Serial.println("Jemuran Tutup");
  }
  }
}
