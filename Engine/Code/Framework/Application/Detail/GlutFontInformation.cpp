// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:51)

#include "Framework/FrameworkExport.h"

#include "GlutFontInformation.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GlutFontInformation)

int Framework::GlutFontInformation
	::GetStringWidth(const String& text) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(GetCharacterWidth('0') * text.size());
}

int Framework::GlutFontInformation
	::GetCharacterWidth(const TChar character) const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(character);

	constexpr auto characterWidth = 8;

	return characterWidth;
}

int Framework::GlutFontInformation
	::GetFontHeight() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	constexpr auto characterHeight = 13;

	return characterHeight; 
}


