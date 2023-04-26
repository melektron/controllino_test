#include <Arduino.h>
#include <Controllino.h>
#include <Ethernet.h>
#include "relay_player.hpp"

uint8_t mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};
uint8_t ip[] = {192, 168, 0, 103};
uint8_t gateway[] = {192, 168, 0, 254};
uint8_t subnet[] = {255, 255, 255, 0};
// Ethernet.begin(mac, ip, gateway, subnet);

void setup()
{
    relay_player::init();    

    Serial.begin(9600);
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    // start the Ethernet connection:
    /*Serial.println("Initialize Ethernet with DHCP:");
    if (Ethernet.begin(mac) == 0)
    {
        Serial.println("Failed to configure Ethernet using DHCP");
        if (Ethernet.hardwareStatus() == EthernetNoHardware)
        {
            Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
        }
        else if (Ethernet.linkStatus() == LinkOFF)
        {
            Serial.println("Ethernet cable is not connected.");
        }
        // no point in carrying on, so do nothing forevermore:
        while (true)
        {
            delay(1);
        }
    }
    // print your local IP address:
    Serial.print("My IP address: ");
    Serial.println(Ethernet.localIP());*/
    relay_player::start_tetris();
}

void loop()
{
    relay_player::run();
    /*for (int freq = 10; freq < 1000; freq += 10)
    {
        int period = 1000 / freq;
        // put your main code here, to run repeatedly:
        for (int i = 0; i < 10; i++)
        {
            digitalWrite(CONTROLLINO_R0 + i, 1);
            delay(period);
        }
        for (int i = 0; i < 10; i++)
        {
            digitalWrite(CONTROLLINO_R0 + i, 0);
            delay(period);
        }
    }*/
    
    /*
    switch (Ethernet.maintain())
    {
    case 1:
        // renewed fail
        Serial.println("Error: renewed fail");
        break;

    case 2:
        // renewed success
        Serial.println("Renewed success");
        // print your local IP address:
        Serial.print("My IP address: ");
        Serial.println(Ethernet.localIP());
        break;

    case 3:
        // rebind fail
        Serial.println("Error: rebind fail");
        break;

    case 4:
        // rebind success
        Serial.println("Rebind success");
        // print your local IP address:
        Serial.print("My IP address: ");
        Serial.println(Ethernet.localIP());
        break;

    default:
        // nothing happened
        break;
    }
    */
}