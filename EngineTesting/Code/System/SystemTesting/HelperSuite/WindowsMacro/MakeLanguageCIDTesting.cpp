///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/16 19:52)

#include "MakeLanguageCIDTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MakeLanguageCIDTesting::MakeLanguageCIDTesting(const OStreamShared& stream)
    : ParentType{ stream }, randomEngine{ GetEngineRandomSeed() }, sortDistribution{ 0x0, maxSortID }, languageDistribution{ 0x0, maxLanguageID }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MakeLanguageCIDTesting)

void System::MakeLanguageCIDTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MakeLanguageCIDTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MakeLanguageCIDTest);
}

bool System::MakeLanguageCIDTesting::MakeLanguageCIDTest()
{
    const auto sortID = sortDistribution(randomEngine);
    const auto languageID = languageDistribution(randomEngine);

    const auto languageCID = MakeLanguageCID(languageID, sortID);
    const auto expectationLCID = (static_cast<WindowsDWord>(sortID) << maxLanguageShiftNum) | static_cast<WindowsDWord>(languageID);

    ASSERT_EQUAL(languageCID, expectationLCID);

    return true;
}
