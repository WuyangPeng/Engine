///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:17)

#include "InitTermRegisterFactoryTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InitTermRegisterFactory.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

bool CoreTools::InitTermRegisterFactoryTesting::terminateCall{ false };
bool CoreTools::InitTermRegisterFactoryTesting::initializeCall{ false };

CoreTools::InitTermRegisterFactoryTesting::InitTermRegisterFactoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, InitTermRegisterFactoryTesting)

void CoreTools::InitTermRegisterFactoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::InitTermRegisterFactoryTesting::MainTest()
{
    ASSERT_FALSE(initializeCall);
    ASSERT_FALSE(terminateCall);

    const InitTermRegisterFactory initTermRegisterFactory{ Initializer, Terminator };

    InitTerm::ExecuteInitializer();

    ASSERT_TRUE(initializeCall);
    ASSERT_FALSE(terminateCall);

    InitTerm::ExecuteTerminator();

    ASSERT_TRUE(initializeCall);
    ASSERT_TRUE(terminateCall);
}

void CoreTools::InitTermRegisterFactoryTesting::Initializer() noexcept
{
    initializeCall = true;
}

void CoreTools::InitTermRegisterFactoryTesting::Terminator() noexcept
{
    terminateCall = true;
}