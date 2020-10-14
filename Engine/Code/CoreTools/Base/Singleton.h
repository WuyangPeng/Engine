//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 9:52)

// 自动Singleton基类的声明，这个基类需要手动控制创建和销毁。
// 如果实例化顺序并不重要，可以通过将派生类设为全局或局部静态，也可以通过在派生类中使用new和delete来自己做，
// 或者直接使用StaticSingleton。
// 静态库和动态库混用时会导致不同dll和exe使用不同的单例，需要特殊处理。
// 单例在创建和销毁时没有加锁，必须保证单线程处理。
#ifndef CORE_TOOLS_BASE_SINGLETON_H
#define CORE_TOOLS_BASE_SINGLETON_H

#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

namespace CoreTools
{
    template <typename T>
    class Singleton
    {
    public:
        using ClassType = Singleton<T>;
        using ValueType = T;
        using PointType = ValueType*;
        using ReferenceType = ValueType&;

    public:
        [[nodiscard]] static ReferenceType GetSingleton() noexcept;
        [[nodiscard]] static PointType GetSingletonPtr() noexcept;

    protected:
        Singleton() noexcept;
        ~Singleton() noexcept;
        [[nodiscard]] static Mutex& GetMutex();

    public:
        Singleton(const Singleton& rhs) noexcept = delete;
        Singleton& operator=(const Singleton& rhs) noexcept = delete;
        Singleton(Singleton&& rhs) noexcept = delete;
        Singleton& operator=(Singleton&& rhs) noexcept = delete;

    private:
        void InitSingleton();
        void DeleteSingleton() noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
        static void CheckSingleton();

    private:
        static PointType sm_Singleton;
    };
}

#endif  // CORE_TOOLS_BASE_SINGLETON_H
