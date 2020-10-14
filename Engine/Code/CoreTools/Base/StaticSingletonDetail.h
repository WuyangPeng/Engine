//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 9:56)

#ifndef CORE_TOOLS_BASE_STATIC_SINGLETON_DETAIL_H
#define CORE_TOOLS_BASE_STATIC_SINGLETON_DETAIL_H

#include "StaticSingleton.h"

template <typename T>
typename CoreTools::StaticSingleton<T>::ReferenceType CoreTools::StaticSingleton<T>::GetSingleton() noexcept
{
    static T singleton{};

    return singleton;
}

template <typename T>
typename CoreTools::StaticSingleton<T>::PointType CoreTools::StaticSingleton<T>::GetSingletonPtr() noexcept
{
    return &GetSingleton();
}

template <typename T>
CoreTools::Mutex& CoreTools::StaticSingleton<T>::GetMutex()
{
    static Mutex mutex{};

    return mutex;
}

#endif  // CORE_TOOLS_BASE_STATIC_SINGLETON_DETAIL_H
