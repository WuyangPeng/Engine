// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:15)

#include "Framework/FrameworkExport.h"

#include "GlutFontInformation.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::GlutFontInformation
	::GlutFontInformation()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::GlutFontInformation
	::~GlutFontInformation()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework,GlutFontInformation)

int Framework::GlutFontInformation
    ::GetStringWidth( const System::String& text ) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return static_cast<int>(8 * text.size());
}

int Framework::GlutFontInformation
	::GetCharacterWidth( const System::TChar character ) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(character);

	return 8;
}

int Framework::GlutFontInformation
	::GetFontHeight() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return 13;
}


