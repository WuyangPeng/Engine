///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 17:05)

#ifndef EXPORT_TEST_EXPORT_COPY_UNSHARED_IMPL_MACRO_H
#define EXPORT_TEST_EXPORT_COPY_UNSHARED_IMPL_MACRO_H

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/ExportTestDll.h"

EXPORT_SHARED_PTR(ExportTest, ExportCopyUnsharedImplMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);
EXPORT_COPY_UNSHARED(ExportTest, ExportCopyUnsharedImplMacro, ExportCopyUnsharedImplMacroImpl, EXPORT_TEST_DEFAULT_DECLARE);

namespace ExportTest
{
    class EXPORT_TEST_DEFAULT_DECLARE ExportCopyUnsharedImplMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ExportCopyUnsharedImplMacro);

    public:
        explicit ExportCopyUnsharedImplMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_COPY_UNSHARED_IMPL_MACRO_H