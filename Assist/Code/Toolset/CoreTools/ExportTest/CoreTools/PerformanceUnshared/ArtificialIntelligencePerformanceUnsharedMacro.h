/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:53)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_PERFORMANCE_UNSHARED_MACRO_H

#include "ArtificialIntelligence/ArtificialIntelligenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

ARTIFICIAL_INTELLIGENCE_PERFORMANCE_UNSHARED_EXPORT_IMPL(ArtificialIntelligencePerformanceUnsharedMacroImpl);

namespace ArtificialIntelligence
{
    class ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE ArtificialIntelligencePerformanceUnsharedMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ArtificialIntelligencePerformanceUnsharedMacro);

    public:
        explicit ArtificialIntelligencePerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_PERFORMANCE_UNSHARED_MACRO_H