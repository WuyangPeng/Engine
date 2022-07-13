///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/01 14:13)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffectDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"

SoundEffect::SoundEffectDelayCopyUnsharedMacroImpl::SoundEffectDelayCopyUnsharedMacroImpl(int count) noexcept
    : mCount{ count }
{
    SOUND_EFFECT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(SoundEffect, SoundEffectDelayCopyUnsharedMacroImpl)

int SoundEffect::SoundEffectDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void SoundEffect::SoundEffectDelayCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_9;

    mCount = count;
}
