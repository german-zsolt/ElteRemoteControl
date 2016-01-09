#ifndef SUM_TEST_H
#define SUM_TEST_H

#include <cxxtest/TestSuite.h>
#include <sum.h>

class SumTest : public CxxTest::TestSuite {
  public:
    void testSum() {
      TS_ASSERT_EQUALS(3, Sum::sum(1,2));
    }
    void testSum2() {
      TS_ASSERT_DIFFERS(3, Sum::sum(2,2));
    }
};

#endif
