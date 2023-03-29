///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/16 20:25)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffectDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"

SoundEffect::SoundEffectDelayCopyUnsharedMacroImpl::SoundEffectDelayCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    SOUND_EFFECT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(SoundEffect, SoundEffectDelayCopyUnsharedMacroImpl)

int SoundEffect::SoundEffectDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;

    return count;
}

void SoundEffect::SoundEffectDelayCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_9;

    count = aCount;
}
