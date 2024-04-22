/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 21:31)

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
