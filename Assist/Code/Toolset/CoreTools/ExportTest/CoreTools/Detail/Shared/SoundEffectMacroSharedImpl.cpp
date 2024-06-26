/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:17)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffectMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"

SoundEffect::SoundEffectMacroSharedImpl::SoundEffectMacroSharedImpl(int count) noexcept
    : count{ count }
{
    SOUND_EFFECT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(SoundEffect, SoundEffectMacroSharedImpl)

int SoundEffect::SoundEffectMacroSharedImpl::GetCount() const noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;

    return count;
}

void SoundEffect::SoundEffectMacroSharedImpl::SetCount(int aCount) noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_9;

    count = aCount;
}
