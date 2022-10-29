///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/14 21:23)

#include "CaseInsensitiveComparisonTesting.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
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
        auto returnFlag = CompareStringOrdinalUseBinary(&lower, 1, &capital, 1, gTrue);
        ASSERT_ENUM_EQUAL(returnFlag, ComparesStringReturn::Equal);

        returnFlag = CompareStringOrdinalUseBinary(&lower, 1, &capital, 1, gFalse);
        ASSERT_ENUM_EQUAL(returnFlag, ComparesStringReturn::GreaterThan);

        lower += 1;
        capital += 1;
    }
}
