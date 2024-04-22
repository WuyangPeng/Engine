/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:13)

#include "OpenGLGetCurrentWglContextTesting.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLGetCurrentWglContextTesting::OpenGLGetCurrentWglContextTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream, hWnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGetCurrentWglContextTesting)

void System::OpenGLGetCurrentWglContextTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGetCurrentWglContextTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetCurrentWglContextTest);
}

void System::OpenGLGetCurrentWglContextTesting::OpenGLGetCurrentWglContextTest()
{
    const auto windowsDC = GetWindowsDc();

    ASSERT_NOT_THROW_EXCEPTION_1(GetContextTest, windowsDC);

    ASSERT_NOT_THROW_EXCEPTION_1(ReleaseWindowsDcTest, windowsDC);
}

void System::OpenGLGetCurrentWglContextTesting::GetContextTest(WindowsHdc windowsDc)
{
    ASSERT_NOT_THROW_EXCEPTION_1(SetWindowPixelFormatTest, windowsDc);

    const auto openGLRcHandle = GetCreateWglContext(windowsDc);

    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLGetCurrentWglContextTest, openGLRcHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteWglContextTest, openGLRcHandle);
}

void System::OpenGLGetCurrentWglContextTesting::DoOpenGLGetCurrentWglContextTest(OpenGLRcHandle openGLRcHandle)
{
    ASSERT_TRUE(OpenGLInit());

    const auto currentWglContext = GetCurrentWglContext();
    ASSERT_EQUAL(openGLRcHandle, currentWglContext);
}
