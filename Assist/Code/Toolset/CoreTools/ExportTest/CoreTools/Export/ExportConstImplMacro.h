/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:46)

#ifndef EXPORT_TEST_EXPORT_CONST_IMPL_MACRO_H
#define EXPORT_TEST_EXPORT_CONST_IMPL_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

EXPORT_CONST_SHARED_PTR(CoreTools, ExportConstImplMacroImpl, CORE_TOOLS_DEFAULT_DECLARE);
EXPORT_CONST_IMPL(ExportConstImplMacroImpl, CORE_TOOLS, PERFORMANCE_UNSHARED);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ExportConstImplMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ExportConstImplMacro);

    public:
        explicit ExportConstImplMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_CONST_IMPL_MACRO_H