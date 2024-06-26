/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:25)

#ifndef EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_COPY_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(CoreTools, CoreToolsTestExportCopyMacroImpl, CORE_TOOLS_DEFAULT_DECLARE);
CORE_TOOLS_COPY_EXPORT(CoreToolsTestExportCopyMacro, CoreToolsTestExportCopyMacroImpl, COPY_UNSHARED);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CoreToolsTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(CoreToolsTestExportCopyMacro);

    public:
        explicit CoreToolsTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_CORE_TOOLS_TEST_EXPORT_COPY_MACRO_H