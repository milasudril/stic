//@	{
//@	"targets":
//@		[{
//@		"name":"test",
//@		"type":"application",
//@		"autorun":1,
//@		"cxxoptions_local":
//@			{
//@			"autorun_launcher":
//@				{"name":"valgrind","args":["{target}"]}
//@			}
//@		}]
//@	}

#include "stic.hpp" //Or add the directory to your stic submodule, ie "stic/stic.hpp" (works due to -iquote.)

STIC_TESTCASE_SHOULD_FAIL("Broken assert")
	{
	STIC_ASSERT(1==2);
	}

STIC_TESTCASE("Working assert")
	{
	STIC_ASSERT(0==0);
	}

STIC_TESTCASE_SHOULD_FAIL("Broken throw")
	{
	STIC_ASSERT_THROW(fputs("No exception\n",stderr););
	}

STIC_TESTCASE("Working throw")
	{
	STIC_ASSERT_THROW(
		fputs("This is not going to work...\n",stderr);
		throw "This is an exception";
		);
	}

STIC_TESTCASE_SHOULD_FAIL("Broken nothrow")
	{
	STIC_ASSERT_NOTHROW(
		fputs("This is not going to work...\n",stderr);
		throw "This is an exception";
		);
	}

STIC_TESTCASE("Working nothrow")
	{
	STIC_ASSERT_NOTHROW(fputs("No exeption\n",stderr););
	}

STIC_TESTCASE_SHOULD_FAIL("I am dead")
	{
	throw "Uncaught exception";
	}
