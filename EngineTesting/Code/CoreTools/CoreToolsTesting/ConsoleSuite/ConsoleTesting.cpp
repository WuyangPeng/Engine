///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:33)

#include "ConsoleTesting.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Console/ConsoleInstanceDetail.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ConsoleTesting::ConsoleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ConsoleTesting)

void CoreTools::ConsoleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ConsoleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InputHandleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OutputHandleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ErrorHandleTest);
}

void CoreTools::ConsoleTesting::InputHandleTest()
{
    ConsoleInstance<StandardHandle::Input> console = ConsoleInstance<StandardHandle::Input>::Create();

    auto handle = console.GetHandle();

    ASSERT_UNEQUAL_NULL_PTR(handle);
    ASSERT_UNEQUAL(handle, System::gInvalidHandleValue);
}

void CoreTools::ConsoleTesting::OutputHandleTest()
{
    ConsoleInstance<StandardHandle::Output> console = ConsoleInstance<StandardHandle::Output>::Create();

    auto handle = console.GetHandle();

    ASSERT_UNEQUAL_NULL_PTR(handle);
    ASSERT_UNEQUAL(handle, System::gInvalidHandleValue);
}

void CoreTools::ConsoleTesting::ErrorHandleTest()
{
    ConsoleInstance<StandardHandle::Error> console = ConsoleInstance<StandardHandle::Error>::Create();

    auto handle = console.GetHandle();

    ASSERT_UNEQUAL_NULL_PTR(handle);
    ASSERT_UNEQUAL(handle, System::gInvalidHandleValue);
}
