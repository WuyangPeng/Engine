///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 14:58)

#include "OpenGLGlutTesting.h"
#include "System/OpenGL/Flags/GlutFlags.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"

int System::OpenGLGlutTesting::destroyWindowID{ 0 };

System::OpenGLGlutTesting::OpenGLGlutTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGlutTesting)

void System::OpenGLGlutTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGlutTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateWindowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CallbackTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyWindowTest);

    // 	GlutMainLoop和GlutLeaveMainLoop在GlutMainLoopTesting中进行测试。
}

void System::OpenGLGlutTesting::CreateWindowTest()
{
    constexpr auto width = 800;
    constexpr auto height = 600;

    GlutInitWindowSize(width, height);
    GlutInitContextVersion(4, 6);
    GlutInitWindowPosition(0, 0);
    GlutInitDisplayMode(true);

    auto window = GlutCreateWindow("OpenGL Glut Testing");
    ASSERT_LESS(0, window);

    const auto mainWindow = GlutGetWindow();

    GlutMouseFunc(MouseClickCallback);
    GlutSetWindow(window);
    GlutSetWindow(mainWindow);

    GlutPostWindowRedisplay(window);

    System::GlutSetOption(GlutOption::WindowClose, EnumCastUnderlying(GlutExtension::GlutMainLoopReturns));
}

void System::OpenGLGlutTesting::CallbackTest()
{
    constexpr auto frame = 17;

    GlutTimerFunc(frame, OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetTimerFunctionCallback(), 1);
    GlutReshapeFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetChangeSizeCallback());
    GlutDisplayFunc(RenderSceneCallback);
    GlutIdleFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetIdleFunctionCallback());
    GlutKeyboardFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetKeyboardDownCallback());
    GlutSpecialFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetSpecialKeysDownCallback());
    GlutKeyboardUpFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetKeyboardUpCallback());
    GlutSpecialUpFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetSpecialKeysUpCallback());
    GlutMouseFunc(MouseClickCallback);
    GlutMotionFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMotionFunctionCallback());
    GlutPassiveMotionFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetPassiveMotionCallback());

    const auto menu = GlutCreateMenu(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetProcessMenuCallback());
    ASSERT_LESS(0, menu);

    GlutDisplayFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetRenderSceneCallback());
}

void System::OpenGLGlutTesting::DestroyWindowTest()
{
    constexpr auto width = 800;
    constexpr auto height = 600;

    GlutInitWindowSize(width, height);
    GlutInitContextVersion(4, 6);
    GlutInitWindowPosition(0, 0);
    GlutInitDisplayMode(false);

    const auto mainWindow = GlutGetWindow();

    destroyWindowID = GlutCreateWindow("Not Displayed Window");
    ASSERT_LESS(0, destroyWindowID);
    GlutSetWindow(destroyWindowID);
    GlutDisplayFunc(RenderSceneCallback);

    GlutSetWindow(mainWindow);
}

void System::OpenGLGlutTesting::RenderSceneCallback() noexcept
{
    GlutSwapBuffers();

    GlutDestroyWindow(destroyWindowID);
}

void System::OpenGLGlutTesting::MouseClickCallback(MAYBE_UNUSED int button, MAYBE_UNUSED int state, MAYBE_UNUSED int xCoordinate, MAYBE_UNUSED int yCoordinate) noexcept
{
    MAYBE_UNUSED const auto modifiers = GlutGetModifiers();

    GlutMouseFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMouseFunctionCallback());
}
