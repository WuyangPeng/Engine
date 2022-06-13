///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/16 14:35)

#include "OpenGLWglPrototypesTesting.h"
#include "System/OpenGL/Flags/OpenGLWglPrototypesFlags.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "System/OpenGL/Using/WglExtensionsUsing.h"
#include "System/Windows/WindowsFontInformation.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"

System::OpenGLWglPrototypesTesting::OpenGLWglPrototypesTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLWglPrototypesTesting)

void System::OpenGLWglPrototypesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLWglPrototypesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateWglTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SwapTest);
}

void System::OpenGLWglPrototypesTesting::CreateWglTest()
{
    auto windowsDC = GetSystemDC(hwnd);

    ASSERT_UNEQUAL_NULL_PTR(windowsDC);

    PixelFormatDescriptor pfd{};
    pfd.nSize = sizeof(PixelFormatDescriptor);
    pfd.nVersion = 1;
    pfd.dwFlags = EnumCastUnderlying(PixelFormatDescriptorFlags::DrawToWindow | PixelFormatDescriptorFlags::SupportOpengl | PixelFormatDescriptorFlags::GenericAccelerated | PixelFormatDescriptorFlags::DoubleBuffer);
    pfd.iPixelType = EnumCastUnderlying<uint8_t>(PixelTypes::TypeRGBA);
    pfd.cColorBits = colorBits;
    pfd.cDepthBits = depthBits;
    pfd.cStencilBits = stencilBits;

    const auto pixelFormat = ChooseWindowPixelFormat(windowsDC, &pfd);

    ASSERT_TRUE(SetWindowPixelFormat(windowsDC, pixelFormat, &pfd));

    auto openGLHglrc = CreateWglContext(windowsDC);

    ASSERT_UNEQUAL_NULL_PTR(openGLHglrc);

    ASSERT_TRUE(MakeWglCurrent(windowsDC, openGLHglrc));

    const auto result = GetCurrentWglContext();
    ASSERT_EQUAL(openGLHglrc, result);

    auto address = GetWglProcAddress("glTexImage3D");
    ASSERT_UNEQUAL_NULL_PTR(address);

    ASSERT_TRUE(OpenGLInit());

    const auto interval = GetWglSwapInterval();
    ASSERT_TRUE(IsWglSwapInterval(interval));

    ASSERT_TRUE(DeleteWglContext(openGLHglrc));

    ASSERT_TRUE(ReleaseSystemDC(hwnd, windowsDC));
}

void System::OpenGLWglPrototypesTesting::SwapTest()
{
    auto windowsDC = GetSystemDC(hwnd);

    ASSERT_UNEQUAL_NULL_PTR(windowsDC);

    PixelFormatDescriptor pfd{};
    pfd.nSize = sizeof(PixelFormatDescriptor);
    pfd.nVersion = 1;
    pfd.dwFlags = EnumCastUnderlying(PixelFormatDescriptorFlags::DrawToWindow | PixelFormatDescriptorFlags::SupportOpengl | PixelFormatDescriptorFlags::GenericAccelerated | PixelFormatDescriptorFlags::DoubleBuffer);
    pfd.iPixelType = EnumCastUnderlying<uint8_t>(PixelTypes::TypeRGBA);
    pfd.cColorBits = colorBits;
    pfd.cDepthBits = depthBits;
    pfd.cStencilBits = stencilBits;

    const auto pixelFormat = ChooseWindowPixelFormat(windowsDC, &pfd);

    ASSERT_TRUE(SetWindowPixelFormat(windowsDC, pixelFormat, &pfd));

    auto OpenGLHglrc = CreateWglContext(windowsDC);

    ASSERT_UNEQUAL_NULL_PTR(OpenGLHglrc);

    ASSERT_TRUE(SwapDeviceBuffers(windowsDC));

    ASSERT_TRUE(DeleteWglContext(OpenGLHglrc));

    ASSERT_TRUE(ReleaseSystemDC(hwnd, windowsDC));
}
