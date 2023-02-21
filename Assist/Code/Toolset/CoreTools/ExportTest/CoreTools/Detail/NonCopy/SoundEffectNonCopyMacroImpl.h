///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 16:51)

#ifndef EXPORT_TEST_SOUND_EFFECT_NON_COPY_MACRO_IMPL_H
#define EXPORT_TEST_SOUND_EFFECT_NON_COPY_MACRO_IMPL_H

#include "SoundEffect/SoundEffectDll.h"

#include <memory>

namespace SoundEffect
{
    class SOUND_EFFECT_HIDDEN_DECLARE SoundEffectNonCopyMacroImpl final
    {
    public:
        using ClassType = SoundEffectNonCopyMacroImpl;

    public:
        explicit SoundEffectNonCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_NON_COPY_MACRO_IMPL_H