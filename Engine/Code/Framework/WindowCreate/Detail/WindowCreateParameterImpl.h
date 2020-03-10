// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:36)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_IMPL_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_IMPL_H

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Flags/WindowFlags.h"
#include "Framework/WindowCreate/WindowPoint.h"

#include <string>

namespace Framework
{
	class WindowCreateParameterImpl
	{
	public:
		using ClassType = WindowCreateParameterImpl;
        using WindowStylesFlags = System::WindowStyles;
        using HWnd = System::WindowHWnd;
        using HMenu = System::WindowHMenu;

	public:
		WindowCreateParameterImpl(const System::String& windowsName,WindowStylesFlags style, HWnd parent, HMenu menu,const WindowPoint& leftTopCorner);		
		
		CLASS_INVARIANT_DECLARE;

		System::String GetWindowsName() const;
	    WindowStylesFlags GetStyle() const;
		WindowPoint GetLeftTopCorner() const;
		HWnd GetParent() const;
		HMenu GetMenu() const;

	private:	
		System::String m_WindowsName;	
		WindowStylesFlags m_Style;	
		WindowPoint m_LeftTopCorner;
		HWnd m_Parent;
		HMenu m_Menu;		
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_IMPL_H