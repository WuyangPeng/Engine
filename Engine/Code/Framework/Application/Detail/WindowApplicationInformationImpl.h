// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:04)

#ifndef FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H
#define FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H

#include "System/Helper/UnicodeUsing.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "System/Window/Flags/WindowFlags.h"

namespace Framework
{
	class WindowApplicationInformationImpl
	{
	public:
		using ClassType = WindowApplicationInformationImpl;
		using WindowStylesFlags = System::WindowStyles;

	public:	
		WindowApplicationInformationImpl(const System::String& windowTitle, 
			                             const WindowSize& size,
			                             const WindowPoint& point,					
                                         bool allowResize);

		WindowApplicationInformationImpl(const System::String& windowTitle, 
			                             const WindowSize& size);
		
		CLASS_INVARIANT_DECLARE;

		const System::String& GetWindowTitle () const;
		const std::string GetWindowTitleWithMultiByte() const;
		int GetXPosition () const;
		int GetYPosition () const;
		int GetWidth () const;
		int GetHeight () const;
		const WindowSize GetWindowSize() const;
		float GetAspectRatio () const;	
		WindowStylesFlags GetStyle() const;

		void SetWindowSize(const WindowSize& size);

	private:
		// 窗口参数。
		System::String m_WindowTitle;
		WindowSize m_Size;
		WindowPoint m_Position;		
		WindowStylesFlags m_Style;
	};
}

#endif // FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H
