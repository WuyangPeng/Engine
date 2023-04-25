///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:00)

#include "AssertExecuteLoopNotThrowTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::AssertExecuteLoopNotThrowTesting::AssertExecuteLoopNotThrowTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertExecuteLoopNotThrowTesting)

void CoreTools::AssertExecuteLoopNotThrowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertExecuteLoopNotThrowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertExceptionMacroTest);
}

void CoreTools::AssertExecuteLoopNotThrowTesting::AssertExceptionMacroTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ExecuteLoopNotThrowTest);

    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION_USE_MESSAGE(ExecuteLoopNotThrowTest, "测试AssertExceptionMacro");
}

bool CoreTools::AssertExecuteLoopNotThrowTesting::ExecuteLoopNotThrowTest() noexcept
{
    return true;
}
