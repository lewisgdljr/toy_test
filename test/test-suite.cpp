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

#include <factorial.hpp>
#include <leap_year.hpp>
#include "toy_test.hpp"
#include "leap-year-test.hpp"
#include "factorial-test.hpp"
#include "demo-test.hpp"

int main() {
  toy_test::run_suites( {leap_year_suite,
			 factorial_suite,
			 demo_suite,
    } );
}
