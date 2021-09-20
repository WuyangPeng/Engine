///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 22:37)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffectCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"

SoundEffect::SoundEffectCopyUnsharedMacroImpl::SoundEffectCopyUnsharedMacroImpl(int count) noexcept
    : m_Count{ count }
{
    SOUND_EFFECT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(SoundEffect, SoundEffectCopyUnsharedMacroImpl)

int SoundEffect::SoundEffectCopyUnsharedMacroImpl::GetCount() const noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void SoundEffect::SoundEffectCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_9;

    m_Count = count;
}
