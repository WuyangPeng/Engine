///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/08/31 17:07)

#ifndef CORE_TOOLS_BASE_STATIC_SINGLETON_DETAIL_H
#define CORE_TOOLS_BASE_STATIC_SINGLETON_DETAIL_H

#include "StaticSingleton.h"

template <typename T, CoreTools::MutexCreate mutexCreate>
CoreTools::StaticSingleton<T, mutexCreate>::StaticSingleton(MAYBE_UNUSED SingletonCreate singletonCreate) noexcept
{
}

template <typename T, CoreTools::MutexCreate mutexCreate>
typename CoreTools::StaticSingleton<T, mutexCreate>::ReferenceType CoreTools::StaticSingleton<T, mutexCreate>::GetSingleton() noexcept
{
    static T singleton{ SingletonCreate::Init };

    return singleton;
}

template <typename T, CoreTools::MutexCreate mutexCreate>
typename CoreTools::StaticSingleton<T, mutexCreate>::PointType CoreTools::StaticSingleton<T, mutexCreate>::GetSingletonPtr() noexcept
{
    return &GetSingleton();
}

template <typename T, CoreTools::MutexCreate mutexCreate>
typename CoreTools::StaticSingleton<T, mutexCreate>::MutexType& CoreTools::StaticSingleton<T, mutexCreate>::GetMutex()
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

#endif  // CORE_TOOLS_BASE_STATIC_SINGLETON_DETAIL_H
