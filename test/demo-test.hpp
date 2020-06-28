//># `namespace demo_test_internal`
//>Just a `namespace` to wrap the test `suite` and any
//>necessary types and variables so they don't pollute the global `namespace`.
//>
namespace demo_test_internal
{
  //>## `toy_test::suite demo_test_internal::demo_suite`
  //>This is the test `suite`. It has one `test_case` that passes,
  //>and one that fails.
  //>
  auto demo_suite = toy_test::suite 
    {
     "demonstration test suite",
     {
      {"passes",
       [] {
	 ASSERT(true);
       }},

      {"fails",
       [] {
	 ASSERT(false);
       }},


     }};
}

//># `toy_test::suite demo_suite`
//>This is a variable alias to make the test `suite` available
//>in the global `namespace`. The idea is that if you have
//>`using` statements, `typedef`s,  and variables inside the
//>`suite`'s `namespace`, they don't pollute the global `namespace`.
//>However, we can still address the `suite` itself using a global variable.
//>
using demo_test_internal::demo_suite;
