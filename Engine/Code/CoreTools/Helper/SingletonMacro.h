///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:05)

// 单例类所需要的宏
#ifndef CORE_TOOLS_HELPER_SINGLETON_MACRO_H
#define CORE_TOOLS_HELPER_SINGLETON_MACRO_H

#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Threading/ScopedMutex.h"

#include <mutex>

#if !defined(TCRE_USE_GCC)

    #define SINGLETON_GET_PTR_DECLARE(className)
    #define SINGLETON_GET_PTR_DEFINE(namespaceName, className)

#else  // TCRE_USE_GCC

    #define SINGLETON_GET_PTR_DECLARE(className)                \
    public:                                                     \
        NODISCARD static className* GetSingletonPtr() noexcept; \
        NODISCARD static className& GetSingleton() noexcept

    #define SINGLETON_GET_PTR_DEFINE(namespaceName, className)                         \
        namespaceName::className* namespaceName::className::GetSingletonPtr() noexcept \
        {                                                                              \
            return ParentType::GetSingletonPtr();                                      \
        }                                                                              \
        namespaceName::className& namespaceName::className::GetSingleton() noexcept    \
        {                                                                              \
            return ParentType::GetSingleton();                                         \
        }

#endif  // !TCRE_USE_GCC

#define SINGLETON_MUTEX_ENTER_GLOBAL(namespaceName) \
    const CoreTools::ScopedMutex holder{ SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)() };

#define SINGLETON_DESTROY_MUTEX_ENTER_GLOBAL(namespaceName, filterType) \
    EXCEPTION_TRY                                                       \
    {                                                                   \
        SINGLETON_MUTEX_ENTER_GLOBAL(namespaceName);                    \
    }                                                                   \
    EXCEPTION_ALL_CATCH(filterType)

#define SINGLETON_MUTEX_ENTER_MEMBER \
    const std::unique_lock holder    \
    {                                \
        GetMutex()                   \
    }

#define SINGLETON_SCOPED_MUTEX_ENTER_MEMBER \
    const CoreTools::ScopedMutex holder     \
    {                                       \
        GetMutex()                          \
    }

#endif  // CORE_TOOLS_HELPER_SINGLETON_MACRO_H
