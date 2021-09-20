///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:53)

#ifndef EXPORT_TEST_EXPORT_PERFORMANCE_UNSHARED_IMPL_MACRO_H
#define EXPORT_TEST_EXPORT_PERFORMANCE_UNSHARED_IMPL_MACRO_H

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

EXPORT_CONST_SHARED_PTR(ExportTest, ExportPerformanceUnsharedImplMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);
EXPORT_PERFORMANCE_UNSHARED(ExportTest, ExportPerformanceUnsharedImplMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);

namespace ExportTest
{
    class EXPORT_TEST_DEFAULT_DECLARE ExportPerformanceUnsharedImplMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ExportPerformanceUnsharedImplMacro);

    public:
        explicit ExportPerformanceUnsharedImplMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_PERFORMANCE_UNSHARED_IMPL_MACRO_H