/*
 * Toy Test - Toy Unit Testing
 * Written in 2018 by Gerald Lewis <lewisgdljr@gmail.com>
 *
 * To the extent possible under law, the author(s) have dedicated all copyright
 * and related and neighboring rights to this software to the public domain
 * worldwide. This software is distributed without any warranty.
 * You should have received a copy of the CC0 Public Domain Dedication along
 * with this software. If not, see
 * <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#include "factorial.hpp"
#include "leap_year.hpp"
#include "toy_test.hpp"

toy_test::suite leap_year_suite{
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

toy_test::suite factorial_suite{
   "Test for factorial",
   {
      {"0! == 1", [] { ASSERT( factorial( 0 ) == 1 ); }},
      {"3! == 6", [] { ASSERT( factorial( 3 ) == 6 ); }},
      {"10! == 3628800", [] { ASSERT( factorial( 10 ) == 3628800 ); }},
   }};

int main() {
   toy_test::run_suites( {leap_year_suite, factorial_suite} );
   // to get 100% coverage in toy_test, too!
   toy_test::run_suites( {factorial_suite} );
}
