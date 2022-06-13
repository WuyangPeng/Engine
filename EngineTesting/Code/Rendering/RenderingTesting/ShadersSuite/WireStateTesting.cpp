///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/11 19:47)

#include "WireStateTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Shaders/WireState.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, WireStateTesting)

void Rendering::WireStateTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::WireStateTesting::InitTest()
{
    WireState firstWireState(CoreTools::DisableNotThrow::Disable);

    ASSERT_FALSE(firstWireState.IsEnabled());

    firstWireState.SetEnabled(true);
    ASSERT_TRUE(firstWireState.IsEnabled());
}

void Rendering::WireStateTesting::CopyTest()
{
    WireState firstWireState(CoreTools::DisableNotThrow::Disable);

    firstWireState.SetEnabled(true);

    WireState secondWireState(firstWireState);

    ASSERT_EQUAL(firstWireState.IsEnabled(), secondWireState.IsEnabled());

    firstWireState.SetEnabled(false);

    ASSERT_UNEQUAL(firstWireState.IsEnabled(), secondWireState.IsEnabled());
}

void Rendering::WireStateTesting::StreamTest() noexcept
{
     
}
