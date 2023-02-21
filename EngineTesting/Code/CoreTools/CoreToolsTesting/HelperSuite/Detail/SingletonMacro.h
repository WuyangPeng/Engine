///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/13 20:32)

#ifndef CORE_TOOLS_HELPER_SUITE_SINGLETON_MACRO_H
#define CORE_TOOLS_HELPER_SUITE_SINGLETON_MACRO_H

#include "CoreTools/Helper/SingletonMacro.h"

// 测试SingletonMacroTesting所需
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