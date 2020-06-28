namespace leap_year_internal
{
  //># toy_test::suite leap_year_suite
  //>A sample test suite. Tests the leap year formula function in leap_year.hpp
  //>
  toy_test::suite leap_year_suite {
   "Test for leap year formula",
   {{"odd years are not leap years", [] { ASSERT( !is_leap_year( 2001 ) ); }},

    {"even years which are not multiples of 4 are not leap years",
     [] { ASSERT( !is_leap_year( 2002 ) ); }},

    {"multiples of 4 but not 100 are leap years",
     [] { ASSERT( is_leap_year( 1996 ) ); }},

    {"multiples of 100 but not 400 are not leap years",
     [] { ASSERT( !is_leap_year( 1900 ) ); }},

    {"multiples of 400 are leap years", [] { ASSERT( is_leap_year( 2000 ) ); }},

    {"years before 1752 are not valid",
     [] { THROWS( is_leap_year( 800 ), std::exception ); }}}};

}

using leap_year_internal::leap_year_suite;
