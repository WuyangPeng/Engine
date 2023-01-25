///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/23 0:05)

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
    const auto windowsDC = GetWindowsDC();

    ASSERT_NOT_THROW_EXCEPTION_1(GetContextTest, windowsDC);

    ASSERT_NOT_THROW_EXCEPTION_1(ReleaseWindowsDCTest, windowsDC);
}

void System::OpenGLSwapDeviceBuffersTesting::GetContextTest(WindowsHDC windowsDC)
{
    ASSERT_NOT_THROW_EXCEPTION_1(SetWindowPixelFormatTest, windowsDC);

    const auto openGLHglrc = GetCreateWglContext(windowsDC);

    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLSwapDeviceBuffersTest, windowsDC);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteWglContextTest, openGLHglrc);
}

void System::OpenGLSwapDeviceBuffersTesting::DoOpenGLSwapDeviceBuffersTest(WindowsHDC windowsDC)
{
    ASSERT_TRUE(OpenGLInit());

    ASSERT_TRUE(DisplayColorBuffer(windowsDC, 0));

    ASSERT_TRUE(SwapDeviceBuffers(windowsDC));
}
