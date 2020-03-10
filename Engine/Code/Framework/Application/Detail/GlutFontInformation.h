// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:00)

#ifndef FRAMEWORK_APPLICATION_GLUT_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_GLUT_FONT_INFORMATION_H

#include "FontInformationImpl.h"

namespace Framework
{
	class GlutFontInformation : public FontInformationImpl
	{
	public:
		typedef GlutFontInformation ClassType;
		typedef FontInformationImpl ParentType;

	public:
		explicit GlutFontInformation();
		virtual ~GlutFontInformation();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual int GetStringWidth (const System::String& text) const;
		virtual int GetCharacterWidth (const System::TChar character) const;
		virtual int GetFontHeight () const;
	};
}

#endif // FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
