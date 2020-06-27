// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 09:44)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_IMPL_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Window/Flags/WindowFlags.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"

#include <boost/noncopyable.hpp>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowCreateHandleImpl : private boost::noncopyable
	{
	public:
		using ClassType = WindowCreateHandleImpl;
		using HWnd = System::WindowHWnd;

	public:
		WindowCreateHandleImpl(const WindowInstanceParameter& windowInstanceParameter, const WindowCreateParameter& windowCreateParameter, const WindowSize& size);

		CLASS_INVARIANT_DECLARE;

		HWnd GetHwnd() const noexcept;

		void SetMainWindow();

	private:
		void InitInstance();

	private:
		WindowInstanceParameter m_WindowInstanceParameter;
		WindowCreateParameter m_WindowCreateParameter;
		WindowSize m_Size;
		HWnd m_Hwnd;
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_IMPL_H

