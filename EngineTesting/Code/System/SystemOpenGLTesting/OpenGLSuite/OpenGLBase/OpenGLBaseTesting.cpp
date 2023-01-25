///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 15:23)

#include "OpenGLBaseTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/Math.h"

System::OpenGLBaseTesting::OpenGLBaseTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLBaseTesting)

void System::OpenGLBaseTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLBaseTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetupRenderStatusTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ClearAllGLBufferBitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLViewportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLDepthRangeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLClearColorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLClearStencilTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLClearDepthTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLFrontFaceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLCullFaceTest);
}

void System::OpenGLBaseTesting::SetupRenderStatusTest() noexcept
{
    SetupRenderStatus();
}

void System::OpenGLBaseTesting::ClearAllGLBufferBitTest() noexcept
{
    ClearAllGLBufferBit();
}

void System::OpenGLBaseTesting::SetGLViewportTest() noexcept
{
    constexpr auto width = 800;
    constexpr auto height = 600;

    SetGLViewport(0, 0, width, height);
}

void System::OpenGLBaseTesting::SetGLDepthRangeTest() noexcept
{
    SetGLDepthRange(0.0, 1.0);
}

void System::OpenGLBaseTesting::SetGLClearColorTest() noexcept
{
    SetGLClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void System::OpenGLBaseTesting::SetGLClearStencilTest() noexcept
{
    SetGLClearStencil(0);
}

void System::OpenGLBaseTesting::SetGLClearDepthTest() noexcept
{
    SetGLClearDepth(1.0);
}

void System::OpenGLBaseTesting::SetGLFrontFaceTest() noexcept
{
    SetGLFrontFace(OpenGLFrontFace::CW);
    SetGLFrontFace(OpenGLFrontFace::CCW);
}

void System::OpenGLBaseTesting::SetGLCullFaceTest() noexcept
{
    SetGLCullFace(RasterizerStateCullFace::Front);
    SetGLCullFace(RasterizerStateCullFace::FrontAndBack);
    SetGLCullFace(RasterizerStateCullFace::Back);
}
