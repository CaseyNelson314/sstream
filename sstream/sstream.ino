#include "sstream.h"

void setup() {
  Serial.begin(115200);
}

void loop() {
  std::sout << "now : " << millis() << std::tab << "ms" << std::endl;
  delay(10);
}
