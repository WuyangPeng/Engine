// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 11:07)

#ifndef SYSTEM_THREADING_FIBER_TOOLS_USING_H  
#define SYSTEM_THREADING_FIBER_TOOLS_USING_H  

#include "System/Helper/Platform.h" 
#include "System/Window/Using/WindowUsing.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using FlsCallbackFunction = PFLS_CALLBACK_FUNCTION;
	constexpr WindowDWord g_FlsOutOfIndexes{ FLS_OUT_OF_INDEXES };
	using FiberStartRoutine = LPFIBER_START_ROUTINE;

#else // !SYSTEM_PLATFORM_WIN32	

	using FlsCallbackFunction = void(*) (void* flsData);
	constexpr WindowDWord g_FlsOutOfIndexes{ 0xFFFFFFFF };
	using FiberStartRoutine = void(*)(void* lpFiberParameter);

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_FIBER_TOOLS_USING_H