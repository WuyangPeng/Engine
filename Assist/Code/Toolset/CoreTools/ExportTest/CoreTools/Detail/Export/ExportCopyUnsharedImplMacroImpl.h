///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 22:15)

#ifndef EXPORT_TEST_EXPORT_COPY_UNSHARED_IMPL_MACRO_IMPL_MACRO_IMPL_H
#define EXPORT_TEST_EXPORT_COPY_UNSHARED_IMPL_MACRO_IMPL_MACRO_IMPL_H

#include "CoreTools/Helper/UserMacro.h"
#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

namespace ExportTest
{
    class EXPORT_TEST_HIDDEN_DECLARE ExportCopyUnsharedImplMacroImpl final
    {
    public:
        using ClassType = ExportCopyUnsharedImplMacroImpl;

    public:
        explicit ExportCopyUnsharedImplMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int mCount;
    };
}

#endif  // EXPORT_TEST_EXPORT_COPY_UNSHARED_IMPL_MACRO_IMPL_MACRO_IMPL_H