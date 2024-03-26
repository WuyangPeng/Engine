/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:38)

#ifndef EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_MACRO_IMPL_H
#define EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_MACRO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CoreToolsTestExportMacroImpl final
    {
    public:
        using ClassType = CoreToolsTestExportMacroImpl;

    public:
        explicit CoreToolsTestExportMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_MACRO_IMPL_H