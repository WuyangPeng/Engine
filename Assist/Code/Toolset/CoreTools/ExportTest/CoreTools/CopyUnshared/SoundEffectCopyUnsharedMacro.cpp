///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:39)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffectCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/SoundEffectCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(SoundEffect, SoundEffectCopyUnsharedMacro)

SoundEffect::SoundEffectCopyUnsharedMacro::SoundEffectCopyUnsharedMacro(int count)
    : impl{ count }
{
    SOUND_EFFECT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(SoundEffect, SoundEffectCopyUnsharedMacro)

int SoundEffect::SoundEffectCopyUnsharedMacro::GetCount() const noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void SoundEffect::SoundEffectCopyUnsharedMacro::SetCount(int count) noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* SoundEffect::SoundEffectCopyUnsharedMacro::GetAddress() const noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}