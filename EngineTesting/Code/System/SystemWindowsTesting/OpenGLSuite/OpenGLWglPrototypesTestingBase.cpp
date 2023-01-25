///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/23 0:04)

#include "OpenGLWglPrototypesTestingBase.h"
#include "System/OpenGL/Flags/OpenGLWglPrototypesFlags.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "System/Windows/WindowsFontInformation.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLWglPrototypesTestingBase::OpenGLWglPrototypesTestingBase(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLWglPrototypesTestingBase)

System::WindowsHWnd System::OpenGLWglPrototypesTestingBase::GetHwnd() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return hwnd;
}

System::WindowsHDC System::OpenGLWglPrototypesTestingBase::GetWindowsDC()
{
    const auto windowsDC = GetSystemDC(hwnd);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(windowsDC, "获取 windowsDC 失败。");

    return windowsDC;
}

void System::OpenGLWglPrototypesTestingBase::ReleaseWindowsDCTest(WindowsHDC windowsDC)
{
    ASSERT_TRUE(ReleaseSystemDC(GetHwnd(), windowsDC));
}

System::OpenGLHglrc System::OpenGLWglPrototypesTestingBase::GetCreateWglContext(WindowsHDC windowsDC)
{
    const auto openGLHglrc = CreateWglContext(windowsDC);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(openGLHglrc, "创建Wgl环境失败。");

    ASSERT_TRUE(MakeWglCurrent(windowsDC, openGLHglrc));

    return openGLHglrc;
}

void System::OpenGLWglPrototypesTestingBase::DeleteWglContextTest(OpenGLHglrc openGLHglrc)
{
    ASSERT_TRUE(DeleteWglContext(openGLHglrc));
}

void System::OpenGLWglPrototypesTestingBase::SetWindowPixelFormatTest(WindowsHDC windowsDC)
{
    PixelFormatDescriptor pixelFormatDescriptor{};
    pixelFormatDescriptor.nSize = sizeof(PixelFormatDescriptor);
    pixelFormatDescriptor.nVersion = 1;
    pixelFormatDescriptor.dwFlags = EnumCastUnderlying(PixelFormatDescriptorFlags::DrawToWindow | PixelFormatDescriptorFlags::SupportOpengl | PixelFormatDescriptorFlags::GenericAccelerated | PixelFormatDescriptorFlags::DoubleBuffer);
    pixelFormatDescriptor.iPixelType = EnumCastUnderlying<uint8_t>(PixelTypes::TypeRGBA);
    pixelFormatDescriptor.cColorBits = colorBits;
    pixelFormatDescriptor.cDepthBits = depthBits;
    pixelFormatDescriptor.cStencilBits = stencilBits;

    const auto pixelFormat = ChooseWindowPixelFormat(windowsDC, &pixelFormatDescriptor);

    ASSERT_TRUE(SetWindowPixelFormat(windowsDC, pixelFormat, &pixelFormatDescriptor));
}
