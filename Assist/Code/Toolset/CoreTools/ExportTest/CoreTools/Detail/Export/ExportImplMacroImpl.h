///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 23:22)

#ifndef EXPORT_TEST_EXPORT_IMPL_MACRO_IMPL_H
#define EXPORT_TEST_EXPORT_IMPL_MACRO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ExportImplMacroImpl final
    {
    public:
        using ClassType = ExportImplMacroImpl;

    public:
        explicit ExportImplMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_EXPORT_IMPL_MACRO_IMPL_H