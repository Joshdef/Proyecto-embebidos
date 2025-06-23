#include <Arduino.h>
#define ROLE_TX 
#define LORA_CS 8
#define LORA_DIO 14
#define LORA_RST 12 
#define LORA_BUSY 13
#include <RadioLib.h>

Module*lora_hw= new Module(LORA_CS, LORA_DIO, LORA_RST, LORA_BUSY);

SX1262 radio(lora_hw);

void setup(){
    Serial.begin(115200);
  while (!Serial) {}

  Serial.println(F("\n[SX1262] Init…"));
  int16_t err = radio.begin(915.0);   // Initialize LoRa at 915 MHz
  if (err != RADIOLIB_ERR_NONE) {
    Serial.printf("Init fail %d\n", err);
    for (;;);
  }
  Serial.println("LoRa OK");
}

void loop() {
  int16_t r = radio.transmit("Ping LoRa");
  Serial.println(r == RADIOLIB_ERR_NONE ? "TX OK" : String("TX err ") + r);
  delay(5000);
}

