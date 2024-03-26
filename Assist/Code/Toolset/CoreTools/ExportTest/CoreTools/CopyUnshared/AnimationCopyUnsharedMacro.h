/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:27)

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

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ANIMATION_COPY_UNSHARED_MACRO_H