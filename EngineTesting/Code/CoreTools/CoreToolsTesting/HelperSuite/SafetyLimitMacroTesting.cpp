/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 12:07)

#include "SafetyLimitMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/SafetyLimitMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::SafetyLimitMacroTesting::SafetyLimitMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SafetyLimitMacroTesting)

void CoreTools::SafetyLimitMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SafetyLimitMacroTesting::MainTest()
{
    ASSERT_THROW_EXCEPTION_0(MacroTest);
}

void CoreTools::SafetyLimitMacroTesting::MacroTest()
{
    auto loop = gSafetyLimit100000;
    SAFETY_WHILE_BEGIN(0 < loop, 100)
    {
        --loop;
    }
    SAFETY_WHILE_END

    ASSERT_EQUAL(loop, 0);
}
