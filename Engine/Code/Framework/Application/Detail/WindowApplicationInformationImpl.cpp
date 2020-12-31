// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:55)

#include "Framework/FrameworkExport.h"

#include "WindowApplicationInformationImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/Renderers/RendererParameter.h"

using std::string;

Framework::WindowApplicationInformationImpl
	::WindowApplicationInformationImpl(const String& windowTitle, const WindowSize& size, const WindowPoint& point, bool allowResize)
	:m_WindowTitle{ windowTitle }, m_Size{ size }, m_Position{ point },
	 m_Style{ allowResize ? WindowStyles::Default :
	          // 这里删除 WS_THICKFRAME 和 WS_MAXIMIZEBOX,它们都允许调整窗口的大小
	          WindowStyles::Overlapped | WindowStyles::Caption | WindowStyles::SysMenu | WindowStyles::MinimizeBox | WindowStyles::Visible },
	 m_WindowName{ SYSTEM_TEXT("Window") }, m_WindowPictorial{ System::WindowBrushTypes::WhiteBrush }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowApplicationInformationImpl
	::WindowApplicationInformationImpl(const String& windowTitle, const WindowSize& size)
	:WindowApplicationInformationImpl{ windowTitle,size,WindowPoint{ },true }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowApplicationInformationImpl
	::WindowApplicationInformationImpl(HInstance instance, const RendererParameter& rendererParameter)
	:m_WindowTitle{ CoreTools::StringConversion::MultiByteConversionStandard(rendererParameter.GetWindowTitle()) },
	 m_Size{ rendererParameter.GetWidth(),rendererParameter.GetHeight() },
	 m_Position{ rendererParameter.GetXPosition(),rendererParameter.GetYPosition() },
	 m_Style{ rendererParameter.IsAllowResize() ? WindowStyles::Default :
			  // 这里删除 WS_THICKFRAME 和 WS_MAXIMIZEBOX,它们都允许调整窗口的大小
			  WindowStyles::Overlapped | WindowStyles::Caption | WindowStyles::SysMenu | WindowStyles::MinimizeBox | WindowStyles::Visible },
	 m_WindowName{ rendererParameter.GetWindowClassName(),rendererParameter.GetWindowMenuName() },
	 m_WindowPictorial{ GetWindowPictorial(instance,rendererParameter) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
Framework::WindowPictorial Framework::WindowApplicationInformationImpl
	::GetWindowPictorial(HInstance instance, const RendererParameter& rendererParameter)
{
	const auto icon = rendererParameter.GetIcon();
	const auto isIconDefault = rendererParameter.IsIconDefault();
	const auto cursor = rendererParameter.GetCursor();
	const auto isCursorDefault = rendererParameter.IsCursorDefault();
	const auto windowBrushTypes = rendererParameter.GetBackground();

	return WindowPictorial{ instance, isIconDefault,icon,isCursorDefault,cursor,windowBrushTypes };
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowApplicationInformationImpl)

const System::String Framework::WindowApplicationInformationImpl
	::GetWindowTitle() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowTitle;
}

int Framework::WindowApplicationInformationImpl
	::GetXPosition() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Position.GetWindowX();
}

int Framework::WindowApplicationInformationImpl
	::GetYPosition() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Position.GetWindowY();
}

int Framework::WindowApplicationInformationImpl
	::GetWidth() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Size.GetWindowWidth();
}

int Framework::WindowApplicationInformationImpl
	::GetHeight() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Size.GetWindowHeight();
}

float Framework::WindowApplicationInformationImpl
	::GetAspectRatio() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	const auto height = GetHeight();

	if (height != 0)
		return GetWidth() / static_cast<float>(height);
	else
		return 0.0f;
}

const string Framework::WindowApplicationInformationImpl
	::GetWindowTitleWithMultiByte() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return CoreTools::StringConversion::StandardConversionMultiByte(m_WindowTitle);
}

const Framework::WindowSize Framework::WindowApplicationInformationImpl
	::GetWindowSize() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Size;
}

System::WindowStyles Framework::WindowApplicationInformationImpl
	::GetStyle() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Style;
}

void Framework::WindowApplicationInformationImpl
	::SetWindowSize(const WindowSize& size) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	m_Size = size;
}

Framework::WindowName Framework::WindowApplicationInformationImpl
	::GetWindowName() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowName;
}

Framework::WindowPictorial Framework::WindowApplicationInformationImpl
	::GetWindowPictorial() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowPictorial;
}

