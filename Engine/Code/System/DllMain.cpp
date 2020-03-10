// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 14:50)

#include "System/SystemExport.h"

#include "System/SystemFwd.h"

#if !defined(BUILDING_SYSTEM_STATIC) && defined(SYSTEM_PLATFORM_WIN32) 

	using System::WindowDWord;
	using System::WindowHInstance;	

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
	int SYSTEM_WINAPI DllMain(WindowHInstance instance, WindowDWord reason, WindowDWord reserved) noexcept 
	{
		SYSTEM_UNUSED_ARG(instance);
		SYSTEM_UNUSED_ARG(reason);
		SYSTEM_UNUSED_ARG(reserved);

		return System::g_True;
	}
#include STSTEM_WARNING_POP 

#else // defined(BUILDING_SYSTEM_STATIC) || !defined(SYSTEM_PLATFORM_WIN32)

	namespace System
	{
		void SystemDllMain() noexcept
		{

		}
	}

#endif // !BUILDING_SYSTEM_STATIC

