///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/02/23 16:36)

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