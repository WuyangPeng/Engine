///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:42)

#ifndef CORE_TOOLS_BASE_SUITE_SINGLETON_SUBCLASS_TESTING_H
#define CORE_TOOLS_BASE_SUITE_SINGLETON_SUBCLASS_TESTING_H

#include "CoreTools/Base/SingletonDetail.h"

namespace CoreTools
{
    class SingletonSubclass final : public Singleton<SingletonSubclass>
    {
    public:
        using ClassType = SingletonSubclass;
        using ParentType = Singleton<SingletonSubclass>;

    private:
        enum class SingletonSubclassCreate
        {
            Init,
        };

    public:
        SingletonSubclass(MAYBE_UNUSED SingletonSubclassCreate singletonSubclassCreate) noexcept;

        CLASS_INVARIANT_DECLARE;

        static void Create();
        static void Destroy() noexcept;

        void DoNothing() const;

    private:
        using SingletonSubclassUniquePtr = std::unique_ptr<SingletonSubclass>;

    private:
        static SingletonSubclassUniquePtr singletonSubclass;
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_SINGLETON_SUBCLASS_TESTING_H