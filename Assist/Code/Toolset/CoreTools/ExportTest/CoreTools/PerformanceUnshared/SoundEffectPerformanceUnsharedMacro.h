///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:00)

#ifndef EXPORT_TEST_SOUND_EFFECT_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_SOUND_EFFECT_PERFORMANCE_UNSHARED_MACRO_H

#include "SoundEffect/SoundEffectDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

SOUND_EFFECT_PERFORMANCE_UNSHARED_EXPORT_IMPL(SoundEffectPerformanceUnsharedMacroImpl);

namespace SoundEffect
{
    class SOUND_EFFECT_DEFAULT_DECLARE SoundEffectPerformanceUnsharedMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(SoundEffectPerformanceUnsharedMacro);

    public:
        explicit SoundEffectPerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_PERFORMANCE_UNSHARED_MACRO_H