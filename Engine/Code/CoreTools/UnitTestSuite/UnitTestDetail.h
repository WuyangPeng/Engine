/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 11:14)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DETAIL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DETAIL_H

#include "UnitTest.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

#include <exception>
#include <sstream>
#include <type_traits>

template <typename LhsType, typename RhsType>
requires(!(std::is_same_v<std::remove_all_extents_t<LhsType>, char> && std::is_same_v<std::remove_all_extents_t<RhsType>, char>) &&
         !(std::is_same_v<std::remove_all_extents_t<LhsType>, wchar_t> && std::is_same_v<std::remove_all_extents_t<RhsType>, wchar_t>) &&
         !(std::is_constructible_v<std::string, LhsType> && std::is_constructible_v<std::string, RhsType>) &&
         !(std::is_constructible_v<std::wstring, LhsType> && std::is_constructible_v<std::wstring, RhsType>) &&
         boost::has_equal_to<LhsType, RhsType, bool>::value &&
         !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
void CoreTools::UnitTest::AssertEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    if (const auto condition = (lhs == rhs);
        condition)
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

template <typename LhsType, typename RhsType>
requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
void CoreTools::UnitTest::AssertEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertEqual(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

template <typename LhsType, typename MhsType, typename RhsType>
requires(boost::has_equal_to<LhsType, MhsType, bool>::value && boost::has_equal_to<RhsType, MhsType, bool>::value)
void CoreTools::UnitTest::AssertEqual(const LhsType& lhs, const MhsType& mhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    const auto lhsCondition = (lhs == mhs);
    const auto rhsCondition = (rhs == mhs);

    if (const auto condition = lhsCondition && rhsCondition;
        condition)
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

template <typename LhsType, typename RhsType>
requires(boost::has_not_equal_to<LhsType, RhsType, bool>::value &&
         !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
void CoreTools::UnitTest::AssertUnequal(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    if (const auto condition = (lhs != rhs);
        condition)
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

template <typename LhsType, typename RhsType>
requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
void CoreTools::UnitTest::AssertUnequal(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertUnequal(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

template <typename LhsType, typename RhsType>
requires(boost::has_minus<LhsType, RhsType>::value && boost::has_less_equal<std::common_type_t<LhsType, RhsType>, double, bool>::value)
void CoreTools::UnitTest::AssertApproximate(const LhsType& lhs, const RhsType& rhs, const std::common_type_t<LhsType, RhsType>& epsilon, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    using EpsilonType = std::common_type_t<LhsType, RhsType>;

    const EpsilonType difference{ abs(lhs - rhs) };

    if (const auto condition = (difference <= epsilon);
        condition)
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

template <typename Function, typename LhsType, typename RhsType, typename EpsilonType>
void CoreTools::UnitTest::AssertApproximateUseFunction(Function function, const LhsType& lhs, const RhsType& rhs, const EpsilonType& epsilon, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    if (const auto condition = function(lhs, rhs, epsilon);
        condition)
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

template <typename PtrType>
void CoreTools::UnitTest::AssertEqualNullPtr(const PtrType& ptr, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    /// Ϊ��֧������ָ�룬��ʹ��
    /// static_assert(std::is_pointer_v<PtrType>, "PtrType is pointer.");

    if (const auto condition = (ptr == nullptr);
        condition)
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

template <typename PtrType>
void CoreTools::UnitTest::AssertUnequalNullPtr(const PtrType& ptr, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    /// Ϊ��֧������ָ�룬��ʹ��
    /// static_assert(std::is_pointer_v<PtrType>, "PtrType is pointer.");

    if (const auto condition = (ptr != nullptr);
        condition)
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

template <typename TestType, typename RangeType>
requires(boost::has_less_equal<RangeType, TestType, bool>::value && boost::has_less_equal<TestType, RangeType, bool>::value)
void CoreTools::UnitTest::AssertRange(const TestType& test, const RangeType& lhs, const RangeType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    if (const auto condition = (lhs <= test && test <= rhs);
        condition)
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

template <typename LhsType, typename RhsType>
requires(boost::has_less<LhsType, RhsType, bool>::value &&
         !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
void CoreTools::UnitTest::AssertLess(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    if (const auto condition = (lhs < rhs);
        condition)
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

template <typename LhsType, typename RhsType>
requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
void CoreTools::UnitTest::AssertLess(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertLess(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

template <typename LhsType, typename RhsType>
requires(boost::has_less_equal<LhsType, RhsType, bool>::value &&
         !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
void CoreTools::UnitTest::AssertLessEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    if (const auto condition = (lhs <= rhs);
        condition)
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

template <typename LhsType, typename RhsType>
requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
void CoreTools::UnitTest::AssertLessEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertLessEqual(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

template <typename LhsType, typename RhsType>
requires(boost::has_greater<LhsType, RhsType, bool>::value &&
         !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
void CoreTools::UnitTest::AssertGreater(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    if (const auto condition = lhs > rhs;
        condition)
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

template <typename LhsType, typename RhsType>
requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
void CoreTools::UnitTest::AssertGreater(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertGreater(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

template <typename LhsType, typename RhsType>
requires(boost::has_greater_equal<LhsType, RhsType, bool>::value &&
         !(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>))
void CoreTools::UnitTest::AssertGreaterEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    if (const auto condition = lhs >= rhs;
        condition)
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
requires(std::is_enum_v<LhsType> && std::is_enum_v<RhsType>)
void CoreTools::UnitTest::AssertGreaterEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertGreaterEqual(System::EnumCastUnderlying(lhs), System::EnumCastUnderlying(rhs), functionDescribed, errorMessage, failureThrow);
}

template <typename LhsType, typename RhsType>
requires((std::is_same_v<std::remove_all_extents_t<LhsType>, wchar_t> && std::is_same_v<std::remove_all_extents_t<RhsType>, wchar_t>) ||
         (std::is_constructible_v<std::wstring, LhsType> && std::is_constructible_v<std::wstring, RhsType>))
void CoreTools::UnitTest::AssertEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    const std::wstring lhsValue{ lhs };
    const std::wstring rhsValue{ rhs };

    if (const auto condition = (lhsValue == rhsValue);
        condition)
    {
        AssertTrue();
    }
    else
    {
        std::stringstream stream{};

        stream << StringConversion::WideCharConversionMultiByte(lhsValue) << "������" << StringConversion::WideCharConversionMultiByte(rhsValue);

        const auto described = GetAssertDescribed(stream.str(), errorMessage);

        AssertTest(condition, functionDescribed, described, failureThrow);
    }
}

template <typename LhsType, typename RhsType>
requires((std::is_same_v<std::remove_all_extents_t<LhsType>, char> && std::is_same_v<std::remove_all_extents_t<RhsType>, char>) ||
         (std::is_constructible_v<std::string, LhsType> && std::is_constructible_v<std::string, RhsType>))
void CoreTools::UnitTest::AssertEqual(const LhsType& lhs, const RhsType& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    const std::string lhsValue{ lhs };
    const std::string rhsValue{ rhs };

    if (const auto condition = (lhsValue == rhsValue);
        condition)
    {
        AssertTrue();
    }
    else
    {
        std::stringstream stream{};

        stream << lhsValue << "������" << rhsValue;

        const auto described = GetAssertDescribed(stream.str(), errorMessage);

        AssertTest(condition, functionDescribed, described, failureThrow);
    }
}

template <typename TestClass, typename Function, typename... Types>
requires(std::is_member_function_pointer_v<Function> && std::is_base_of_v<CoreTools::UnitTest, TestClass>)
void CoreTools::UnitTest::AssertNotThrowException(TestClass* test, Function function, const FunctionDescribed& functionDescribed, const std::string& errorMessage, Types&&... args)
{
    try
    {
        (test->*function)(std::forward<Types>(args)...);

        ErrorTest(true, functionDescribed, GetCorrectNothrowExceptionDescribe());
    }
    catch (const Error& error)
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

template <typename TestClass, typename Function, typename... Types>
requires(std::is_member_function_pointer_v<Function> && std::is_base_of_v<CoreTools::UnitTest, TestClass>)
void CoreTools::UnitTest::AssertThrowException(TestClass* test, Function function, const FunctionDescribed& functionDescribed, const std::string& errorMessage, Types&&... args)
{
    try
    {
        (test->*function)(std::forward<Types>(args)...);

        AssertExceptionErrorLog(functionDescribed, errorMessage);
    }
    catch (const Error& error)
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
requires(std::is_member_function_pointer_v<Function> && std::is_base_of_v<CoreTools::UnitTest, TestClass>)
void CoreTools::UnitTest::ExecuteLoopTesting(TestClass* test, Function function)
{
    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        if (!(test->*function)())
        {
            GetStream() << "Function Execute Loop End.\n";

            break;
        }
    }
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_DETAIL_H
