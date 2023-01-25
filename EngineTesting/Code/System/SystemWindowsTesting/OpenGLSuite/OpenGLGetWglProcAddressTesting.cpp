///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/23 0:05)

#include "OpenGLGetWglProcAddressTesting.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLGetWglProcAddressTesting::OpenGLGetWglProcAddressTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream, hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGetWglProcAddressTesting)

void System::OpenGLGetWglProcAddressTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGetWglProcAddressTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetWglProcAddressTest);
}

void System::OpenGLGetWglProcAddressTesting::OpenGLGetWglProcAddressTest()
{
    const auto windowsDC = GetWindowsDC();

    ASSERT_NOT_THROW_EXCEPTION_1(GetContextTest, windowsDC);

    ASSERT_NOT_THROW_EXCEPTION_1(ReleaseWindowsDCTest, windowsDC);
}

void System::OpenGLGetWglProcAddressTesting::GetContextTest(WindowsHDC windowsDC)
{
    ASSERT_NOT_THROW_EXCEPTION_1(SetWindowPixelFormatTest, windowsDC);

    const auto openGLHglrc = GetCreateWglContext(windowsDC);

    ASSERT_NOT_THROW_EXCEPTION_0(DoOpenGLGetWglProcAddressTest);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteWglContextTest, openGLHglrc);
}

void System::OpenGLGetWglProcAddressTesting::DoOpenGLGetWglProcAddressTest()
{
    ASSERT_TRUE(OpenGLInit());

    const auto address = GetWglProcAddress("glTexImage3D");
    ASSERT_UNEQUAL_NULL_PTR(address);
}
