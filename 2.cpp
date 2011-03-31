#include <boost/static_assert.hpp>
#include <iostream>

template <size_t n>
struct fib {
  static const size_t value = fib<n-1>::value + fib<n-2>::value;
};

template <>
struct fib<1> {
  static const size_t value = 1;
};

template <>
struct fib<2> {
  static const size_t value = 2;
};

int main() {
  BOOST_STATIC_ASSERT(fib<1>::value == 1);
  BOOST_STATIC_ASSERT(fib<2>::value == 2);
  BOOST_STATIC_ASSERT(fib<3>::value == 3);
  BOOST_STATIC_ASSERT(fib<4>::value == 5);
  BOOST_STATIC_ASSERT(fib<5>::value == 8);
  BOOST_STATIC_ASSERT(fib<6>::value == 13);
  BOOST_STATIC_ASSERT(fib<7>::value == 21);
  BOOST_STATIC_ASSERT(fib<8>::value == 34);
  BOOST_STATIC_ASSERT(fib<9>::value == 55);
  BOOST_STATIC_ASSERT(fib<10>::value == 89);
}
