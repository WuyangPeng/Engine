///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:56)

#ifndef EXPORT_TEST_SOUND_EFFECT_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_SOUND_EFFECT_TEST_EXPORT_MACRO_H

#include "SoundEffect/SoundEffectDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(SoundEffect, SoundEffectTestExportMacroImpl, SOUND_EFFECT_DEFAULT_DECLARE);
SOUND_EFFECT_EXPORT(SoundEffectTestExportMacroImpl, NON_COPY);
SOUND_EFFECT_EXPORT_UNIQUE_PTR(SoundEffectTestExportMacro);

namespace SoundEffect
{
    class SOUND_EFFECT_DEFAULT_DECLARE SoundEffectTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(SoundEffectTestExportMacro);

    public:
        explicit SoundEffectTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_TEST_EXPORT_MACRO_H