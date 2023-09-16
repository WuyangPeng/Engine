///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:50)

#include "MakeLanguageIdTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MakeLanguageIdTesting::MakeLanguageIdTesting(const OStreamShared& stream)
    : ParentType{ stream },
      randomEngine{ GetEngineRandomSeed() },
      primaryDistribution{ 0x0, maxPrimaryId },
      subDistribution{ 0x0, maxSubId }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MakeLanguageIdTesting)

void System::MakeLanguageIdTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MakeLanguageIdTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MakeLanguageIdTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MakeMaxLanguageIdTest);
}

bool System::MakeLanguageIdTesting::MakeLanguageIdTest()
{
    const auto primaryId = primaryDistribution(randomEngine);
    const auto subId = subDistribution(randomEngine);

    const auto languageId = MakeLanguageId(primaryId, subId);
    const auto expectationLanguageId = boost::numeric_cast<WindowsWord>((subId << maxPrimaryShiftNum) | primaryId);

    ASSERT_EQUAL(languageId, expectationLanguageId);

    const auto reversePrimaryId = GetPrimaryLanguageId(languageId);
    const auto reverseSubId = GetSubLanguageId(languageId);

    ASSERT_EQUAL(reversePrimaryId, primaryId);
    ASSERT_EQUAL(reverseSubId, subId);

    return true;
}

void System::MakeLanguageIdTesting::MakeMaxLanguageIdTest()
{
    constexpr auto languageId = MakeLanguageId(maxPrimaryId, maxSubId);
    constexpr auto expectationLanguageId = (maxSubId << maxPrimaryShiftNum) | maxPrimaryId;

    ASSERT_EQUAL(languageId, expectationLanguageId);

    constexpr auto primaryId = GetPrimaryLanguageId(languageId);
    constexpr auto subId = GetSubLanguageId(languageId);

    ASSERT_EQUAL(primaryId, maxPrimaryId);
    ASSERT_EQUAL(subId, maxSubId);
}
