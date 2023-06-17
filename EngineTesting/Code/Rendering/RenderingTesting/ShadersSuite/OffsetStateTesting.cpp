///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:05)

#include "OffsetStateTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Shaders/OffsetState.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Rendering::OffsetStateTesting::OffsetStateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OffsetStateTesting)

void Rendering::OffsetStateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::OffsetStateTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::OffsetStateTesting::InitTest()
{
    OffsetState firstOffsetState{ CoreTools::DisableNotThrow::Disable };

    ASSERT_FALSE(firstOffsetState.IsFillEnabled());
    ASSERT_FALSE(firstOffsetState.IsLineEnabled());
    ASSERT_FALSE(firstOffsetState.IsPointEnabled());
    ASSERT_APPROXIMATE(firstOffsetState.GetScale(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstOffsetState.GetBias(), 0.0f, 1e-8f);

    firstOffsetState.SetFillEnabled(true);
    ASSERT_TRUE(firstOffsetState.IsFillEnabled());

    firstOffsetState.SetLineEnabled(true);
    ASSERT_TRUE(firstOffsetState.IsLineEnabled());

    firstOffsetState.SetPointEnabled(true);
    ASSERT_TRUE(firstOffsetState.IsPointEnabled());

    firstOffsetState.SetScale(1.5f);
    ASSERT_APPROXIMATE(firstOffsetState.GetScale(), 1.5f, 1e-8f);

    firstOffsetState.SetBias(1.6f);
    ASSERT_APPROXIMATE(firstOffsetState.GetBias(), 1.6f, 1e-8f);
}

void Rendering::OffsetStateTesting::CopyTest()
{
    OffsetState firstOffsetState{ CoreTools::DisableNotThrow::Disable };

    firstOffsetState.SetFillEnabled(true);
    firstOffsetState.SetLineEnabled(true);
    firstOffsetState.SetPointEnabled(true);
    firstOffsetState.SetScale(1.5f);
    firstOffsetState.SetBias(1.6f);

    OffsetState secondOffsetState(firstOffsetState);

    ASSERT_EQUAL(firstOffsetState.IsFillEnabled(), secondOffsetState.IsFillEnabled());
    ASSERT_EQUAL(firstOffsetState.IsLineEnabled(), secondOffsetState.IsLineEnabled());
    ASSERT_EQUAL(firstOffsetState.IsPointEnabled(), secondOffsetState.IsPointEnabled());
    ASSERT_APPROXIMATE(firstOffsetState.GetScale(), secondOffsetState.GetScale(), 1e-8f);
    ASSERT_APPROXIMATE(firstOffsetState.GetBias(), secondOffsetState.GetBias(), 1e-8f);

    secondOffsetState.SetScale(2.5f);
    ASSERT_APPROXIMATE(firstOffsetState.GetScale(), 1.5f, 1e-8f);
    ASSERT_APPROXIMATE(secondOffsetState.GetScale(), 2.5f, 1e-8f);
}

void Rendering::OffsetStateTesting::StreamTest() noexcept
{
}
