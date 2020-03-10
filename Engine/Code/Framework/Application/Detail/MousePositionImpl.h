// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:00)

#ifndef FRAMEWORK_APPLICATION_MOUSE_POSITION_IMPL_H
#define FRAMEWORK_APPLICATION_MOUSE_POSITION_IMPL_H

#include "Framework/WindowCreate/WindowPoint.h"
#include "System/Window/Flags/WindowFlags.h"

namespace Framework
{
	class MousePositionImpl
	{
	public:
		using ClassType = MousePositionImpl;
		using MousePositionImplPtr = std::shared_ptr<ClassType>;
		using HWnd = System::WindowHWnd;

	public:
		MousePositionImpl();
		virtual ~MousePositionImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		static MousePositionImplPtr CreateWindowMousePositionPtr(HWnd hwnd);

		//  Û±ÍŒª÷√
		virtual const WindowPoint GetMousePosition() const = 0;
		virtual void SetMousePosition (const WindowPoint& windowPoint) = 0;

		virtual MousePositionImplPtr Clone()  = 0;
	};
}

#endif // FRAMEWORK_APPLICATION_MOUSE_POSITION_IMPL_H
