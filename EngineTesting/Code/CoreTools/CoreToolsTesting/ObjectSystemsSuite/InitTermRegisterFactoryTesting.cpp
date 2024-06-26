﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/23 17:07)

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

    ASSERT_NOT_THROW_EXCEPTION_0(ExecuteInitializerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExecuteTerminatorTest);
}

void CoreTools::InitTermRegisterFactoryTesting::ExecuteInitializerTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_TRUE(initializeCall);
    ASSERT_FALSE(terminateCall);
}

void CoreTools::InitTermRegisterFactoryTesting::ExecuteTerminatorTest()
{
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