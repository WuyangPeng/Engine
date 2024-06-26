/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:02)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffectDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/SoundEffectDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(SoundEffect, SoundEffectDelayCopyUnsharedMacro)

SoundEffect::SoundEffectDelayCopyUnsharedMacro::SoundEffectDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    SOUND_EFFECT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(SoundEffect, SoundEffectDelayCopyUnsharedMacro)

int SoundEffect::SoundEffectDelayCopyUnsharedMacro::GetCount() const noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void SoundEffect::SoundEffectDelayCopyUnsharedMacro::SetCount(int count)
{
    SOUND_EFFECT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* SoundEffect::SoundEffectDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}