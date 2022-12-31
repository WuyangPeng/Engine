///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/17 18:12)

#include "MakeLanguageIDTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MakeLanguageIDTesting::MakeLanguageIDTesting(const OStreamShared& stream)
    : ParentType{ stream },
      randomEngine{ GetEngineRandomSeed() },
      primaryDistribution{ 0x0, maxPrimaryID },
      subDistribution{ 0x0, maxSubID }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MakeLanguageIDTesting)

void System::MakeLanguageIDTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MakeLanguageIDTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MakeLanguageIDTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MakeMaxLanguageIDTest);
}

bool System::MakeLanguageIDTesting::MakeLanguageIDTest()
{
    const auto primaryID = primaryDistribution(randomEngine);
    const auto subID = subDistribution(randomEngine);

    const auto languageID = MakeLanguageID(primaryID, subID);
    const auto expectationLanguageID = boost::numeric_cast<WindowsWord>((subID << maxPrimaryShiftNum) | primaryID);

    ASSERT_EQUAL(languageID, expectationLanguageID);

    const auto reversePrimaryID = GetPrimaryLanguageID(languageID);
    const auto reverseSubID = GetSubLanguageID(languageID);

    ASSERT_EQUAL(reversePrimaryID, primaryID);
    ASSERT_EQUAL(reverseSubID, subID);

    return true;
}

void System::MakeLanguageIDTesting::MakeMaxLanguageIDTest()
{
    constexpr auto languageID = MakeLanguageID(maxPrimaryID, maxSubID);
    constexpr auto expectationLanguageID = (maxSubID << maxPrimaryShiftNum) | maxPrimaryID;

    ASSERT_EQUAL(languageID, expectationLanguageID);

    constexpr auto primaryID = GetPrimaryLanguageID(languageID);
    constexpr auto subID = GetSubLanguageID(languageID);

    ASSERT_EQUAL(primaryID, maxPrimaryID);
    ASSERT_EQUAL(subID, maxSubID);
}
