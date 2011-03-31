#include <boost/static_assert.hpp>
#include <iostream>

template <size_t n>
struct fib {
  static const size_t value = fib<n-1>::value + fib<n-2>::value;
};

template <>
struct fib<0> {
  static const size_t value = 0;
};

template <>
struct fib<1> {
  static const size_t value = 1;
};

template <>
struct fib<2> {
  static const size_t value = 2;
};

template <size_t f>
struct isEven {
  static const bool value = f%2==0;
};

template <size_t n>
struct nextTerm {
  static const size_t limit = 4000000;
  static const size_t value =
    fib<n+1>::value < limit ?
      n+1 :
      0;
};

template <size_t n=1>
struct sum {
  static const size_t value =
    fib<n>::value
    *
    isEven<
      fib<n>::value
    >::value
    +
    sum<
      nextTerm<n>::value
    >::value;
};
template <>
struct sum<0> {
  static const size_t value = 0;
};

int main() {
  // checks for fibonacci generator
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

  BOOST_STATIC_ASSERT(isEven<10>::value);

  std::cout << sum<>::value << std::endl;
}
