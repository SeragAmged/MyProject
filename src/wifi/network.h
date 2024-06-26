#ifndef NETWORK_H
#define NETWORK_H
#include<WiFi.h>


extern const char *ssid, *password;
extern WiFiServer myServer;
extern WiFiClient client ;
extern int currentData;

           
typedef void (*DataHandler)(int);

void connectToWifi(const char *ssid, const char *password);
void handleClientConnection(DataHandler handler,size_t type);//type 0 ,1 send receive
void receiveClientData();

#endif