///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:25)

#include "MainFunctionMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::MainFunctionMacroTesting::MainFunctionMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MainFunctionMacroTesting)

void CoreTools::MainFunctionMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MainFunctionMacroTesting::MainTest() noexcept
{
    // 宏MAIN_FUNCTION使用Toolset中的MainFunction测试。
    // 宏DLL_MAIN_FUNCTION使用Toolset中的DllMainFunction测试。
}
