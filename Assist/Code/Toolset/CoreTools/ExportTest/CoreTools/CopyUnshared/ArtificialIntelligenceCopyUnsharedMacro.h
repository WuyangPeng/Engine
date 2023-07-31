///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:54)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_COPY_UNSHARED_MACRO_H

#include "ArtificialIntelligence/ArtificialIntelligenceDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

ARTIFICIAL_INTELLIGENCE_COPY_UNSHARED_EXPORT_IMPL(ArtificialIntelligenceCopyUnsharedMacro, ArtificialIntelligenceCopyUnsharedMacroImpl);

namespace ArtificialIntelligence
{
    class ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE ArtificialIntelligenceCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ArtificialIntelligenceCopyUnsharedMacro);

    public:
        explicit ArtificialIntelligenceCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLIGENCE_COPY_UNSHARED_MACRO_H