// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 11:52)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_IMPL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "Framework/WindowRegister/WindowHIcon.h"
#include "Framework/WindowRegister/WindowHCursor.h"
#include "Framework/WindowRegister/WindowRegisterFwd.h"

#include <memory>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowPictorialImpl
	{
	public:
		using ClassType = WindowPictorialImpl;
		using TChar = System::TChar;
		using HIcon = System::WindowsHIcon;
		using HBrush = System::WindowsHBrush;
		using HCursor = System::WindowsHCursor;
		using HInstance = System::WindowsHInstance;
		using WindowBrushTypes = System::WindowsBrushTypes;

	public:
		explicit WindowPictorialImpl(WindowBrushTypes background);
		WindowPictorialImpl(const TChar* icon, const TChar* cursor, WindowBrushTypes background);
		WindowPictorialImpl(HInstance instance, int icon, int cursor, WindowBrushTypes background);
		WindowPictorialImpl(HInstance instance, int icon, const TChar* cursor, WindowBrushTypes background);
		WindowPictorialImpl(HInstance instance, const TChar* icon, int cursor, WindowBrushTypes background);
		WindowPictorialImpl(HInstance instance, bool isDefaultIcon, int icon, bool isDefaultCursor, int cursor, WindowBrushTypes background);

		CLASS_INVARIANT_DECLARE;

		HIcon GetHIcon() const noexcept;
		HCursor GetHCursor() const noexcept;
		HBrush GetHBrush() const noexcept;	 

	private:
		using WindowHBrushUniquePtr = std::unique_ptr<WindowHBrush>;
		
	private:
		static WindowHBrushUniquePtr CreateWindowsHBrush(WindowBrushTypes background);		

	private:
		WindowHIcon m_WindowsHIcon;
		WindowHCursor m_WindowsHCursor;
		WindowHBrushUniquePtr m_WindowsHBrush;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_IMPL_H
