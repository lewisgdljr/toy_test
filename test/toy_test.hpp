/*
 * Toy Test - Toy Unit Testing
 * Written in 2018 - 2020 by Gerald Lewis <lewisgdljr@gmail.com>
 *
 * To the extent possible under law, the author(s) have dedicated all copyright
 * and related and neighboring rights to this software to the public domain
 * worldwide. This software is distributed without any warranty.
 * You should have received a copy of the CC0 Public Domain Dedication along
 * with this software. If not, see
 * <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#pragma once
#ifndef TOY_TEST_HPP_INCLUDED
#define TOY_TEST_HPP_INCLUDED

#include <functional>
#include <initializer_list>
#include <iostream>
#include <vector>

//># namespace toy_test
//>
namespace toy_test {
  //>## `class toy_test::test_case`
  //>An element of a `suite`. Contains a name and an anonymous function.
  //>Usually created anonymously, as an element of an array within a `suite`.
  //>
  struct test_case {
    const char*           name;
    std::function<void()> run;
    void                  operator()() const { run(); }
  };

  //>## `class toy_test::failure`
  //>Holds information about a `test_case`'s failure.
  //>Not usually instantiated directly, but from the failure of an `ASSERT`.
  //>
  struct failure {
    const char* expr;
    int         line;
  };

  //>## `class toy_test::suite`
  //>A container for `test_case`s. Holds a name and a `std::vector`
  //>of `test_case`s. Usually initialized using aggregate initialization.
  //>
  struct suite {
    const char*            name;
    std::vector<test_case> tests;
    //>### `bool toy_test::suite::run()`
    //>Function that executes the `test_case`s in a `suite`.
    //>It prints the results of the test run, including how many
    //>`test_case`s succeeded and failed.
    //>
    bool run() const {
      auto ok = true;
      auto count = 0;
      auto count_ok = 0;
      auto count_fail = 0;
      std::cout << "[SUITE] Running test suite: \"" << name << "\""
		<< std::endl;
      for ( auto&& test : tests ) {
	try {
	  ++count;
	  test();
	  ++count_ok;
	  std::cout << "[OK] \"" << test.name << "\" passed."
		    << std::endl;
	} catch ( failure& caught ) {
	  ok = false;
	  ++count_fail;
	  std::cout << "[FAIL] \"" << test.name << "\" failed."
		    << std::endl;
	  std::cout << "Failing condition: \"" << caught.expr
		    << "\" at line: " << caught.line << std::endl;
	}
      }
      if ( ok ) {
	std::cout << "[SUITE] " << count_ok << "/" << count << " tests passed."
		  << std::endl;
      } else {
	std::cout << std::endl
		  << "[WARNING] Test failures detected in suite: \"" << name
		  << "\"" << std::endl
		  << "[WARNING] " << count_ok <<"/" << count << " tests passed and "
		  << count_fail << "/" << count << " tests failed."
		  << std::endl;
      }
      return ok;
    }
  };

  //>## `bool toy_test::run_suite(suite const& suite)`
  //>Runs the contents of a `suite`.
  //>Returns `false` if there were any failures.
  //>
  bool run_suite( suite const& suite ) {
    auto result = suite.run();
    std::cout << std::endl;
    return result;
  }

  //>## `bool toy_test::run_suites(std::initializer_list<suite const> const& suites)`
  //>Runs the contents of a set of `suite`s, given as a list-initialized
  //>parameter. Returns `false` if there were any failures in any `suite`.
  //>
  bool run_suites( std::initializer_list<suite const> const& suites ) {
    bool ok = true;
    for ( auto const& a : suites ) {
      ok &= run_suite( std::forward<suite const>( a ) );
    }

    if ( ok ) {
      std::cout << "All tests passed." << std::endl
		<< std::endl;
    } else {
      std::cout << "[WARNING] Test failures detected." << std::endl
		<< " Check the output for details." << std::endl
		<< std::endl;
    }
    return ok;
  }
  // end of namespace toy_test
}

//># `macro ASSERT(condition)`
//>Tests a condition. Fails the `test_case` if the condition is `false`.
//>Also aborts the `test_case` on failure.
//>
#define ASSERT( condition )						\
  void( ( condition ) ? 0						\
	: throw toy_test::failure(					\
				  {"ASSERT(" #condition ")", __LINE__} ) )

//># `macro THROWS(expression, exception)`
//>Tests to ensure that a provided expression causes a particular exception,
//>or one of its subtypes, is thrown. Fails the `test_case` and aborts it if
//>the expected exception is not thrown.
//>
#define THROWS( expression, exception )					\
  try {									\
    ( expression );							\
    throw toy_test::failure(						\
			    {"THROWS(" #expression ", " #exception ")", __LINE__} ); \
  } catch ( exception& ) {						\
  } catch ( ... ) {							\
    throw toy_test::failure(						\
			    {"THROWS(" #expression ", " #exception ")", __LINE__} ); \
  }

#endif // TOY_TEST_HPP_INCLUDED
