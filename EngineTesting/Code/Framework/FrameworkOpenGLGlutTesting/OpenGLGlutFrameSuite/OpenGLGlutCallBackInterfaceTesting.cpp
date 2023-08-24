///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 18:04)

#include "OpenGLGlutCallBackInterfaceTesting.h"
#include "System/Helper/Helper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"

Framework::OpenGLGlutCallBackInterfaceTesting::OpenGLGlutCallBackInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutCallBackInterfaceTesting)

void Framework::OpenGLGlutCallBackInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::OpenGLGlutCallBackInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InterfaceTest);
}

void Framework::OpenGLGlutCallBackInterfaceTesting::InterfaceTest()
{
    OpenGLGlutCallBackInterface openGLGlutCallBackInterface{ 9 };

    openGLGlutCallBackInterface.SetWindowId(10);
    ASSERT_EQUAL(openGLGlutCallBackInterface.GetWindowId(), 10);

    ASSERT_TRUE(openGLGlutCallBackInterface.RenderScene());
    ASSERT_TRUE(openGLGlutCallBackInterface.ChangeSize(0, 0));
    ASSERT_TRUE(openGLGlutCallBackInterface.TimerFunction(TimerFunction));
    ASSERT_TRUE(openGLGlutCallBackInterface.MotionFunction(0, 0));
    ASSERT_TRUE(openGLGlutCallBackInterface.PassiveMotion(0, 0));
    ASSERT_TRUE(openGLGlutCallBackInterface.MouseClick(0, 0, 0, 0));
    ASSERT_TRUE(openGLGlutCallBackInterface.KeyboardDown(0, 0, 0));
    ASSERT_TRUE(openGLGlutCallBackInterface.KeyboardUp(0, 0, 0));
    ASSERT_TRUE(openGLGlutCallBackInterface.SpecialKeysDown(0, 0, 0));
    ASSERT_TRUE(openGLGlutCallBackInterface.SpecialKeysUp(0, 0, 0));
    ASSERT_TRUE(openGLGlutCallBackInterface.IdleFunction());
    ASSERT_TRUE(openGLGlutCallBackInterface.ProcessMenu(0));
    ASSERT_TRUE(openGLGlutCallBackInterface.PreCreate());
    ASSERT_TRUE(openGLGlutCallBackInterface.Initialize());
    openGLGlutCallBackInterface.PreIdle();
    openGLGlutCallBackInterface.Terminate();
    openGLGlutCallBackInterface.DestroyWindow();

    openGLGlutCallBackInterface.SetMillisecond(10u);
    ASSERT_EQUAL(openGLGlutCallBackInterface.GetMillisecond(), 10);

    ASSERT_EQUAL(openGLGlutCallBackInterface.GetTerminateKey(), GlutApplicationTrait::KeyIdentifiers::keyTerminate);
}
