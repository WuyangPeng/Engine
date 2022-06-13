///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/11 18:03)

#include "CullStateTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Shaders/CullState.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CullStateTesting)

void Rendering::CullStateTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::CullStateTesting::InitTest()
{
    CullState firstCullState{ CoreTools::DisableNotThrow::Disable };

    ASSERT_TRUE(firstCullState.IsEnabled());
    ASSERT_TRUE(firstCullState.IsCCWOrder());

    firstCullState.SetEnabled(false);
    ASSERT_FALSE(firstCullState.IsEnabled());

    firstCullState.SetCCWOrder(false);
    ASSERT_FALSE(firstCullState.IsCCWOrder());
}

void Rendering::CullStateTesting::CopyTest()
{
    CullState firstCullState{ CoreTools::DisableNotThrow::Disable };

    firstCullState.SetEnabled(false);
    firstCullState.SetCCWOrder(false);

    CullState secondCullState(firstCullState);

    ASSERT_EQUAL(firstCullState.IsEnabled(), secondCullState.IsEnabled());
    ASSERT_EQUAL(firstCullState.IsCCWOrder(), secondCullState.IsCCWOrder());

    firstCullState.SetCCWOrder(true);

    ASSERT_UNEQUAL(firstCullState.IsCCWOrder(), secondCullState.IsCCWOrder());
}

void Rendering::CullStateTesting::StreamTest() noexcept
{
}
