#include <Arduino.h>
#include <WiFi.h>
#include "network.h"
#include <led/led.h>

const char *ssid = "Home",
           *password = "AAA@@BBB##CCC";

WiFiServer myServer = WiFiServer(80);
WiFiClient client;

void connectToWifi(const char *ssid, const char *password)
{

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println("IP Address: " + WiFi.localIP().toString());

  myServer.begin();

  blinkLed(3);
}
int myCounter = 0;

void handleClientConnection(DataHandler handler, size_t type)
{

  if (!client.connected())
  {
    client = myServer.available();
  }

  if (type == 0)
  { // receive
    if (client.available())
    {
      int data = client.read();
      handler(data);

      Serial.println("Received data: " + String(data));
    }
  }
  else if (type == 1)
  // send
  {
    if (client.connected())
    {
      // client.write(String(3).c_str());
      client.write(String(3).c_str());

      client.write(("Object detected! Count: " + String(myCounter++)).c_str());
      Serial.println("Handler should work");
    }
    else
    {
      Serial.println("Failed to connect to client");
    }
  }
}

int currentData = 0;

void receiveClientData()
{
  if (!client.connected())
  {
    client = myServer.available();
  }

  if (client.available())
  {
    currentData = client.read();

    Serial.println("Received data: " + String(currentData));
  }
}
