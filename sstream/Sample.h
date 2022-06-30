#include "sstream.h"

class Sample {
    const int integer;
  public:
    Sample(int integer): integer(integer) {}
    friend std::sstream& operator<<(std::sstream& ss, const Sample& input) noexcept {
      ss << input.integer;
      return ss;
    }
};
