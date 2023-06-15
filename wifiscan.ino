#include <SPI.h>  
#include <WiFiNINA.h> 
void setup() 
	{ 
	 //Initialize serial and wait for port to open: 
	 Serial.begin(9600); 
	 while (!Serial) { 
	   ; // wait for serial port to connect. Needed for native USB port only 
	 }  // scan for existing networks: 
	 Serial.println(); 
	 Serial.println("Scanning available networks..."); 
	 listNetworks(); 
	} 
	void loop() 
	{ 
	 delay(10000);  // scan for existing networks: 
	 Serial.println("Scanning available networks..."); 
	 listNetworks(); 
	} 
	void listNetworks() 
	{  // scan for nearby networks: 
	 Serial.println("** Scan Networks **"); 
	 int numSsid = WiFi.scanNetworks(); 
	 if (numSsid == -1) 
	 { 
	   Serial.println("Couldn't get a WiFi connection"); 
	   while (true); 
	 }  // print the list of networks seen: 
	 Serial.print("number of available networks: "); 
	 Serial.println(numSsid); 
	 // print the network number and name for each network found: 
	 for (int thisNet = 0; thisNet < numSsid; thisNet++) { 
	   Serial.print(thisNet + 1); 
	   Serial.print(" SSID: "); 
	   Serial.println(WiFi.SSID(thisNet)); 
	   Serial.flush(); 
	 } 
	 Serial.println(); 
	}  
