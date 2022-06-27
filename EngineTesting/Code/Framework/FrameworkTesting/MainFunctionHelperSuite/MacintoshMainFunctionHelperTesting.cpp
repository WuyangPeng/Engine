///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 10:45)

#include "MacintoshMainFunctionHelperTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::MacintoshMainFunctionHelperTesting::MacintoshMainFunctionHelperTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MacintoshMainFunctionHelperTesting)

void Framework::MacintoshMainFunctionHelperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::MacintoshMainFunctionHelperTesting::MainTest()
{
    // 框架类MacintoshdMainFunctionHelper1使用工具箱调用，无法单独运行单元测试。

    CoreTools::Directory directory{ System::GetEngineeringDirectory() };

    ASSERT_NOT_THROW_EXCEPTION_0(MacintoshMainFunctionHelper1Test);
}

void Framework::MacintoshMainFunctionHelperTesting::MacintoshMainFunctionHelper1Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("MacintoshMainFunctionHelper1")));
}
