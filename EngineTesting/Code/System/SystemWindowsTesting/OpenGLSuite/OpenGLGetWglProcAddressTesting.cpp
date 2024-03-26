/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:13)

#include "OpenGLGetWglProcAddressTesting.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLGetWglProcAddressTesting::OpenGLGetWglProcAddressTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream, hWnd }
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
    const auto windowsDc = GetWindowsDc();

    ASSERT_NOT_THROW_EXCEPTION_1(GetContextTest, windowsDc);

    ASSERT_NOT_THROW_EXCEPTION_1(ReleaseWindowsDcTest, windowsDc);
}

void System::OpenGLGetWglProcAddressTesting::GetContextTest(WindowsHdc windowsDc)
{
    ASSERT_NOT_THROW_EXCEPTION_1(SetWindowPixelFormatTest, windowsDc);

    const auto openGLRcHandle = GetCreateWglContext(windowsDc);

    ASSERT_NOT_THROW_EXCEPTION_0(DoOpenGLGetWglProcAddressTest);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteWglContextTest, openGLRcHandle);
}

void System::OpenGLGetWglProcAddressTesting::DoOpenGLGetWglProcAddressTest()
{
    ASSERT_TRUE(OpenGLInit());

    const auto address = GetWglProcAddress("glTexImage3D");
    ASSERT_UNEQUAL_NULL_PTR(address);
}
