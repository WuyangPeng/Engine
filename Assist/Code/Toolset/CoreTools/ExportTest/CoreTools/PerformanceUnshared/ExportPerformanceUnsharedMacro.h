///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/02 13:59)

#ifndef EXPORT_TEST_EXPORT_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_EXPORT_PERFORMANCE_UNSHARED_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

NON_COPY_EXPORT_IMPL(ExportPerformanceUnsharedMacroImpl, CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ExportPerformanceUnsharedMacro
    {
    public:
        NON_COPY_TYPE_DECLARE(ExportPerformanceUnsharedMacro);

    public:
        explicit ExportPerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_EXPORT_PERFORMANCE_UNSHARED_MACRO_H