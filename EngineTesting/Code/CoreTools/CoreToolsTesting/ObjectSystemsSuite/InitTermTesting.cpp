///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/24 09:55)

#include "InitTermTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
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

    InitTerm::AddInitializer(Initializer);
    InitTerm::AddTerminator(Terminator);

    ASSERT_FALSE(initializeCall);
    ASSERT_FALSE(terminateCall);

    InitTerm::ExecuteInitializer();

    ASSERT_TRUE(initializeCall);
    ASSERT_FALSE(terminateCall);

    InitTerm::ExecuteTerminator();

    ASSERT_TRUE(initializeCall);
    ASSERT_TRUE(terminateCall);
}
