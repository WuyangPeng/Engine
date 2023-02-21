///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 16:44)

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