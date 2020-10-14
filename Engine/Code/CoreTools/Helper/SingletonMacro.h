//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/09 10:03)

// ����������Ҫ�ĺ�
#ifndef CORE_TOOLS_HELPER_SINGLETON_MACRO_H
#define CORE_TOOLS_HELPER_SINGLETON_MACRO_H

#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Threading/ScopedMutex.h"

#if !defined(TCRE_USE_GCC)

    #define SINGLETON_GET_PTR_DECLARE(className)
    #define SINGLETON_GET_PTR_DEFINE(namespaceName, className)

#else  // TCRE_USE_GCC

    #define SINGLETON_GET_PTR_DECLARE(className)                    \
    public:                                                         \
        [[nodiscard]] static className* GetSingletonPtr() noexcept; \
                                                                    \
    public:                                                         \
        [[nodiscard]] static className& GetSingleton() noexcept

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
    const CoreTools::ScopedMutex holder{ GetMutex() };

#endif  // CORE_TOOLS_HELPER_SINGLETON_MACRO_H
