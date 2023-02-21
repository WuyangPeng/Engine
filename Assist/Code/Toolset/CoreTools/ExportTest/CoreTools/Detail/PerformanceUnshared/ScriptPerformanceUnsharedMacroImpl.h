///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 16:54)

#ifndef EXPORT_TEST_SCRIPT_PERFORMANCE_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_SCRIPT_PERFORMANCE_UNSHARED_MACRO_IMPL_H

#include "Script/ScriptDll.h"

namespace Script
{
    class SCRIPT_HIDDEN_DECLARE ScriptPerformanceUnsharedMacroImpl final
    {
    public:
        using ClassType = ScriptPerformanceUnsharedMacroImpl;

    public:
        explicit ScriptPerformanceUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept; 

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_SCRIPT_PERFORMANCE_UNSHARED_MACRO_IMPL_H