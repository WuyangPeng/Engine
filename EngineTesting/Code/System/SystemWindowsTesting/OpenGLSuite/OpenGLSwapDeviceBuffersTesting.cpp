///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:48)

#include "OpenGLSwapDeviceBuffersTesting.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLSwapDeviceBuffersTesting::OpenGLSwapDeviceBuffersTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream, hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLSwapDeviceBuffersTesting)

void System::OpenGLSwapDeviceBuffersTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLSwapDeviceBuffersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLSwapDeviceBuffersTest);
}

void System::OpenGLSwapDeviceBuffersTesting::OpenGLSwapDeviceBuffersTest()
{
    const auto windowsDc = GetWindowsDc();

    ASSERT_NOT_THROW_EXCEPTION_1(GetContextTest, windowsDc);

    ASSERT_NOT_THROW_EXCEPTION_1(ReleaseWindowsDcTest, windowsDc);
}

void System::OpenGLSwapDeviceBuffersTesting::GetContextTest(WindowsHdc windowsDc)
{
    ASSERT_NOT_THROW_EXCEPTION_1(SetWindowPixelFormatTest, windowsDc);

    const auto openGLHglrc = GetCreateWglContext(windowsDc);

    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLSwapDeviceBuffersTest, windowsDc);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteWglContextTest, openGLHglrc);
}

void System::OpenGLSwapDeviceBuffersTesting::DoOpenGLSwapDeviceBuffersTest(WindowsHdc windowsDc)
{
    ASSERT_TRUE(OpenGLInit());

    ASSERT_TRUE(DisplayColorBuffer(windowsDc, 0));

    ASSERT_TRUE(SwapDeviceBuffers(windowsDc));
}
