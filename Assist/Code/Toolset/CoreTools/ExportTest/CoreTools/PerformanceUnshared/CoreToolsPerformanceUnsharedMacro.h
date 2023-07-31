///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:59)

#ifndef EXPORT_TEST_CORE_TOOLS_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_CORE_TOOLS_PERFORMANCE_UNSHARED_MACRO_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(CoreToolsPerformanceUnsharedMacroImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CoreToolsPerformanceUnsharedMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CoreToolsPerformanceUnsharedMacro);

    public:
        explicit CoreToolsPerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_CORE_TOOLS_PERFORMANCE_UNSHARED_MACRO_H