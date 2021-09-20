// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 09:44)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_IMPL_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "Framework/WindowCreate/WindowPoint.h"

#include <string>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowCreateParameterImpl
	{
	public:
		using ClassType = WindowCreateParameterImpl;
		using String = System::String;
		using HWnd = System::WindowsHWnd;
		using HMenu = System::WindowsHMenu;
		using WindowStyles = System::WindowsStyles;

	public:
		WindowCreateParameterImpl(const String& windowsName, WindowStyles style, HWnd parent, HMenu menu, const WindowPoint& leftTopCorner);

		CLASS_INVARIANT_DECLARE;

		const String GetWindowsName() const;
		WindowStyles GetStyle() const noexcept;
		const WindowPoint GetLeftTopCorner() const noexcept;
		HWnd GetParent() const noexcept;
		HMenu GetMenu() const noexcept;

	private:
		String m_WindowsName;
		WindowStyles m_Style;
		WindowPoint m_LeftTopCorner;
		HWnd m_Parent;
		HMenu m_Menu;
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_IMPL_H