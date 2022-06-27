///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 15:21)

#include "OpenGLGlutProcessTesting.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"

Framework::OpenGLGlutProcessOpenGLGlutCallBack::OpenGLGlutProcessOpenGLGlutCallBack() noexcept
    : ParentType{ System::g_Microseconds / 60 }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutProcessOpenGLGlutCallBack);

namespace Framework
{
    template <>
    OpenGLGlutProcess<Framework::OpenGLGlutProcessOpenGLGlutCallBack>::OpenGLGlutProcess(MAYBE_UNUSED int64_t delta)
    {
        CoreTools::DisableNoexcept();

        FRAMEWORK_SELF_CLASS_IS_VALID_9;
    }
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Framework, OpenGLGlutProcessTesting)

void Framework::OpenGLGlutProcessTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetWindowIDSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMillisecondSucceedTest);
}

void Framework::OpenGLGlutProcessTesting::SetWindowIDSucceedTest()
{
    OpenGLGlutProcess<OpenGLGlutProcessOpenGLGlutCallBack> process{ System::g_Microseconds / 60 };

    const int window(process.GetWindowID());

    process.SetWindowID(window);
}

void Framework::OpenGLGlutProcessTesting::CallbackSucceedTest()
{
    OpenGLGlutProcess<OpenGLGlutProcessOpenGLGlutCallBack> process{ System::g_Microseconds / 60 };

    ASSERT_TRUE(process.PreCreate());
    ASSERT_TRUE(process.Initialize());
    process.PreIdle();
    process.Terminate();

    OpenGLGlutProcessManager::RenderSceneCallback renderScenePtr = process.GetRenderSceneCallback();

    ASSERT_UNEQUAL_NULL_PTR(renderScenePtr);

    if (renderScenePtr != nullptr)
        renderScenePtr();

    OpenGLGlutProcessManager::ChangeSizeCallback changeSizePtr = process.GetChangeSizeCallback();

    ASSERT_UNEQUAL_NULL_PTR(changeSizePtr);

    if (changeSizePtr != nullptr)
        changeSizePtr(0, 0);

    OpenGLGlutProcessManager::TimerFunctionCallback timerFunctionPtr = process.GetTimerFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(timerFunctionPtr);

    if (timerFunctionPtr != nullptr)
        timerFunctionPtr(0);

    OpenGLGlutProcessManager::SpecialKeysDownCallback specialKeysPtr = process.GetSpecialKeysDownCallback();

    ASSERT_UNEQUAL_NULL_PTR(specialKeysPtr);

    if (specialKeysPtr != nullptr)
        specialKeysPtr(0, 0, 0);

    OpenGLGlutProcessManager::KeyboardDownCallback keyboardPtr = process.GetKeyboardDownCallback();

    ASSERT_UNEQUAL_NULL_PTR(keyboardPtr);

    if (keyboardPtr != nullptr)
        keyboardPtr(0, 0, 0);

    OpenGLGlutProcessManager::SpecialKeysUpCallback specialKeysUpPtr = process.GetSpecialKeysUpCallback();

    ASSERT_UNEQUAL_NULL_PTR(specialKeysUpPtr);

    if (specialKeysUpPtr != nullptr)
        specialKeysUpPtr(0, 0, 0);

    OpenGLGlutProcessManager::KeyboardUpCallback keyboardUpPtr = process.GetKeyboardUpCallback();

    ASSERT_UNEQUAL_NULL_PTR(keyboardUpPtr);

    if (keyboardUpPtr != nullptr)
        keyboardUpPtr(0, 0, 0);

    OpenGLGlutProcessManager::MouseFunctionCallback mouseFunctionPtr = process.GetMouseFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(mouseFunctionPtr);

    if (mouseFunctionPtr != nullptr)
        mouseFunctionPtr(0, 0, 0, 0);

    OpenGLGlutProcessManager::MotionFunctionCallback motionFunctionPtr = process.GetMotionFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(motionFunctionPtr);

    if (motionFunctionPtr != nullptr)
        motionFunctionPtr(0, 0);

    OpenGLGlutProcessManager::PassiveMotionFunctionCallback passiveFunctionPtr = process.GetPassiveMotionCallback();

    ASSERT_UNEQUAL_NULL_PTR(passiveFunctionPtr);

    if (passiveFunctionPtr != nullptr)
        passiveFunctionPtr(0, 0);

    OpenGLGlutProcessManager::IdleFunctionCallback idleFunction = process.GetIdleFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(idleFunction);

    if (idleFunction != nullptr)
        idleFunction();

    OpenGLGlutProcessManager::ProcessMenuCallback processMenuFunction = process.GetProcessMenuCallback();

    ASSERT_UNEQUAL_NULL_PTR(processMenuFunction);

    if (processMenuFunction != nullptr)
        processMenuFunction(0);

    OpenGLGlutProcessManager::TerminateCallback terminateFunction = process.GetTerminateCallback();

    ASSERT_UNEQUAL_NULL_PTR(terminateFunction);
}

void Framework::OpenGLGlutProcessTesting::SetMillisecondSucceedTest()
{
    OpenGLGlutProcess<OpenGLGlutProcessOpenGLGlutCallBack> process{ System::g_Microseconds / 60 };

    constexpr auto millisecond = 17;

    process.SetMillisecond(millisecond);

    ASSERT_EQUAL(process.GetMillisecond(), millisecond);
}
