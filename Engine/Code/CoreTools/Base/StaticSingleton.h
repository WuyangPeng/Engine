/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 16:37)

#ifndef CORE_TOOLS_BASE_STATIC_SINGLETON_H
#define CORE_TOOLS_BASE_STATIC_SINGLETON_H

#include "CoreTools/Threading/Flags/MutexFlags.h"
#include "CoreTools/Threading/Flags/MutexTraits.h"

namespace CoreTools
{
    template <typename T, MutexCreate MutexCreate = MutexCreate::UseOriginalStdRecursive>
    class StaticSingleton
    {
    public:
        using ClassType = StaticSingleton<T, MutexCreate>;

        using ValueType = T;
        using PointType = ValueType*;
        using ReferenceType = ValueType&;
        using MutexType = typename MutexTraits<MutexCreate>::MutexType;

    public:
        NODISCARD static ReferenceType GetSingleton() noexcept;
        NODISCARD static PointType GetSingletonPtr() noexcept;

    protected:
        static constexpr auto isStdMutex = MutexCreate == MutexCreate::UseOriginalStd || MutexCreate == MutexCreate::UseOriginalStdRecursive;

    protected:
        enum class SingletonCreate
        {
            Init,
        };

        explicit StaticSingleton(SingletonCreate singletonCreate) noexcept;
        ~StaticSingleton() noexcept = default;
        NODISCARD static MutexType& GetMutex() requires(isStdMutex);
        NODISCARD static MutexType& GetMutex() requires(!isStdMutex);

    public:
        StaticSingleton(const StaticSingleton& rhs) noexcept = delete;
        StaticSingleton& operator=(const StaticSingleton& rhs) noexcept = delete;
        StaticSingleton(StaticSingleton&& rhs) noexcept = delete;
        StaticSingleton& operator=(StaticSingleton&& rhs) noexcept = delete;
    };
}

#endif  // CORE_TOOLS_BASE_STATIC_SINGLETON_H
