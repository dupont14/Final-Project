#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include "MQTTClient.h"
#include "../Headers/GPIO.h"
using namespace std;
using namespace exploringBB;

//Please replace the username, feed and token with your values
#define ADDRESS    "tcp://io.adafruit.com"
#define CLIENTID   "Beagle4"
#define TOPIC      "Dupont14/feeds/cpe-522-final-project.windowopen"
#define AUTHMETHOD "Dupont14"
#define AUTHTOKEN  ""
#define QOS        1
#define TIMEOUT    10000L
#define ADC_PATH   "/sys/bus/iio/devices/iio:device0/in_voltage"
#define ADC        0



int main(int argc, char* argv[]) {
   GPIO led(112); 
   char str_payload[100];          // Set your max message size here
   MQTTClient client;
   cout << "Starting Beagle board MQTT Adafruit Publish Example" << endl;
   MQTTClient_connectOptions opts = MQTTClient_connectOptions_initializer;
   MQTTClient_message pubmsg = MQTTClient_message_initializer;
   MQTTClient_deliveryToken token;
   MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
   opts.keepAliveInterval = 20;
   opts.cleansession = 1;
   opts.username = AUTHMETHOD;
   opts.password = AUTHTOKEN;
   int rc;
   if ((rc = MQTTClient_connect(client, &opts)) != MQTTCLIENT_SUCCESS) {
      cout << "Failed to connect, return code " << rc << endl;
      return -1;
   }

   GPIO_VALUE value = led.getValue();
   int pubValue;
   if(value == HIGH)
	{
	pubValue = 0;
	}
   else
	{
	pubValue = 1;
	}

   sprintf(str_payload, "%d", pubValue);
   pubmsg.payload = str_payload;
   pubmsg.payloadlen = strlen(str_payload);
   pubmsg.qos = QOS;
   pubmsg.retained = 0;
   MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
   cout << "Waiting for up to " << (int)(TIMEOUT/1000) <<
        " seconds for publication of " << str_payload <<
        " \non topic " << TOPIC << " for ClientID: " << CLIENTID << endl;
   rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
   if(rc == MQTTCLIENT_SUCCESS) {
     cout << "Message with token " << (int)token << " delivered." << endl;
   }
   else {
     cout << "Did not complete with error code: " << rc << endl;
     // MQTTCLIENT_SUCCESS 0           MQTTCLIENT_FAILURE -1
     // MQTTCLIENT_DISCONNECTED -3     MQTTCLIENT_MAX_MESSAGES_INFLIGHT -4
     // MQTTCLIENT_BAD_UTF8_STRING -5  MQTTCLIENT_NULL_PARAMETER -6
     // MQTTCLIENT_TOPICNAME_TRUNCATED -7   MQTTCLIENT_BAD_STRUCTURE -8
     // MQTTCLIENT_BAD_QOS   -9        MQTTCLIENT_SSL_NOT_SUPPORTED   -10
   }
   MQTTClient_disconnect(client, 10000);
   MQTTClient_destroy(&client);
   return rc;
   
}

