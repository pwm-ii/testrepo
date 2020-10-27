#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"
#include <SHT1x.h>
// Library only supports hardware SPI at this time
// Connect SCLK to UNO Digital #13 (Hardware SPI clock)
// Connect MISO to UNO Digital #12 (Hardware SPI MISO)
// Connect MOSI to UNO Digital #11 (Hardware SPI MOSI)
#define RA8875_INT 2
#define RA8875_CS 10
#define RA8875_RESET 9

int x = 5.0/1024.0; 
int i = 0;
int j = 0.0;
int sensePin = A7;
int myArray[1023];
int flow;
int FlowLPM;
float temp_c;
float humidity;


// Specify data and clock connections and instantiate SHT1x object
#define dataPin  20
#define clockPin 21
SHT1x sht1x(dataPin, clockPin);

//Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);
//uint16_t tx, ty;



void setup() {
  Serial.begin(38400);
  

    Serial.println("RA8875 start");
    Serial.print("Humidity");
    Serial.print(" (%) ");
    Serial.print(",   \t ");
    Serial.print("Temperature");
    Serial.print(" (*C) ");
    Serial.print(",   \t ");
    Serial.print("Flow Rate");
    Serial.println(" (L/min) ");
    /* Initialize the display using 'RA8875_480x80', 'RA8875_480x128', 'RA8875_480x272' or 'RA8875_800x480' */
     /*if (!tft.begin(RA8875_800x480)) {
  //  Serial.println("RA8875 Not Found!");
  //  while (1);
  
 } */

 

}
 




void loop() {

    /*  for (i = 0; i < 1024; i++){
        j = (j + x);
     myArray[i] =  0.8651023864 + j; 
     
    }
    Serial.println(j);
   */

  // Read values from the sensor
  temp_c = sht1x.readTemperatureC();
  humidity = sht1x.readHumidity();

  
   if (humidity < 0){
    humidity = 0.00;
 }

  Serial.print(temp_c, DEC);
  Serial.print(" / ");
  Serial.print(humidity, DEC);
    flow = analogRead(sensePin);
  Serial.print(" / ");

   
  //  FlowLPM = (((myArray[flow-79]-0.865)/0.825));
 //if (FlowLPM < 0.0){
 //   FlowLPM = 0.00;
  //}

 Serial.print(FlowLPM, DEC );
 Serial.print(" / ");
 Serial.println(flow, DEC);
 
  delay(500);
 

 /* tft.displayOn(true);
  tft.GPIOX(true);      // Enable TFT - display enable tied to GPIOX
  tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
  tft.PWM1out(255);
  tft.fillScreen(RA8875_BLACK);

tft.textMode();
tft.cursorBlink(32);

   Set the cursor location (in pixels) 
  tft.textSetCursor(70, 200);

  /* Render some text! 
  char string1[15] = " Temp (C): ";

  if (temp_c<=25 && temp_c >=23){
  tft.textTransparent(RA8875_GREEN);
  }
  if ((temp_c>=25 && temp_c<=30)|| (temp_c<=23 && temp_c>=15)){
  tft.textTransparent(RA8875_YELLOW);
  }
  if (temp_c>30 && temp_c<=15) {
  tft.textTransparent(RA8875_RED);
  }
  tft.textEnlarge(3);
  tft.textWrite(string1);
  tft.textWrite(dtostrf(temp_c, 3, 2, string1));
tft.textSetCursor(100,125);


 char string2[15]= "Humidity (%):";
 
 if (humidity<8){ 
  tft.textTransparent(RA8875_GREEN);
 }
 if (humidity>=5 && humidity<=10){
  tft.textTransparent(RA8875_YELLOW);
 }
 if (humidity>10){
  tft.textTransparent(RA8875_RED);
 }
  tft.textEnlarge(3);
  tft.textWrite(string2);
  tft.textWrite(dtostrf(humidity, 4, 3, string2));
 

  /* Change the cursor location and color ... 
  tft.textSetCursor(80,45);

  char string3[15] = "Flow (L/min):";
  if (FlowLPM>1.3 && FlowLPM<3.2){ 
  tft.textTransparent(RA8875_GREEN);
 }
 if (FlowLPM>=0.5 && FlowLPM<=1.3 || FlowLPM >= 3.2 && FlowLPM <= 4){
  tft.textTransparent(RA8875_YELLOW);
 }
 if (FlowLPM < 0.5 && FlowLPM > 4){
  tft.textTransparent(RA8875_RED);
 }
  tft.textEnlarge(3);
  tft.textWrite(string3);
  tft.textWrite(dtostrf(FlowLPM,5,2,string3));

if (humidity>=10 || (temp_c>30 && temp_c<=15) || (FlowLPM < 0.5 && FlowLPM > 4)){
  tft.fillRect(0,325,800,155, RA8875_RED);
  tft.textSetCursor(290,380);
  char string4[15] = "DANGER!";
  tft.textTransparent(RA8875_BLACK);
  tft.textEnlarge(4);
  tft.textWrite(string4);
}  
else if (humidity>=5 && humidity<10 || (temp_c>=25 && temp_c<=30)|| (temp_c<=23 && temp_c>=15) || (FlowLPM>=0.5 && FlowLPM<=1.3 || FlowLPM >= 3.2 && FlowLPM <= 4 )){
  tft.fillRect(0,325,800,155, RA8875_YELLOW);
} 
else {
  tft.fillRect(0,325,800,155, RA8875_GREEN);
}
*/
 
  }
