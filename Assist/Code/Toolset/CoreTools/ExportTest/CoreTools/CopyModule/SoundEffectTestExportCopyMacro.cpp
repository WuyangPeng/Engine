///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 09:14)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffectTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/SoundEffectClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/SoundEffectTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(SoundEffect, SoundEffectTestExportCopyMacro)

SoundEffect::SoundEffectTestExportCopyMacro::SoundEffectTestExportCopyMacro(int count)
    : impl{ count }
{
    SOUND_EFFECT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(SoundEffect, SoundEffectTestExportCopyMacro)

int SoundEffect::SoundEffectTestExportCopyMacro::GetCount() const noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void SoundEffect::SoundEffectTestExportCopyMacro::SetCount(int count) noexcept
{
    SOUND_EFFECT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}


