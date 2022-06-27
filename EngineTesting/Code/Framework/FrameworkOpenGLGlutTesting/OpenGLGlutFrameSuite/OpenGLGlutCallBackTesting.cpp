///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 15:45)

#include "OpenGLGlutCallBackTesting.h"
#include "System/Helper/Helper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Framework, OpenGLGlutCallBackTesting)

void Framework::OpenGLGlutCallBackTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InterfaceTest);
}

void Framework::OpenGLGlutCallBackTesting::InterfaceTest()
{
    OpenGLGlutCallBack<MiddleLayerInterface> openGLGlutCallBack(9);

    openGLGlutCallBack.SetWindowID(10);
    ASSERT_EQUAL(openGLGlutCallBack.GetWindowID(), 10);

    ASSERT_TRUE(openGLGlutCallBack.RenderScene());
    ASSERT_TRUE(openGLGlutCallBack.ChangeSize(0, 0));
    ASSERT_TRUE(openGLGlutCallBack.TimerFunction(TimerFunction));
    ASSERT_TRUE(openGLGlutCallBack.MotionFunction(0, 0));
    ASSERT_TRUE(openGLGlutCallBack.PassiveMotion(0, 0));
    ASSERT_TRUE(openGLGlutCallBack.KeyboardDown(0, 0, 0));
    ASSERT_TRUE(openGLGlutCallBack.KeyboardUp(0, 0, 0));
    ASSERT_TRUE(openGLGlutCallBack.SpecialKeysDown(0, 0, 0));
    ASSERT_TRUE(openGLGlutCallBack.SpecialKeysUp(0, 0, 0));
    ASSERT_TRUE(openGLGlutCallBack.IdleFunction());
    ASSERT_TRUE(openGLGlutCallBack.ProcessMenu(0));
    ASSERT_TRUE(openGLGlutCallBack.PreCreate());
    ASSERT_TRUE(openGLGlutCallBack.Initialize());
    openGLGlutCallBack.PreIdle();
    openGLGlutCallBack.Terminate();
    openGLGlutCallBack.DestroyWindow();

    openGLGlutCallBack.SetMillisecond(10u);
    ASSERT_EQUAL(openGLGlutCallBack.GetMillisecond(), 10);

    ASSERT_EQUAL(openGLGlutCallBack.GetTerminateKey(), GlutApplicationTrait::KeyIdentifiers::keyTerminate);
}

void Framework::OpenGLGlutCallBackTesting::TimerFunction(MAYBE_UNUSED int value) noexcept
{
}
