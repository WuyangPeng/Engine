/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/13 21:09)

#ifndef CORE_TOOLS_HELPER_SUITE_SINGLETON_MACRO_H
#define CORE_TOOLS_HELPER_SUITE_SINGLETON_MACRO_H

#include "CoreTools/Helper/SingletonMacro.h"

/// ����SingletonMacroTesting����
namespace CoreTools
{
    class SingletonMacro final : public Singleton<SingletonMacro>
    {
    public:
        using ClassType = SingletonMacro;
        using ParentType = Singleton<SingletonMacro>;

    private:
        enum class SingletonMacroCreate
        {
            Init,
        };

    public:
        explicit SingletonMacro(SingletonMacroCreate singletonMacroCreate) noexcept;

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(SingletonMacro)

        void DoNothing();

    public:
        CLASS_INVARIANT_VIRTUAL_DECLARE;

    private:
        using SingletonMacroUniquePtr = std::unique_ptr<SingletonMacro>;

    private:
        static SingletonMacroUniquePtr singletonMacro;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_SINGLETON_MACRO_H