/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:35)

#ifndef EXPORT_TEST_SOUND_EFFECT_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_SOUND_EFFECT_COPY_UNSHARED_MACRO_IMPL_H

#include "SoundEffect/SoundEffectDll.h"

namespace SoundEffect
{
    class SOUND_EFFECT_HIDDEN_DECLARE SoundEffectCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = SoundEffectCopyUnsharedMacroImpl;

    public:
        explicit SoundEffectCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_COPY_UNSHARED_MACRO_IMPL_H