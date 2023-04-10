///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:39)

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

CoreTools::MutexFactory::MutexImplSharedPtr CoreTools::MutexFactory::Create(MutexCreate mutexCreate)
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
            FALLTHROUGH;
        case MutexCreate::UseCriticalSection:
            return make_shared<ThreadMutex>();

#endif  // SYSTEM_PLATFORM_WIN32

        case MutexCreate::UseStd:
            FALLTHROUGH;
        case MutexCreate::UseOriginalStd:
            return make_shared<StdMutex>();

        case MutexCreate::UseStdRecursive:
            FALLTHROUGH;
        case MutexCreate::UseOriginalStdRecursive:
            return make_shared<StdRecursiveMutex>();

        case MutexCreate::UseBoost:
            return make_shared<BoostMutex>();

        case MutexCreate::UseBoostRecursive:
            return make_shared<BoostRecursiveMutex>();

        default:
            return make_shared<NullMutex>();
    }
}
