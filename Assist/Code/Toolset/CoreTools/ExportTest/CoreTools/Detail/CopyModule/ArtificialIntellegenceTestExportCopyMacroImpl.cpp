///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 18:58)

#include "ArtificialIntellegence/ArtificialIntellegenceExport.h"

#include "ArtificialIntellegenceTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"

ArtificialIntellegence::ArtificialIntellegenceTestExportCopyMacroImpl::ArtificialIntellegenceTestExportCopyMacroImpl(int count) noexcept
    : count{ count }
{
    ARTIFICIAL_INTELLIGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntellegence, ArtificialIntellegenceTestExportCopyMacroImpl)

int ArtificialIntellegence::ArtificialIntellegenceTestExportCopyMacroImpl::GetCount() const noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_CONST_9;

    return count;
}

void ArtificialIntellegence::ArtificialIntellegenceTestExportCopyMacroImpl::SetCount(int aCount) noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_9;

    count = aCount;
}