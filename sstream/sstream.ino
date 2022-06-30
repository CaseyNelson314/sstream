#include "sstream.h"
#include "Sample.h"

Sample samp(4321);

void setup() {
  Serial.begin(115200);
}

void loop() {
  std::sout << "now : "
            << millis()
            << samp      << std::tab
            << "ms"      << std::endl;
  delay(10);
}
