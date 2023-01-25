///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/12 23:24)

#include "OpenGLGlutCallbackTesting.h"
#include "System/Helper/Tools.h"
#include "System/OpenGL/Flags/GlutFlags.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"

System::OpenGLGlutCallbackTesting::OpenGLGlutCallbackTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGlutCallbackTesting)

void System::OpenGLGlutCallbackTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGlutCallbackTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateWindowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CallbackTest);
}

void System::OpenGLGlutCallbackTesting::CreateWindowTest()
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

    GlutMouseFunc(MouseClickCallback);
    GlutSetWindow(window);
    GlutSetWindow(mainWindow);

    GlutPostWindowRedisplay(window);

    System::GlutSetOption(GlutOption::WindowClose, EnumCastUnderlying(GlutExtension::GlutMainLoopReturns));
}

void System::OpenGLGlutCallbackTesting::CallbackTest()
{
    constexpr auto frame = 17;

    GlutTimerFunc(frame, OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetTimerFunctionCallback(), 1);
    GlutReshapeFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetChangeSizeCallback());
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

void System::OpenGLGlutCallbackTesting::MouseClickCallback(int button, int state, int xCoordinate, int yCoordinate) noexcept
{
    UnusedFunction(button, state, xCoordinate, yCoordinate);

    MAYBE_UNUSED const auto modifiers = GlutGetModifiers();

    GlutMouseFunc(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMouseFunctionCallback());
}
