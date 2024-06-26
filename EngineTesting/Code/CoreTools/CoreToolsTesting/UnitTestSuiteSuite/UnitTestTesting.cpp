/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 10:52)

#include "UnitTestTesting.h"
#include "Detail/TestEnum.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::UnitTestTesting::UnitTestTesting(const OStreamShared& stream)
    : ParentType{ stream }, passNumber{ 0 }, failNumber{ 0 }, errorNumber{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::UnitTestTesting::IsValid() const noexcept
{
    return ParentType::IsValid() && 0 <= passNumber && 0 <= failNumber && 0 <= errorNumber;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::UnitTestTesting::PrintTipsMessage()
{
    GetStream() << "这个测试测试单元测试本身，会出现测试失败和测试错误，请按“否”取消。\n";

    System::SystemPause();
}

void CoreTools::UnitTestTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

bool CoreTools::UnitTestTesting::ExecuteLoopTest() noexcept
{
    return true;
}

void CoreTools::UnitTestTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertTestTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertTrueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ErrorTestTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertEqualTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertCellValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertCompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertNotThrowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertThrowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TestResultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PrintReportTest);

    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ExecuteLoopTest);
}

void CoreTools::UnitTestTesting::NameTest()
{
    ASSERT_EQUAL(GetName(), typeid(*this).name());

    /// NameTest包含一个ASSERT_EQUAL成功测试和一个ASSERT_NOT_THROW成功测试。
    passNumber += 2;
}

void CoreTools::UnitTestTesting::StreamTest() noexcept
{
    /// StreamTest包含0个ASSERT成功测试和一个ASSERT_NOT_THROW成功测试。
    passNumber += 1;
}

void CoreTools::UnitTestTesting::AssertTestTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "以下代码测试单元测试未通过的情况。存在一个测试失败！\n";

    ASSERT_TRUE(true);
    ASSERT_TRUE(false);

    GetStream() << "以上代码测试单元测试未通过的情况。\n";

    /// 上面有5个测试。其中4个为成功测试，1个为失败测试。
    passNumber += 4;
    failNumber += 1;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    /// 上面有3个ASSERT_EQUAL成功测试，加上一个ASSERT_NOT_THROW成功测试。
    passNumber += 4;
}

void CoreTools::UnitTestTesting::AssertTrueTest() noexcept
{
    AssertTrue();

    /// AssertTrueTest包含1个ASSERT成功测试。
    passNumber += 2;
}

void CoreTools::UnitTestTesting::ErrorTestTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "以下代码测试单元测试未通过的情况。存在一个测试错误！\n";

    ErrorTest(true, CORE_TOOLS_FUNCTION_DESCRIBED);
    ErrorTest(false, CORE_TOOLS_FUNCTION_DESCRIBED);

    GetStream() << "以上代码测试单元测试未通过的情况。\n";

    /// 上面有5个测试。其中4个为成功测试，1个为错误测试。
    passNumber += 4;
    errorNumber += 1;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    /// 上面有3个ASSERT_EQUAL成功测试，加上一个ASSERT_NOT_THROW成功测试。
    passNumber += 4;
}

void CoreTools::UnitTestTesting::AssertEqualTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "以下代码测试单元测试未通过的情况。存在十五个测试失败！\n";

    int* ptr{ nullptr };

    ASSERT_EQUAL(1, 1);
    ASSERT_EQUAL(1, 2);
    ASSERT_THREE_EQUAL(1, 1, 1);
    ASSERT_THREE_EQUAL(1, 2, 1);
    ASSERT_UNEQUAL(1, 1);
    ASSERT_UNEQUAL(1, 2);
    ASSERT_APPROXIMATE(1.0f, 1.01f, 0.02f);
    ASSERT_APPROXIMATE(1.0f, 1.11f, 0.1f);
    ASSERT_EQUAL_NULL_PTR(ptr);
    ASSERT_EQUAL_NULL_PTR(this);
    ASSERT_UNEQUAL_NULL_PTR(ptr);
    ASSERT_UNEQUAL_NULL_PTR(this);
    ASSERT_EQUAL(TestEnum::Ten, TestEnum::Ten);
    ASSERT_UNEQUAL(TestEnum::Ten, TestEnum::Fifteen);
    constexpr auto value = 1.0f;
    ASSERT_FLOATING_POINT_COMPLETE_EQUAL(value, value);
    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL(value, value + 0.00001f);
    const auto stringValue = SYSTEM_TEXT("value"s);
    ASSERT_EQUAL(stringValue, stringValue);

    ASSERT_EQUAL(1, 1);
    ASSERT_EQUAL(1, 2);
    ASSERT_UNEQUAL(1, 1);
    ASSERT_UNEQUAL(1, 2);

    ASSERT_EQUAL_USE_MESSAGE(1, 1, "测试ASSERT_EQUAL_USE_MESSAGE");
    ASSERT_EQUAL_USE_MESSAGE(1, 2, "测试ASSERT_EQUAL_USE_MESSAGE");
    ASSERT_UNEQUAL_USE_MESSAGE(1, 1, "测试ASSERT_UNEQUAL_USE_MESSAGE");
    ASSERT_UNEQUAL_USE_MESSAGE(1, 2, "测试ASSERT_UNEQUAL_USE_MESSAGE");
    ASSERT_APPROXIMATE_USE_MESSAGE(1.0f, 1.01f, 0.02f, "测试ASSERT_APPROXIMATE_USE_MESSAGE");
    ASSERT_APPROXIMATE_USE_MESSAGE(1.0f, 1.11f, 0.1f, "测试ASSERT_APPROXIMATE_USE_MESSAGE");
    ASSERT_EQUAL_NULL_PTR_USE_MESSAGE(ptr, "测试ASSERT_EQUAL_NULL_PTR_USE_MESSAGE");
    ASSERT_EQUAL_NULL_PTR_USE_MESSAGE(this, "测试ASSERT_EQUAL_NULL_PTR_USE_MESSAGE");
    ASSERT_UNEQUAL_NULL_PTR_USE_MESSAGE(ptr, "测试ASSERT_UNEQUAL_NULL_PTR_USE_MESSAGE");
    ASSERT_UNEQUAL_NULL_PTR_USE_MESSAGE(this, "测试ASSERT_UNEQUAL_NULL_PTR_USE_MESSAGE");
    ASSERT_FLOATING_POINT_COMPLETE_EQUAL_USE_MESSAGE(value, value, "测试ASSERT_FLOATING_POINT_COMPLETE_EQUAL_USE_MESSAGE");
    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_USE_MESSAGE(value, value + 0.00001f, "测试ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_USE_MESSAGE");

    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate, 1.0, 1.01, 0.02);
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate, 1.0, 1.11, 0.1);

    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(Approximate, 1.0, 1.01, 0.02, "测试ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE");
    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(Approximate, 1.0, 1.11, 0.1, "测试ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE");

    GetStream() << "以上代码测试单元测试未通过的情况。\n";

    /// 上面有40个测试。其中25个为成功测试，15个为失败测试。
    passNumber += 25;
    failNumber += 15;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    /// 上面有3个ASSERT_EQUAL成功测试，加上一个ASSERT_NOT_THROW成功测试。
    passNumber += 4;
}

void CoreTools::UnitTestTesting::AssertStringTest()
{
    ASSERT_EQUAL("1", "1");
    ASSERT_EQUAL("1", "1"s);
    ASSERT_EQUAL("1"s, "1"s);
    ASSERT_EQUAL("1"s, "1");

    ASSERT_EQUAL(L"1", L"1");
    ASSERT_EQUAL(L"1", L"1"s);
    ASSERT_EQUAL(L"1"s, L"1"s);
    ASSERT_EQUAL(L"1"s, L"1");

    ASSERT_EQUAL('1', '1');
    ASSERT_EQUAL(L'1', L'1');

    /// 上面有10个ASSERT_EQUAL成功测试。
    passNumber += 11;
}

void CoreTools::UnitTestTesting::AssertCellValueTest()
{
    ASSERT_EQUAL(SimpleCSV::CellValue{ 7 }, SimpleCSV::CellValue{ 7 });

    /// 上面有1个ASSERT_EQUAL成功测试。
    passNumber += 2;
}

void CoreTools::UnitTestTesting::AssertCompareTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "以下代码测试单元测试未通过的情况。存在十个测试失败！\n";

    ASSERT_LESS(1, 1);
    ASSERT_LESS(2, 4);
    ASSERT_LESS_EQUAL(1, 1);
    ASSERT_LESS_EQUAL(7, 2);
    ASSERT_RANGE(1, 1, 3);
    ASSERT_RANGE(1, 2, 2);
    ASSERT_GREATER(1.0f, 1.01f);
    ASSERT_GREATER(1.12f, 1.11f);
    ASSERT_GREATER_EQUAL(7, 7);
    ASSERT_GREATER_EQUAL(1.0f, 1.11f);

    ASSERT_LESS(TestEnum::Ten, TestEnum::Fifteen);
    ASSERT_LESS_EQUAL(TestEnum::Ten, TestEnum::Ten);
    ASSERT_GREATER(TestEnum::Fifteen, TestEnum::Ten);
    ASSERT_GREATER_EQUAL(TestEnum::Fifteen, TestEnum::Ten);

    ASSERT_LESS_USE_MESSAGE(1, 7, "测试ASSERT_LESS_USE_MESSAGE");
    ASSERT_LESS_USE_MESSAGE(10, 2, "测试ASSERT_LESS_USE_MESSAGE");
    ASSERT_LESS_EQUAL_USE_MESSAGE(1, 11, "测试ASSERT_LESS_EQUAL_USE_MESSAGE");
    ASSERT_LESS_EQUAL_USE_MESSAGE(11, 2, "测试ASSERT_LESS_EQUAL_USE_MESSAGE");
    ASSERT_RANGE_USE_MESSAGE(1.011f, 1.01f, 1.012f, "测试ASSERT_RANGE_USE_MESSAGE");
    ASSERT_RANGE_USE_MESSAGE(1.0f, 1.11f, 0.12f, "测试ASSERT_RANGE_USE_MESSAGE");
    ASSERT_GREATER_USE_MESSAGE(7, 6, "测试ASSERT_GREATER_USE_MESSAGE");
    ASSERT_GREATER_USE_MESSAGE(6, 7, "测试ASSERT_GREATER_USE_MESSAGE");
    ASSERT_GREATER_EQUAL_USE_MESSAGE(70, 85, "测试ASSERT_GREATER_EQUAL_USE_MESSAGE");
    ASSERT_GREATER_EQUAL_USE_MESSAGE(85, 70, "测试ASSERT_GREATER_EQUAL_USE_MESSAGE");

    GetStream() << "以上代码测试单元测试未通过的情况。\n";

    /// 上面有27个测试。其中17个为成功测试，10个为失败测试。
    passNumber += 17;
    failNumber += 10;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    /// 上面有3个ASSERT_EQUAL成功测试，加上一个ASSERT_NOT_THROW成功测试。
    passNumber += 4;
}

void CoreTools::UnitTestTesting::AssertNotThrowTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "以下代码测试单元测试未通过的情况。存在三个测试错误！\n";

    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_0(NotThrowException, "测试ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_0");
    ASSERT_NOT_THROW_EXCEPTION_1(NotThrowExceptionWithParameter, 0);
    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_2(NotThrowExceptionWithTwoParameter, 0, 0.2f, "测试ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_2");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_0(NotThrowException, "测试ASSERT_THROW_EXCEPTION_USE_MESSAGE_0");
    ASSERT_THROW_EXCEPTION_1(NotThrowExceptionWithParameter, 0);
    ASSERT_THROW_EXCEPTION_2(NotThrowExceptionWithTwoParameter, 0, 0.2f);

    GetStream() << "以上代码测试单元测试未通过的情况。\n";

    /// 上面有9个测试。其中6个为成功测试，3个为错误测试。
    passNumber += 6;
    errorNumber += 3;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    /// 上面有3个ASSERT_EQUAL成功测试，加上一个ASSERT_NOT_THROW成功测试。
    passNumber += 4;
}

void CoreTools::UnitTestTesting::AssertThrowTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "以下代码测试单元测试未通过的情况。存在三个测试错误！\n";

    ASSERT_NOT_THROW_EXCEPTION_0(ThrowException);
    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_1(ThrowExceptionWithParameter, 0, "测试ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_1");
    ASSERT_NOT_THROW_EXCEPTION_2(ThrowExceptionWithTwoParameter, 0, 0.2f);
    ASSERT_THROW_EXCEPTION_0(ThrowException);
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_1(ThrowExceptionWithParameter, 0, "测试ASSERT_THROW_EXCEPTION_USE_MESSAGE_1");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_2(ThrowExceptionWithTwoParameter, 0, 0.2f, "测试ASSERT_THROW_EXCEPTION_USE_MESSAGE_2");

    GetStream() << "以上代码测试单元测试未通过的情况。\n";

    /// 上面有9个测试。其中6个为成功测试，3个为错误测试。
    passNumber += 6;
    errorNumber += 3;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    /// 上面有3个ASSERT_EQUAL成功测试，加上一个ASSERT_NOT_THROW成功测试。
    passNumber += 4;
}

void CoreTools::UnitTestTesting::TestResultTest()
{
    const auto aPassNumber = GetPassedNumber();
    const auto aFailedNumber = GetFailedNumber();
    const auto aErrorNumber = GetErrorNumber();

    ResetTestData();

    ASSERT_EQUAL(aPassNumber, passNumber);
    ASSERT_EQUAL(aFailedNumber, failNumber);
    ASSERT_EQUAL(aErrorNumber, errorNumber);
}

void CoreTools::UnitTestTesting::PrintReportTest()
{
    PrintReport();
    PrintRunUnitTest();
    PrintTipsMessage();
}

void CoreTools::UnitTestTesting::NotThrowException() noexcept
{
}

void CoreTools::UnitTestTesting::NotThrowExceptionWithParameter(int parameter) noexcept
{
    System::UnusedFunction(parameter);
}

void CoreTools::UnitTestTesting::NotThrowExceptionWithTwoParameter(int parameter1, float parameter2) noexcept
{
    System::UnusedFunction(parameter1, parameter2);
}

void CoreTools::UnitTestTesting::ThrowException()
{
    THROW_EXCEPTION(SYSTEM_TEXT("这里测试抛出异常。如果触发断言，请按“否”取消。"));
}

void CoreTools::UnitTestTesting::ThrowExceptionWithParameter(int parameter)
{
    System::UnusedFunction(parameter);

    THROW_EXCEPTION(SYSTEM_TEXT("这里测试抛出异常。如果触发断言，请按“否”取消。"));
}

void CoreTools::UnitTestTesting::ThrowExceptionWithTwoParameter(int parameter1, float parameter2)
{
    System::UnusedFunction(parameter1, parameter2);

    THROW_EXCEPTION(SYSTEM_TEXT("这里测试抛出异常。如果触发断言，请按“否”取消。"));
}

bool CoreTools::Approximate(double lhs, double rhs, double epsilon) noexcept
{
    return abs(lhs - rhs) <= epsilon;
}
