///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:33)

#include "ArtificialIntellegence/ArtificialIntellegenceExport.h"

#include "ArtificialIntellegenceNonCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/NonCopy/ArtificialIntellegenceNonCopyMacroImpl.h"

ArtificialIntellegence::ArtificialIntellegenceNonCopyMacro::ArtificialIntellegenceNonCopyMacro(int count)
    : impl{ count }
{
    ARTIFICIAL_INTELLIGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntellegence, ArtificialIntellegenceNonCopyMacro)

int ArtificialIntellegence::ArtificialIntellegenceNonCopyMacro::GetCount() const noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ArtificialIntellegence::ArtificialIntellegenceNonCopyMacro::SetCount(int count) noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
