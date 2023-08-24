///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 15:06)

#include "Framework/FrameworkExport.h"

#include "WindowApplicationInformation.h"
#include "Detail/WindowApplicationInformationImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Framework, WindowApplicationInformation)

Framework::WindowApplicationInformation::WindowApplicationInformation(const String& windowTitle, const WindowSize& size, const WindowPoint& point, bool allowResize)
    : impl{ windowTitle, size, point, allowResize }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowApplicationInformation::WindowApplicationInformation(const String& windowTitle, const WindowSize& size)
    : impl{ windowTitle, size }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowApplicationInformation::WindowApplicationInformation(WindowsHInstance instance, const RendererParameter& rendererParameter)
    : impl{ instance, rendererParameter }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowApplicationInformation)

Framework::WindowApplicationInformation::String Framework::WindowApplicationInformation::GetWindowTitle() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowTitle();
}

std::string Framework::WindowApplicationInformation::GetWindowTitleWithMultiByte() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowTitleWithMultiByte();
}

int Framework::WindowApplicationInformation::GetXPosition() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetXPosition();
}

int Framework::WindowApplicationInformation::GetYPosition() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetYPosition();
}

int Framework::WindowApplicationInformation::GetWidth() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWidth();
}

int Framework::WindowApplicationInformation::GetHeight() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetHeight();
}

Framework::WindowSize Framework::WindowApplicationInformation::GetWindowSize() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowSize();
}

float Framework::WindowApplicationInformation::GetAspectRatio() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetAspectRatio();
}

Framework::WindowApplicationInformation::WindowStyles Framework::WindowApplicationInformation::GetStyle() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetStyle();
}

void Framework::WindowApplicationInformation::SetWindowSize(const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetWindowSize(size);
}

Framework::WindowName Framework::WindowApplicationInformation::GetWindowName() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowName();
}

Framework::WindowPictorial Framework::WindowApplicationInformation::GetWindowPictorial() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowPictorial();
}
