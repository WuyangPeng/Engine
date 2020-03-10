// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:03)

#ifndef SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_FWD_H
#define SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_FWD_H

#include "System/Helper/UnicodeUsing.h"

namespace System
{
	void OutputDebugStringWithChar(const char* outputString) noexcept;
	void OutputDebugStringWithWChar(const wchar_t* outputString) noexcept;
	void OutputDebugStringWithTChar(const TChar* outputString) noexcept;
}

#endif // SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_FWD_H