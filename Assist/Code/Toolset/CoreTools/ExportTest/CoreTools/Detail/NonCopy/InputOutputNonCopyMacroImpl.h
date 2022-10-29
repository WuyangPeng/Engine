///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 23:34)

#ifndef EXPORT_TEST_INPUT_OUTPUT_NON_COPY_MACRO_IMPL_H
#define EXPORT_TEST_INPUT_OUTPUT_NON_COPY_MACRO_IMPL_H

#include "InputOutput/InputOutputDll.h"

namespace InputOutput
{
    class INPUT_OUTPUT_HIDDEN_DECLARE InputOutputNonCopyMacroImpl final
    {
    public:
        using ClassType = InputOutputNonCopyMacroImpl;

    public:
        explicit InputOutputNonCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_INPUT_OUTPUT_NON_COPY_MACRO_IMPL_H