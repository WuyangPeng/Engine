// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:05)

#ifndef FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H

#include "FontInformationImpl.h"

namespace Framework
{
	class WindowFontInformation : public FontInformationImpl
	{
	public:
		using ClassType = WindowFontInformation;
		using ParentType = FontInformationImpl;

	public:
		explicit WindowFontInformation(HWnd hwnd);
		virtual ~WindowFontInformation();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual int GetStringWidth (const System::String& text) const;
		virtual int GetCharacterWidth (const System::TChar character) const;
		virtual int GetFontHeight () const;

	private:
		HWND m_Hwnd;
	};
}

#endif // FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
