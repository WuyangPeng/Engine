///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:05)

#include "DepthStateTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Shaders/DepthState.h"

Rendering::DepthStateTesting::DepthStateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DepthStateTesting)

void Rendering::DepthStateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::DepthStateTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::DepthStateTesting::InitTest()
{
    DepthState firstDepthState{ CoreTools::DisableNotThrow::Disable };

    ASSERT_TRUE(firstDepthState.IsEnabled());
    ASSERT_TRUE(firstDepthState.IsWritable());
    ASSERT_ENUM_EQUAL(firstDepthState.GetCompare(), DepthStateFlags::CompareMode::LessEqual);

    firstDepthState.SetEnabled(false);
    ASSERT_FALSE(firstDepthState.IsEnabled());

    firstDepthState.SetWritable(false);
    ASSERT_FALSE(firstDepthState.IsWritable());

    firstDepthState.SetCompare(DepthStateFlags::CompareMode::GreaterEqual);
    ASSERT_ENUM_EQUAL(firstDepthState.GetCompare(), DepthStateFlags::CompareMode::GreaterEqual);
}

void Rendering::DepthStateTesting::CopyTest()
{
    DepthState firstDepthState{ CoreTools::DisableNotThrow::Disable };
    firstDepthState.SetEnabled(false);
    firstDepthState.SetWritable(false);
    firstDepthState.SetCompare(DepthStateFlags::CompareMode::GreaterEqual);

    DepthState secondDepthState(firstDepthState);

    ASSERT_EQUAL(firstDepthState.IsEnabled(), secondDepthState.IsEnabled());
    ASSERT_EQUAL(firstDepthState.IsWritable(), secondDepthState.IsWritable());
    ASSERT_ENUM_EQUAL(firstDepthState.GetCompare(), secondDepthState.GetCompare());

    secondDepthState.SetCompare(DepthStateFlags::CompareMode::Less);
    ASSERT_ENUM_EQUAL(secondDepthState.GetCompare(), DepthStateFlags::CompareMode::Less);
    ASSERT_ENUM_EQUAL(firstDepthState.GetCompare(), DepthStateFlags::CompareMode::GreaterEqual);
}

void Rendering::DepthStateTesting::StreamTest() noexcept
{
}
