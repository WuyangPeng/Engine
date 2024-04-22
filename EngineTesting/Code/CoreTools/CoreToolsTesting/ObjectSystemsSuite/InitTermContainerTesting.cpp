/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 17:26)

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

    initTermContainer.AddExecuteFunction(Initializer);

    ASSERT_FALSE(initializeCall);
    ASSERT_FALSE(terminateCall);

    initTermContainer.Execute();

    ASSERT_TRUE(initializeCall);
    ASSERT_FALSE(terminateCall);

    initTermContainer.AddExecuteFunction(Terminator);

    ASSERT_TRUE(initializeCall);
    ASSERT_FALSE(terminateCall);

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