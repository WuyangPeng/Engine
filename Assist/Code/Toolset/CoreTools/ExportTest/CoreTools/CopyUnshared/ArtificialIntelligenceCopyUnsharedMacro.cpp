///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:38)

#include "ArtificialIntelligence/ArtificialIntelligenceExport.h"

#include "ArtificialIntelligenceCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/ArtificialIntelligenceCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(ArtificialIntelligence, ArtificialIntelligenceCopyUnsharedMacro)

ArtificialIntelligence::ArtificialIntelligenceCopyUnsharedMacro::ArtificialIntelligenceCopyUnsharedMacro(int count)
    : impl{ count }
{
    ARTIFICIAL_INTELLIGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntelligence, ArtificialIntelligenceCopyUnsharedMacro)

int ArtificialIntelligence::ArtificialIntelligenceCopyUnsharedMacro::GetCount() const noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ArtificialIntelligence::ArtificialIntelligenceCopyUnsharedMacro::SetCount(int count) noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* ArtificialIntelligence::ArtificialIntelligenceCopyUnsharedMacro::GetAddress() const noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}