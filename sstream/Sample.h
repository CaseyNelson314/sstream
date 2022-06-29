#include "sstream.h"

class Sample {
    const int sapm;
  public:

    Sample(int sapm): samp(samp) {}

    friend std::sstream& operator<<(std::sstream ss&, const Sample& r) {
      ss << r.sapm;
      return ss;
    }

};
