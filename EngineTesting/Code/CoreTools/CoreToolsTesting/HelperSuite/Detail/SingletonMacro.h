///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:16)

#ifndef CORE_TOOLS_HELPER_SUITE_SINGLETON_MACRO_H
#define CORE_TOOLS_HELPER_SUITE_SINGLETON_MACRO_H

#include "CoreTools/Helper/SingletonMacro.h"

// ����SingletonMacroTesting����
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
        explicit SingletonMacro(MAYBE_UNUSED SingletonMacroCreate singletonMacroCreate) noexcept;

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(SingletonMacro);

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