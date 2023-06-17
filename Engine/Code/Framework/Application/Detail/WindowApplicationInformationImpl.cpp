///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:49)

#include "Framework/FrameworkExport.h"

#include "WindowApplicationInformationImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/Renderers/RendererParameter.h"

Framework::WindowApplicationInformationImpl::WindowApplicationInformationImpl(const String& windowTitle, const WindowSize& size, const WindowPoint& point, bool allowResize)
    : windowTitle{ windowTitle },
      size{ size },
      position{ point },
      style{ allowResize ?
                 WindowsStyles::Default :
                 // 这里删除 WS_THICKFRAME 和 WS_MAXIMIZEBOX,它们都允许调整窗口的大小
                 WindowsStyles::Overlapped | WindowsStyles::Caption | WindowsStyles::SysMenu | WindowsStyles::MinimizeBox | WindowsStyles::Visible },
      windowName{ SYSTEM_TEXT("Window") },
      windowPictorial{ System::WindowsBrushTypes::WhiteBrush }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowApplicationInformationImpl::WindowApplicationInformationImpl(const String& windowTitle, const WindowSize& size)
    : WindowApplicationInformationImpl{ windowTitle, size, WindowPoint{}, true }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowApplicationInformationImpl::WindowApplicationInformationImpl(WindowsHInstance instance, const RendererParameter& rendererParameter)
    : windowTitle{ CoreTools::StringConversion::MultiByteConversionStandard(rendererParameter.GetWindowTitle()) },
      size{ rendererParameter.GetWidth(), rendererParameter.GetHeight() },
      position{ rendererParameter.GetXPosition(), rendererParameter.GetYPosition() },
      style{ rendererParameter.IsAllowResize() ?
                 WindowsStyles::Default :
                 // 这里删除 WS_THICKFRAME 和 WS_MAXIMIZEBOX,它们都允许调整窗口的大小
                 WindowsStyles::Overlapped | WindowsStyles::Caption | WindowsStyles::SysMenu | WindowsStyles::MinimizeBox | WindowsStyles::Visible },
      windowName{ rendererParameter.GetWindowClassName(), rendererParameter.GetWindowMenuName() },
      windowPictorial{ GetWindowPictorial(instance, rendererParameter) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
Framework::WindowPictorial Framework::WindowApplicationInformationImpl::GetWindowPictorial(WindowsHInstance instance, const RendererParameter& rendererParameter)
{
    const auto icon = rendererParameter.GetIcon();
    const auto isIconDefault = rendererParameter.IsIconDefault();
    const auto cursor = rendererParameter.GetCursor();
    const auto isCursorDefault = rendererParameter.IsCursorDefault();
    const auto windowBrushTypes = rendererParameter.GetBackground();

    return WindowPictorial{ instance, isIconDefault, icon, isCursorDefault, cursor, windowBrushTypes };
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowApplicationInformationImpl)

System::String Framework::WindowApplicationInformationImpl::GetWindowTitle() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowTitle;
}

int Framework::WindowApplicationInformationImpl::GetXPosition() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return position.GetWindowX();
}

int Framework::WindowApplicationInformationImpl::GetYPosition() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return position.GetWindowY();
}

int Framework::WindowApplicationInformationImpl::GetWidth() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return size.GetWindowWidth();
}

int Framework::WindowApplicationInformationImpl::GetHeight() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return size.GetWindowHeight();
}

float Framework::WindowApplicationInformationImpl::GetAspectRatio() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    const auto height = GetHeight();

    if (height != 0)
        return GetWidth() / static_cast<float>(height);
    else
        return 0.0f;
}

std::string Framework::WindowApplicationInformationImpl::GetWindowTitleWithMultiByte() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return CoreTools::StringConversion::StandardConversionMultiByte(windowTitle);
}

Framework::WindowSize Framework::WindowApplicationInformationImpl::GetWindowSize() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return size;
}

System::WindowsStyles Framework::WindowApplicationInformationImpl::GetStyle() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return style;
}

void Framework::WindowApplicationInformationImpl::SetWindowSize(const WindowSize& aSize) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    size = aSize;
}

Framework::WindowName Framework::WindowApplicationInformationImpl::GetWindowName() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowName;
}

Framework::WindowPictorial Framework::WindowApplicationInformationImpl::GetWindowPictorial() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowPictorial;
}
