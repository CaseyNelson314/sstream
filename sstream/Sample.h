#include "sstream.h"

class Sample {
    int integer;
  public:

    Sample(int integer): integer(integer) {}
    
    friend std::sstream& operator<<(std::sstream& ss, Sample out) {
      ss << out.integer;
      return ss;
    }
    
};
