/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 09:59)

#include "MakeLanguageCidTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MakeLanguageCidTesting::MakeLanguageCidTesting(const OStreamShared& stream)
    : ParentType{ stream },
      randomEngine{ GetEngineRandomSeed() },
      sortDistribution{ 0x0, maxSortId },
      languageDistribution{ 0x0, maxLanguageId }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MakeLanguageCidTesting)

void System::MakeLanguageCidTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MakeLanguageCidTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MakeLanguageCidTest);
}

bool System::MakeLanguageCidTesting::MakeLanguageCidTest()
{
    const auto sortId = sortDistribution(randomEngine);
    const auto languageId = languageDistribution(randomEngine);

    const auto languageCid = MakeLanguageCid(languageId, sortId);
    const auto expectationLcid = (static_cast<WindowsDWord>(sortId) << maxLanguageShiftNum) | static_cast<WindowsDWord>(languageId);

    ASSERT_EQUAL(languageCid, expectationLcid);

    return true;
}
