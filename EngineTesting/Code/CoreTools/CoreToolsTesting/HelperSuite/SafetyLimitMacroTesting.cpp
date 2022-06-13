///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:39)

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
