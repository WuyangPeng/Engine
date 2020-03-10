// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:05)

#ifndef FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H
#define FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H

#include "MousePositionImpl.h"

namespace Framework
{
	class WindowMousePosition : public MousePositionImpl
	{
	public:
		using ClassType = WindowMousePosition;
		using ParentType = MousePositionImpl;

	public:
		explicit WindowMousePosition(HWnd hwnd);
		virtual ~WindowMousePosition();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		//  Û±ÍŒª÷√
		virtual const WindowPoint GetMousePosition() const;
		virtual void SetMousePosition (const WindowPoint& windowPoint);
		virtual MousePositionImplPtr Clone();  

	private:
		HWnd m_Hwnd;
	};
}

#endif // FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H
