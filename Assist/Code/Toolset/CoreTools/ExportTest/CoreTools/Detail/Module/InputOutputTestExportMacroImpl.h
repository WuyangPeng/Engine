///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 16:47)

#ifndef EXPORT_TEST_INPUT_OUTPUT_TEST_EXPORT_MACRO_IMPL_H
#define EXPORT_TEST_INPUT_OUTPUT_TEST_EXPORT_MACRO_IMPL_H

#include "InputOutput/InputOutputDll.h"

namespace InputOutput
{
    class INPUT_OUTPUT_HIDDEN_DECLARE InputOutputTestExportMacroImpl final
    {
    public:
        using ClassType = InputOutputTestExportMacroImpl;

    public:
        explicit InputOutputTestExportMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_INPUT_OUTPUT_TEST_EXPORT_MACRO_IMPL_H