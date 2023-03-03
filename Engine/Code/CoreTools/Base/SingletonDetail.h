///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/23 14:50)

#ifndef CORE_TOOLS_BASE_SINGLETON_DETAIL_H
#define CORE_TOOLS_BASE_SINGLETON_DETAIL_H

#include "Singleton.h"
#include "System/Helper/Noexcept.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

template <typename T, CoreTools::MutexCreate MutexCreate>
typename CoreTools::Singleton<T, MutexCreate>::PointType CoreTools::Singleton<T, MutexCreate>::singleton{ nullptr };

template <typename T, CoreTools::MutexCreate MutexCreate>
CoreTools::Singleton<T, MutexCreate>::Singleton() noexcept
{
    CoreTools::NoexceptNoReturn(*this, &ClassType::InitSingleton);
}

template <typename T, CoreTools::MutexCreate MutexCreate>
void CoreTools::Singleton<T, MutexCreate>::InitSingleton() noexcept(gAssert < 2 || gCoreToolsAssert < 2)
{
    CORE_TOOLS_ASSERTION_2(singleton == nullptr, "单例%s重复初始化！", typeid(T).name());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26491)

    singleton = static_cast<T*>(this);

#include STSTEM_WARNING_POP
}

template <typename T, CoreTools::MutexCreate MutexCreate>
CoreTools::Singleton<T, MutexCreate>::~Singleton() noexcept
{
    CoreTools::NoexceptNoReturn(*this, &ClassType::DeleteSingleton);
}

template <typename T, CoreTools::MutexCreate MutexCreate>
void CoreTools::Singleton<T, MutexCreate>::DeleteSingleton() const noexcept(gAssert < 2 || gCoreToolsAssert < 2)
{
    CORE_TOOLS_ASSERTION_2(singleton != nullptr, "单例%s重复删除！", typeid(T).name());

    singleton = nullptr;
}

template <typename T, CoreTools::MutexCreate MutexCreate>
typename CoreTools::Singleton<T, MutexCreate>::ReferenceType CoreTools::Singleton<T, MutexCreate>::GetSingleton() noexcept
{
    return *GetSingletonPtr();
}

template <typename T, CoreTools::MutexCreate MutexCreate>
typename CoreTools::Singleton<T, MutexCreate>::PointType CoreTools::Singleton<T, MutexCreate>::GetSingletonPtr() noexcept
{
    System::NoexceptNoReturn(&ClassType::CheckSingleton);

    return singleton;
}

template <typename T, CoreTools::MutexCreate MutexCreate>
void CoreTools::Singleton<T, MutexCreate>::CheckSingleton() noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_0(singleton != nullptr, "单例%s指针为空！", typeid(T).name());
}

template <typename T, CoreTools::MutexCreate MutexCreate>
typename CoreTools::Singleton<T, MutexCreate>::MutexType& CoreTools::Singleton<T, MutexCreate>::GetMutex()
{
    if constexpr (MutexCreate == MutexCreate::UseOriginalStd || MutexCreate == MutexCreate::UseOriginalStdRecursive)
    {
        static MutexType mutex{};

        return mutex;
    }
    else
    {
        static MutexType mutex{ MutexCreate };

        return mutex;
    }
}

#endif  // CORE_TOOLS_BASE_SINGLETON_DETAIL_H
