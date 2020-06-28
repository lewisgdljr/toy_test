namespace factorial_internal
{
  //># toy_test::suite factorial_suite
  //>A sample test suite. Tests the factorial function in factorial.hpp
  //>

  toy_test::suite factorial_suite{
   "Test for factorial",
   {
      {"0! == 1", [] { ASSERT( factorial( 0 ) == 1 ); }},
      {"3! == 6", [] { ASSERT( factorial( 3 ) == 6 ); }},
      {"10! == 3628800", [] { ASSERT( factorial( 10 ) == 3628800 ); }},
   }};
}
using factorial_internal::factorial_suite;
