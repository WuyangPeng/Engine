///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 19:06)

#include "ArtificialIntellegence/ArtificialIntellegenceExport.h"

#include "ArtificialIntellegencePerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntellegenceClassInvariantMacro.h"

ArtificialIntellegence::ArtificialIntellegencePerformanceUnsharedMacroImpl::ArtificialIntellegencePerformanceUnsharedMacroImpl(int count) noexcept
    : mCount{ count }
{
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntellegence, ArtificialIntellegencePerformanceUnsharedMacroImpl)

int ArtificialIntellegence::ArtificialIntellegencePerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void ArtificialIntellegence::ArtificialIntellegencePerformanceUnsharedMacroImpl::SetCount(int count) noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_9;

    mCount = count;
}