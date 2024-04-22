/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 00:14)

#include "FunctionProhibitedFromCallingTesting.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/CustomAssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::FunctionProhibitedFromCallingTesting::FunctionProhibitedFromCallingTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FunctionProhibitedFromCallingTesting)

void CoreTools::FunctionProhibitedFromCallingTesting::PrintTipsMessage()
{
    GetStream() << "这个测试测试断言失败，请按否取消。\n";

    System::SystemPause();
}

void CoreTools::FunctionProhibitedFromCallingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FunctionProhibitedFromCallingTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FunctionProhibitedFromCallingTest);
}

void CoreTools::FunctionProhibitedFromCallingTesting::FunctionProhibitedFromCallingTest() noexcept(gAssert < 4)
{
    FunctionProhibitedFromCalling("这里测试断言失败，请按否取消。", 1, 2, 3);
}
