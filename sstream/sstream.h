/**
       @file   sstream.h
       @brief  Serial stream output
       @date   2022/06/29
*/

namespace std {

String streambuf = "";

class sstream {
  public:
    // insertion number
    template<class T>
    friend sstream& operator<<(sstream &sstrm, T out) {
      streambuf += out;
      return sstrm;
    }

    // insertion function
    friend sstream& operator<<(sstream &sstrm, void(*f)()) {
      f();
      return sstrm;
    }
};

extern sstream sout;

/**
 * @brief バッファクリア
 */
void flush() {
  streambuf = "";
}

/**
   @brief 改行コードを挿入し出力
   バッファをクリア
*/
void endl() {
  Serial.println(streambuf);
  flush();
}

/**
   @brief 出力
   バッファをクリア
*/
void end() {
  Serial.print(streambuf);
  flush();
}

/**
   @brief tab挿入
*/
void tab() {
  streambuf += '\t';
}


}  // namespace std
