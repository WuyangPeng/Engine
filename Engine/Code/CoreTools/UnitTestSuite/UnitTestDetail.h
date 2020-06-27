// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 09:57)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DETAIL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DETAIL_H

#include "UnitTest.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/TypeTraits.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

#include <sstream>
#include <exception>
#include <type_traits>

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(boost::has_equal_to<LhsType, RhsType, bool>::value, "LhsType and RhsType has equal to bool.");

	const auto condition = (lhs == rhs);

	std::string described{};

	if (!condition)
	{
		std::stringstream stream{};

		stream << lhs << "������" << rhs;

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertEnumEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	AssertEqual(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow); 
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertEqualDoNotUseMessage(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(boost::has_equal_to<LhsType, RhsType, bool>::value, "LhsType and RhsType has equal to bool.");

	const auto condition = (lhs == rhs);
	AssertTest(condition, functionDescribed, "", failureThrow);
}

// protected
template <typename LhsType, typename MhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertEqual(const LhsType& lhs, const MhsType& mhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(boost::has_equal_to<LhsType, RhsType, bool>::value, "LhsType and MhsType has equal to bool.");
	static_assert(boost::has_equal_to<LhsType, RhsType, bool>::value, "MhsType and RhsType has equal to bool.");

	auto lhsCondition = (lhs == mhs);
	auto rhsCondition = (mhs == rhs);
	auto condition = lhsCondition && rhsCondition;

	std::string described{};

	if (!condition)
	{
		std::stringstream stream{};

		if (!(lhsCondition || rhsCondition))
			stream << lhs << "��" << mhs << "��" << rhs << "�����";
		else if (!lhsCondition)
			stream << lhs << "������" << mhs;
		else
			stream << mhs << "������" << rhs;

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertUnequal(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(boost::has_not_equal_to<LhsType, RhsType, bool>::value, "LhsType and RhsType has not equal to bool.");

	const auto condition = (lhs != rhs);

	std::string described{};

	if (!condition)
	{
		std::stringstream stream{};

		stream << lhs << "����" << rhs;

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertEnumUnequal(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	AssertUnequal(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow); 
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertUnequalDoNotUseMessage(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(boost::has_not_equal_to<LhsType, RhsType, bool>::value, "LhsType and RhsType has not equal to bool.");

	auto condition = (lhs != rhs);
	AssertTest(condition, functionDescribed, "", failureThrow);
}

// protected
template<typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertApproximate(const LhsType& lhs, const RhsType& rhs, const std::common_type_t<LhsType, RhsType>& epsilon, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(boost::has_minus<LhsType, RhsType>::value, "LhsType RhsType has minus.");

	using EpsilonType = std::common_type_t<LhsType, RhsType>;

	static_assert(boost::has_less_equal<EpsilonType, double, bool>::value, "EpsilonType and double has less equal bool.");

	const EpsilonType difference{ abs(lhs - rhs) };
	const auto condition = (difference <= epsilon);

	std::string described{};

	if (!condition)
	{
		std::stringstream stream;

		stream << lhs << "��" << rhs << "֮��Ĳ�ֵΪ" << difference << "������" << epsilon;

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

template <typename Function, typename LhsType, typename RhsType, typename EpsilonType>
void CoreTools::UnitTest
	::AssertApproximateUseFunction(Function function, const LhsType& lhs, const RhsType& rhs, const EpsilonType& epsilon, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	const auto condition = function(lhs, rhs, epsilon);

	std::string described{};

	if (!condition)
	{
		std::stringstream stream{};

		stream << lhs << "��" << rhs << "֮��Ĳ�ֵ����" << epsilon;

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

// protected
template <typename PtrType>
void CoreTools::UnitTest
	::AssertEqualNullPtr(const PtrType& ptr, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	// Ϊ��֧������ָ�룬��ʹ��
	// static_assert(std::is_pointer_v<PtrType>, "PtrType is pointer.");

	const auto condition = (ptr == nullptr);

	std::string described{};

	if (!condition)
	{
		std::stringstream stream;

		stream << ptr << "���ǿ�ָ��";

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

// protected
template <typename PtrType>
void CoreTools::UnitTest
	::AssertUnequalNullPtr(const PtrType& ptr, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	// Ϊ��֧������ָ�룬��ʹ��
	// static_assert(std::is_pointer_v<PtrType>, "PtrType is pointer.");

	const auto condition = ptr != nullptr;

	std::string described{};

	if (!condition)
	{
		std::stringstream stream{};

		stream << ptr << "�ǿ�ָ��";

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

// protected
template <typename TestType, typename RangeType>
void CoreTools::UnitTest
	::AssertRange(const TestType& test, const RangeType& lhs, const RangeType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	static_assert(boost::has_less_equal<RangeType, TestType, bool>::value, "RangeType and TestType has less equal bool.");
	static_assert(boost::has_less_equal<TestType, RangeType, bool>::value, "TestType and RangeType has less equal bool.");

	const auto condition = (lhs <= test && test <= rhs);

	std::string described{};

	if (!condition)
	{
		std::stringstream stream{};

		stream << test << "����" << lhs << "��" << rhs << "֮��";

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertLess(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	static_assert(boost::has_less<LhsType, RhsType, bool>::value, "RangeType and TestType has less equal bool.");

	const auto condition = (lhs < rhs);

	std::string described{};

	if (!condition)
	{
		std::stringstream stream{};

		stream << lhs << "��С��" << rhs;

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertEnumLess(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	AssertLess(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow); 
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertLessEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	static_assert(boost::has_less_equal<LhsType, RhsType, bool>::value, "RangeType and TestType has less equal bool.");

	const auto condition = (lhs <= rhs);

	std::string described{};

	if (!condition)
	{
		std::stringstream stream{};

		stream << lhs << "��С�ڻ����" << rhs;

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertEnumLessEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	AssertLessEqual(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertGreater(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	static_assert(boost::has_greater<LhsType, RhsType, bool>::value, "RangeType and TestType has less equal bool.");

	auto condition = lhs > rhs;

	std::string described{};

	if (!condition)
	{
		std::stringstream stream{};

		stream << lhs << "������" << rhs;

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertEnumGreater(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	AssertGreater(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertGreaterEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	static_assert(boost::has_greater_equal<LhsType, RhsType, bool>::value, "RangeType and TestType has less equal bool.");

	const auto condition = lhs >= rhs;

	std::string described{};

	if (!condition)
	{
		std::stringstream stream{};

		stream << lhs << "�����ڻ����" << rhs;

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

template<typename LhsType, typename RhsType>
void CoreTools::UnitTest
	::AssertEnumGreaterEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	AssertGreaterEqual(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

// protected
template <typename TestClass, typename Function>
void CoreTools::UnitTest
	::AssertNotThrowException(TestClass* test, Function function, const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(std::is_member_function_pointer_v<Function>, "Function is member function pointer.");
	static_assert(std::is_base_of_v<UnitTest, TestClass>, "UnitTest is base of TestClass.");

	try
	{
		(test->*function)();

		ErrorTest(true, functionDescribed, GetCorrectNothrowExceptionDescribe());
	}
	catch (const CoreTools::Error& error)
	{
		AssertExceptionErrorLog(error, errorMessage);
	}
	catch (const std::exception& error)
	{
		AssertExceptionFatalLog(error, functionDescribed, errorMessage);
	}
	catch (...)
	{
		AssertExceptionFatalLog(functionDescribed, errorMessage);
	}
}

// protected
template <typename TestClass, typename Function, typename Parameter>
void CoreTools::UnitTest
	::AssertNotThrowException(TestClass* test, Function function, const Parameter& parameter, const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(std::is_member_function_pointer_v<Function>, "Function is member function pointer.");
	static_assert(std::is_base_of_v<UnitTest, TestClass>, "UnitTest is base of TestClass.");

	try
	{
		(test->*function)(parameter);

		ErrorTest(true, functionDescribed, GetCorrectNothrowExceptionDescribe());
	}
	catch (const CoreTools::Error& error)
	{
		AssertExceptionErrorLog(error, errorMessage);
	}
	catch (const std::exception& error)
	{
		AssertExceptionFatalLog(error, functionDescribed, errorMessage);
	}
	catch (...)
	{
		AssertExceptionFatalLog(functionDescribed, errorMessage);
	}
}

// protected
template <typename TestClass, typename Function, typename FirstParameter, typename SecondParameter>
void CoreTools::UnitTest
	::AssertNotThrowException(TestClass* test, Function function, const FirstParameter& firstParameter, const SecondParameter& secondParameter, const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(std::is_member_function_pointer_v<Function>, "Function is member function pointer.");
	static_assert(std::is_base_of_v<UnitTest, TestClass>, "UnitTest is base of TestClass.");

	try
	{
		(test->*function)(firstParameter, secondParameter);

		ErrorTest(true, functionDescribed, GetCorrectNothrowExceptionDescribe());
	}
	catch (const CoreTools::Error& error)
	{
		AssertExceptionErrorLog(error, errorMessage);
	}
	catch (const std::exception& error)
	{
		AssertExceptionFatalLog(error, functionDescribed, errorMessage);
	}
	catch (...)
	{
		AssertExceptionFatalLog(functionDescribed, errorMessage);
	}
}

// protected
template <typename TestClass, typename Function>
void CoreTools::UnitTest
	::AssertThrowException(TestClass* test, Function function, const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(std::is_member_function_pointer_v<Function>, "Function is member function pointer.");
	static_assert(std::is_base_of_v<UnitTest, TestClass>, "UnitTest is base of TestClass.");

	try
	{
		(test->*function)();

		AssertExceptionErrorLog(functionDescribed, errorMessage);
	}
	catch (const CoreTools::Error& error)
	{
		AssertExceptionInfoLog(error, errorMessage);
	}
	catch (const std::exception& error)
	{
		AssertExceptionInfoLog(error, functionDescribed, errorMessage);
	}
	catch (...)
	{
		AssertExceptionInfoLog(functionDescribed, errorMessage);
	}
}

// protected
template <typename TestClass, typename Function, typename Parameter>
void CoreTools::UnitTest
	::AssertThrowException(TestClass* test, Function function, const Parameter& parameter, const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(std::is_member_function_pointer_v<Function>, "Function is member function pointer.");
	static_assert(std::is_base_of_v<UnitTest, TestClass>, "UnitTest is base of TestClass.");

	try
	{
		(test->*function)(parameter);

		AssertExceptionErrorLog(functionDescribed, errorMessage);
	}
	catch (const CoreTools::Error& error)
	{
		AssertExceptionInfoLog(error, errorMessage);
	}
	catch (const std::exception& error)
	{
		AssertExceptionInfoLog(error, functionDescribed, errorMessage);
	}
	catch (...)
	{
		AssertExceptionInfoLog(functionDescribed, errorMessage);
	}
}

// protected
template <typename TestClass, typename Function, typename FirstParameter, typename SecondParameter>
void CoreTools::UnitTest
	::AssertThrowException(TestClass* test, Function function, const FirstParameter& firstParameter, const SecondParameter& secondParameter, const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(std::is_member_function_pointer_v<Function>, "Function is member function pointer.");
	static_assert(std::is_base_of_v<UnitTest, TestClass>, "UnitTest is base of TestClass.");

	try
	{
		(test->*function)(firstParameter, secondParameter);

		AssertExceptionErrorLog(functionDescribed, errorMessage);
	}
	catch (const CoreTools::Error& error)
	{
		AssertExceptionInfoLog(error, errorMessage);
	}
	catch (const std::exception& error)
	{
		AssertExceptionInfoLog(error, functionDescribed, errorMessage);
	}
	catch (...)
	{
		AssertExceptionInfoLog(functionDescribed, errorMessage);
	}
}

template <typename TestClass, typename Function>
void CoreTools::UnitTest
	::ExecuteLoopTesting(TestClass* test, Function function)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	static_assert(std::is_member_function_pointer_v<Function>, "Function is member function pointer.");
	static_assert(std::is_base_of_v<UnitTest, TestClass>, "UnitTest is base of TestClass.");

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		if (!(test->*function)())
		{
			break;
		}
	}
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DETAIL_H
