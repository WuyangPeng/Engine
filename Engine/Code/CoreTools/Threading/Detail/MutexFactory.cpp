///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/08/31 22:51)

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
        case MutexCreate::UseCriticalSection:
            return make_shared<ThreadMutex>();

#endif  // SYSTEM_PLATFORM_WIN32

        case MutexCreate::UseStd:
        case MutexCreate::UseOriginalStd:
            return make_shared<StdMutex>();
        case MutexCreate::UseStdRecursive:
        case MutexCreate::UseOriginalStdRecursive:
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
