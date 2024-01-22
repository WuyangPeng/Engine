///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:48)

#include "OpenGLWglPrototypesTestingBase.h"
#include "System/OpenGL/Flags/OpenGLWglPrototypesFlags.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "System/Windows/WindowsFontInformation.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLWglPrototypesTestingBase::OpenGLWglPrototypesTestingBase(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hWnd{ hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLWglPrototypesTestingBase)

System::WindowsHWnd System::OpenGLWglPrototypesTestingBase::GetHWnd() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return hWnd;
}

System::WindowsHdc System::OpenGLWglPrototypesTestingBase::GetWindowsDc()
{
    const auto windowsDc = GetSystemDC(hWnd);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(windowsDc, "获取 windowsDC 失败。");

    return windowsDc;
}

void System::OpenGLWglPrototypesTestingBase::ReleaseWindowsDcTest(WindowsHdc windowsDc)
{
    ASSERT_TRUE(ReleaseSystemDC(GetHWnd(), windowsDc));
}

System::OpenGLRcHandle System::OpenGLWglPrototypesTestingBase::GetCreateWglContext(WindowsHdc windowsDc)
{
    const auto openGLHglrc = CreateWglContext(windowsDc);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(openGLHglrc, "创建Wgl环境失败。");

    ASSERT_TRUE(MakeWglCurrent(windowsDc, openGLHglrc));

    return openGLHglrc;
}

void System::OpenGLWglPrototypesTestingBase::DeleteWglContextTest(OpenGLRcHandle openGLHglrc)
{
    ASSERT_TRUE(DeleteWglContext(openGLHglrc));
}

void System::OpenGLWglPrototypesTestingBase::SetWindowPixelFormatTest(WindowsHdc windowsDc)
{
    PixelFormatDescriptor pixelFormatDescriptor{};
    pixelFormatDescriptor.nSize = sizeof(PixelFormatDescriptor);
    pixelFormatDescriptor.nVersion = 1;
    pixelFormatDescriptor.dwFlags = EnumCastUnderlying(PixelFormatDescriptorFlags::DrawToWindow | PixelFormatDescriptorFlags::SupportOpengl | PixelFormatDescriptorFlags::GenericAccelerated | PixelFormatDescriptorFlags::DoubleBuffer);
    pixelFormatDescriptor.iPixelType = EnumCastUnderlying<uint8_t>(PixelTypes::TypeRGBA);
    pixelFormatDescriptor.cColorBits = colorBits;
    pixelFormatDescriptor.cDepthBits = depthBits;
    pixelFormatDescriptor.cStencilBits = stencilBits;

    const auto pixelFormat = ChooseWindowPixelFormat(windowsDc, &pixelFormatDescriptor);

    ASSERT_TRUE(SetWindowPixelFormat(windowsDc, pixelFormat, &pixelFormatDescriptor));
}
