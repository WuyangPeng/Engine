/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:01)

#include "ArtificialIntelligence/ArtificialIntelligenceExport.h"

#include "ArtificialIntelligenceDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/ArtificialIntelligenceDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(ArtificialIntelligence, ArtificialIntelligenceDelayCopyUnsharedMacro)

ArtificialIntelligence::ArtificialIntelligenceDelayCopyUnsharedMacro::ArtificialIntelligenceDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    ARTIFICIAL_INTELLIGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntelligence, ArtificialIntelligenceDelayCopyUnsharedMacro)

int ArtificialIntelligence::ArtificialIntelligenceDelayCopyUnsharedMacro::GetCount() const noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ArtificialIntelligence::ArtificialIntelligenceDelayCopyUnsharedMacro::SetCount(int count)
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* ArtificialIntelligence::ArtificialIntelligenceDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}
