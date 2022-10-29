///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/18 0:05)

#ifndef EXPORT_TEST_MATHEMATICS_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_MATHEMATICS_PERFORMANCE_UNSHARED_MACRO_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

MATHEMATICS_PERFORMANCE_UNSHARED_EXPORT_IMPL(MathematicsPerformanceUnsharedMacroImpl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE MathematicsPerformanceUnsharedMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(MathematicsPerformanceUnsharedMacro);

    public:
        explicit MathematicsPerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_MATHEMATICS_PERFORMANCE_UNSHARED_MACRO_H