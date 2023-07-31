///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 15:33)

#ifndef EXPORT_TEST_CORE_TOOLS_NON_COPY_MACRO_IMPL_H
#define EXPORT_TEST_CORE_TOOLS_NON_COPY_MACRO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CoreToolsNonCopyMacroImpl final
    {
    public:
        using ClassType = CoreToolsNonCopyMacroImpl;

    public:
        explicit CoreToolsNonCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_CORE_TOOLS_NON_COPY_MACRO_IMPL_H