///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 17:08)

#ifndef EXPORT_TEST_EXPORT_SHARED_IMPL_MACRO_SHARED_H
#define EXPORT_TEST_EXPORT_SHARED_IMPL_MACRO_SHARED_H

#include "CoreTools/Helper/Export/SharedExportMacro.h"
#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

EXPORT_SHARED_PTR(ExportTest, ExportSharedImplMacroSharedImpl, EXPORT_TEST_DEFAULT_DECLARE);
EXPORT_SHARED(ExportTest, ExportSharedImplMacroSharedImpl, EXPORT_TEST_DEFAULT_DECLARE);

namespace ExportTest
{
    class EXPORT_TEST_DEFAULT_DECLARE ExportSharedImplMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(ExportSharedImplMacroShared);

    public:
        explicit ExportSharedImplMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_SHARED_IMPL_MACRO_SHARED_H