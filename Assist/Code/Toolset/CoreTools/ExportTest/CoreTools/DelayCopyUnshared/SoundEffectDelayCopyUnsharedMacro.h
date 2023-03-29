///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 15:28)

#ifndef EXPORT_TEST_SOUND_EFFECT_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_SOUND_EFFECT_DELAY_COPY_UNSHARED_MACRO_H

#include "SoundEffect/SoundEffectDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

SOUND_EFFECT_DELAY_COPY_UNSHARED_EXPORT_IMPL(SoundEffectDelayCopyUnsharedMacro, SoundEffectDelayCopyUnsharedMacroImpl);

namespace SoundEffect
{
    class SOUND_EFFECT_DEFAULT_DECLARE SoundEffectDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(SoundEffectDelayCopyUnsharedMacro);

    public:
        explicit SoundEffectDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_DELAY_COPY_UNSHARED_MACRO_H