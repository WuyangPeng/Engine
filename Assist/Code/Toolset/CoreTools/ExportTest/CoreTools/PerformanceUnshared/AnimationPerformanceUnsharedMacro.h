///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 17:15)

#ifndef EXPORT_TEST_ANIMATION_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_ANIMATION_PERFORMANCE_UNSHARED_MACRO_H

#include "Animation/AnimationDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

ANIMATION_PERFORMANCE_UNSHARED_EXPORT_IMPL(AnimationPerformanceUnsharedMacroImpl);

namespace Animation
{
    class ANIMATION_DEFAULT_DECLARE AnimationPerformanceUnsharedMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(AnimationPerformanceUnsharedMacro);

    public:
        explicit AnimationPerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_ANIMATION_PERFORMANCE_UNSHARED_MACRO_H