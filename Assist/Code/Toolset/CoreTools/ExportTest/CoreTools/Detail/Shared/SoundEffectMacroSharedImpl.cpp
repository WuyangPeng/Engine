///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 19:00)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffectMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"

SoundEffect::SoundEffectMacroSharedImpl::SoundEffectMacroSharedImpl(int count) noexcept
    : mCount{ count }
{
    SOUND_EFFECT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(SoundEffect, SoundEffectMacroSharedImpl)

int SoundEffect::SoundEffectMacroSharedImpl::GetCount() const noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void SoundEffect::SoundEffectMacroSharedImpl::SetCount(int count) noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_9;

    mCount = count;
}
