///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:07)

#ifndef EXPORT_TEST_EXPORT_NON_COPY_IMPL_MACRO_H
#define EXPORT_TEST_EXPORT_NON_COPY_IMPL_MACRO_H

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

EXPORT_SHARED_PTR(ExportTest, ExportNonCopyImplMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);
EXPORT_NON_COPY(ExportTest, ExportNonCopyImplMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);

namespace ExportTest
{
    class EXPORT_TEST_DEFAULT_DECLARE ExportNonCopyImplMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ExportNonCopyImplMacro);

    public:
        explicit ExportNonCopyImplMacro(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_NON_COPY_IMPL_MACRO_H