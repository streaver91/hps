#ifndef HPS_DOUBLE_SERIALIZER_H_
#define HPS_DOUBLE_SERIALIZER_H_

#include <iostream>
#include <type_traits>
#include "../serializer.h"

namespace hps {

template <class T, class B>
class Serializer<T, B, typename std::enable_if<std::is_floating_point<T>::value, void>::type> {
 public:
  static void serialize(const T& num, OutputBuffer<B>& ob) {
    const char* num_ptr = reinterpret_cast<const char*>(&num);
    ob.write(num_ptr, sizeof(num));
  }

  static void parse(T& num, InputBuffer<B>& ib) {
    char* num_ptr = reinterpret_cast<char*>(&num);
    ib.read(num_ptr, sizeof(num));
  }
};

}  // namespace hps

#endif
