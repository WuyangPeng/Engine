/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:51)

#ifndef EXPORT_TEST_ANIMATION_NON_COPY_MACRO_H
#define EXPORT_TEST_ANIMATION_NON_COPY_MACRO_H

#include "Animation/AnimationDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

ANIMATION_NON_COPY_EXPORT_IMPL(AnimationNonCopyMacroImpl);

namespace Animation
{
    class ANIMATION_DEFAULT_DECLARE AnimationNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(AnimationNonCopyMacro);

    public:
        explicit AnimationNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ANIMATION_NON_COPY_MACRO_H