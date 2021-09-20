//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 18:52)

#include "CoreTools/CoreToolsExport.h"

#include "BoostMutex.h"
#include "BoostRecursiveMutex.h"
#include "MutexFactory.h"
#include "NullMutex.h"
#include "StdMutex.h"
#include "StdRecursiveMutex.h"
#include "CoreTools/Threading/Flags/MutexFlags.h"

#if defined(SYSTEM_PLATFORM_WIN32)
    #include "CriticalSection.h"
    #include "WindowsMutex.h"
#else  // !SYSTEM_PLATFORM_WIN32
    #include "ThreadMutex.h"
#endif  // SYSTEM_PLATFORM_WIN32

using std::make_shared;

CoreTools::MutexFactory::MutexImplPtr CoreTools::MutexFactory::Create(MutexCreate mutexCreate)
{
    switch (mutexCreate)
    {
#if defined(SYSTEM_PLATFORM_WIN32)

        case MutexCreate::UseDefault:
            return make_shared<WindowsMutex>();
        case MutexCreate::UseCriticalSection:
            return make_shared<CriticalSection>();

#else  // !SYSTEM_PLATFORM_WIN32

        case MutexCreate::UseDefault:
        case MutexCreate::UseCriticalSection:
            return make_shared<ThreadMutex>();

#endif  // SYSTEM_PLATFORM_WIN32

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
