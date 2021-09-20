///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:39)

#ifndef EXPORT_TEST_EXPORT_COPY_IMPL_MACRO_IMPL_H
#define EXPORT_TEST_EXPORT_COPY_IMPL_MACRO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ExportCopyImplMacroImpl final
    {
    public:
        using ClassType = ExportCopyImplMacroImpl;

    public:
        explicit ExportCopyImplMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_EXPORT_COPY_IMPL_MACRO_IMPL_H