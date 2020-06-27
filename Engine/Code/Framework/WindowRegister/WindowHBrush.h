// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 11:52)

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
		using ClassType = WindowHBrush;
		using HBrush = System::WindowHBrush;
		using HGdiObj = System::WindowHGdiObj;
		using WindowBrushTypes = System::WindowBrushTypes;

	public:
		explicit WindowHBrush(WindowBrushTypes background = WindowBrushTypes::WhiteBrush) noexcept;

		CLASS_INVARIANT_DECLARE;

		HBrush GetHBrush() const noexcept;

	private:
		void CheckUpHBrush() noexcept;

	private:
		HGdiObj m_HBrush;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_HBRUSH_H
