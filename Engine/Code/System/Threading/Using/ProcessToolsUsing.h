// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:12)

#ifndef SYSTEM_THREADING_PROCESS_TOOLS_USING_H
#define SYSTEM_THREADING_PROCESS_TOOLS_USING_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	 

	using AsynchronousProcedureCallFunction = PAPCFUNC;
	using ProcessorNumber = PROCESSOR_NUMBER;
	using ProcessorNumberPtr = PPROCESSOR_NUMBER;

#else // !SYSTEM_PLATFORM_WIN32	 

	using AsynchronousProcedureCallFunction = void(*)(WindowPtrULongPtr parameter);

	struct ProcessorNumber
	{
		uint16_t Group;
		uint8_t Number;
		uint8_t Reserved;
	};
	using ProcessorNumberPtr = ProcessorNumber*;

#endif // SYSTEM_PLATFORM_WIN32	 
}

#endif // SYSTEM_THREADING_PROCESS_TOOLS_USING_H