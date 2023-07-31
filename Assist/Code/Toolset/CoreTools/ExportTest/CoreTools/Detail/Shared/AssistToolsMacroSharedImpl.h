///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 15:35)

#ifndef EXPORT_TEST_ASSIST_TOOLS_MACRO_SHARED_IMPL_H
#define EXPORT_TEST_ASSIST_TOOLS_MACRO_SHARED_IMPL_H

#include "AssistTools/AssistToolsDll.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE AssistToolsMacroSharedImpl final
    {
    public:
        using ClassType = AssistToolsMacroSharedImpl;

    public:
        explicit AssistToolsMacroSharedImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_ASSIST_TOOLS_MACRO_SHARED_IMPL_H