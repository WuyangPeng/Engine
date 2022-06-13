///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 14:13)

#include "UnitTestTesting.h"
#include "Detail/TestEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::ostream;
using std::string;

CoreTools::UnitTestTesting::UnitTestTesting(const OStreamShared& stream)
    : ParentType{ stream }, passNumber{ 0 }, failNumber{ 0 }, errorNumber{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::UnitTestTesting::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= passNumber && 0 <= failNumber && 0 <= errorNumber)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::UnitTestTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::UnitTestTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertTestTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ErrorTestTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertEqualTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertCompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertNotThrowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertThrowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TestResultTest);
}

void CoreTools::UnitTestTesting::NameTest()
{
    ASSERT_EQUAL(GetName(), typeid(*this).name());

    // NameTest����һ��ASSERT_EQUAL�ɹ����Ժ�һ��ASSERT_NOT_THROW�ɹ����ԡ�
    passNumber += 2;
}

void CoreTools::UnitTestTesting::StreamTest() noexcept
{
    // StreamTest����0��ASSERT�ɹ����Ժ�һ��ASSERT_NOT_THROW�ɹ����ԡ�
    passNumber += 1;
}

void CoreTools::UnitTestTesting::AssertTestTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "���´�����Ե�Ԫ����δͨ�������������һ������ʧ�ܣ�\n";

    ASSERT_TRUE(true);
    ASSERT_TRUE(false);

    GetStream() << "���ϴ�����Ե�Ԫ����δͨ���������\n";

    // ������5�����ԡ�����4��Ϊ�ɹ����ԣ�1��Ϊʧ�ܲ��ԡ�
    passNumber += 4;
    failNumber += 1;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    // ������3��ASSERT_EQUAL�ɹ����ԣ�����һ��ASSERT_NOT_THROW�ɹ����ԡ�
    passNumber += 4;
}

void CoreTools::UnitTestTesting::ErrorTestTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "���´�����Ե�Ԫ����δͨ�������������һ�����Դ���\n";

    ErrorTest(true, CORE_TOOLS_FUNCTION_DESCRIBED);
    ErrorTest(false, CORE_TOOLS_FUNCTION_DESCRIBED);

    GetStream() << "���ϴ�����Ե�Ԫ����δͨ���������\n";

    // ������5�����ԡ�����4��Ϊ�ɹ����ԣ�1��Ϊ������ԡ�
    passNumber += 4;
    errorNumber += 1;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    // ������3��ASSERT_EQUAL�ɹ����ԣ�����һ��ASSERT_NOT_THROW�ɹ����ԡ�
    passNumber += 4;
}

void CoreTools::UnitTestTesting::AssertEqualTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "���´�����Ե�Ԫ����δͨ�������������ʮ�������ʧ�ܣ�\n";

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
    ASSERT_ENUM_EQUAL(TestEnum::Ten, TestEnum::Ten);
    ASSERT_ENUM_UNEQUAL(TestEnum::Ten, TestEnum::Fifteen);
    constexpr float value{ 1.0f };
    ASSERT_FLOATING_POINT_COMPLETE_EQUAL(value, value);
    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL(value, value + 0.00001f);
    System::String stringValue{ SYSTEM_TEXT("value") };
    ASSERT_EQUAL(stringValue, stringValue);

    ASSERT_EQUAL(1, 1);
    ASSERT_EQUAL(1, 2);
    ASSERT_UNEQUAL(1, 1);
    ASSERT_UNEQUAL(1, 2);

    ASSERT_EQUAL_USE_MESSAGE(1, 1, "����ASSERT_EQUAL_USE_MESSAGE");
    ASSERT_EQUAL_USE_MESSAGE(1, 2, "����ASSERT_EQUAL_USE_MESSAGE");
    ASSERT_UNEQUAL_USE_MESSAGE(1, 1, "����ASSERT_UNEQUAL_USE_MESSAGE");
    ASSERT_UNEQUAL_USE_MESSAGE(1, 2, "����ASSERT_UNEQUAL_USE_MESSAGE");
    ASSERT_APPROXIMATE_USE_MESSAGE(1.0f, 1.01f, 0.02f, "����ASSERT_APPROXIMATE_USE_MESSAGE");
    ASSERT_APPROXIMATE_USE_MESSAGE(1.0f, 1.11f, 0.1f, "����ASSERT_APPROXIMATE_USE_MESSAGE");
    ASSERT_EQUAL_NULL_PTR_USE_MESSAGE(ptr, "����ASSERT_EQUAL_NULL_PTR_USE_MESSAGE");
    ASSERT_EQUAL_NULL_PTR_USE_MESSAGE(this, "����ASSERT_EQUAL_NULL_PTR_USE_MESSAGE");
    ASSERT_UNEQUAL_NULL_PTR_USE_MESSAGE(ptr, "����ASSERT_UNEQUAL_NULL_PTR_USE_MESSAGE");
    ASSERT_UNEQUAL_NULL_PTR_USE_MESSAGE(this, "����ASSERT_UNEQUAL_NULL_PTR_USE_MESSAGE");
    ASSERT_FLOATING_POINT_COMPLETE_EQUAL_USE_MESSAGE(value, value, "����ASSERT_FLOATING_POINT_COMPLETE_EQUAL_USE_MESSAGE");
    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_USE_MESSAGE(value, value + 0.00001f, "����ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_USE_MESSAGE");

    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate, 1.0, 1.01, 0.02);
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate, 1.0, 1.11, 0.1);

    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(Approximate, 1.0, 1.01, 0.02, "����ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE");
    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(Approximate, 1.0, 1.11, 0.1, "����ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE");

    GetStream() << "���ϴ�����Ե�Ԫ����δͨ���������\n";

    // ������40�����ԡ�����25��Ϊ�ɹ����ԣ�15��Ϊʧ�ܲ��ԡ�
    passNumber += 25;
    failNumber += 15;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    // ������3��ASSERT_EQUAL�ɹ����ԣ�����һ��ASSERT_NOT_THROW�ɹ����ԡ�
    passNumber += 4;
}

void CoreTools::UnitTestTesting::AssertCompareTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "���´�����Ե�Ԫ����δͨ�������������ʮ������ʧ�ܣ�\n";

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

    ASSERT_ENUM_LESS(TestEnum::Ten, TestEnum::Fifteen);
    ASSERT_ENUM_LESS_EQUAL(TestEnum::Ten, TestEnum::Ten);
    ASSERT_ENUM_GREATER(TestEnum::Fifteen, TestEnum::Ten);
    ASSERT_ENUM_GREATER_EQUAL(TestEnum::Fifteen, TestEnum::Ten);

    ASSERT_LESS_USE_MESSAGE(1, 7, "����ASSERT_LESS_USE_MESSAGE");
    ASSERT_LESS_USE_MESSAGE(10, 2, "����ASSERT_LESS_USE_MESSAGE");
    ASSERT_LESS_EQUAL_USE_MESSAGE(1, 11, "����ASSERT_LESS_EQUAL_USE_MESSAGE");
    ASSERT_LESS_EQUAL_USE_MESSAGE(11, 2, "����ASSERT_LESS_EQUAL_USE_MESSAGE");
    ASSERT_RANGE_USE_MESSAGE(1.011f, 1.01f, 1.012f, "����ASSERT_RANGE_USE_MESSAGE");
    ASSERT_RANGE_USE_MESSAGE(1.0f, 1.11f, 0.12f, "����ASSERT_RANGE_USE_MESSAGE");
    ASSERT_GREATER_USE_MESSAGE(7, 6, "����ASSERT_GREATER_USE_MESSAGE");
    ASSERT_GREATER_USE_MESSAGE(6, 7, "����ASSERT_GREATER_USE_MESSAGE");
    ASSERT_GREATER_EQUAL_USE_MESSAGE(70, 85, "����ASSERT_GREATER_EQUAL_USE_MESSAGE");
    ASSERT_GREATER_EQUAL_USE_MESSAGE(85, 70, "����ASSERT_GREATER_EQUAL_USE_MESSAGE");

    GetStream() << "���ϴ�����Ե�Ԫ����δͨ���������\n";

    // ������27�����ԡ�����17��Ϊ�ɹ����ԣ�10��Ϊʧ�ܲ��ԡ�
    passNumber += 17;
    failNumber += 10;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    // ������3��ASSERT_EQUAL�ɹ����ԣ�����һ��ASSERT_NOT_THROW�ɹ����ԡ�
    passNumber += 4;
}

void CoreTools::UnitTestTesting::AssertNotThrowTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "���´�����Ե�Ԫ����δͨ��������������������Դ���\n";

    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_0(NotThrowException, "����ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_0");
    ASSERT_NOT_THROW_EXCEPTION_1(NotThrowExceptionWithParameter, 0);
    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_2(NotThrowExceptionWithTwoParameter, 0, 0.2f, "����ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_2");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_0(NotThrowException, "����ASSERT_THROW_EXCEPTION_USE_MESSAGE_0");
    ASSERT_THROW_EXCEPTION_1(NotThrowExceptionWithParameter, 0);
    ASSERT_THROW_EXCEPTION_2(NotThrowExceptionWithTwoParameter, 0, 0.2f);

    GetStream() << "���ϴ�����Ե�Ԫ����δͨ���������\n";

    // ������9�����ԡ�����6��Ϊ�ɹ����ԣ�3��Ϊ������ԡ�
    passNumber += 6;
    errorNumber += 3;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    // ������3��ASSERT_EQUAL�ɹ����ԣ�����һ��ASSERT_NOT_THROW�ɹ����ԡ�
    passNumber += 4;
}

void CoreTools::UnitTestTesting::AssertThrowTest()
{
    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    GetStream() << "���´�����Ե�Ԫ����δͨ��������������������Դ���\n";

    ASSERT_NOT_THROW_EXCEPTION_0(ThrowException);
    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_1(ThrowExceptionWithParameter, 0, "����ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_1");
    ASSERT_NOT_THROW_EXCEPTION_2(ThrowExceptionWithTwoParameter, 0, 0.2f);
    ASSERT_THROW_EXCEPTION_0(ThrowException);
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_1(ThrowExceptionWithParameter, 0, "����ASSERT_THROW_EXCEPTION_USE_MESSAGE_1");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_2(ThrowExceptionWithTwoParameter, 0, 0.2f, "����ASSERT_THROW_EXCEPTION_USE_MESSAGE_2");

    GetStream() << "���ϴ�����Ե�Ԫ����δͨ���������\n";

    // ������9�����ԡ�����6��Ϊ�ɹ����ԣ�3��Ϊ������ԡ�
    passNumber += 6;
    errorNumber += 3;

    ASSERT_EQUAL(GetPassedNumber(), passNumber);
    ASSERT_EQUAL(GetFailedNumber(), failNumber);
    ASSERT_EQUAL(GetErrorNumber(), errorNumber);

    // ������3��ASSERT_EQUAL�ɹ����ԣ�����һ��ASSERT_NOT_THROW�ɹ����ԡ�
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

void CoreTools::UnitTestTesting::NotThrowException() noexcept
{
}

void CoreTools::UnitTestTesting::NotThrowExceptionWithParameter([[maybe_unused]] int parameter) noexcept
{
}

void CoreTools::UnitTestTesting::NotThrowExceptionWithTwoParameter([[maybe_unused]] int parameter1, [[maybe_unused]] float parameter2) noexcept
{
}

void CoreTools::UnitTestTesting::ThrowException()
{
    THROW_EXCEPTION(SYSTEM_TEXT("��������׳��쳣������������ԣ��밴����ȡ����"));
}

void CoreTools::UnitTestTesting::ThrowExceptionWithParameter([[maybe_unused]] int parameter)
{
    THROW_EXCEPTION(SYSTEM_TEXT("��������׳��쳣������������ԣ��밴����ȡ����"));
}

void CoreTools::UnitTestTesting::ThrowExceptionWithTwoParameter([[maybe_unused]] int parameter1, [[maybe_unused]] float parameter2)
{
    THROW_EXCEPTION(SYSTEM_TEXT("��������׳��쳣������������ԣ��밴����ȡ����"));
}

bool CoreTools::Approximate(double lhs, double rhs, double epsilon) noexcept
{
    return abs(lhs - rhs) <= epsilon;
}
