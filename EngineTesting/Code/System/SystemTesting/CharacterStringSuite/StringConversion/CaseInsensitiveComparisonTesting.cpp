///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/06 13:55)

#include "CaseInsensitiveComparisonTesting.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "System/Helper/WindowsMacro.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"

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
        auto returnFlag = CompareStringOrdinalUseBinary(&lower, 1, &capital, 1, g_True);
        ASSERT_ENUM_EQUAL(returnFlag, ComparesStringReturn::Equal);

        returnFlag = CompareStringOrdinalUseBinary(&lower, 1, &capital, 1, g_False);
        ASSERT_ENUM_EQUAL(returnFlag, ComparesStringReturn::GreaterThan);

        lower += 1;
        capital += 1;
    }
}
