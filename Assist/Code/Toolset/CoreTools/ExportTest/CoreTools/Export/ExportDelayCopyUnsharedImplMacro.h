///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 17:05)

#ifndef EXPORT_TEST_EXPORT_DELAY_COPY_UNSHARED_IMPL_MACRO_H
#define EXPORT_TEST_EXPORT_DELAY_COPY_UNSHARED_IMPL_MACRO_H

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

EXPORT_SHARED_PTR(ExportTest, ExportDelayCopyUnsharedImplMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);
EXPORT_DELAY_COPY_UNSHARED(ExportTest, ExportDelayCopyUnsharedImplMacro, ExportDelayCopyUnsharedImplMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);

namespace ExportTest
{
    class EXPORT_TEST_DEFAULT_DECLARE ExportDelayCopyUnsharedImplMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ExportDelayCopyUnsharedImplMacro);

    public:
        explicit ExportDelayCopyUnsharedImplMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_DELAY_COPY_UNSHARED_IMPL_MACRO_H