///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/26 20:46)

#ifndef CORE_TOOLS_BASE_STATIC_SINGLETON_H
#define CORE_TOOLS_BASE_STATIC_SINGLETON_H

#include "CoreTools/Threading/Mutex.h"

namespace CoreTools
{
    template <typename T>
    class StaticSingleton
    {
    public:
        using ClassType = StaticSingleton<T>;
        using ValueType = T;
        using PointType = ValueType*;
        using ReferenceType = ValueType&;

    public:
        NODISCARD static ReferenceType GetSingleton() noexcept;
        NODISCARD static PointType GetSingletonPtr() noexcept;

    protected:
        enum class SingletonCreate
        {
            Init,
        };

        explicit StaticSingleton(MAYBE_UNUSED SingletonCreate singletonCreate) noexcept;
        ~StaticSingleton() noexcept = default;
        NODISCARD static Mutex& GetMutex();

    public:
        StaticSingleton(const StaticSingleton& rhs) noexcept = delete;
        StaticSingleton& operator=(const StaticSingleton& rhs) noexcept = delete;
        StaticSingleton(StaticSingleton&& rhs) noexcept = delete;
        StaticSingleton& operator=(StaticSingleton&& rhs) noexcept = delete;
    };
}

#endif  // CORE_TOOLS_BASE_STATIC_SINGLETON_H
