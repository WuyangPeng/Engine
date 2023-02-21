///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 17:17)

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

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_PERFORMANCE_UNSHARED_MACRO_H