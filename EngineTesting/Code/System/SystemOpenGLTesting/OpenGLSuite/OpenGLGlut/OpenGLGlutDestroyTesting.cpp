///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:24)

#include "OpenGLGlutDestroyTesting.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

int System::OpenGLGlutDestroyTesting::destroyWindowId{ 0 };

System::OpenGLGlutDestroyTesting::OpenGLGlutDestroyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGlutDestroyTesting)

void System::OpenGLGlutDestroyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGlutDestroyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyWindowTest);
}

void System::OpenGLGlutDestroyTesting::DestroyWindowTest()
{
    constexpr auto width = 800;
    constexpr auto height = 600;

    GlutInitWindowSize(width, height);
    GlutInitContextVersion(4, 6);
    GlutInitWindowPosition(0, 0);
    GlutInitDisplayMode(false);

    const auto mainWindow = GlutGetWindow();

    destroyWindowId = GlutCreateWindow("Not Displayed Window");
    ASSERT_LESS(0, destroyWindowId);
    GlutSetWindow(destroyWindowId);
    GlutDisplayFunc(RenderSceneCallback);

    GlutSetWindow(mainWindow);
}

void System::OpenGLGlutDestroyTesting::RenderSceneCallback() noexcept
{
    GlutSwapBuffers();

    GlutDestroyWindow(destroyWindowId);
}
