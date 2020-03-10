// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:51)

#ifndef SYSTEM_FILE_MANAGE_C_FILE_FLAGS_H
#define SYSTEM_FILE_MANAGE_C_FILE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

#include <string>

namespace System
{
	enum class FileSeek 
	{
		Set = SEEK_SET,
		Cur = SEEK_CUR,
		End = SEEK_END
	};	

	enum class FileSetvBuf
	{
		IOFBF = _IOFBF,
		IOLBF = _IOLBF,
		IONBF = _IONBF,
	};	
}

#endif // SYSTEM_FILE_MANAGE_C_FILE_FLAGS_H
