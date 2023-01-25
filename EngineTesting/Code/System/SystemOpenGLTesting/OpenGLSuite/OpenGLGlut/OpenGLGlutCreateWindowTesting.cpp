///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/12 23:24)

#include "OpenGLGlutCreateWindowTesting.h"
#include "System/Helper/Tools.h"
#include "System/OpenGL/Flags/GlutFlags.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"

System::OpenGLGlutCreateWindowTesting::OpenGLGlutCreateWindowTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGlutCreateWindowTesting)

void System::OpenGLGlutCreateWindowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGlutCreateWindowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateWindowTest);

    // 	GlutMainLoop和GlutLeaveMainLoop在GlutMainLoopTesting中进行测试。
}

void System::OpenGLGlutCreateWindowTesting::CreateWindowTest()
{
    constexpr auto width = 800;
    constexpr auto height = 600;

    GlutInitWindowSize(width, height);
    GlutInitContextVersion(4, 6);
    GlutInitWindowPosition(0, 0);
    GlutInitDisplayMode(true);

    const auto window = GlutCreateWindow("OpenGL Glut Testing");
    ASSERT_LESS(0, window);

    const auto mainWindow = GlutGetWindow();

    GlutSetWindow(window);
    GlutSetWindow(mainWindow);

    GlutPostWindowRedisplay(window);
    GlutDisplayFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetRenderSceneCallback());

    System::GlutSetOption(GlutOption::WindowClose, EnumCastUnderlying(GlutExtension::GlutMainLoopReturns));
}
