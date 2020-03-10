// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:12)

#ifndef SYSTEM_THREADING_SLIM_READER_WRITER_USING_H  
#define SYSTEM_THREADING_SLIM_READER_WRITER_USING_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using SlimReaderWriterLock = SRWLOCK;
	using SlimReaderWriterLockPtr = PSRWLOCK;

#else // !SYSTEM_PLATFORM_WIN32	

	struct SlimReaderWriterLock
	{
		void* Ptr;
	};
	using SlimReaderWriterLockPtr = SlimReaderWriterLock*;

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_SLIM_READER_WRITER_USING_H