// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:41)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_HBRUSH_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_HBRUSH_H

#include "Framework/FrameworkDll.h"

#include "System/Window/Flags/WindowPictorialFlags.h"
#include "System/Window/Using/WindowPictorialUsing.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowHBrush
	{
	public:
		typedef WindowHBrush ClassType;
		typedef System::WindowHBrush HBrush;
		typedef System::WindowHGdiObj HGdiObj;

	public:
		explicit WindowHBrush(System::WindowBrushTypes background =  System::WindowBrushTypes::WhiteBrush);

		CLASS_INVARIANT_DECLARE;

		HBrush GetHBrush() const;

	private:
		void CheckUpHBrush();

	private:
		HGdiObj m_HBrush;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_HBRUSH_H
