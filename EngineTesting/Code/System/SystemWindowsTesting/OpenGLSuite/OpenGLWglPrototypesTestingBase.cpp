/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:14)

#include "OpenGLWglPrototypesTestingBase.h"
#include "System/OpenGL/Flags/OpenGLWglPrototypesFlags.h"
#include "System/OpenGL/OpenGLWglPrototypes.h"
#include "System/Windows/WindowsFontInformation.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLWglPrototypesTestingBase::OpenGLWglPrototypesTestingBase(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
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

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(windowsDc, "��ȡ windowsDC ʧ�ܡ�");

    return windowsDc;
}

void System::OpenGLWglPrototypesTestingBase::ReleaseWindowsDcTest(WindowsHdc windowsDc)
{
    ASSERT_TRUE(ReleaseSystemDC(GetHWnd(), windowsDc));
}

System::OpenGLRcHandle System::OpenGLWglPrototypesTestingBase::GetCreateWglContext(WindowsHdc windowsDc)
{
    const auto context = CreateWglContext(windowsDc);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(context, "����Wgl����ʧ�ܡ�");

    ASSERT_TRUE(MakeWglCurrent(windowsDc, context));

    return context;
}

void System::OpenGLWglPrototypesTestingBase::DeleteWglContextTest(OpenGLRcHandle openGLRcHandle)
{
    ASSERT_TRUE(DeleteWglContext(openGLRcHandle));
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
