// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:17)

#ifndef SYSTEM_CHARACTER_STRING_CODE_PAGE_FWD_H
#define SYSTEM_CHARACTER_STRING_CODE_PAGE_FWD_H 

#include "CharacterStringFlagsFwd.h"
#include "System/CharacterString/Using/CodePageUsing.h"

namespace System
{
	bool IsCodePageValid(CodePage codePage) noexcept;
	CodePage GetANSICodePage() noexcept;
	CodePage GetOEMCodePage() noexcept;
	bool GetCodePageInfo(CodePage codePage, CodePageInfoPtr codePageInfo) noexcept;
	bool GetCodePageInfo(CodePage codePage, CodePageInfoExPtr codePageInfo) noexcept;
}

#endif // SYSTEM_CHARACTER_STRING_CODE_PAGE_FWD_H