// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:43)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_FLAGS_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32 	

	enum class ResourceEnum
	{
		Ln = RESOURCE_ENUM_LN,
		Mui = RESOURCE_ENUM_MUI,
		MuiSystem = RESOURCE_ENUM_MUI_SYSTEM,
		Validate = RESOURCE_ENUM_VALIDATE,
		ModouleExact = RESOURCE_ENUM_MODULE_EXACT,
	};

#else // !SYSTEM_PLATFORM_WIN32  	

	enum class ResourceEnum
	{
		Ln = 0x0001,
		Mui = 0x0002,
		MuiSystem = 0x0004,
		Validate = 0x0008,
		ModouleExact = 0x0010,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_FLAGS_H
