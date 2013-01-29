#include <iostream>
#include <boost/lexical_cast.hpp>
#include <string>
#include "abandon-all-reason.h"

bool failed = false;

void fail() {
  failed = true;
}

typedef std::string string;

template <class a>
class str;

#define as_string_0(type, expr) \
  template <> \
  class str < type > { \
  public: \
    string s = (expr); \
  } \
  ;

#define as_string_1(type, expr) \
  template <class a> \
  class str < type > { \
  public: \
    string s = (expr); \
  } \
  ;

as_string_0(One, "One");
as_string_0(Z, "Z");
as_string_1(Not<a>, "Not(" + str<a>().s + ")");
as_string_1(Prime<a>, "Prime(" + str<a>().s + ")");
as_string_1(S<a>, boost::lexical_cast<string>(1 + a()));

template <unsigned val>
class str <Peano<val> > {
public:
  string s = boost::lexical_cast<string>(val);
};

template <class a, class b>
class str <Add<a, b> > {
public:
  string s = "Add(" + str<a>().s + ", " + str<b>().s + ")";
};

template <class a, class b>
class str <Mul<a, b> > {
public:
  string s = "Mul(" + str<a>().s + ", " + str<b>().s + ")";
};

template <class a, class b, class av, class bv>
class really_equal {
public:
  really_equal() {
    std::cerr
      << str<a>().s
      << " is not equal to "
      << str<b>().s
      << "\n  because "
      << av()
      << " != "
      << bv()
      << "\n";
    fail();
  }
};

template <class a, class b, class v>
class really_equal <a, b, v, v> {
};

template <class a, class b>
class equal {
  typedef really_equal<a, b, typename a::V, typename b::V> my_equal_t;
  my_equal_t really;
public:
  equal() : really(my_equal_t()) {}
};

#ifdef assert
#undef assert
#endif

template <class a, class b>
class really_assert {
};

template <class a>
class really_assert <a, Z> {
public:
  really_assert() {
    std::cerr
      << str<a>().s
      << " is not true\n";
    fail();
  }
};

template <class a>
class assert {
  typedef really_assert<a, typename a::V> my_assert_t;
  my_assert_t really;
public:
  assert() : really(my_assert_t()) {}
};

int main() {
  assert<Not<Prime<Peano<38>::V>::V> >();
  assert<Prime<Peano<37>::V> >();
  equal<Add<Peano<7>::V, Peano<5>::V>, Peano<12> >();
  equal<Mul<Peano<7>::V, Peano<5>::V>, Peano<35> >();
  return failed ? One() : Z();
}
