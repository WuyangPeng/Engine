/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:26)

#ifndef EXPORT_TEST_SOUND_EFFECT_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_SOUND_EFFECT_TEST_EXPORT_COPY_MACRO_H

#include "SoundEffect/SoundEffectDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(SoundEffect, SoundEffectTestExportCopyMacroImpl, SOUND_EFFECT_DEFAULT_DECLARE);
SOUND_EFFECT_COPY_EXPORT(SoundEffectTestExportCopyMacro, SoundEffectTestExportCopyMacroImpl, COPY_UNSHARED);

namespace SoundEffect
{
    class SOUND_EFFECT_DEFAULT_DECLARE SoundEffectTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(SoundEffectTestExportCopyMacro);

    public:
        explicit SoundEffectTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_SOUND_EFFECT_TEST_EXPORT_COPY_MACRO_H