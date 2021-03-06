#ifndef TESTFWK_VALIDATION_HPP
#define TESTFWK_VALIDATION_HPP

#include "./testsuite.hpp"

#include <string>
#include <cstdio>

namespace TestFwk::detail
{
	std::string const& format(std::string const& str)
	{
		return str;
	}

	std::string const& format(std::string const&&) = delete;

	template<class T>
	std::string format(T const& value)
	{
		using std::to_string;
		return to_string(value);
	}
}

#define TESTFWK_STRINGIFY(x) #x
#define TESTFWK_TOSTRING(x) TESTFWK_STRINGIFY(x)

#define CHECK_OP(a, op, b, type) \
	if(!((a) op (b))) \
	{ \
		fprintf(stderr, "%s%s%s%s\n", \
			__FILE__ ":" TESTFWK_TOSTRING(__LINE__) ": error: " type " " #a " " #op " " #b ", but " #a " == ", \
			TestFwk::detail::format(a).c_str(), \
			", and " #b " == ", TestFwk::detail::format(b).c_str()); \
		TestFwk::currentTestcase->testcaseFailed(); \
	}

#define EXPECT_OP(a, op, b) CHECK_OP(a, op, b, "Expected")

#define EXPECT_EQ(a, b) EXPECT_OP(a, ==, b)
#define EXPECT_LT(a, b) EXPECT_OP(a, <, b)
#define EXPECT_GT(a, b) EXPECT_OP(a, >, b)
#define EXPECT_NE(a, b) EXPECT_OP(a, !=, b)
#define EXPECT_GE(a, b) EXPECT_OP(a, >=, b)
#define EXPECT_LE(a, b) EXPECT_OP(a, <=, b)

#define REQUIRE_OP(a, op, b) \
	CHECK_OP(a, op, b, "Required") \
	if(!((a) op (b))) \
	{ \
		throw std::runtime_error{"Requirement not satisfied. Testcase aborted."}; \
	}

#define REQUIRE_EQ(a, b) REQUIRE_OP(a, ==, b)
#define REQUIRE_LT(a, b) REQUIRE_OP(a, <, b)
#define REQUIRE_GT(a, b) REQUIRE_OP(a, >, b)
#define REQUIRE_NE(a, b) REQUIRE_OP(a, !=, b)
#define REQUIRE_GE(a, b) REQUIRE_OP(a, >=, b)
#define REQUIRE_LE(a, b) REQUIRE_OP(a, <=, b)

#endif