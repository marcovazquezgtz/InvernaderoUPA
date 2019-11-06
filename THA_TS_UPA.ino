#include <OneWire.h>                
#include <DallasTemperature.h>
#include "DHT.h"
#include <DHT.h> 
#define DHTPIN 2                // Pin donde está conectado el sensor
#define DHTTYPE DHT11           // Sensor DHT11
DHT dht(DHTPIN, DHTTYPE);       // Inicializando el sensor DHT11

OneWire ourWire1(3);                    //Se establece el pin 3  como bus OneWire
DallasTemperature sensors1(&ourWire1); //Se declara una variable u objeto para nuestro sensor1

int temp1,temp2,temp3,temp4,temp5,hum1,hum2,hum3,hum4,hum5,temps1,temps2,temps3,temps4,temps5;
int sensorReading;//Pin análogo en espera
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
  /*Serial.print('\t');
  Serial.print("Ts1");
  Serial.print('\t');
  Serial.print('\t');
  Serial.print("HS1");*/
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
 
  /*temps1=map(val1,1024,0,100,0);
  temps1=100-temps1;
  hum1=temps1;*/
 //Impresion de Valores
   Serial.print('\t');
   Serial.print(h);      //Valor de la Humedad Ambiental
   Serial.print('\t');
   Serial.print(t);      //Valor de la tempertura ambiental
  
   Serial.print('\n');
  delay(6000);
}
