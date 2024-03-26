/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:24)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_TEST_EXPORT_COPY_MACRO_H

#include "ArtificialIntelligence/ArtificialIntelligenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(ArtificialIntelligence, ArtificialIntelligenceTestExportCopyMacroImpl, ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE);
ARTIFICIAL_INTELLIGENCE_COPY_EXPORT(ArtificialIntelligenceTestExportCopyMacro, ArtificialIntelligenceTestExportCopyMacroImpl, COPY_UNSHARED);

namespace ArtificialIntelligence
{
    class ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE ArtificialIntelligenceTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ArtificialIntelligenceTestExportCopyMacro);

    public:
        explicit ArtificialIntelligenceTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_TEST_EXPORT_COPY_MACRO_H