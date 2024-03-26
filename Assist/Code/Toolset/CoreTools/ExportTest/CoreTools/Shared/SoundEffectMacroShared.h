/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 09:56)

#ifndef EXPORT_TEST_SOUND_EFFECT_MACRO_SHARED_H
#define EXPORT_TEST_SOUND_EFFECT_MACRO_SHARED_H

#include "SoundEffect/SoundEffectDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

SOUND_EFFECT_SHARED_EXPORT_IMPL(SoundEffectMacroSharedImpl);

namespace SoundEffect
{
    class SOUND_EFFECT_DEFAULT_DECLARE SoundEffectMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(SoundEffectMacroShared);

    public:
        explicit SoundEffectMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_MACRO_SHARED_H