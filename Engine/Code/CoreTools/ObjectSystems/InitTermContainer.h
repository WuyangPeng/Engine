//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/21 20:59)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_CONTAINER_H
#define CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include <array>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE InitTermContainer final
    {
    public:
        using ClassType = InitTermContainer;
        using ExecuteFunction = void (*)();

    public:
        InitTermContainer() noexcept;

        CLASS_INVARIANT_DECLARE;

        void AddExecuteFunction(ExecuteFunction function);
        void Execute();

    private:
        // 这个数目必须足够大，以支持你的应用程序。如果你的应用程序触发此断言，修改这个值然后重新编译。
        // 其目标是避免执行期间premain和postmain的动态分配，从而使其更容易管理和跟踪内存使用情况。
        static constexpr auto sm_MaxElements = 256;
        static_assert(0 < sm_MaxElements);

        int m_NumFunction;
        std::array<ExecuteFunction, sm_MaxElements> m_ExecuteFunction;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_CONTAINER_H
