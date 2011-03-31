#include <boost/static_assert.hpp>
#include <iostream>

template <int n>
struct isMultiple {
  static const int value = n%3==0 or n%5==0;
};

template <int n>
struct sum {
  static const int value = isMultiple<n>::value*n + sum<n-1>::value;
};

template <>
struct sum<2> {
  static const int value = 0;
};

int main() {
  BOOST_STATIC_ASSERT(sum<10-1>::value == 23);
  BOOST_STATIC_ASSERT(isMultiple<3>::value == true);
  BOOST_STATIC_ASSERT(isMultiple<5>::value == true);
  BOOST_STATIC_ASSERT(isMultiple<6>::value == true);
  BOOST_STATIC_ASSERT(isMultiple<9>::value == true);

  std::cout << sum<1000>::value << std::endl;
}
