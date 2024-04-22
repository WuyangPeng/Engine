/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 21:11)

#ifndef CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_SUBCLASS_TESTING_H
#define CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_SUBCLASS_TESTING_H

#include "CoreTools/Base/StaticSingletonDetail.h"
#include "CoreTools/Threading/Mutex.h"

namespace CoreTools
{
    class StaticSingletonSubclass final : public StaticSingleton<StaticSingletonSubclass, MutexCreate::UseCriticalSection>
    {
    public:
        using ClassType = StaticSingletonSubclass;
        using ParentType = StaticSingleton<StaticSingletonSubclass, MutexCreate::UseCriticalSection>;

    public:
        explicit StaticSingletonSubclass(SingletonCreate singletonCreate) noexcept;

    public:
        CLASS_INVARIANT_DECLARE;

        void DoNothing() const;
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_SUBCLASS_TESTING_H