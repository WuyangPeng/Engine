///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/02 22:22)

#ifndef EXPORT_TEST_ASSIST_TOOLS_PERFORMANCE_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_ASSIST_TOOLS_PERFORMANCE_UNSHARED_MACRO_IMPL_H

#include "AssistTools/AssistToolsDll.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE AssistToolsPerformanceUnsharedMacroImpl final
    {
    public:
        using ClassType = AssistToolsPerformanceUnsharedMacroImpl;

    public:
        explicit AssistToolsPerformanceUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int mCount;
    };
}

#endif  // EXPORT_TEST_ASSIST_TOOLS_PERFORMANCE_UNSHARED_MACRO_IMPL_H