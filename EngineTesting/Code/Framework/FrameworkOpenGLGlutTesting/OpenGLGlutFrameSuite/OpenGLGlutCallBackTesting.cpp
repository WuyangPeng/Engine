///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 18:05)

#include "OpenGLGlutCallBackTesting.h"
#include "System/Helper/Helper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackDetail.h"

Framework::OpenGLGlutCallBackTesting::OpenGLGlutCallBackTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutCallBackTesting)

void Framework::OpenGLGlutCallBackTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::OpenGLGlutCallBackTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InterfaceTest);
}

void Framework::OpenGLGlutCallBackTesting::InterfaceTest()
{
    OpenGLGlutCallBack<MiddleLayerInterface> openGLGlutCallBack{ 9, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    openGLGlutCallBack.SetWindowId(10);
    ASSERT_EQUAL(openGLGlutCallBack.GetWindowId(), 10);

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
