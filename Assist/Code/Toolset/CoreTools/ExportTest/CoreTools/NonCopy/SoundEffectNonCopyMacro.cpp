///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:23)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffectNonCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/NonCopy/SoundEffectNonCopyMacroImpl.h"

SoundEffect::SoundEffectNonCopyMacro::SoundEffectNonCopyMacro(int count)
    : impl{ count }
{
    SOUND_EFFECT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(SoundEffect, SoundEffectNonCopyMacro)

int SoundEffect::SoundEffectNonCopyMacro::GetCount() const noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void SoundEffect::SoundEffectNonCopyMacro::SetCount(int count) noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
