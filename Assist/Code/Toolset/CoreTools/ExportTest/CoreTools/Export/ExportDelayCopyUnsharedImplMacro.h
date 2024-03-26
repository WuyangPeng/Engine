/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:47)

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