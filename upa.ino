#include <OneWire.h>                
#include <DallasTemperature.h>
#include "DHT.h"
#include <DHT.h> 
#define DHTPIN 2                // Pin donde está conectado el sensor
#define DHTTYPE DHT11           // Sensor DHT11
DHT dht(DHTPIN, DHTTYPE);       // Inicializando el sensor DHT11

OneWire ourWire1(3);                    //Se establece el pin 3  como bus OneWire
DallasTemperature sensors1(&ourWire1); //Se declara una variable u objeto para nuestro sensor1

int temp1,temp2,temp3,temp4,hum1,hum2,hum3,hum4,temps1,temps2,temps3,temps4;
int sensorReading;                    //Pin análogo en espera
void setup()
{
 delay(1000);
 Serial.begin(9600);
 dht.begin();             //Se inicia el sensor
 sensors1.begin();   //Se inicia el sensor 1
  // Encabezado de valores a mostrar
  Serial.print('\t');
  Serial.print("HA");
  Serial.print('\t');
  Serial.print("TC");
  Serial.print('\t');
  Serial.print("Ts1");
  Serial.print('\t');
  Serial.print('\t');
  Serial.print("HS1");
  Serial.print('\t');
  Serial.print("HS2");
  Serial.print('\t');
  Serial.print("HS3");
  Serial.print('\t');
  Serial.print("HS4");
  Serial.print('\n'); 
}
 
void loop() 
{
 sensors1.requestTemperatures();           //Se envía el comando para leer la temperatura
 float temp1= sensors1.getTempCByIndex(0); //Se obtiene la temperatura en ºC del sensor 1  
 
 sensorReading=analogRead(0);              //Instrucción para obtener dato analógico de Hum y Temp ambiental
 int h = dht.readHumidity();               //Leemos la Humedad ambiental
 int t = dht.readTemperature();            //Leemos la temperatura ambiental en grados Celsius

 int val1 = analogRead(A0);               // Lectura de Analogico 0
 int val2 = analogRead(A1);               // Lectura de Analogico 1
 int val3 = analogRead(A2);               // Lectura de Analogico 2
 int val4 = analogRead(A3);               // Lectura de Analogico 3

  temps1=map(val1,1024,0,100,0);
  temps1=100-temps1;
  hum1=temps1;
  temps2=map(val2,1024,0,100,0);
  temps2=100-temps2;
  hum2=temps2;
  temps3=map(val3,1024,0,100,0);
  temps3=100-temps3;
  hum3=temps3;     
  temps4=map(val4,1024,0,100,0);
  temps4=100-temps4;
  hum4=temps4;

 //Impresion de Valores
   Serial.print('\t');
   Serial.print(h);      //Valor de la Humedad Ambiental
   Serial.print('\t');
   Serial.print(t);      //Valor de la tempertura ambiental
   Serial.print('\t');
   Serial.print(temp1);   //Valor de la humedad de suelo 1
   Serial.print('\t');
   Serial.print('\t');
   Serial.print(hum1);     //Valor de la humedad de suelo 1
   Serial.print('\t');
   Serial.print(hum2);     //Valor de la humedad de suelo 2
   Serial.print('\t');
   Serial.print(hum3);     //Valor de la humedad de suelo 3
   Serial.print('\t');
   Serial.print(hum4);     //Valor de la humedad de suelo 4
   Serial.print('\n');
  delay(6000);
}
