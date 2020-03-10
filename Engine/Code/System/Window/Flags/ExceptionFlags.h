// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:34)

#ifndef SYSTEM_WINDOW_EXCEPTION_FLAGS_H
#define SYSTEM_WINDOW_EXCEPTION_FLAGS_H

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32 

	enum class Exception 
	{  
		ExecuteHandler = EXCEPTION_EXECUTE_HANDLER,       
		ContinueSearch = EXCEPTION_CONTINUE_SEARCH,      
		ContinueExecution = EXCEPTION_CONTINUE_EXECUTION,               
	};
	
#else // !SYSTEM_PLATFORM_WIN32  

	enum class Exception 
	{   
		ExecuteHandler = 1,
		ContinueSearch = 0,
		ContinueExecution = -1, 
	};
	
#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_WINDOW_EXCEPTION_FLAGS_H
