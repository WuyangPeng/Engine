///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/02 13:59)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_PERFORMANCE_UNSHARED_MACRO_H

#include "ArtificialIntellegence/ArtificialIntellegenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

ARTIFICIAL_INTELLEGENCE_PERFORMANCE_UNSHARED_EXPORT_IMPL(ArtificialIntellegencePerformanceUnsharedMacroImpl);

namespace ArtificialIntellegence
{
    class ARTIFICIAL_INTELLEGENCE_DEFAULT_DECLARE ArtificialIntellegencePerformanceUnsharedMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ArtificialIntellegencePerformanceUnsharedMacro);

    public:
        explicit ArtificialIntellegencePerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_PERFORMANCE_UNSHARED_MACRO_H