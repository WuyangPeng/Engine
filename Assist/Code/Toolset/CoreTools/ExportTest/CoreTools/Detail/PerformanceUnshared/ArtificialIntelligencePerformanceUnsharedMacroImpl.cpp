/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:13)

#include "ArtificialIntelligence/ArtificialIntelligenceExport.h"

#include "ArtificialIntelligencePerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"

ArtificialIntelligence::ArtificialIntelligencePerformanceUnsharedMacroImpl::ArtificialIntelligencePerformanceUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    ARTIFICIAL_INTELLIGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntelligence, ArtificialIntelligencePerformanceUnsharedMacroImpl)

int ArtificialIntelligence::ArtificialIntelligencePerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_CONST_9;

    return count;
}
