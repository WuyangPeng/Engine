///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:19)

#include "ArtificialIntellegence/ArtificialIntellegenceExport.h"

#include "ArtificialIntellegenceNonCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"

ArtificialIntellegence::ArtificialIntellegenceNonCopyMacroImpl::ArtificialIntellegenceNonCopyMacroImpl(int count) noexcept
    : count{ count }
{
    ARTIFICIAL_INTELLIGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntellegence, ArtificialIntellegenceNonCopyMacroImpl)

int ArtificialIntellegence::ArtificialIntellegenceNonCopyMacroImpl::GetCount() const noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_CONST_9;

    return count;
}

void ArtificialIntellegence::ArtificialIntellegenceNonCopyMacroImpl::SetCount(int aCount) noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_9;

    count = aCount;
}