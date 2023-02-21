///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:21)

#ifndef CORE_TOOLS_BASE_SINGLETON_DETAIL_H
#define CORE_TOOLS_BASE_SINGLETON_DETAIL_H

#include "Singleton.h"
#include "System/Helper/Noexcept.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

template <typename T, CoreTools::MutexCreate mutexCreate>
typename CoreTools::Singleton<T, mutexCreate>::PointType CoreTools::Singleton<T, mutexCreate>::singleton{ nullptr };

template <typename T, CoreTools::MutexCreate mutexCreate>
CoreTools::Singleton<T, mutexCreate>::Singleton() noexcept
{
    CoreTools::NoexceptNoReturn(*this, &ClassType::InitSingleton);
}

template <typename T, CoreTools::MutexCreate mutexCreate>
void CoreTools::Singleton<T, mutexCreate>::InitSingleton() noexcept(gAssert < 2 || gCoreToolsAssert < 2)
{
    CORE_TOOLS_ASSERTION_2(singleton == nullptr, "单例%s重复初始化！", typeid(T).name());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26491)

    singleton = static_cast<T*>(this);

#include STSTEM_WARNING_POP
}

template <typename T, CoreTools::MutexCreate mutexCreate>
CoreTools::Singleton<T, mutexCreate>::~Singleton() noexcept
{
    CoreTools::NoexceptNoReturn(*this, &ClassType::DeleteSingleton);
}

template <typename T, CoreTools::MutexCreate mutexCreate>
void CoreTools::Singleton<T, mutexCreate>::DeleteSingleton() noexcept(gAssert < 2 || gCoreToolsAssert < 2)
{
    CORE_TOOLS_ASSERTION_2(singleton != nullptr, "单例%s重复删除！", typeid(T).name());

    singleton = nullptr;
}

template <typename T, CoreTools::MutexCreate mutexCreate>
typename CoreTools::Singleton<T, mutexCreate>::ReferenceType CoreTools::Singleton<T, mutexCreate>::GetSingleton() noexcept
{
    return *GetSingletonPtr();
}

template <typename T, CoreTools::MutexCreate mutexCreate>
typename CoreTools::Singleton<T, mutexCreate>::PointType CoreTools::Singleton<T, mutexCreate>::GetSingletonPtr() noexcept
{
    System::NoexceptNoReturn(&ClassType::CheckSingleton);

    return singleton;
}

template <typename T, CoreTools::MutexCreate mutexCreate>
void CoreTools::Singleton<T, mutexCreate>::CheckSingleton() noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_0(singleton != nullptr, "单例%s指针为空！", typeid(T).name());
}

template <typename T, CoreTools::MutexCreate mutexCreate>
typename CoreTools::Singleton<T, mutexCreate>::MutexType& CoreTools::Singleton<T, mutexCreate>::GetMutex()
{
    if constexpr (mutexCreate == MutexCreate::UseOriginalStd || mutexCreate == MutexCreate::UseOriginalStdRecursive)
    {
        static MutexType mutex{};

        return mutex;
    }
    else
    {
        static MutexType mutex{ mutexCreate };

        return mutex;
    }
}

#endif  // CORE_TOOLS_BASE_SINGLETON_DETAIL_H
