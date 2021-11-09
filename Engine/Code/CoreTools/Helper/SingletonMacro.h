///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/08/31 17:09)

// ����������Ҫ�ĺ�
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
                                                                \
    public:                                                     \
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

#define SINGLETON_MUTEX_ENTER_MEMBER \
    const std::unique_lock holder{ GetMutex() };

#define SINGLETON_SCOPED_MUTEX_ENTER_MEMBER \
    const CoreTools::ScopedMutex holder{ GetMutex() };

#endif  // CORE_TOOLS_HELPER_SINGLETON_MACRO_H
