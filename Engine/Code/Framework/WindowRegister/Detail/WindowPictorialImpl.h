// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:40)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_IMPL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Window/Flags/WindowPictorialFlags.h"
#include "Framework/WindowRegister/WindowHIcon.h"
#include "Framework/WindowRegister/WindowHCursor.h"

#include <boost/shared_ptr.hpp>

namespace Framework
{
	class WindowHBrush;

	class FRAMEWORK_HIDDEN_DECLARE WindowPictorialImpl
	{
	public:
		using ClassType = WindowPictorialImpl;
		using HInstance = System::WindowHInstance;
		using HIcon = System::WindowHIcon;
		using HCursor = System::WindowHCursor;
		using HBrush = System::WindowHBrush;

	public:
		explicit WindowPictorialImpl(System::WindowBrushTypes background);
		WindowPictorialImpl(const System::TChar* icon,const System::TChar* cursor,System::WindowBrushTypes background);
		WindowPictorialImpl(HInstance hInstance,int icon,int cursor,System::WindowBrushTypes background);
		WindowPictorialImpl(HInstance hInstance,int icon,const System::TChar* cursor,System::WindowBrushTypes background);
		WindowPictorialImpl(HInstance hInstance,const System::TChar* icon,int cursor,System::WindowBrushTypes background);

		CLASS_INVARIANT_DECLARE;

        HIcon GetHIcon() const;
		HCursor GetHCursor() const;
		HBrush GetHBrush() const;

	private:
		using WindowHBrushPtr = std::shared_ptr<WindowHBrush>;

	private:
		static WindowHBrushPtr CreateWindowsHBrushPtr(System::WindowBrushTypes background);

	private:
		WindowHIcon m_WindowsHIcon;
		WindowHCursor m_WindowsHCursor;
		WindowHBrushPtr m_WindowsHBrushPtr;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_IMPL_H
