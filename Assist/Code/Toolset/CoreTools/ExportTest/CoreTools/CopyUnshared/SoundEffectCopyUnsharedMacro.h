///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 15:06)

#ifndef EXPORT_TEST_SOUND_EFFECT_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_SOUND_EFFECT_COPY_UNSHARED_MACRO_H

#include "SoundEffect/SoundEffectDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

SOUND_EFFECT_COPY_UNSHARED_EXPORT_IMPL(SoundEffectCopyUnsharedMacro, SoundEffectCopyUnsharedMacroImpl);

namespace SoundEffect
{
    class SOUND_EFFECT_DEFAULT_DECLARE SoundEffectCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(SoundEffectCopyUnsharedMacro);

    public:
        explicit SoundEffectCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_COPY_UNSHARED_MACRO_H