#include <DHT.h>
#include <DHT_U.h>

float result [5];           //Sensor result array        //Including DHT11 library
#define DHTPIN 2          //Define DHT11 digital pin
#define DHTTYPE DHT11     //Define DHT TYPE which is DHT11
DHT dht(DHTPIN, DHTTYPE); //Execute DHT11 library

void setup() 
{
  Serial.begin(9600);       //Starting serial communication
  Serial.println("Program started");
  //Analog setup
  pinMode(A0, INPUT);       //Soil
  pinMode(A1, INPUT);       //Rain
  Serial.print("AWS :");
  Serial.print("\t");
  Serial.print("Rain Drop\t");
  Serial.print("Soil Hum\t");
  Serial.print("Air Hum\t");
  Serial.print("\t");
  Serial.println("Temp \t") ;
  dht.begin(); 
}

void loop()
{
  int A_Rain = analogRead(A0);
  int A_Soil = analogRead(A1); 
  A_Rain = map(A_Rain, 800, 1023, 100, 0);
  A_Soil = map(A_Soil, 400, 1023, 100, 0);
  result[0]=A_Soil;
  result[1]=A_Rain;
  result[3] = dht.readHumidity();
  result[4] = dht.readTemperature();
  Serial.print("AWS : ");
  Serial.print(" \t");
  Serial.print(result[0]);
  Serial.print(" %\t");
  Serial.print("\t");
  Serial.print(result[1]);
  Serial.print(" %\t");
  Serial.print(result[3]);
  Serial.print(" %\t");
  Serial.print("\t");
  Serial.print(result[4]);
  Serial.println("C \t");
  delay(5000);
}