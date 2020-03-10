// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:35)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_IMPL_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_IMPL_H

#include "System/Window/Flags/WindowFlags.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"

#include <boost/noncopyable.hpp>

namespace Framework
{
	class WindowCreateHandleImpl : private boost::noncopyable
	{
	public:
		using ClassType = WindowCreateHandleImpl;
        using HWnd = System::WindowHWnd;

	public:		
		WindowCreateHandleImpl(const WindowInstanceParameter& windowInstanceParameter,const WindowCreateParameter& windowCreateParameter,const WindowSize& size);
		
		CLASS_INVARIANT_DECLARE;	

		HWnd GetHwnd() const;
		
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

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_IMPL_H

