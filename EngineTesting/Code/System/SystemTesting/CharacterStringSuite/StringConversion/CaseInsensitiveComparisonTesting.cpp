///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/02 15:20)

#include "CaseInsensitiveComparisonTesting.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CaseInsensitiveComparisonTesting::CaseInsensitiveComparisonTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CaseInsensitiveComparisonTesting)

void System::CaseInsensitiveComparisonTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CaseInsensitiveComparisonTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CaseInsensitiveComparisonTest);
}

void System::CaseInsensitiveComparisonTesting::CaseInsensitiveComparisonTest()
{
    constexpr auto letterNum = 26;
    auto lower = L'a';
    auto capital = L'A';

    for (auto index = 0; index < letterNum; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(CompareStringOrdinalUseBinaryTest, lower, capital);

        lower += 1;
        capital += 1;
    }
}

void System::CaseInsensitiveComparisonTesting::CompareStringOrdinalUseBinaryTest(wchar_t lower, wchar_t capital)
{
    const auto ignoreCaseResult = CompareStringOrdinalUseBinary(std::wstring{ lower }, std::wstring{ capital }, gTrue);
    ASSERT_ENUM_EQUAL(ignoreCaseResult, ComparesStringReturn::Equal);

    const auto caseResult = CompareStringOrdinalUseBinary(std::wstring{ lower }, std::wstring{ capital }, gFalse);
    ASSERT_ENUM_EQUAL(caseResult, ComparesStringReturn::GreaterThan);
}
