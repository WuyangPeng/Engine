///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 18:10)

#include "OpenGLGlutProcessOpenGLGlutCallBack.h"
#include "OpenGLGlutProcessTesting.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"

Framework::OpenGLGlutProcessTesting::OpenGLGlutProcessTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutProcessTesting)

void Framework::OpenGLGlutProcessTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::OpenGLGlutProcessTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetWindowIdSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CallbackSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMillisecondSucceedTest);
}

void Framework::OpenGLGlutProcessTesting::SetWindowIdSucceedTest()
{
    OpenGLGlutProcess<OpenGLGlutProcessOpenGLGlutCallBack> process{ System::gMicroseconds / 60 };

    const auto window = process.GetWindowId();

    process.SetWindowId(window);
}

void Framework::OpenGLGlutProcessTesting::CallbackSucceedTest()
{
    OpenGLGlutProcess<OpenGLGlutProcessOpenGLGlutCallBack> process{ System::gMicroseconds / 60 };

    ASSERT_TRUE(process.PreCreate());
    ASSERT_TRUE(process.Initialize());
    process.PreIdle();
    process.Terminate();

    const auto renderSceneCallback = process.GetRenderSceneCallback();

    ASSERT_UNEQUAL_NULL_PTR(renderSceneCallback);

    if (renderSceneCallback != nullptr)
    {
        renderSceneCallback();
    }

    const auto changeSizeCallback = process.GetChangeSizeCallback();

    ASSERT_UNEQUAL_NULL_PTR(changeSizeCallback);

    if (changeSizeCallback != nullptr)
    {
        changeSizeCallback(0, 0);
    }

    const auto timerFunctionCallback = process.GetTimerFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(timerFunctionCallback);

    if (timerFunctionCallback != nullptr)
    {
        timerFunctionCallback(0);
    }

    const auto specialKeysDownCallback = process.GetSpecialKeysDownCallback();

    ASSERT_UNEQUAL_NULL_PTR(specialKeysDownCallback);

    if (specialKeysDownCallback != nullptr)
    {
        specialKeysDownCallback(0, 0, 0);
    }

    const auto keyboardDownCallback = process.GetKeyboardDownCallback();

    ASSERT_UNEQUAL_NULL_PTR(keyboardDownCallback);

    if (keyboardDownCallback != nullptr)
    {
        keyboardDownCallback(0, 0, 0);
    }

    const auto specialKeysUpCallback = process.GetSpecialKeysUpCallback();

    ASSERT_UNEQUAL_NULL_PTR(specialKeysUpCallback);

    if (specialKeysUpCallback != nullptr)
    {
        specialKeysUpCallback(0, 0, 0);
    }

    const auto keyboardUpCallback = process.GetKeyboardUpCallback();

    ASSERT_UNEQUAL_NULL_PTR(keyboardUpCallback);

    if (keyboardUpCallback != nullptr)
    {
        keyboardUpCallback(0, 0, 0);
    }

    const auto mouseFunctionCallback = process.GetMouseFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(mouseFunctionCallback);

    if (mouseFunctionCallback != nullptr)
    {
        mouseFunctionCallback(0, 0, 0, 0);
    }

    const auto motionFunctionCallback = process.GetMotionFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(motionFunctionCallback);

    if (motionFunctionCallback != nullptr)
    {
        motionFunctionCallback(0, 0);
    }

    const auto passiveMotionFunctionCallback = process.GetPassiveMotionCallback();

    ASSERT_UNEQUAL_NULL_PTR(passiveMotionFunctionCallback);

    if (passiveMotionFunctionCallback != nullptr)
    {
        passiveMotionFunctionCallback(0, 0);
    }

    const auto idleFunctionCallback = process.GetIdleFunctionCallback();

    ASSERT_UNEQUAL_NULL_PTR(idleFunctionCallback);

    if (idleFunctionCallback != nullptr)
    {
        idleFunctionCallback();
    }

    const auto processMenuCallback = process.GetProcessMenuCallback();

    ASSERT_UNEQUAL_NULL_PTR(processMenuCallback);

    if (processMenuCallback != nullptr)
    {
        processMenuCallback(0);
    }

    const auto terminateCallback = process.GetTerminateCallback();

    ASSERT_UNEQUAL_NULL_PTR(terminateCallback);
}

void Framework::OpenGLGlutProcessTesting::SetMillisecondSucceedTest()
{
    OpenGLGlutProcess<OpenGLGlutProcessOpenGLGlutCallBack> process{ System::gMicroseconds / 60 };

    constexpr auto millisecond = 17;

    process.SetMillisecond(millisecond);

    ASSERT_EQUAL(process.GetMillisecond(), millisecond);
}
