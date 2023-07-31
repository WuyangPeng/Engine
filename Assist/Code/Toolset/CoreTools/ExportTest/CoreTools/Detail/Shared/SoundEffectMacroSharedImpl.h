///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:36)

#ifndef EXPORT_TEST_SOUND_EFFECT_MACRO_SHARED_IMPL_H
#define EXPORT_TEST_SOUND_EFFECT_MACRO_SHARED_IMPL_H

#include "SoundEffect/SoundEffectDll.h"

namespace SoundEffect
{
    class SOUND_EFFECT_HIDDEN_DECLARE SoundEffectMacroSharedImpl final
    {
    public:
        using ClassType = SoundEffectMacroSharedImpl;

    public:
        explicit SoundEffectMacroSharedImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_MACRO_SHARED_IMPL_H