// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:19)

#include "Framework/FrameworkExport.h"

#include "WindowApplicationInformationImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::string;

Framework::WindowApplicationInformationImpl
	::WindowApplicationInformationImpl( const System::String& windowTitle,const WindowSize& size, const WindowPoint& point,bool allowResize)
	:m_WindowTitle(windowTitle),
	 m_Size(size),m_Position(point),
	 m_Style(allowResize ? System::WindowStyles::Default : 
	         // 这里删除 WS_THICKFRAME 和 WS_MAXIMIZEBOX,它们都允许调整窗口的大小
			 System::WindowStyles::Overlapped | System::WindowStyles::Caption | System::WindowStyles::SysMenu | System::WindowStyles::MinimizeBox | System::WindowStyles::Visible)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowApplicationInformationImpl
	::WindowApplicationInformationImpl( const System::String& windowTitle,  const WindowSize& size )
    :m_WindowTitle(windowTitle),
	 m_Size(size),m_Position(),
	 m_Style(System::WindowStyles::Default)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,WindowApplicationInformationImpl)

const System::String& Framework::WindowApplicationInformationImpl
	::GetWindowTitle() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowTitle;
}

int Framework::WindowApplicationInformationImpl
	::GetXPosition() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Position.GetWindowX();
}

int Framework::WindowApplicationInformationImpl
	::GetYPosition() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Position.GetWindowY();
}

int Framework::WindowApplicationInformationImpl
	::GetWidth() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Size.GetWindowWidth();
}

int Framework::WindowApplicationInformationImpl
	::GetHeight() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Size.GetWindowHeight();
}

float Framework::WindowApplicationInformationImpl
	::GetAspectRatio() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	int height = GetHeight();

	if(height != 0)
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
	::GetWindowSize() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9; 

	return m_Size;
}

System::WindowStyles Framework::WindowApplicationInformationImpl
	::GetStyle() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9; 
	
	return m_Style;
}

void Framework::WindowApplicationInformationImpl
	::SetWindowSize(const WindowSize& size)
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9; 
	
	m_Size = size;
}

