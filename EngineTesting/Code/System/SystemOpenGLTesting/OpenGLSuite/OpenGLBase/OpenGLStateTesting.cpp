///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 19:35)

#include "OpenGLStateTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLStateTesting::OpenGLStateTesting(const OStreamShared& stream)
    : ParentType{ stream },
      openGLEnables{ OpenGLEnable::Blend,
                     OpenGLEnable::DepthTest,
                     OpenGLEnable::StencilTest,
                     OpenGLEnable::SampleCoverage,
                     OpenGLEnable::CullFace,
                     OpenGLEnable::PolygonOffsetFill,
                     OpenGLEnable::PolygonOffsetLine,
                     OpenGLEnable::PolygonOffsetPoint }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLStateTesting)

void System::OpenGLStateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLStateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EnableGLStateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DisableGLStateTest);
}

void System::OpenGLStateTesting::EnableGLStateTest() noexcept
{
    for (auto openGLEnable : openGLEnables)
    {
        EnableGLState(openGLEnable);
    }

    EnableGLState(OpenGLEnable::Blend, 0);
}

void System::OpenGLStateTesting::DisableGLStateTest() noexcept
{
    for (auto openGLEnable : openGLEnables)
    {
        DisableGLState(openGLEnable);
    }

    DisableGLState(OpenGLEnable::Blend, 0);
}
