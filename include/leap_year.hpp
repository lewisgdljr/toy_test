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

#define INTENTIONAL_FAILURE
//># `bool is_leap_year(int year)`
//>Calculates whether the parameter, `year`, was a leap year.
//>There's a `#define` to make the test fail, `INTENTIONAL_FAILURE`.
//>This causes the function to NOT throw an exception for years < 1752,
//>which is an error because that was the year that the Gregorian calendar
//>was adopted by the British Empire. (Although it was used by other
//>European nations before that, so it's not an error in those countries...)
//>But I basically just put it in to demonstrate the THROWS() macro.
//>
bool is_leap_year( int year ) {
#ifndef INTENTIONAL_FAILURE
   if ( year < 1752 ) {
      // is the year one in which the Gregorian calendar
      // was used in the British Empire and/or USA?
      throw std::invalid_argument(
         "The Gregorian calendar wasn't used in the "
         "British Empire (and therefore the American colonies) before 1752!" );
   }
#endif // INTENTIONAL_FAILURE

   if ( ( year & 3 ) || ( !( year % 100 ) && ( year % 400 ) ) ) {
      // is the year odd or not a multiple of 4?
      // or is the year an even century but NOT a multiple of 400 years?
      return false;
   }

   return true;
}
