/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 16:36)

/// 自动Singleton基类的声明，这个基类需要手动控制创建和销毁。
/// 如果实例化顺序并不重要，可以通过将派生类设为全局或局部静态，
/// 也可以通过在派生类中使用new和delete来自己做，或者直接使用StaticSingleton。
/// 静态库和动态库混用时会导致不同dll和exe使用不同的单例，需要特殊处理。
/// 单例在创建和销毁时没有加锁，必须保证单线程处理。
#ifndef CORE_TOOLS_BASE_SINGLETON_H
#define CORE_TOOLS_BASE_SINGLETON_H

#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Threading/Flags/MutexFlags.h"
#include "CoreTools/Threading/Flags/MutexTraits.h"

namespace CoreTools
{
    template <typename T, MutexCreate MutexCreate = MutexCreate::UseOriginalStdRecursive>
    class Singleton
    {
    public:
        using ClassType = Singleton<T, MutexCreate>;

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
        Singleton() noexcept;
        ~Singleton() noexcept;
        NODISCARD static MutexType& GetMutex() noexcept requires(isStdMutex);
        NODISCARD static MutexType& GetMutex() requires(!isStdMutex);

    public:
        Singleton(const Singleton& rhs) noexcept = delete;
        Singleton& operator=(const Singleton& rhs) noexcept = delete;
        Singleton(Singleton&& rhs) noexcept = delete;
        Singleton& operator=(Singleton&& rhs) noexcept = delete;

    private:
        void InitSingleton() noexcept(gAssert < 2 || gCoreToolsAssert < 2);
        void DeleteSingleton() const noexcept(gAssert < 2 || gCoreToolsAssert < 2);
        static void CheckSingleton() noexcept(gAssert < 0 || gCoreToolsAssert < 0);

    private:
        static PointType singleton;
    };
}

#endif  // CORE_TOOLS_BASE_SINGLETON_H
