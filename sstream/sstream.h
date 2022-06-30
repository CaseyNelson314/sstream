/**
       @file   sstream.h
       @brief  Serial stream output
       @date   2022/06/29
*/

#pragma once

namespace std {
  
String streambuf;  // stream buffer

/**
   @breif オプション挿入
*/
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
  

class sstream {
  public:
    /**
       @brief ストリーム挿入
       @param 出力値
    */
    template<class T>
    friend sstream& operator<<(sstream &sstrm, const T input) noexcept {
      streambuf += input;
      return sstrm;
    }
    friend sstream& operator<<(sstream &sstrm, void(*input)()) noexcept {
      input();
      return sstrm;
    }

    /**
       @brief 通常出力
       @param 出力値
    */
    template<class T>
    void print(const T input) const noexcept {
      Serial.print(input);
    }
    template<class T>
    void println(const T input) const noexcept {
      Serial.println(input);
    }
};

extern sstream sout;

}  // namespace std
