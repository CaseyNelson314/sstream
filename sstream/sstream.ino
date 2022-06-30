#include "sstream.h"
#include "Sample.h"

Sample samp(4321);

void setup() {
  Serial.begin(115200);
  const uint32_t t = micros();

  std::sout << samp << std::endl;

  std::sout << "now : " << 1000 << std::tab << "ms" << std::endl;

  std::sout << micros() - t << std::endl;
}

void loop() {
}
