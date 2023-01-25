///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/23 0:05)

#include "OpenGLWglSwapIntervalTesting.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLWglSwapIntervalTesting::OpenGLWglSwapIntervalTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream, hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLWglSwapIntervalTesting)

void System::OpenGLWglSwapIntervalTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLWglSwapIntervalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLWglSwapIntervalTest);
}

void System::OpenGLWglSwapIntervalTesting::OpenGLWglSwapIntervalTest()
{
    const auto windowsDC = GetWindowsDC();

    ASSERT_NOT_THROW_EXCEPTION_1(GetContextTest, windowsDC);

    ASSERT_NOT_THROW_EXCEPTION_1(ReleaseWindowsDCTest, windowsDC);
}

void System::OpenGLWglSwapIntervalTesting::GetContextTest(WindowsHDC windowsDC)
{
    ASSERT_NOT_THROW_EXCEPTION_1(SetWindowPixelFormatTest, windowsDC);

    const auto openGLHglrc = GetCreateWglContext(windowsDC);

    ASSERT_NOT_THROW_EXCEPTION_0(DoOpenGLWglSwapIntervalTest);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteWglContextTest, openGLHglrc);
}

void System::OpenGLWglSwapIntervalTesting::DoOpenGLWglSwapIntervalTest()
{
    ASSERT_TRUE(OpenGLInit());

    const auto interval = GetWglSwapInterval();
    ASSERT_TRUE(IsWglSwapInterval(interval));
}
