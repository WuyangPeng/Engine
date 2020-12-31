// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:39)

#ifndef FRAMEWORK_APPLICATION_GLUT_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_GLUT_FONT_INFORMATION_H

#include "FontInformationImpl.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE GlutFontInformation final : public FontInformationImpl
	{
	public:
		using ClassType = GlutFontInformation;
		using ParentType = FontInformationImpl;

	public: 
		CLASS_INVARIANT_OVERRIDE_DECLARE;

		int GetStringWidth(const String& text) const final;
		int GetCharacterWidth(const TChar character) const noexcept final;
		int GetFontHeight() const noexcept final;
	};
}

#endif // FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
