///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/20 13:42)

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
    auto loop = 10000;
    SAFETY_WHILE_BEGIN(0 < loop, 100)
    {
        --loop;
    }
    SAFETY_WHILE_END
}
