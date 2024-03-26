/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/15 14:04)

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
    ASSERT_NOT_THROW_EXCEPTION_1(GlutInit, true);

    const auto window = GlutCreateWindow("OpenGL Glut Testing");
    ASSERT_LESS(0, window);

    const auto mainWindow = GlutGetWindow();

    GlutMouseFunc(MouseClickCallback);
    ASSERT_NOT_THROW_EXCEPTION_2(DoCreateWindowTest, window, mainWindow);
}

void System::OpenGLGlutCallbackTesting::CallbackTest()
{
    GlutTimerFunc(frame, Framework::OpenGLGlutProcessManager::GetTimerFunctionCallback(), 1);
    GlutReshapeFunc(Framework::OpenGLGlutProcessManager::GetChangeSizeCallback());
    GlutIdleFunc(Framework::OpenGLGlutProcessManager::GetIdleFunctionCallback());
    GlutKeyboardFunc(Framework::OpenGLGlutProcessManager::GetKeyboardDownCallback());
    GlutSpecialFunc(Framework::OpenGLGlutProcessManager::GetSpecialKeysDownCallback());
    GlutKeyboardUpFunc(Framework::OpenGLGlutProcessManager::GetKeyboardUpCallback());
    GlutSpecialUpFunc(Framework::OpenGLGlutProcessManager::GetSpecialKeysUpCallback());
    GlutMouseFunc(MouseClickCallback);
    GlutMotionFunc(Framework::OpenGLGlutProcessManager::GetMotionFunctionCallback());
    GlutPassiveMotionFunc(Framework::OpenGLGlutProcessManager::GetPassiveMotionCallback());

    const auto menu = GlutCreateMenu(Framework::OpenGLGlutProcessManager::GetProcessMenuCallback());
    ASSERT_LESS(0, menu);

    GlutDisplayFunc(Framework::OpenGLGlutProcessManager::GetRenderSceneCallback());
}

void System::OpenGLGlutCallbackTesting::MouseClickCallback(int button, int state, int xCoordinate, int yCoordinate) noexcept
{
    const auto modifiers = GlutGetModifiers();

    GlutMouseFunc(Framework::OpenGLGlutProcessManager::GetMouseFunctionCallback());

    UnusedFunction(button, state, xCoordinate, yCoordinate, modifiers);
}
