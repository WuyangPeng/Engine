///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 13:41)

#include "StringReplacingTesting.h"
#include "CoreTools/EngineConfiguration/StringReplacing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(CoreTools, StringReplacing)

void CoreTools::StringReplacingTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StringReplacingTest);
}

void CoreTools::StringReplacingTesting::StringReplacingTest()
{
    TestingType stringReplacing{ "Configuration/StringReplacing.json" };

    ASSERT_EQUAL(stringReplacing.GetReplacing(SYSTEM_TEXT("V1")), System::String(SYSTEM_TEXT("Temp1")));
    ASSERT_EQUAL(stringReplacing.GetReplacing(SYSTEM_TEXT("V2")), System::String(SYSTEM_TEXT("Temp2")));
}
