///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/27 11:45)

#ifndef CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_SUBCLASS_TESTING_H
#define CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_SUBCLASS_TESTING_H

#include "CoreTools/Base/StaticSingletonDetail.h"

namespace CoreTools
{
    class StaticSingletonSubclass final : public StaticSingleton<StaticSingletonSubclass>
    {
    public:
        using ClassType = StaticSingletonSubclass;
        using ParentType = StaticSingleton<StaticSingletonSubclass>;

    public:
        explicit StaticSingletonSubclass(SingletonCreate singletonCreate) noexcept;

    public:
        CLASS_INVARIANT_DECLARE;

        void DoNothing() const;
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_SUBCLASS_TESTING_H