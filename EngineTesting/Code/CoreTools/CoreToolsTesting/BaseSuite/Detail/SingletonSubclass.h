/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 10:26)

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