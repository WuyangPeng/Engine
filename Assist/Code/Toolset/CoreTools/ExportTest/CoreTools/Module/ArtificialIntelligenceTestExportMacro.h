/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:49)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_TEST_EXPORT_MACRO_H

#include "ArtificialIntelligence/ArtificialIntelligenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(ArtificialIntelligence, ArtificialIntelligenceTestExportMacroImpl, ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE);
ARTIFICIAL_INTELLIGENCE_EXPORT(ArtificialIntelligenceTestExportMacroImpl, NON_COPY);
ARTIFICIAL_INTELLIGENCE_EXPORT_UNIQUE_PTR(ArtificialIntelligenceTestExportMacro);

namespace ArtificialIntelligence
{
    class ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE ArtificialIntelligenceTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(ArtificialIntelligenceTestExportMacro);

    public:
        explicit ArtificialIntelligenceTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_TEST_EXPORT_MACRO_H