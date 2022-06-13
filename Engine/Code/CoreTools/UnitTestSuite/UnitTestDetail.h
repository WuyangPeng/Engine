///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/14 14:59)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DETAIL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DETAIL_H

#include "UnitTest.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/TypeTraits.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

#include <exception>
#include <sstream>
#include <type_traits>

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    static_assert(boost::has_equal_to<LhsType, RhsType, bool>::value, "LhsType and RhsType has equal to bool.");

    const auto condition = (lhs == rhs);

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        if constexpr (std::is_arithmetic_v<LhsType> && std::is_arithmetic_v<RhsType>)
        {
            std::stringstream stream{};

            stream << lhs << "������" << rhs;

            const auto described = GetAssertDescribed(stream.str(), errorMessage);

            AssertTest(condition, functionDescribed, described, failureThrow);
        }
        else
        {
            AssertTest(condition, functionDescribed, errorMessage, failureThrow);
        }
    }
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertEnumEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertEqual(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

// protected
template <typename LhsType, typename MhsType, typename RhsType>
void CoreTools::UnitTest::AssertEqual(const LhsType& lhs, const MhsType& mhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    static_assert(boost::has_equal_to<LhsType, MhsType, bool>::value, "LhsType and MhsType has equal to bool.");
    static_assert(boost::has_equal_to<RhsType, MhsType, bool>::value, "RhsType and MhsType has equal to bool.");

    const auto lhsCondition = (lhs == mhs);
    const auto rhsCondition = (rhs == mhs);
    const auto condition = lhsCondition && rhsCondition;

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        if constexpr (std::is_arithmetic_v<LhsType> && std::is_arithmetic_v<MhsType> && std::is_arithmetic_v<RhsType>)
        {
            std::stringstream stream{};

            if (!(lhsCondition || rhsCondition))
                stream << lhs << "��" << mhs << "��" << rhs << "�����";
            else if (!lhsCondition)
                stream << lhs << "������" << mhs;
            else
                stream << mhs << "������" << rhs;

            const auto described = GetAssertDescribed(stream.str(), errorMessage);

            AssertTest(condition, functionDescribed, described, failureThrow);
        }
        else
        {
            AssertTest(condition, functionDescribed, errorMessage, failureThrow);
        }
    }
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertUnequal(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    static_assert(boost::has_not_equal_to<LhsType, RhsType, bool>::value, "LhsType and RhsType has not equal to bool.");

    const auto condition = (lhs != rhs);

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        if constexpr (std::is_arithmetic_v<LhsType> && std::is_arithmetic_v<RhsType>)
        {
            std::stringstream stream{};

            stream << lhs << "����" << rhs;

            const auto described = GetAssertDescribed(stream.str(), errorMessage);

            AssertTest(condition, functionDescribed, described, failureThrow);
        }
        else
        {
            AssertTest(condition, functionDescribed, errorMessage, failureThrow);
        }
    }
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertEnumUnequal(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertUnequal(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertApproximate(const LhsType& lhs, const RhsType& rhs, const std::common_type_t<LhsType, RhsType>& epsilon, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    static_assert(boost::has_minus<LhsType, RhsType>::value, "LhsType RhsType has minus.");

    using EpsilonType = std::common_type_t<LhsType, RhsType>;

    static_assert(boost::has_less_equal<EpsilonType, double, bool>::value, "EpsilonType and double has less equal bool.");

    const EpsilonType difference{ abs(lhs - rhs) };
    const auto condition = (difference <= epsilon);

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        if constexpr (std::is_arithmetic_v<LhsType> && std::is_arithmetic_v<RhsType>)
        {
            std::stringstream stream{};

            stream << lhs << "��" << rhs << "֮��Ĳ�ֵΪ" << difference << "������" << epsilon;

            const auto described = GetAssertDescribed(stream.str(), errorMessage);

            AssertTest(condition, functionDescribed, described, failureThrow);
        }
        else
        {
            AssertTest(condition, functionDescribed, errorMessage, failureThrow);
        }
    }
}

// protected
template <typename Function, typename LhsType, typename RhsType, typename EpsilonType>
void CoreTools::UnitTest::AssertApproximateUseFunction(Function function, const LhsType& lhs, const RhsType& rhs, const EpsilonType& epsilon, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    const auto condition = function(lhs, rhs, epsilon);

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        if constexpr (std::is_arithmetic_v<LhsType> && std::is_arithmetic_v<RhsType>)
        {
            std::stringstream stream{};

            stream << lhs << "��" << rhs << "֮��Ĳ�ֵ����" << epsilon;

            const auto described = GetAssertDescribed(stream.str(), errorMessage);

            AssertTest(condition, functionDescribed, described, failureThrow);
        }
        else
        {
            AssertTest(condition, functionDescribed, errorMessage, failureThrow);
        }
    }
}

// protected
template <typename PtrType>
void CoreTools::UnitTest::AssertEqualNullPtr(const PtrType& ptr, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    // Ϊ��֧������ָ�룬��ʹ��
    // static_assert(std::is_pointer_v<PtrType>, "PtrType is pointer.");

    const auto condition = (ptr == nullptr);

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        std::stringstream stream{};

        stream << "ptr���ǿ�ָ��";

        const auto described = GetAssertDescribed(stream.str(), errorMessage);

        AssertTest(condition, functionDescribed, described, failureThrow);
    }
}

// protected
template <typename PtrType>
void CoreTools::UnitTest::AssertUnequalNullPtr(const PtrType& ptr, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    // Ϊ��֧������ָ�룬��ʹ��
    // static_assert(std::is_pointer_v<PtrType>, "PtrType is pointer.");

    const auto condition = ptr != nullptr;

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        std::stringstream stream{};

        stream << "ptr�ǿ�ָ��";

        const auto described = GetAssertDescribed(stream.str(), errorMessage);

        AssertTest(condition, functionDescribed, described, failureThrow);
    }
}

// protected
template <typename TestType, typename RangeType>
void CoreTools::UnitTest::AssertRange(const TestType& test, const RangeType& lhs, const RangeType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    static_assert(boost::has_less_equal<RangeType, TestType, bool>::value, "RangeType and TestType has less equal bool.");
    static_assert(boost::has_less_equal<TestType, RangeType, bool>::value, "TestType and RangeType has less equal bool.");

    const auto condition = (lhs <= test && test <= rhs);

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        if constexpr (std::is_arithmetic_v<TestType> && std::is_arithmetic_v<RangeType>)
        {
            std::stringstream stream{};

            stream << test << "����" << lhs << "��" << rhs << "֮��";

            const auto described = GetAssertDescribed(stream.str(), errorMessage);

            AssertTest(condition, functionDescribed, described, failureThrow);
        }
        else
        {
            AssertTest(condition, functionDescribed, errorMessage, failureThrow);
        }
    }
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertLess(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    static_assert(boost::has_less<LhsType, RhsType, bool>::value, "RangeType and TestType has less equal bool.");

    const auto condition = (lhs < rhs);

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        if constexpr (std::is_arithmetic_v<LhsType> && std::is_arithmetic_v<RhsType>)
        {
            std::stringstream stream{};

            stream << lhs << "��С��" << rhs;

            const auto described = GetAssertDescribed(stream.str(), errorMessage);

            AssertTest(condition, functionDescribed, described, failureThrow);
        }
        else
        {
            AssertTest(condition, functionDescribed, errorMessage, failureThrow);
        }
    }
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertEnumLess(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertLess(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertLessEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    static_assert(boost::has_less_equal<LhsType, RhsType, bool>::value, "RangeType and TestType has less equal bool.");

    const auto condition = (lhs <= rhs);

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        if constexpr (std::is_arithmetic_v<LhsType> && std::is_arithmetic_v<RhsType>)
        {
            std::stringstream stream{};

            stream << lhs << "��С�ڻ����" << rhs;

            const auto described = GetAssertDescribed(stream.str(), errorMessage);

            AssertTest(condition, functionDescribed, described, failureThrow);
        }
        else
        {
            AssertTest(condition, functionDescribed, errorMessage, failureThrow);
        }
    }
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertEnumLessEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertLessEqual(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertGreater(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    static_assert(boost::has_greater<LhsType, RhsType, bool>::value, "RangeType and TestType has less equal bool.");

    const auto condition = lhs > rhs;

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        if constexpr (std::is_arithmetic_v<LhsType> && std::is_arithmetic_v<RhsType>)
        {
            std::stringstream stream{};

            stream << lhs << "������" << rhs;

            const auto described = GetAssertDescribed(stream.str(), errorMessage);

            AssertTest(condition, functionDescribed, described, failureThrow);
        }
        else
        {
            AssertTest(condition, functionDescribed, errorMessage, failureThrow);
        }
    }
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertEnumGreater(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertGreater(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

// protected
template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertGreaterEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    static_assert(boost::has_greater_equal<LhsType, RhsType, bool>::value, "RangeType and TestType has less equal bool.");

    const auto condition = lhs >= rhs;

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        if constexpr (std::is_arithmetic_v<LhsType> && std::is_arithmetic_v<RhsType>)
        {
            std::stringstream stream{};

            stream << lhs << "�����ڻ����" << rhs;

            const auto described = GetAssertDescribed(stream.str(), errorMessage);

            AssertTest(condition, functionDescribed, described, failureThrow);
        }
        else
        {
            AssertTest(condition, functionDescribed, errorMessage, failureThrow);
        }
    }
}

template <typename LhsType, typename RhsType>
void CoreTools::UnitTest::AssertEnumGreaterEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertGreaterEqual(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

template <typename TestClass, typename Function, typename... Types>
void CoreTools::UnitTest::AssertNotThrowException(TestClass* test, Function function, const FunctionDescribed& functionDescribed, const std::string& errorMessage, Types&&... args)
{
    static_assert(std::is_member_function_pointer_v<Function>, "Function is member function pointer.");
    static_assert(std::is_base_of_v<UnitTest, TestClass>, "UnitTest is base of TestClass.");

    try
    {
        (test->*function)(std::forward<Types>(args)...);

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
template <typename TestClass, typename Function, typename... Types>
void CoreTools::UnitTest::AssertThrowException(TestClass* test, Function function, const FunctionDescribed& functionDescribed, const std::string& errorMessage, Types&&... args)
{
    static_assert(std::is_member_function_pointer_v<Function>, "Function is member function pointer.");
    static_assert(std::is_base_of_v<UnitTest, TestClass>, "UnitTest is base of TestClass.");

    try
    {
        (test->*function)(std::forward<Types>(args)...);

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
void CoreTools::UnitTest::ExecuteLoopTesting(TestClass* test, Function function)
{
    static_assert(std::is_member_function_pointer_v<Function>, "Function is member function pointer.");
    static_assert(std::is_base_of_v<UnitTest, TestClass>, "UnitTest is base of TestClass.");

    const auto testLoopCount = GetTestLoopCount();
    for (auto i = 0; i < testLoopCount; ++i)
    {
        if (!(test->*function)())
        {
            GetStream() << "Function Execute Loop End.\n";

            break;
        }
    }
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DETAIL_H
