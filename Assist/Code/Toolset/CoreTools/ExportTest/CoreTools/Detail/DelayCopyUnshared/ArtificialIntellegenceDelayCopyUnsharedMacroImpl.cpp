///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/01 14:12)

#include "ArtificialIntellegence/ArtificialIntellegenceExport.h"

#include "ArtificialIntellegenceDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntellegenceClassInvariantMacro.h"

ArtificialIntellegence::ArtificialIntellegenceDelayCopyUnsharedMacroImpl::ArtificialIntellegenceDelayCopyUnsharedMacroImpl(int count) noexcept
    : mCount{ count }
{
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntellegence, ArtificialIntellegenceDelayCopyUnsharedMacroImpl)

int ArtificialIntellegence::ArtificialIntellegenceDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void ArtificialIntellegence::ArtificialIntellegenceDelayCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_9;

    mCount = count;
}