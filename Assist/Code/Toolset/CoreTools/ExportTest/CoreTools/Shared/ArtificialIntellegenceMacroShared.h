///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 17:17)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_MACRO_SHARED_H
#define EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_MACRO_SHARED_H

#include "ArtificialIntellegence/ArtificialIntellegenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

ARTIFICIAL_INTELLIGENCE_SHARED_EXPORT_IMPL(ArtificialIntellegenceMacroSharedImpl);

namespace ArtificialIntellegence
{
    class ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE ArtificialIntellegenceMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(ArtificialIntellegenceMacroShared);

    public:
        explicit ArtificialIntellegenceMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_MACRO_SHARED_H