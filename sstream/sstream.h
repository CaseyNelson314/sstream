/**
       @file   sstream.h
       @brief  Serial stream output
       @date   2022/06/29
*/

#pragma once

namespace std {

static String streambuf;  // stream buffer

class sstream {
  public:
    // insertion number
    template<class T>
    friend sstream& operator<<(sstream &sstrm, T out) {
      streambuf += out;  // stream挿入
      return sstrm;
    }

    // insertion function
    friend sstream& operator<<(sstream &sstrm, void(*f)()) {
      f();
      return sstrm;
    }
    
};

extern sstream sout;

void flush() {
  streambuf = "";  // baffer clear
}
void endl() {
  Serial.println(streambuf);
  flush();
}
void end() {
  Serial.print(streambuf);
  flush();
}
void tab() {
  streambuf += '\t';  // stream挿入
}


}  // namespace std
