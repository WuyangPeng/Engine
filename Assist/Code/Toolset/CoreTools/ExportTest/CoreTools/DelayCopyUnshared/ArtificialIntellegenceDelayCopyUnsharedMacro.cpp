///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 18:55)

#include "ArtificialIntellegence/ArtificialIntellegenceExport.h"

#include "ArtificialIntellegenceDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntellegenceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/ArtificialIntellegenceDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(ArtificialIntellegence, ArtificialIntellegenceDelayCopyUnsharedMacro)

ArtificialIntellegence::ArtificialIntellegenceDelayCopyUnsharedMacro::ArtificialIntellegenceDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntellegence, ArtificialIntellegenceDelayCopyUnsharedMacro)

int ArtificialIntellegence::ArtificialIntellegenceDelayCopyUnsharedMacro::GetCount() const noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ArtificialIntellegence::ArtificialIntellegenceDelayCopyUnsharedMacro::SetCount(int count)
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* ArtificialIntellegence::ArtificialIntellegenceDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}
