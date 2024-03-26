/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:47)

#ifndef EXPORT_TEST_EXPORT_NON_COPY_IMPL_MACRO_H
#define EXPORT_TEST_EXPORT_NON_COPY_IMPL_MACRO_H

#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(ExportTest, ExportNonCopyImplMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);
EXPORT_NON_COPY(ExportTest, ExportNonCopyImplMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);

namespace ExportTest
{
    class EXPORT_TEST_DEFAULT_DECLARE ExportNonCopyImplMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ExportNonCopyImplMacro);

    public:
        NODISCARD static ExportNonCopyImplMacro Create();

        CLASS_INVARIANT_DECLARE;

    private:
        using DisableNotThrow = CoreTools::DisableNotThrow;

    private:
        explicit ExportNonCopyImplMacro(DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_NON_COPY_IMPL_MACRO_H