/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/23 17:08)

#include "InitTermTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

bool CoreTools::InitTermTesting::terminateCall{ false };
bool CoreTools::InitTermTesting::initializeCall{ false };

CoreTools::InitTermTesting::InitTermTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, InitTermTesting)

void CoreTools::InitTermTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::InitTermTesting::Initializer() noexcept
{
    initializeCall = true;
}

void CoreTools::InitTermTesting::Terminator() noexcept
{
    terminateCall = true;
}

void CoreTools::InitTermTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTermTest);
}

void CoreTools::InitTermTesting::InitTermTest()
{
    ASSERT_FALSE(initializeCall);
    ASSERT_FALSE(terminateCall);

    ASSERT_NOT_THROW_EXCEPTION_0(InitTermAddTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExecuteInitializerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExecuteTerminatorTest);
}

void CoreTools::InitTermTesting::ExecuteInitializerTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_TRUE(initializeCall);
    ASSERT_FALSE(terminateCall);
}

void CoreTools::InitTermTesting::ExecuteTerminatorTest()
{
    InitTerm::ExecuteTerminator();

    ASSERT_TRUE(initializeCall);
    ASSERT_TRUE(terminateCall);
}

void CoreTools::InitTermTesting::InitTermAddTest()
{
    InitTerm::AddInitializer(Initializer);
    InitTerm::AddTerminator(Terminator);

    ASSERT_FALSE(initializeCall);
    ASSERT_FALSE(terminateCall);
}
