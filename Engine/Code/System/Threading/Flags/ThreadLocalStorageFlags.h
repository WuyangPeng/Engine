// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:08)

#ifndef SYSTEM_THREADING_THREAD_LOCAL_STORAGE_FLAGS_H
#define SYSTEM_THREADING_THREAD_LOCAL_STORAGE_FLAGS_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class ThreadLocalStorageIndexes : uint32_t
	{
		OutOfIndexes = TLS_OUT_OF_INDEXES,
	};

#else // !SYSTEM_PLATFORM_WIN32	

	enum class ThreadLocalStorageIndexes : uint32_t
	{
		OutOfIndexes = (0xFFFFFFFF),
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_THREAD_LOCAL_STORAGE_FLAGS_H