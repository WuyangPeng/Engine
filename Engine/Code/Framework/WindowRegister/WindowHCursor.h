// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 11:52)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_HCURSOR_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_HCURSOR_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h" 
#include "System/Window/Using/WindowRegistryUsing.h"
#include "System/Window/Using/WindowPictorialUsing.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowHCursor
	{
	public:
		using ClassType = WindowHCursor;
		using TChar = System::TChar;
		using HCursor = System::WindowHCursor;
		using HInstance = System::WindowHInstance;

	public:
		explicit WindowHCursor(const TChar* cursor = System::g_Arrow) noexcept;
		WindowHCursor(HInstance instance, int cursor);

		static WindowHCursor Create(HInstance instance, bool isDefaultCursor, int cursor);

		CLASS_INVARIANT_DECLARE;

		HCursor GetHCursor() const noexcept;

	private:
		void CheckUpHCursor() noexcept;

	private:
		HCursor m_HCursor;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_HCURSOR_H
