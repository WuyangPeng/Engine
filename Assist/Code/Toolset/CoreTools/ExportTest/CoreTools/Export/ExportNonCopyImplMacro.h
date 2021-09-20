///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 16:52)

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