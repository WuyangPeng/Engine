///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 16:56)

#ifndef EXPORT_TEST_SOUND_EFFECT_PERFORMANCE_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_SOUND_EFFECT_PERFORMANCE_UNSHARED_MACRO_IMPL_H

#include "SoundEffect/SoundEffectDll.h"

#include <memory>

namespace SoundEffect
{
    class SOUND_EFFECT_HIDDEN_DECLARE SoundEffectPerformanceUnsharedMacroImpl final
    {
    public:
        using ClassType = SoundEffectPerformanceUnsharedMacroImpl;

    public:
        explicit SoundEffectPerformanceUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept; 

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_PERFORMANCE_UNSHARED_MACRO_IMPL_H