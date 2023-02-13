/*#ifndef ESP32PING_H
#define ESP32PING_H

#include <Arduino.h>
#include <WiFi.h>

//extern "C" {
#include <ping.h>
//}

#ifdef ENABLE_DEBUG_PING
#define DEBUG_PING(...) Serial.printf(__VA_ARGS__)
#else
#define DEBUG_PING(...)
#endif

#ifdef __cplusplus
extern "C"{
#endif

void esp_schedule(void);
void esp_yield(void);

#ifdef __cplusplus
} // extern "C"
#endif

class PingClass {
public:
    PingClass();

    bool ping(IPAddress dest, byte count = 5);

    bool ping(const char *host, byte count = 5);

    float averageTime();

protected:
    static void _ping_sent_cb(void *opt, void *pdata);

    static void _ping_recv_cb(void *opt, void *pdata);

    IPAddress _dest;
    ping_option _options;

    static byte _expected_count, _errors, _success;
    static float _avg_time;
};


extern PingClass Ping;

#endif*/