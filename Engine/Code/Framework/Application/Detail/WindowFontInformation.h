// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:42)

#ifndef FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H

#include "FontInformationImpl.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowFontInformation final : public FontInformationImpl
	{
	public:
		using ClassType = WindowFontInformation;
		using ParentType = FontInformationImpl;

	public:
		explicit WindowFontInformation(HWnd hwnd) noexcept;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		int GetStringWidth(const String& text) const noexcept final;
		int GetCharacterWidth(const TChar character) const final;
		int GetFontHeight() const noexcept final;

	private:
		HWnd m_Hwnd;
	};
}

#endif // FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
