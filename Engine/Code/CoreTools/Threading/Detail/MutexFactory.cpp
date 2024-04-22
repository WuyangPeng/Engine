/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 18:06)

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

CoreTools::MutexFactory::MutexImplSharedPtr CoreTools::MutexFactory::Create(MutexCreate mutexCreate)
{
    switch (mutexCreate)
    {
#if defined(SYSTEM_PLATFORM_WIN32)

        case MutexCreate::UseDefault:
            return std::make_shared<StdRecursiveMutex>();

        case MutexCreate::UseCriticalSection:
            return std::make_shared<CriticalSection>();

#else  // !SYSTEM_PLATFORM_WIN32

        case MutexCreate::UseDefault:
            FALLTHROUGH;
        case MutexCreate::UseCriticalSection:
            return std::make_shared<StdRecursiveMutex>();

#endif  // SYSTEM_PLATFORM_WIN32

        case MutexCreate::UseStd:
            FALLTHROUGH;
        case MutexCreate::UseOriginalStd:
            return std::make_shared<StdMutex>();

        case MutexCreate::UseStdRecursive:
            FALLTHROUGH;
        case MutexCreate::UseOriginalStdRecursive:
            return std::make_shared<StdRecursiveMutex>();

        case MutexCreate::UseBoost:
            return std::make_shared<BoostMutex>();

        case MutexCreate::UseBoostRecursive:
            return std::make_shared<BoostRecursiveMutex>();

        default:
            return std::make_shared<NullMutex>();
    }
}
