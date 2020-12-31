//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 10:42)

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
        [[nodiscard]] static ReferenceType GetSingleton() noexcept;
        [[nodiscard]] static PointType GetSingletonPtr() noexcept;

    protected:
        StaticSingleton() noexcept = default;
        ~StaticSingleton() noexcept = default;
        static Mutex& GetMutex();

    public:
        StaticSingleton(const StaticSingleton& rhs) noexcept = delete;
        StaticSingleton& operator=(const StaticSingleton& rhs) noexcept = delete;
        StaticSingleton(StaticSingleton&& rhs) noexcept = delete;
        StaticSingleton& operator=(StaticSingleton&& rhs) noexcept = delete;
    };
}

#endif  // CORE_TOOLS_BASE_STATIC_SINGLETON_H
