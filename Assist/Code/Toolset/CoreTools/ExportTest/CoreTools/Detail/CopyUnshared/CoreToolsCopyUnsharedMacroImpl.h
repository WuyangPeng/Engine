///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 13:37)

#ifndef EXPORT_TEST_CORE_TOOLS_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_CORE_TOOLS_COPY_UNSHARED_MACRO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CoreToolsCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = CoreToolsCopyUnsharedMacroImpl;

    public:
        explicit CoreToolsCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_CORE_TOOLS_COPY_UNSHARED_MACRO_IMPL_H