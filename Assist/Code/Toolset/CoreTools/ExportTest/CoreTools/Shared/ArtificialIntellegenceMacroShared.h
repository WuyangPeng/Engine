///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/02 13:57)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_MACRO_SHARED_H
#define EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_MACRO_SHARED_H

#include "ArtificialIntellegence/ArtificialIntellegenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

ARTIFICIAL_INTELLEGENCE_SHARED_EXPORT_IMPL(ArtificialIntellegenceMacroSharedImpl);

namespace ArtificialIntellegence
{
    class ARTIFICIAL_INTELLEGENCE_DEFAULT_DECLARE ArtificialIntellegenceMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(ArtificialIntellegenceMacroShared);

    public:
        explicit ArtificialIntellegenceMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_MACRO_SHARED_H