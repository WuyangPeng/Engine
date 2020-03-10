// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:12)

#ifndef SYSTEM_THREADING_THREAD_TOOLS_USING_H
#define SYSTEM_THREADING_THREAD_TOOLS_USING_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using ProcThreadAttributeList = _PROC_THREAD_ATTRIBUTE_LIST;
	using ProcThreadAttributeListPtr = LPPROC_THREAD_ATTRIBUTE_LIST;

#else // !SYSTEM_PLATFORM_WIN32	

	struct ProcThreadAttributeList
	{
	};

	using ProcThreadAttributeListPtr = ProcThreadAttributeList*;

#endif // SYSTEM_PLATFORM_WIN32	 
}

#endif // SYSTEM_THREADING_THREAD_TOOLS_USING_H