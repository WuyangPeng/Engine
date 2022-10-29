///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/17 11:16)

#ifndef EXPORT_TEST_ANIMATION_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_ANIMATION_COPY_UNSHARED_MACRO_H

#include "Animation/AnimationDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

ANIMATION_COPY_UNSHARED_EXPORT_IMPL(AnimationCopyUnsharedMacro, AnimationCopyUnsharedMacroImpl);

namespace Animation
{
    class ANIMATION_DEFAULT_DECLARE AnimationCopyUnsharedMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(AnimationCopyUnsharedMacro);

    public:
        explicit AnimationCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ANIMATION_COPY_UNSHARED_MACRO_H