// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:41)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_HCURSOR_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_HCURSOR_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h" 
#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Using/WindowPictorialUsing.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowHCursor
	{
	public:
		using ClassType = WindowHCursor;
		using HInstance = System::WindowHInstance;
		using HCursor = System::WindowHCursor;

	public:
		explicit WindowHCursor(const System::TChar* cursor = IDC_ARROW);
		WindowHCursor(HInstance hInstance,int cursor);

		CLASS_INVARIANT_DECLARE;

		HCursor GetHCursor() const;

	private:
		void CheckUpHCursor();

	private:
		HCursor m_HCursor;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_HCURSOR_H
