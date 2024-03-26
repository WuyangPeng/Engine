/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:37)

#ifndef EXPORT_TEST_EXPORT_CONST_IMPL_MACRO_IMPL_H
#define EXPORT_TEST_EXPORT_CONST_IMPL_MACRO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ExportConstImplMacroImpl final
    {
    public:
        using ClassType = ExportConstImplMacroImpl;

    public:
        explicit ExportConstImplMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_EXPORT_CONST_IMPL_MACRO_IMPL_H