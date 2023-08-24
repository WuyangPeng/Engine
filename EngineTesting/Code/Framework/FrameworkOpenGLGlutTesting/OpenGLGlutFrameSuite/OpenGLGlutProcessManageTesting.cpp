///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 18:06)

#include "OpenGLGlutProcessManageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"

Framework::OpenGLGlutProcessManagerTesting::OpenGLGlutProcessManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutProcessManagerTesting)

void Framework::OpenGLGlutProcessManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::OpenGLGlutProcessManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGlutCallBackPtrTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MainFunctionHelperPtrTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetWindowIDSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMillisecondSucceedTest);

    ASSERT_NOT_THROW_EXCEPTION_0(RenderSceneCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChangeSizeCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TimerFunctionCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpecialKeysDownCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(KeyboardDownCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpecialKeysUpCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(KeyboardUpCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MouseFunctionCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MotionFunctionCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IdleFunctionCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProcessMenuCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TerminateCallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PreCreateSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InitializeSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PreIdleSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TerminateSucceedTest);
}

void Framework::OpenGLGlutProcessManagerTesting::OpenGLGlutCallBackPtrTest()
{
    const auto openGlGlutCallBackInterface = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetOpenGLGlutCallBackInterface();

    ASSERT_UNEQUAL_NULL_PTR(openGlGlutCallBackInterface);

    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.ClearOpenGLGlutCallBack();

    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetOpenGLGlutCallBack(openGlGlutCallBackInterface);

    ASSERT_EQUAL(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetOpenGLGlutCallBackInterface(), openGlGlutCallBackInterface);
}

void Framework::OpenGLGlutProcessManagerTesting::MainFunctionHelperPtrTest()
{
    const auto mainFunctionHelper = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMainFunctionHelper();
    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.ClearMainFunctionHelper();
    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetMainFunctionHelper(mainFunctionHelper);
}

void Framework::OpenGLGlutProcessManagerTesting::SetWindowIDSucceedTest()
{
    const auto window = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetWindowId();

    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetWindowId(window);
}

void Framework::OpenGLGlutProcessManagerTesting::SetMillisecondSucceedTest()
{
    constexpr auto millisecond = 17;

    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetMillisecond(millisecond);
    ASSERT_EQUAL(OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMillisecond(), millisecond);
}

void Framework::OpenGLGlutProcessManagerTesting::RenderSceneCallbackSucceedTest()
{
    const auto renderSceneCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetRenderSceneCallback();

    ASSERT_UNEQUAL_NULL_PTR(renderSceneCallback);

    if (renderSceneCallback != nullptr)
    {
        renderSceneCallback();
    }
}

void Framework::OpenGLGlutProcessManagerTesting::ChangeSizeCallbackSucceedTest()
{
    const auto changeSizeCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetChangeSizeCallback();

    ASSERT_UNEQUAL_NULL_PTR(changeSizeCallback);

    if (changeSizeCallback != nullptr)
    {
        changeSizeCallback(0, 0);
    }
}

void Framework::OpenGLGlutProcessManagerTesting::TimerFunctionCallbackSucceedTest()
{
    const auto timerFunctionCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetTimerFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(timerFunctionCallback);

    if (timerFunctionCallback != nullptr)
    {
        timerFunctionCallback(0);
    }
}

void Framework::OpenGLGlutProcessManagerTesting::SpecialKeysDownCallbackSucceedTest()
{
    const auto specialKeysDownCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetSpecialKeysDownCallback();

    ASSERT_UNEQUAL_NULL_PTR(specialKeysDownCallback);

    if (specialKeysDownCallback != nullptr)
    {
        specialKeysDownCallback(0, 0, 0);
    }
}

void Framework::OpenGLGlutProcessManagerTesting::KeyboardDownCallbackSucceedTest()
{
    const auto keyboardDownCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetKeyboardDownCallback();

    ASSERT_UNEQUAL_NULL_PTR(keyboardDownCallback);

    if (keyboardDownCallback != nullptr)
    {
        keyboardDownCallback(0, 0, 0);
    }
}

void Framework::OpenGLGlutProcessManagerTesting::SpecialKeysUpCallbackSucceedTest()
{
    const auto specialKeysUpCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetSpecialKeysUpCallback();

    ASSERT_UNEQUAL_NULL_PTR(specialKeysUpCallback);

    if (specialKeysUpCallback != nullptr)
    {
        specialKeysUpCallback(0, 0, 0);
    }
}

void Framework::OpenGLGlutProcessManagerTesting::KeyboardUpCallbackSucceedTest()
{
    const auto keyboardUpCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetKeyboardUpCallback();

    ASSERT_UNEQUAL_NULL_PTR(keyboardUpCallback);

    if (keyboardUpCallback != nullptr)
    {
        keyboardUpCallback(0, 0, 0);
    }
}

void Framework::OpenGLGlutProcessManagerTesting::MouseFunctionCallbackSucceedTest()
{
    const auto mouseFunctionCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMouseFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(mouseFunctionCallback);

    if (mouseFunctionCallback != nullptr)
    {
        mouseFunctionCallback(0, 0, 0, 0);
    }
}

void Framework::OpenGLGlutProcessManagerTesting::MotionFunctionCallbackSucceedTest()
{
    const auto motionFunctionCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMotionFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(motionFunctionCallback);

    if (motionFunctionCallback != nullptr)
    {
        motionFunctionCallback(0, 0);
    }
}

void Framework::OpenGLGlutProcessManagerTesting::IdleFunctionCallbackSucceedTest()
{
    const auto idleFunctionCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetIdleFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(idleFunctionCallback);

    if (idleFunctionCallback != nullptr)
    {
        idleFunctionCallback();
    }
}

void Framework::OpenGLGlutProcessManagerTesting::ProcessMenuCallbackSucceedTest()
{
    const auto processMenuCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetProcessMenuCallback();

    ASSERT_UNEQUAL_NULL_PTR(processMenuCallback);

    if (processMenuCallback != nullptr)
    {
        processMenuCallback(0);
    }
}

void Framework::OpenGLGlutProcessManagerTesting::TerminateCallbackSucceedTest()
{
    const auto terminateCallback = OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetTerminateCallback();

    ASSERT_UNEQUAL_NULL_PTR(terminateCallback);
}

void Framework::OpenGLGlutProcessManagerTesting::PreCreateSucceedTest()
{
    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.PreCreate();
}

void Framework::OpenGLGlutProcessManagerTesting::InitializeSucceedTest()
{
    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.Initialize();
}

void Framework::OpenGLGlutProcessManagerTesting::PreIdleSucceedTest()
{
    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.PreIdle();
}

void Framework::OpenGLGlutProcessManagerTesting::TerminateSucceedTest()
{
    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.Terminate();
}
