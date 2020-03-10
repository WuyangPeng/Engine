// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:11)

#ifndef SYSTEM_THREADING_INIT_ONCE_USING_H  
#define SYSTEM_THREADING_INIT_ONCE_USING_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using InitOnce = INIT_ONCE;
	using InitOncePtr = PINIT_ONCE;
	using InitOnceFunction = PINIT_ONCE_FN;

#else // !SYSTEM_PLATFORM_WIN32	

	struct InitOnce
	{
		void* Ptr;
	};
	using InitOncePtr = InitOnce*;
	using InitOnceFunction = int(*) (InitOncePtr initOnce, void* parameter, void** context);

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_INIT_ONCE_USING_H