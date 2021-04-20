//
// Created by Noisyedge on 2019-05-20.
//

#ifndef MDL_CUSTOM_ASSERT_H
#define MDL_CUSTOM_ASSERT_H

#include <cstdlib>
#include <iostream>

class Assert {
public:
  Assert(bool cond) : assertion(cond) {}
  ~Assert() {
    if (!assertion) {
      std::cerr << std::endl;
      abort();
    }
  }
  template <class T> inline Assert &operator<<(const T &message) {
    if (!assertion)
      std::cerr << message;
    return *this;
  }

private:
  bool assertion;
};

#ifdef NDEBUG
class NullAssert {
public:
  NullAssert(bool cond) {}
  template <class T> inline NullAssert &operator<<(const T &message) {
    return *this;
  }
};
#endif

#ifndef NDEBUG
#undef assert

#define assert(cond)                                                           \
  Assert(cond) << "Assertion failure at " << __FILE__ << ":" << __LINE__       \
               << " -- "
#define release_assert(cond)                                                   \
  Assert(cond) << "Fatal error at at " << __FILE__ << ":" << __LINE__ << " -- "
#else
#undef assert
#define assert(cond) NullAssert(cond)
#define release_assert(cond) Assert(cond) << "Fatal error -- "
#endif

#define UNREACHABLE                                                            \
  do {                                                                         \
    release_assert(false) << "UNREACHABLE";                                    \
    exit(3);                                                                   \
  } while (0)
#define NOT_IMPLEMENTED                                                        \
  do {                                                                         \
    release_assert(false) << "NOT IMPLEMENTED";                                \
    exit(3);                                                                   \
  } while (0)

#endif // MDL_CUSTOM_ASSERT_H