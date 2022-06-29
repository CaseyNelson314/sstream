#include "sstream.h"
#include "Sample.h"

void setup() {
  Serial.begin(115200);
}

void loop() {
  Sample samp;
  std::sout << "now : " << millis() << std::tab << 0 << std::endl;
  delay(10);
}
