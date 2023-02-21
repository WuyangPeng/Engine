///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 17:15)

#ifndef EXPORT_TEST_SOUND_EFFECT_NON_COPY_MACRO_H
#define EXPORT_TEST_SOUND_EFFECT_NON_COPY_MACRO_H

#include "SoundEffect/SoundEffectDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

SOUND_EFFECT_NON_COPY_EXPORT_IMPL(SoundEffectNonCopyMacroImpl);

namespace SoundEffect
{
    class SOUND_EFFECT_DEFAULT_DECLARE SoundEffectNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(SoundEffectNonCopyMacro);

    public:
        explicit SoundEffectNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_NON_COPY_MACRO_H