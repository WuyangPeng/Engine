///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/26 20:43)

#ifndef CORE_TOOLS_BASE_STATIC_SINGLETON_DETAIL_H
#define CORE_TOOLS_BASE_STATIC_SINGLETON_DETAIL_H

#include "StaticSingleton.h"

template <typename T>
CoreTools::StaticSingleton<T>::StaticSingleton(MAYBE_UNUSED SingletonCreate singletonCreate) noexcept
{
}

template <typename T>
typename CoreTools::StaticSingleton<T>::ReferenceType CoreTools::StaticSingleton<T>::GetSingleton() noexcept
{
    static T singleton{ SingletonCreate::Init };

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
