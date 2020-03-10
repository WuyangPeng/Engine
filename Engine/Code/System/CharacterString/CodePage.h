// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 13:22)

#ifndef SYSTEM_CHARACTER_STRING_CODE_PAGE_H
#define SYSTEM_CHARACTER_STRING_CODE_PAGE_H

#include "System/SystemDll.h"

#include "Using/CodePageUsing.h"
#include "Fwd/CharacterStringFlagsFwd.h"

namespace System
{
	// 获取代码页的相关信息。

	bool SYSTEM_DEFAULT_DECLARE IsCodePageValid(CodePage codePage) noexcept;
	CodePage SYSTEM_DEFAULT_DECLARE GetANSICodePage() noexcept;
	CodePage SYSTEM_DEFAULT_DECLARE GetOEMCodePage() noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetCodePageInfo(CodePage codePage, CodePageInfoPtr codePageInfo) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetCodePageInfo(CodePage codePage, CodePageInfoExPtr codePageInfo) noexcept;
}

#endif // SYSTEM_CHARACTER_STRING_CODE_PAGE_H
