///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/17 19:31)

#ifndef CORE_TOOLS_BASE_STATIC_SINGLETON_DETAIL_H
#define CORE_TOOLS_BASE_STATIC_SINGLETON_DETAIL_H

#include "StaticSingleton.h"
#include "System/Helper/Tools.h"

template <typename T, CoreTools::MutexCreate MutexCreate>
CoreTools::StaticSingleton<T, MutexCreate>::StaticSingleton(SingletonCreate singletonCreate) noexcept
{
    System::UnusedFunction(singletonCreate);
}

template <typename T, CoreTools::MutexCreate MutexCreate>
typename CoreTools::StaticSingleton<T, MutexCreate>::ReferenceType CoreTools::StaticSingleton<T, MutexCreate>::GetSingleton() noexcept
{
    static T singleton{ SingletonCreate::Init };

    return singleton;
}

template <typename T, CoreTools::MutexCreate MutexCreate>
typename CoreTools::StaticSingleton<T, MutexCreate>::PointType CoreTools::StaticSingleton<T, MutexCreate>::GetSingletonPtr() noexcept
{
    return &GetSingleton();
}

template <typename T, CoreTools::MutexCreate MutexCreate>
typename CoreTools::StaticSingleton<T, MutexCreate>::MutexType& CoreTools::StaticSingleton<T, MutexCreate>::GetMutex()
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

#endif  // CORE_TOOLS_BASE_STATIC_SINGLETON_DETAIL_H
