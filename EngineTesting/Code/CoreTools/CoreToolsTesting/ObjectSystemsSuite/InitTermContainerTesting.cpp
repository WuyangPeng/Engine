/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/23 17:01)

#include "InitTermContainerTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/ObjectSystems/InitTermContainer.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

bool CoreTools::InitTermContainerTesting::terminateCall{ false };
bool CoreTools::InitTermContainerTesting::initializeCall{ false };

CoreTools::InitTermContainerTesting::InitTermContainerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, InitTermContainerTesting)

void CoreTools::InitTermContainerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::InitTermContainerTesting::MainTest()
{
    ASSERT_FALSE(initializeCall);
    ASSERT_FALSE(terminateCall);

    InitTermContainer initTermContainer{};

    ASSERT_NOT_THROW_EXCEPTION_1(AddExecuteFunction0Test, initTermContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(Execute0Test, initTermContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(AddExecuteFunction1Test, initTermContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(Execute1Test, initTermContainer);
}

void CoreTools::InitTermContainerTesting::AddExecuteFunction0Test(InitTermContainer& initTermContainer)
{
    initTermContainer.AddExecuteFunction(Initializer);

    ASSERT_FALSE(initializeCall);
    ASSERT_FALSE(terminateCall);
}

void CoreTools::InitTermContainerTesting::Execute0Test(InitTermContainer& initTermContainer)
{
    initTermContainer.Execute();

    ASSERT_TRUE(initializeCall);
    ASSERT_FALSE(terminateCall);
}

void CoreTools::InitTermContainerTesting::AddExecuteFunction1Test(InitTermContainer& initTermContainer)
{
    initTermContainer.AddExecuteFunction(Terminator);

    ASSERT_TRUE(initializeCall);
    ASSERT_FALSE(terminateCall);
}

void CoreTools::InitTermContainerTesting::Execute1Test(InitTermContainer& initTermContainer)
{
    initTermContainer.Execute();

    ASSERT_TRUE(initializeCall);
    ASSERT_TRUE(terminateCall);
}

void CoreTools::InitTermContainerTesting::Initializer() noexcept
{
    initializeCall = true;
}

void CoreTools::InitTermContainerTesting::Terminator() noexcept
{
    terminateCall = true;
}