// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:20)

#include "CoreTools/CoreToolsExport.h"

#include "MutexFactory.h"
#include "StdMutex.h"
#include "NullMutex.h"
#include "BoostMutex.h"
#include "StdRecursiveMutex.h"
#include "BoostRecursiveMutex.h"
#include "CoreTools/Threading/Flags/MutexFlags.h"

#if defined(SYSTEM_PLATFORM_WIN32)
	#include "CriticalSection.h"
	#include "WindowsMutex.h"
#else // !SYSTEM_PLATFORM_WIN32
	#include "ThreadMutex.h"
	#include "System/Helper/UnusedMacro.h"
#endif // SYSTEM_PLATFORM_WIN32

using std::make_shared;

CoreTools::MutexFactory::MutexImplPtr CoreTools::MutexFactory
	::GenerateMutex(MutexCreate mutexCreate)
{
	switch (mutexCreate)
	{
#if defined(SYSTEM_PLATFORM_WIN32)	

		case MutexCreate::UseDefault:
			return make_shared<WindowsMutex>();
		case MutexCreate::UseCriticalSection:
			return make_shared<CriticalSection>();

#else // !SYSTEM_PLATFORM_WIN32

		case MutexCreate::UseDefault:
		case MutexCreate::UseCriticalSection:
			return make_shared<ThreadMutex>();

#endif // SYSTEM_PLATFORM_WIN32 

		case MutexCreate::UseStd:
			return make_shared<StdMutex>();
		case MutexCreate::UseStdRecursive:
			return make_shared<StdRecursiveMutex>();
		case MutexCreate::UseBoost:
			return make_shared<BoostMutex>();
		case MutexCreate::UseBoostRecursive:
			return make_shared<BoostRecursiveMutex>();
		case MutexCreate::UseNull:
		default:
			return make_shared<NullMutex>();
	}
}




