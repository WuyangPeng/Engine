///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/10 18:15)

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
        explicit SingletonSubclass(SingletonSubclassCreate singletonSubclassCreate) noexcept;

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