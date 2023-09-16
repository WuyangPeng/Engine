///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:49)

#include "OpenGLWglSwapIntervalTesting.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLWglSwapIntervalTesting::OpenGLWglSwapIntervalTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream, hWnd }
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
    const auto windowsDc = GetWindowsDc();

    ASSERT_NOT_THROW_EXCEPTION_1(GetContextTest, windowsDc);

    ASSERT_NOT_THROW_EXCEPTION_1(ReleaseWindowsDcTest, windowsDc);
}

void System::OpenGLWglSwapIntervalTesting::GetContextTest(WindowsHdc windowsDc)
{
    ASSERT_NOT_THROW_EXCEPTION_1(SetWindowPixelFormatTest, windowsDc);

    const auto openGLHglrc = GetCreateWglContext(windowsDc);

    ASSERT_NOT_THROW_EXCEPTION_0(DoOpenGLWglSwapIntervalTest);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteWglContextTest, openGLHglrc);
}

void System::OpenGLWglSwapIntervalTesting::DoOpenGLWglSwapIntervalTest()
{
    ASSERT_TRUE(OpenGLInit());

    const auto interval = GetWglSwapInterval();
    ASSERT_TRUE(IsWglSwapInterval(interval));
}
